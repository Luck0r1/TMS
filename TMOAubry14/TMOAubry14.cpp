/*******************************************************************************
*                                                                              *
*                         Brno University of Technology                        *
*                       Faculty of Information Technology                      *
*                                                                              *
*             Fast Local Laplacian Filters: Theory and Applications (2014)     *
* by Mathieu Aubry, Sylvain Paris, Samuel W. Hasinoff, Jan Kautz, Fredo Durand *
*                         ACM Transactions on Graphics                         *
*                                                                              *
*             Author: Tomas Hudziec [xhudzi01 AT stud.fit.vutbr.cz]            *
*         Term project for Computational Photography course - 2018             *
*       Part of master thesis (HDR support, code reorganization) - 2019        *
*                                                                              *
*******************************************************************************/

// FIXME for HDR input tmocmd creates black pixels (big negative values)
// in very bright areas
// FIXME moreover, for image HancockKitchenInside_small.hdr postprocessing
// brought white pixels elsewhere
// however, in tmogui it works fine
// also, tmocmd with LDR image returns the same unchanged image as output

/* --------------------------------------------------------------------------- *
 * TMOAubry14.cpp: implementation of the TMOAubry14 class.   *
 * --------------------------------------------------------------------------- */
#include "TMOAubry14.h"

/* --------------------------------------------------------------------------- *
 * Constructor serves for describing a technique and input parameters          *
 * --------------------------------------------------------------------------- */
TMOAubry14::TMOAubry14()
{
	SetName(L"Aubry14");
	SetDescription(L"Tone mapping and detail manipulation using fast local Laplacian filters");

	sigmaParameter.SetName(L"sigma");
	sigmaParameter.SetDescription(L"ballance between local and global contrast");
	sigmaParameter.SetDefault(0.1);
	sigmaParameter.SetRange(0.01, 1.0);

	NParameter.SetName(L"N");
	NParameter.SetDescription(L"discretisation level");
	NParameter.SetDefault(10);
	NParameter.SetRange(2, 15);

	factParameter.SetName(L"factor");
	factParameter.SetDescription(L"multiply factor");
	factParameter.SetDefault(5);
	factParameter.SetRange(-10, 10);
	
	HDRParameter.SetName(L"HDR");
	HDRParameter.SetDescription(L"checkbox whether input image is HDR");
	HDRParameter.SetDefault(false);
	HDRParameter = false;	

	this->Register(HDRParameter);	
	this->Register(factParameter);
	this->Register(NParameter);
	this->Register(sigmaParameter);
}

TMOAubry14::~TMOAubry14()
{
}

// https://github.com/daikiyamanaka/L0-gradient-smoothing
void cvMat2Vec(const cv::Mat &mat, std::vector<double> &vec){
	int rows = mat.rows;
	int cols = mat.cols;
	vec.resize(rows*cols);

	for(int i=0; i<rows; i++){
		double *ptr = reinterpret_cast<double*>(mat.data+mat.step*i);
		for(int j=0; j<cols; j++){
			vec[i*cols+j] = *ptr;
			++ptr;
		}
	}
}

// https://en.wikipedia.org/wiki/Percentile#The_nearest-rank_method
// FIXME maybe better idea would be create histogram and compute percentile from it,
// rather than sorting all pixels from whole image
double prctileNearestRank(cv::Mat matrix, double percentile) {
	std::vector<double> vector;
	cvMat2Vec(matrix, vector);
	std::sort(vector.begin(), vector.end());
	double ordinalRank = percentile/100.0 * vector.size();
	return vector[std::ceil(ordinalRank)-1];
}

/* --------------------------------------------------------------------------- *
 * This overloaded function is an implementation of the tone mapping operator *
 * --------------------------------------------------------------------------- */
int TMOAubry14::Transform()
{
	// Source image is stored in local parameter pSrc
	// Destination image is in pDst

	pSrc->Convert(TMO_RGB);

	double* pSourceData = pSrc->GetData();
	double* pDestinationData = pDst->GetData();

	double sigma = sigmaParameter.GetDouble();
	double fact = factParameter.GetDouble();
	int N = NParameter.GetInt();

	double eps = 1e-10;

	int height = pSrc->GetHeight();
	int width  = pSrc->GetWidth();

	cv::Mat I_RGB(height, width, CV_64FC3);
	cv::Mat I_Gray(height, width, CV_64FC1);

	double R, G, B;

	// Convert to grayscale
	for (int j = 0; j < height; j++)
	{
		pSrc->ProgressBar(j, height);	// provide progress bar
		for (int i = 0; i < width; i++)
		{
			// need to store rgb in mat to calculate colour ratio later
			I_RGB.at<cv::Vec3d>(j,i)[0] = R = *pSourceData++;
			I_RGB.at<cv::Vec3d>(j,i)[1] = G = *pSourceData++;
			I_RGB.at<cv::Vec3d>(j,i)[2] = B = *pSourceData++;
			// convert to grayscale
			I_Gray.at<double>(j,i) = (0.2989*R + 0.5870*G + 0.1140*B);
		}
	}

	// make image of size of 2^n for pyramid functions
	int correctionWidth, correctionHeight;
	correctionWidth = std::ceil(log2(width));
	correctionHeight = std::ceil(log2(height));
	correctionHeight = std::pow(2, correctionHeight);
	correctionWidth = std::pow(2, correctionWidth);
	// resizing image to 2^n dimensions, borders are interpolated
	cv::copyMakeBorder(I_RGB, I_RGB,
		0, correctionHeight-height,
		0, correctionWidth-width,
		cv::BORDER_DEFAULT);
	cv::copyMakeBorder(I_Gray, I_Gray,
		0, correctionHeight-height,
		0, correctionWidth-width,
		cv::BORDER_DEFAULT);

	// method works with luminance part of image,
	// so calculate colour ratio to bring colours back at the end
	cv::Mat I_ratio, I_gray_3c;
	cv::Mat grayChannels[] = {I_Gray, I_Gray, I_Gray};
	cv::merge(grayChannels, 3, I_gray_3c);
	cv::divide(I_RGB, I_gray_3c + eps, I_ratio, 1, -1);

	// convert HDR image to logarithmic domain
	if (HDRParameter) {
		cv::log(I_Gray + eps, I_Gray);
	}

	cv::normalize(I_Gray, I_Gray, 0.0, 1.0, cv::NORM_MINMAX, I_Gray.type());

	// Fast Local Laplacian Filtering algorithm
	std::cout << "Fast Local Laplacian Filtering... " << std::flush;
	cv::Mat I_result_gray = FastLocalLaplFilt(I_Gray, sigma, fact, N, pSrc);
	std::cout << "done" << '\n';

	if (HDRParameter) {
		// get HDR image from logarithmic domain
		cv::exp(I_result_gray, I_result_gray);
		I_result_gray -= eps;

		// HDR postprocessing
		std::cout << "HDR postprocessing... " << std::flush;
		double DR_desired = 100;
		double prc_clip = 0.5;
		double Imax_clip = prctileNearestRank(I_result_gray, 100-prc_clip);
		double Imin_clip = prctileNearestRank(I_result_gray, prc_clip);
		double DR_clip = Imax_clip / Imin_clip;
		double exponent = log(DR_desired) / log(DR_clip);

		for (int j = 0; j < height; j++) {
			pSrc->ProgressBar(j, height);	// provide progress bar
			for (int i = 0; i < width; i++) {
				double division = I_result_gray.at<double>(j,i) / Imax_clip;
				I_result_gray.at<double>(j,i) = (division > 0)
												? pow(division, exponent)
												: 0;
			}
		}
		std::cout << "done" << '\n';
	}

	// shift image values to positive, not sure if neccesary
	cv::normalize(I_result_gray, I_result_gray, 0, 1, cv::NORM_MINMAX, I_result_gray.type());

	// multiply result with ratio to get colours back
	cv::Mat resultChannels[] = {I_result_gray, I_result_gray, I_result_gray};
	cv::Mat I_result_gray_3c, I_result_RGB;
	cv::merge(resultChannels, 3, I_result_gray_3c);
	cv::multiply(I_result_gray_3c + eps, I_ratio, I_result_RGB);

	// for tone mapping, gamma correct linear intensities for display
	if (HDRParameter) {
		cv::pow(I_result_RGB, 1/2.2, I_result_RGB);
	}

	// output in range <0,1>
	cv::normalize(I_result_RGB, I_result_RGB, 0.0, 1.0, cv::NORM_MINMAX, I_result_RGB.type());

	// output result
	for (int j = 0; j < height; j++)
	{
		pSrc->ProgressBar(j, height);	// provide progress bar
		for (int i = 0; i < width; i++)
		{
			// put result to output, taking only the image itself, size correction is discarded
			*pDestinationData++ = I_result_RGB.at<cv::Vec3d>(j,i)[0];
			*pDestinationData++ = I_result_RGB.at<cv::Vec3d>(j,i)[1];
			*pDestinationData++ = I_result_RGB.at<cv::Vec3d>(j,i)[2];
		}
	}

	return 0;
}
