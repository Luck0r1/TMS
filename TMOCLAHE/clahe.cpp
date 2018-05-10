#include "clahe.h"

cv::Mat histogramEqualization(cv::Mat matrix, int height, int width,  int gridRegions, double cl) {
	double histogram[256] = {0};
	double newhistogram[256] = {0};
	double cmphistogram[256] = {0};

	cv::Mat newImage;
	newImage = cv::Mat::zeros(height, width, CV_32F);	

	/*
		Getting scale, + subValue
	*/
	double maxValue1 = 0;
	double minValue1 = 1E90;

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			if (matrix.at<float>(j, i) < minValue1) {
				minValue1 = matrix.at<float>(j, i);
			}

			if (matrix.at<float>(j, i) > maxValue1) {
				maxValue1 = matrix.at<float>(j, i);
			}
		}
	}
	double subValue1 = (maxValue1 - minValue1) / 256.0;
	// std::cout << maxValue1 << "\t" << minValue1 << std::endl;
	/*
		Computing regions
	*/
	
	int widthNumberRegions = width / gridRegions;

	if (width % gridRegions != 0) {
		widthNumberRegions += 1;
	}
	int heightNumberRegions = height / gridRegions;
	if (height % gridRegions != 0) {
		heightNumberRegions += 1;
	}
	int counter;
	/*std::cout << widthNumberRegions << "\t" << width << std::endl;
	std::cout << heightNumberRegions << "\t" << height << std::endl;*/
	cv::Mat regionHistograms = cv::Mat::zeros(256, widthNumberRegions*heightNumberRegions, CV_32F);
	for (int j = 0; j < heightNumberRegions; j++) {	
		for (int i = 0; i < widthNumberRegions; i++) {
			/*
				Also with corners and edges
			*/
			int widthRegion = gridRegions;
			int heightRegion = gridRegions;

			if (i == widthNumberRegions - 1 && j == heightNumberRegions - 1) {
				if (height % gridRegions != 0) {
					heightRegion = height % gridRegions;
				}

				if (width % gridRegions != 0) {
					widthRegion = width % gridRegions;
				}
			} else if (i == widthNumberRegions - 1) {
				if (width % gridRegions != 0) {
					widthRegion = width % gridRegions;
				}
			}  else if (j == heightNumberRegions - 1) {
				if (height % gridRegions != 0) {
					heightRegion = height % gridRegions;
				}
			}
			// std::cout << j << "\t" << i << std::endl;
			int regionHistogram[256] = {0};
			double regionNewHistogram[256] = {0};
			double regionCmphistogram[256] = {0};
		
			/*
				Computing with boundaries
			*/
			/*
				Getting histogram
			*/

			int counter = 0;
			for (int jjjj = 0; jjjj < heightRegion; jjjj++) {
				for (int iiii = 0; iiii < widthRegion; iiii++)  {
					if (matrix.at<float>((j * gridRegions) + jjjj, (i * gridRegions) + iiii) == maxValue1) {
						regionHistogram[255]++;
					} else {	
						regionHistogram[(int)floor(matrix.at<float>((j * gridRegions) + jjjj, (i * gridRegions) + iiii) / subValue1)]++;
					}					
				}
			}
			/*
				Clipping histogram
			*/

			double regionClippedHistogram[256] = {0};
			double averageValue = 0;
			if (cl > 0) {
				/*
					Getting average value of counts of histogram bins
				*/
				for (int i = 0; i < 256; i++) {
					averageValue += regionHistogram[i];
				}
				averageValue = averageValue/256;

				int maxBinValueCL = (floor)(averageValue*cl);

				/*
					Getting number of bins to layout uniformly
				*/
				int toLayoutBins = 0;
				for (int i = 0; i < 256; i++) {
					if (regionHistogram[i] > maxBinValueCL) {
						toLayoutBins += regionHistogram[i] - maxBinValueCL;
						regionClippedHistogram[i] = maxBinValueCL;					
					}					
				}

				/*
					Uniformly coresponding bins
				*/
				int toLayoutForBin = toLayoutBins / 256;
				int residual = toLayoutBins - toLayoutForBin * 256;
				for (int i = 0; i < 256; i++) {
					regionClippedHistogram[i] += toLayoutForBin;
				}

				for (int i = 0; i < residual; i++) {
					regionClippedHistogram[i]++;
				}
			} else {
				for (int i = 0; i < 256; i++) {
					regionClippedHistogram[i] = regionHistogram[i];
				}
			}

			int c1 = 0;
			int c2 = 0;

			if (i == 0 && j==0) {
				for (int a = 0; a < 256; a++) {
					c1 += regionHistogram[a];
					c2 += regionClippedHistogram[a];
				}
				std::cout << c1 << "\t" << c2 << std::endl;
			}
			/*
				Cumulate propability
			*/
			for (int a = 0; a < 256; a++) {
				if (a == 0) {
					regionCmphistogram[a] = regionClippedHistogram[a]/(heightRegion*widthRegion);
				} else {
					regionCmphistogram[a] = regionCmphistogram[a - 1] + regionClippedHistogram[a]/(heightRegion*widthRegion);
				}
			}
			/*
				Creating new histogram
			*/
			for (int a = 0; a < 256; a++) {
				// regionNewHistogram[a] = regionCmphistogram[a]*((maxValue1 - minValue1) + minValue1);
				regionHistograms.at<float>(a, j * widthNumberRegions + i) = regionCmphistogram[a]*((maxValue1 - minValue1) + minValue1);
				
			}
			// regionNewHistograms.push_back(regionNewHistogram);
			/*
				Save to image
			*/
			for (int b = 0; b < heightRegion; b++) {
				for (int a = 0; a < widthRegion; a++)  {
					if (matrix.at<float>((j * gridRegions) + b, (i * gridRegions) + a) == maxValue1) {
						newImage.at<float>((j * gridRegions) + b, (i * gridRegions) + a) = regionHistograms.at<float>(255, j * widthNumberRegions + i);
					}else {
						newImage.at<float>((j * gridRegions) + b, (i * gridRegions) + a) = regionHistograms.at<float>((int)floor(matrix.at<float>((j * gridRegions) + b, (i * gridRegions) + a) / subValue1), j * widthNumberRegions + i);
					}
				}
			}		
		}
	}

	/*
		Bilinear interpolation
	*/
	int startI = gridRegions/2;
	int startJ = gridRegions/2;
	int endI = width - (width % gridRegions)/2;
	if (width % gridRegions == 0) {
		endI = width - gridRegions/2;
	}
	
	int endJ = height - (height % gridRegions)/2; 
	if (height % gridRegions == 0) {
		endJ = height - gridRegions/2;
	}
	for (int j = startJ + 1; j < endJ; j++) {
		for (int i = startI + 1; i < endI; i++) {
			double coordinatesXLess = ((i - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesXGreater = coordinatesXLess + gridRegions;
			if (coordinatesXGreater >= width) {
				coordinatesXGreater = coordinatesXLess + (width - coordinatesXLess) / 2;
			}
			double coordinatesYLess = ((j - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesYGreater = coordinatesYLess + gridRegions;
			if (coordinatesYGreater >= height) {
				coordinatesYGreater = coordinatesYLess + (height - coordinatesYLess) / 2;
			}
		

			int actualIRegion = coordinatesXLess / (gridRegions);
			int actualJRegion = coordinatesYLess / (gridRegions);
			double sizeX = i - coordinatesXLess;
			double sizeXMinusOne = (coordinatesXGreater - coordinatesXLess) - sizeX;
			double sizeY = j - coordinatesYLess;
			double sizeYMinusOne = (coordinatesYGreater - coordinatesYLess) - sizeY;
			sizeX = sizeX / (coordinatesXGreater - coordinatesXLess);
			sizeXMinusOne = sizeXMinusOne / (coordinatesXGreater - coordinatesXLess);
			sizeY = sizeY / (coordinatesYGreater - coordinatesYLess);
			sizeYMinusOne = sizeYMinusOne / (coordinatesYGreater - coordinatesYLess);

			double tmp1 = 0;
			double tmp2 = 0;
			double tmp3 = 0;
			double tmp4 = 0;
			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp1 = regionHistograms.at<float>(255, widthNumberRegions*actualJRegion + actualIRegion);
			} else {
				tmp1 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*actualJRegion + actualIRegion);
			}

			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp2 = regionHistograms.at<float>(255, widthNumberRegions*actualJRegion + actualIRegion + 1);
			} else {
				tmp2 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*actualJRegion + actualIRegion + 1);
			}

			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp3 = regionHistograms.at<float>(255, widthNumberRegions*(actualJRegion + 1) + actualIRegion);
			} else {
				tmp3 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*(actualJRegion + 1) + actualIRegion);
			}
			
			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp4 = regionHistograms.at<float>(255, widthNumberRegions*(actualJRegion + 1) + actualIRegion + 1);
			} else {
				tmp4 =regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*(actualJRegion + 1) + actualIRegion + 1);
			}
			double dump1 = sizeYMinusOne * (sizeXMinusOne * tmp1 + sizeX * tmp2);
			double dump2 = sizeY * (sizeXMinusOne * tmp3 + sizeX * tmp4);
		
			newImage.at<float>(j, i) = abs(dump1 + dump2);
		}
	}

	/*
		Linear interpolation top-edge
	*/

	for (int j = 0; j <= startJ; j++) {
		for (int i = startI; i <= endI; i++) {
			double coordinatesXLess = ((i - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesXGreater = coordinatesXLess + gridRegions;
			if (coordinatesXGreater >= width) {
				coordinatesXGreater = coordinatesXLess + (width - coordinatesXLess) / 2;
			}

			double coordinatesYLess = ((j - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesYGreater = coordinatesYLess + gridRegions;
			if (coordinatesYGreater >= height) {
				coordinatesYGreater = coordinatesYLess + (height - coordinatesYLess) / 2;
			}
			double sizeX = i - coordinatesXLess;
			double sizeXMinusOne = (coordinatesXGreater - coordinatesXLess) - sizeX;
			sizeX = sizeX / (coordinatesXGreater - coordinatesXLess);
			sizeXMinusOne = sizeXMinusOne / (coordinatesXGreater - coordinatesXLess);
			int actualIRegion = coordinatesXLess / (gridRegions);
			double sizeY = j - coordinatesYLess;
			double sizeYMinusOne = (coordinatesYGreater - coordinatesYLess) - sizeY;
			int actualJRegion = coordinatesYLess / (gridRegions);

			double tmp1 = 0;
			double tmp2 = 0;
			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp1 = regionHistograms.at<float>(255, widthNumberRegions*actualJRegion + actualIRegion);
			} else {
				tmp1 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*actualJRegion + actualIRegion);
			}

			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp2 = regionHistograms.at<float>(255, widthNumberRegions*actualJRegion + actualIRegion + 1);
			} else {
				tmp2 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*actualJRegion + actualIRegion + 1);
			}
			newImage.at<float>(j, i) = abs(sizeXMinusOne * tmp1 + sizeX * tmp2);
		}
	}

	/*
		Linear interpolation bottom-edge
	*/
	for (int j = endJ; j < height; j++) {
		for (int i = startI; i <= endI; i++) {
			double coordinatesXLess = ((i - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesXGreater = coordinatesXLess + gridRegions;
			if (coordinatesXGreater >= width) {
				coordinatesXGreater = coordinatesXLess + (width - coordinatesXLess) / 2;
			}

			double coordinatesYLess = ((j - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesYGreater = coordinatesYLess + gridRegions;
			if (coordinatesYGreater >= height) {
				coordinatesYGreater = coordinatesYLess + (height - coordinatesYLess) / 2;
			}
			double sizeX = i - coordinatesXLess;
			double sizeXMinusOne = (coordinatesXGreater - coordinatesXLess) - sizeX;
			sizeX = sizeX / (coordinatesXGreater - coordinatesXLess);
			sizeXMinusOne = sizeXMinusOne / (coordinatesXGreater - coordinatesXLess);
			int actualIRegion = coordinatesXLess / (gridRegions);
			double sizeY = j - coordinatesYLess;
			double sizeYMinusOne = (coordinatesYGreater - coordinatesYLess) - sizeY;
			int actualJRegion = coordinatesYLess / (gridRegions);

			double tmp1 = 0;
			double tmp2 = 0;
			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp1 = regionHistograms.at<float>(255, widthNumberRegions*actualJRegion + actualIRegion);
			} else {
				tmp1 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*actualJRegion+ actualIRegion);
			}

			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp2 = regionHistograms.at<float>(255, widthNumberRegions*actualJRegion + actualIRegion + 1);
			} else {
				tmp2 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*actualJRegion + actualIRegion + 1);
			}
			newImage.at<float>(j, i) = abs(sizeXMinusOne * tmp1 + sizeX * tmp2);
		}
	}
/*
		Linear interpolation left-edge
	*/
	for (int j = startJ; j <= endJ; j++) {
		for (int i = 0; i <= startI; i++) {
			double coordinatesXLess = ((i - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesXGreater = coordinatesXLess + gridRegions;
			if (coordinatesXGreater >= width) {
				coordinatesXGreater = coordinatesXLess + (width - coordinatesXLess) / 2;
			}

			double coordinatesYLess = ((j - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesYGreater = coordinatesYLess + gridRegions;
			if (coordinatesYGreater >= height) {
				coordinatesYGreater = coordinatesYLess + (height - coordinatesYLess) / 2;
			}
			double sizeX = i - coordinatesXLess;
			double sizeXMinusOne = (coordinatesXGreater - coordinatesXLess) - sizeX;
			sizeX = sizeX / (coordinatesXGreater - coordinatesXLess);
			sizeXMinusOne = sizeXMinusOne / (coordinatesXGreater - coordinatesXLess);
			int actualIRegion = coordinatesXLess / (gridRegions);
			double sizeY = j - coordinatesYLess;
			double sizeYMinusOne = (coordinatesYGreater - coordinatesYLess) - sizeY;
			sizeY = sizeY / (coordinatesYGreater - coordinatesYLess);
			sizeYMinusOne = sizeYMinusOne / (coordinatesYGreater - coordinatesYLess);
			int actualJRegion = coordinatesYLess / (gridRegions);

			double tmp1 = 0;
			double tmp2 = 0;
			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp1 = regionHistograms.at<float>(255, widthNumberRegions*actualJRegion + actualIRegion);
			} else {
				tmp1 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*actualJRegion + actualIRegion);
			}
			
			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp2 = regionHistograms.at<float>(255, widthNumberRegions*(actualJRegion + 1) + actualIRegion);
			} else {
				tmp2 =regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*(actualJRegion + 1) + actualIRegion);
			}
			newImage.at<float>(j, i) = abs(sizeYMinusOne * tmp1 + sizeY * tmp2);
		}
	}

	/*
		Linear interpolation right-edge
	*/
	for (int j = startJ; j <= endJ; j++) {
		for (int i = endI; i < width; i++) {
			double coordinatesXLess = ((i - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesXGreater = coordinatesXLess + gridRegions;
			if (coordinatesXGreater >= width) {
				coordinatesXGreater = coordinatesXLess + (width - coordinatesXLess) / 2;
			}

			double coordinatesYLess = ((j - gridRegions/2)/gridRegions) * gridRegions + gridRegions/2;
			double coordinatesYGreater = coordinatesYLess + gridRegions;
			if (coordinatesYGreater >= height) {
				coordinatesYGreater = coordinatesYLess + (height - coordinatesYLess) / 2;
			}
			double sizeX = i - coordinatesXLess;
			double sizeXMinusOne = (coordinatesXGreater - coordinatesXLess) - sizeX;
			sizeX = sizeX / (coordinatesXGreater - coordinatesXLess);
			sizeXMinusOne = sizeXMinusOne / (coordinatesXGreater - coordinatesXLess);
			int actualIRegion = coordinatesXLess / (gridRegions);
			double sizeY = j - coordinatesYLess;
			double sizeYMinusOne = (coordinatesYGreater - coordinatesYLess) - sizeY;
			sizeY = sizeY / (coordinatesYGreater - coordinatesYLess);
			sizeYMinusOne = sizeYMinusOne / (coordinatesYGreater - coordinatesYLess);
			int actualJRegion = coordinatesYLess / (gridRegions);

			/* std::cout << actualJRegion << "\t" << heightNumberRegions << std::endl;
			std::cout << actualIRegion << "\t" << widthNumberRegions << std::endl;
			std::cout << "--------------------------" << std::endl;*/
			double tmp1 = 0;
			double tmp2 = 0;
			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp1 = regionHistograms.at<float>(255, widthNumberRegions*(actualJRegion + 1) + actualIRegion);
			} else {
				tmp1 = regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*actualJRegion + actualIRegion);
			}
			
			if ((int)floor(matrix.at<float>(j, i) / subValue1) > 255) {
				tmp2 = regionHistograms.at<float>(255, widthNumberRegions*(actualJRegion + 1) + actualIRegion);
			} else {
				tmp2 =regionHistograms.at<float>((int)floor(matrix.at<float>(j, i) / subValue1), widthNumberRegions*(actualJRegion + 1) + actualIRegion);
			}
			newImage.at<float>(j, i) = abs(sizeYMinusOne * tmp1 + sizeY * tmp2);
		}
	}
	// std::cout << newImage << std::endl;
	matrix.release();
    return newImage;
}