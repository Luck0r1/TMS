/*******************************************************************************
*                                                                              *
*                         Brno University of Technology                        *
*                       Faculty of Information Technology                      *
*                                                                              *
*                         Color-to-Grayscale Conversions                       *
*                                                                              *
*                                 Bachelor thesis                              *
*             Author: Filip Brezna [xbrezn00 AT stud.fit.vutbr.cz]             *
*                                    Brno 2018                                 *
*                                                                              *
*******************************************************************************/


/* --------------------------------------------------------------------------- *
 * TMOJin17.cpp: implementation of the TMOJin17 class.   		  			   *
 * --------------------------------------------------------------------------- */

#include "TMOJin17.h"
#include <stdlib.h>
#include <math.h>
#include <cstring>

#include <mlpack/core/optimizers/adam/adam.hpp> //armadillo-7.950.1

//tmolib contains definition for EPS,
//so does openCV so we undefine it and then put it back. After link
#ifdef EPS
#undef EPS
#define EPS EPS2
#endif
#include "opencv2/opencv.hpp"
#undef EPS

using namespace cv;
	std::ofstream myfile;

#define BETA 0.5
#define CIELAB_NUM_CHANNELS 3
#define SHIFT_TO_L 0
#define SHIFT_TO_A 1
#define SHIFT_TO_B 2			

unsigned int IMAGE_WIDTH; //global variable for width of loaded image
unsigned int IMAGE_HEIGHT; //global variable for height of loaded image


#include <fstream>

/* --------------------------------------------------------------------------- *
 * Constructor serves for describing a technique and input parameters          *
 * --------------------------------------------------------------------------- */
TMOJin17::TMOJin17()
{
	SetName(L"Jin17");						
	SetDescription(L"Preserving perceptual contrast in decolorization with optimized color orders");	

	K_clusters.SetName(L"K");
	K_clusters.SetDescription(L"Value of K for K-means clustering ; <5,50>");
	K_clusters.SetDefault(30);
	K_clusters=30;		
	K_clusters.SetRange(5,50);
	this->Register(K_clusters);
}

TMOJin17::~TMOJin17()
{
}

unsigned int SignFunction(Mat centersRGB, int x, int y)
{

	//if r_x >= r_y AND g_x >= g_y AND b_x >= b_y
	if  (
			//SHIFT_TO_L == SHIFT_TO_R
			( centersRGB.at <float> (x, SHIFT_TO_L) >= centersRGB.at <float> (y, SHIFT_TO_L) ) &&
			//SHIFT_TO_L == SHIFT_TO_G
			( centersRGB.at <float> (x, SHIFT_TO_L) >= centersRGB.at <float> (y, SHIFT_TO_A) ) &&
		    //SHIFT_TO_L == SHIFT_TO_B
			( centersRGB.at <float> (x, SHIFT_TO_L) >= centersRGB.at <float> (y, SHIFT_TO_B) ) 
		)
		return 1;

	//if r_x < r_y AND g_x < g_y AND b_x < b_y
	else if
		(
			//SHIFT_TO_L == SHIFT_TO_R
			( centersRGB.at <float> (x, SHIFT_TO_L) < centersRGB.at <float> (y, SHIFT_TO_L) ) &&
			//SHIFT_TO_L == SHIFT_TO_G
			( centersRGB.at <float> (x, SHIFT_TO_L) < centersRGB.at <float> (y, SHIFT_TO_A) ) &&
		    //SHIFT_TO_L == SHIFT_TO_B
			( centersRGB.at <float> (x, SHIFT_TO_L) < centersRGB.at <float> (y, SHIFT_TO_B) ) 
		)
		return 2;

	//else
	return 3;
}


//color conversion from CIELab to RGB
//Always must go through XYZ color space
void convertLAB2RGB(Mat srcLab, Mat &dstRGB)
{
	float L, a, b;
	float X, Y, Z;
	float R, G, B;

	// Lab -> normalized XYZ (X,Y,Z are all in 0...1)
	for (unsigned int i = 0; i < srcLab.size().height; ++i)
	{
		L = srcLab.at <float> (i, SHIFT_TO_L);
		a = srcLab.at <float> (i, SHIFT_TO_A);
		b = srcLab.at <float> (i, SHIFT_TO_B);


		Y = L * (1.0/116.0) + 16.0/116.0;
		X = a * (1.0/500.0) + Y;
		Z = b * (-1.0/200.0) + Y;

		X = X > 6.0/29.0 ? X * X * X : X * (108.0/841.0) - 432.0/24389.0;
		Y = L > 8.0 ? Y * Y * Y : L * (27.0/24389.0);
		Z = Z > 6.0/29.0 ? Z * Z * Z : Z * (108.0/841.0) - 432.0/24389.0;

		// normalized XYZ -> linear sRGB (in 0...1)

		R = X * (1219569.0/395920.0)     + Y * (-608687.0/395920.0)    + Z * (-107481.0/197960.0);
		G = X * (-80960619.0/87888100.0) + Y * (82435961.0/43944050.0) + Z * (3976797.0/87888100.0);
		B = X * (93813.0/1774030.0)      + Y * (-180961.0/887015.0)    + Z * (107481.0/93370.0);

		// linear sRGB -> gamma-compressed sRGB (in 0...1)

		R = R > 0.0031308 ? pow(R, 1.0 / 2.4) * 1.055 - 0.055 : R * 12.92;
		G = G > 0.0031308 ? pow(G, 1.0 / 2.4) * 1.055 - 0.055 : G * 12.92;
		B = B > 0.0031308 ? pow(B, 1.0 / 2.4) * 1.055 - 0.055 : B * 12.92;

		dstRGB.at <float> (i, SHIFT_TO_L) = R * 255; 
		dstRGB.at <float> (i, SHIFT_TO_A) = G * 255; 
		dstRGB.at <float> (i, SHIFT_TO_B) = B * 255; 

	}

}


void colorToGrayscaleConversion(Mat sourceImageRGB, Mat &destImageGray, int Mat_height, int Mat_width, double *Omega)
{

	unsigned int Omega_array_index = 0;
	double sourceImageRGB_r, sourceImageRGB_g, sourceImageRGB_b;
	double result;

	for (unsigned int r = 0; r <= 2; ++r)
	{
		for (unsigned int g = 0; g <= 2; ++g)
		{
			for (unsigned int b = 0; b <= 2; ++b)
			{
				
				if ( ((r + g + b) <= 2) &&  ((r + g + b) > 0) )
				{
					
					for (unsigned int row = 0; row < Mat_height; ++row)
					{
				
						for (unsigned int col = 0; col < Mat_width; ++col)
						{
							//taking all RGB values for one pixel and computing new ones to destination image
							sourceImageRGB_r = sourceImageRGB.at <float> (col + row * Mat_width, SHIFT_TO_L);
							sourceImageRGB_g = sourceImageRGB.at <float> (col + row * Mat_width, SHIFT_TO_A);
							sourceImageRGB_b = sourceImageRGB.at <float> (col + row * Mat_width, SHIFT_TO_B);

							//multiplying values with computed weight coefficients
							result = Omega[Omega_array_index] * pow(sourceImageRGB_r, r) * pow(sourceImageRGB_g, g) * pow(sourceImageRGB_b, b);

							//actualization of destination image for current pixel
							destImageGray.at <float> (row, col) += result;

						}
					}

					
					Omega_array_index++;
				}
			}	
		}
	}

}


double contrastLossComputation(unsigned int *PixNumberInClusters, Mat centersLAB, Mat centersRGB, Mat centersGray, int centersSize, double *Omega)
{
	double weightClusterPair;

	unsigned int signFunReturned;
	double midStepCalculation;

	double contrastLossSum = 0.0;

	colorToGrayscaleConversion(centersLAB, centersGray, centersLAB.size().height, 1, Omega);

	//main cycle for Contrast Loss computation
	for (unsigned int Ci = 0; Ci < centersSize; ++Ci)
	{
		for (unsigned int Cj = 0; Cj < centersSize; ++Cj)
		{

			midStepCalculation = ( 1 / log(1 + BETA) ) * ( BETA / ( BETA * (centersGray.at <float> (Cj, 0)) + 1) ) * ( (centersGray.at <float> (Ci, 0)) - (centersGray.at <float> (Cj, 0)) ); 

			signFunReturned = SignFunction(centersRGB, Ci, Cj);

			if (signFunReturned == 2)
				midStepCalculation *= -1;

			else if (signFunReturned == 3)
				midStepCalculation = std::abs(midStepCalculation);

			//second square root for this three channels
			midStepCalculation -= sqrt(
				//(L_Ci - L_Cj)^2 +
				pow( (centersLAB.at <float> (Ci, SHIFT_TO_L) - (centersLAB.at <float> (Cj, SHIFT_TO_L)) ), 2) +
				//(A_Ci - A_Cj)^2 +
				pow( (centersLAB.at <float> (Ci, SHIFT_TO_A) - (centersLAB.at <float> (Cj, SHIFT_TO_A)) ), 2) +
				//(B_Ci - B_Cj)^2
				pow( (centersLAB.at <float> (Ci, SHIFT_TO_B) - (centersLAB.at <float> (Cj, SHIFT_TO_B)) ), 2)
		 	);

			//^2 for the rest
			midStepCalculation = pow(midStepCalculation, 2);

			weightClusterPair = (PixNumberInClusters[Ci] * PixNumberInClusters[Cj]) / pow((0.01 * IMAGE_WIDTH * IMAGE_HEIGHT), 2);

			contrastLossSum += weightClusterPair * midStepCalculation;
		}
	}

	return contrastLossSum;	
}


/* --------------------------------------------------------------------------- *
 * This overloaded function is an implementation of your tone mapping operator *
 * --------------------------------------------------------------------------- */
int TMOJin17::Transform()
{
	myfile.open ("test.txt");
 
	// Source image is stored in local parameter pSrc
	pSrc->Convert(TMO_LAB);								// This is format of CIELab
	// Destination image is in pDst
	pDst->Convert(TMO_LAB);								// This is format of CIELab

	double *sourceImage = pSrc->GetData();				// You can work at low level data
	double *destinationImage = pDst->GetData();			// Data are stored in form of array 
														// of three doubles representing
														// three colour components

	//saving values of image width and height to global variables
	IMAGE_WIDTH = pSrc->GetWidth();
	IMAGE_HEIGHT = pSrc->GetHeight();

	unsigned int row, col, CIELab_channel;

	Mat sourceImage_2D (IMAGE_HEIGHT * IMAGE_WIDTH, CIELAB_NUM_CHANNELS, CV_32F);

	//go through all image pixels
	for (row = 0; row < IMAGE_HEIGHT; ++row)
	{
		for (col = 0; col < IMAGE_WIDTH; ++col)
		{
			//we copy and transform source image into 2D picture [row and col][color channel]
			for (CIELab_channel = 0; CIELab_channel < CIELAB_NUM_CHANNELS; ++CIELab_channel)
				sourceImage_2D.at <float> (row + col * IMAGE_HEIGHT, CIELab_channel) = *(sourceImage + ((col + IMAGE_WIDTH  * row ) * CIELAB_NUM_CHANNELS) + CIELab_channel);	
		
		}
	}		

	// Flag to specify the number of times the algorithm is executed using different initial labellings.
	//The algorithm returns the labels that yield the best compactness (see the last function parameter).
	int attempts = 5;
	
	//Input/output integer array that stores the cluster indices for every sample.
	Mat labelsLAB, labelsGray;

	//Output matrix of the cluster centers, one row per each cluster center.
	Mat centersLAB;

	//function for kmeans clustering. Image color reduction. For faster computations and memory save up
	kmeans(sourceImage_2D, K_clusters, labelsLAB, TermCriteria(CV_TERMCRIT_ITER|CV_TERMCRIT_EPS, 10000, 0.0001), attempts, KMEANS_PP_CENTERS, centersLAB);


	unsigned int cluserID;

	//go through all image pixels
/*	for (row = 0; row < IMAGE_HEIGHT; ++row)
	{	
		for (col = 0; col < IMAGE_WIDTH; ++col)
	    { 
	    	//get id of cluster on row and col
	    	//zero because it is col with zero ID. We have only one anyway
			cluserID = labelsLAB.at <int> (row + col * IMAGE_HEIGHT, 0);

			//return cluster from center on clusterID and save it to destination image
			*(destinationImage + ((col + IMAGE_WIDTH  * row ) * CIELAB_NUM_CHANNELS) + SHIFT_TO_L) = centersLAB.at <float> (cluserID, SHIFT_TO_L);
			*(destinationImage + ((col + IMAGE_WIDTH  * row ) * CIELAB_NUM_CHANNELS) + SHIFT_TO_A) = centersLAB.at <float> (cluserID, SHIFT_TO_A);
			*(destinationImage + ((col + IMAGE_WIDTH  * row ) * CIELAB_NUM_CHANNELS) + SHIFT_TO_B) = centersLAB.at <float> (cluserID, SHIFT_TO_B);
		}
	}
*/		
	
	//###CONTRAST LOSS COMPUTATION###

	int labelsSize = labelsLAB.size().height;
	int centersSize = centersLAB.size().height;

	unsigned int *PixNumberInClusters = new unsigned int [centersSize];
	//fill array PixNumberInClusters with zeroes - starting value
	std::fill_n(PixNumberInClusters, centersSize, 0);

	unsigned int indexToArray;
	
	//computation for number of pixels in specific clusters
	for (unsigned int i = 0; i < labelsSize; ++i)
	{
		//find value in labels, take it as index
		indexToArray = labelsLAB.at <int> (i, 0);
		
		//on that index increment number of occurrence
		PixNumberInClusters[indexToArray] += 1;
	}

	Mat centersRGB = Mat::zeros(centersLAB.size().height, centersLAB.size().width, CV_32F);	
	convertLAB2RGB(centersLAB, centersRGB);
	
	Mat centersGray = Mat::zeros(centersLAB.size().height, 1, CV_32F);


	//					w_b  w_b^2  w_g  w_gb w_g^2 w_r w_rb w_rg w_r^2
	double Omega[9] = {0.33, 0.0, 0.33, 0.0, 0.0, 0.33, 0.0, 0.0, 0.0};

	double contrastLoss = contrastLossComputation (PixNumberInClusters, centersLAB, centersRGB, centersGray, centersSize, Omega);


	myfile << "contrastLoss" << contrastLoss << std::endl;
 	//dealocation of array for storage
	delete[] PixNumberInClusters;
/*	
	
	//Any primitive type from the list can be defined by an identifier in the form CV_<bit-depth>{U|S|F}C(<number_of_channels>)
	Mat sourceImageMat = Mat::zeros(IMAGE_HEIGHT, IMAGE_WIDTH, CV_32FC3);

	//sourceImage copy to cv::Mat
	for (row = 0; row < IMAGE_HEIGHT; ++row)
	{
		for (col = 0; col < IMAGE_WIDTH; ++col)
		{
			//Vec3f is 3 channels float
			sourceImageMat.at <cv::Vec3f> (row, col)[SHIFT_TO_L] = *(sourceImage++);
			sourceImageMat.at <cv::Vec3f> (row, col)[SHIFT_TO_A] = *(sourceImage++);
			sourceImageMat.at <cv::Vec3f> (row, col)[SHIFT_TO_B] = *(sourceImage++);
		}
	}


	//convert or declare to 8 bit values, Thats what decolor function needs as parameters
	Mat destinationImageMat = Mat::zeros(IMAGE_HEIGHT, IMAGE_WIDTH, CV_8U);
	Mat color_boost = Mat::zeros(IMAGE_HEIGHT, IMAGE_WIDTH, CV_8UC3);
	sourceImageMat.convertTo(sourceImageMat, CV_8UC3);

	//decolorization of image using openCV function as used in source algorithm
	//Cewu Lu, Li Xu, Jiaya Jia, “Contrast Preserving Decolorization”
	//IEEE International Conference on Computational Photography (ICCP), 2012. 
	decolor(sourceImageMat, destinationImageMat, color_boost);

	//convert back to 32 bit float
	destinationImageMat.convertTo(destinationImageMat, CV_32F);
	
	//color boost stores color image with better contrast
	color_boost.convertTo(color_boost, CV_32FC3);

	//go through whole image and compute new values for destinationImage
	for (row = 0; row < IMAGE_HEIGHT; ++row)
	{
		for (col = 0; col < IMAGE_WIDTH; ++col)
		{
			//get id of cluster on row and col
	    	//zero because it is col with zero ID. We have only one anyway
			cluserID = labels.at <int> (row + col * IMAGE_HEIGHT, 0);


			//L channel
			*(destinationImage++) = destinationImageMat.at <float> (row, col);// + contrastLossSum;
			//A and B channels
			*(destinationImage++) = 0;
			*(destinationImage++) = 0;
		}
	}
*/
  myfile.close();
 
	return 0;
}