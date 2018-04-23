/* --------------------------------------------------------------------------- *
 * TMOAubry14.cpp: implementation of the TMOAubry14 class.   *
 * --------------------------------------------------------------------------- */

#include "TMOAubry14.h"

/* --------------------------------------------------------------------------- *
 * Constructor serves for describing a technique and input parameters          *
 * --------------------------------------------------------------------------- */
TMOAubry14::TMOAubry14()
{
	SetName(L"Aubry14");						// TODO - Insert operator name
	SetDescription(L"Tone mapping using fast local Laplacian filters");	// TODO - Insert description

	dParameter.SetName(L"ParameterName");				// TODO - Insert parameters names
	dParameter.SetDescription(L"ParameterDescription");	// TODO - Insert parameter descriptions
	dParameter.SetDefault(1);							// TODO - Add default values
	dParameter=1.;
	dParameter.SetRange(0.0,1.0);				// TODO - Add acceptable range if needed
	// this->Register(dParameter);
}

TMOAubry14::~TMOAubry14()
{
}

/* --------------------------------------------------------------------------- *
 * This overloaded function is an implementation of your tone mapping operator *
 * --------------------------------------------------------------------------- */
int TMOAubry14::Transform()
{
	// Source image is stored in local parameter pSrc
	// Destination image is in pDst

	// Initialy images are in RGB format, but you can
	// convert it into other format
	// pSrc->Convert(TMO_Yxy);								// This is format of Y as luminance
	// pDst->Convert(TMO_Yxy);								// x, y as color information

	double* pSourceData = pSrc->GetData();
	double* pDestinationData = pDst->GetData();

	int height = pSrc->GetHeight();
	int width  = pSrc->GetWidth();

	// TODO accept all sizes of image (not only 2^n or even)
	cv::Mat I_RGB(height, width, CV_64FC3);
	cv::Mat I_Gray(height, width, CV_64FC1);

	double R, G, B;

	// Convert to grayscale
	int j = 0;
	for (j = 0; j < height; j++)
	{
		pSrc->ProgressBar(j, height);	// providing progress bar
		for (int i = 0; i < width; i++)
		{
			// need to store rgb in mat to calculate colour ratio later
			I_RGB.at<cv::Vec3d>(j,i)[0] = R = *pSourceData++;
			I_RGB.at<cv::Vec3d>(j,i)[1] = G = *pSourceData++;
			I_RGB.at<cv::Vec3d>(j,i)[2] = B = *pSourceData++;
			// convert to grayscale
			I_Gray.at<double>(j,i) = (0.2989*R + 0.5870*G + 0.1140*B) / 255.0;
		}
	}

	// calculate ratio for converting to rgb at the end
	// I_rgb = imread(sprintf('images/%s.png',name));
	// I = rgb2gray(im2double(I_rgb));
	// I_ratio=double(I_rgb)./repmat(I,[1 1 3])./255;
	cv::Mat I_ratio, I_gray_3c;
	cv::Mat grayChannels[] = {I_Gray, I_Gray, I_Gray};
	cv::merge(grayChannels, 3, I_gray_3c);
	cv::divide(I_RGB, I_gray_3c, I_ratio, 1/255.0, -1);

	// The algorithm of Local Laplacian Filters follows
	// the method works on grayscale image
	cv::Mat I = I_Gray;

	// Build Gaussian pyramid
	// FIXME should be pyrLevels int?
	double pyrLevels = std::ceil(log(std::min(height, width))-log(2))+2;
	// 1.level is the image itself
	std::vector<cv::Mat> inGaussianPyr;
	inGaussianPyr.push_back(I);	// 1.level is the image itself
	cv::Mat GaussImg;
	for (size_t n = 1; n < pyrLevels; n++) {
		cv::pyrDown(inGaussianPyr[n-1], GaussImg);
		inGaussianPyr.push_back(GaussImg);
	}
	GaussImg.release();

	// Build Laplacian pyramid from Gaussian one
	// the last level is the same as last level of gaussian pyramid
	std::vector<cv::Mat> outLaplacePyr;
	outLaplacePyr.push_back(inGaussianPyr.back());
	cv::Mat smallerUpsampledGauss, LaplaceImg;
	for (size_t n = pyrLevels - 1; n > 0; n--) {
		cv::pyrUp(inGaussianPyr[n], smallerUpsampledGauss);
		cv::subtract(inGaussianPyr[n-1], smallerUpsampledGauss, LaplaceImg);
		outLaplacePyr.insert(outLaplacePyr.begin(), LaplaceImg);
	}
	LaplaceImg.release();  // necessary for later usage of LaplaceImg!

	// TODO make these parameters of the method
	double sigma = 0.1;
	double fact = 5;
	int N = 10;

	std::vector<double> discretisation = this->linspace(0, 1, N);
	double discretisationStep = discretisation[1];

	cv::Mat I_remap(I.size(), CV_64FC1);


	// main loop of the algorithm
	for (auto ref : discretisation) {
		// calculate I_remap
		for (j = 0; j < I_remap.rows; j++) {
			pSrc->ProgressBar(j, I_remap.rows);	// provide progress bar
			for (int i = 0; i < I_remap.cols; i++) {
				double pixI = I.at<double>(j,i);
				I_remap.at<double>(j,i) =
				fact*(pixI-ref)*exp(-(pixI-ref)*(pixI-ref)/(2.0*sigma*sigma));
			}
		}

		// Build temporary Laplacian pyramid
		std::vector<cv::Mat> tmpLaplacePyr;
		cv::Mat down, up;
		cv::Mat current = I_remap.clone();
		for (size_t n = 0; n < pyrLevels - 1; n++) {
			// apply low pass filter, and downsample
			cv::pyrDown(current, down);
			// in each level, store difference between image and upsampled low pass version
			cv::pyrUp(down, up);
			cv::subtract(current, up, LaplaceImg);
			tmpLaplacePyr.push_back(LaplaceImg);
			// continue with low pass image
			current = down;
		}
		// the coarest level contains the residual low pass image
		tmpLaplacePyr.push_back(current);

		down.release(); up.release(); current.release();
		LaplaceImg.release();

		// compute output Laplace pyramid
		for (size_t level = 0; level < pyrLevels - 1; level++) {
			for (j = 0; j < outLaplacePyr[level].rows; j++) {
				pSrc->ProgressBar(j, outLaplacePyr[level].rows);	// provide progress bar
				for (int i = 0; i < outLaplacePyr[level].cols; i++) {
					double pixInGaussPyr = inGaussianPyr[level].at<double>(j,i);
					double absDiff = abs(pixInGaussPyr - ref);
					if (absDiff < discretisationStep) {
						outLaplacePyr[level].at<double>(j,i) +=
						tmpLaplacePyr[level].at<double>(j,i)*
						(1-absDiff/discretisationStep);
					}
				}
			}
		}

	}// main loop of the algorithm

	// Reconstruct laplacian pyramid
	// start with low pass residual
	cv::Mat I_result_gray = outLaplacePyr.back();
	for (int lev = pyrLevels - 2; lev >= 0; --lev) {
		// upsample, and add to current level
		cv::pyrUp(I_result_gray, I_result_gray);
		I_result_gray += outLaplacePyr[lev];
	}

	// multiply result with ratio to get colours back
	// I_enhanced=llf(I,sigma,fact,N);
	// I_enhanced=repmat(I_enhanced,[1 1 3]).*I_ratio;
	cv::Mat resultChannels[] = {I_result_gray, I_result_gray, I_result_gray};
	cv::Mat I_result_gray_3c, I_result_RGB;
	cv::merge(resultChannels, 3, I_result_gray_3c);
	cv::multiply(I_result_gray_3c, I_ratio, I_result_RGB);

	// show grayscale result
	for (j = 0; j < height; j++)
	{
		pSrc->ProgressBar(j, height);	// You can provide progress bar
		for (int i = 0; i < width; i++)
		{
			// store results to the destination image
			*pDestinationData++ = I_result_RGB.at<cv::Vec3d>(j,i)[0] * 255;
			*pDestinationData++ = I_result_RGB.at<cv::Vec3d>(j,i)[1] * 255;
			*pDestinationData++ = I_result_RGB.at<cv::Vec3d>(j,i)[2] * 255;
		}
	}

	pSrc->ProgressBar(j, pSrc->GetHeight());
	return 0;
}

// author: Damith Suranga Jinasena
// https://dsj23.me/2013/02/13/matlab-linspace-function-written-in-c/
std::vector<double> TMOAubry14::linspace(double min, double max, int n)
{
    std::vector<double> result;
    // vector iterator
	// TODO remove this and use i instead
    int iterator = 0;

    for (int i = 0; i <= n-2; i++)
    {
        double temp = min + i*(max-min)/(std::floor((double)n) - 1);
        result.insert(result.begin() + iterator, temp);
        iterator += 1;
    }

    result.insert(result.begin() + iterator, max);
    return result;
}
