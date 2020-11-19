#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		std::cout<<"usage: /hist <image_path>\n";
		return -1;
	}

	cv::Mat src;
	src = cv::imread (argv[1], cv::IMREAD_COLOR);

	if(!src.data)
	{
		std::cout<< "No image data...\n";
		return -1;
	}
	//split separa imagen en 3 canales (B G R)
	std::vector<cv::Mat> bgr_planes;
	split(src, bgr_planes);

	// número de conglomerados (bins)
	int histSize = 256;

	//Rangos de B, G, R
	float rango[] = {0, 255};
	const float* histRange = {rango};

	//constantes del histograma
	bool uniform = true;
	bool accumulate = true;

	//Calcular histograma, con tres matrices
	cv::Mat b_hist, g_hist, r_hist;
	calcHist(&bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	int hist_h=400, hist_w = 512;
	int bin_w = cvRound( (double)hist_w/histSize );

	cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar(0,0,0) );

	//normalizar
	normalize( b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
	normalize( g_hist, g_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
	normalize( r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );

	for(int idx=1; idx < histSize; idx++)
	{
		cv::line(histImage, cv::Point( bin_w*(idx-1), cvRound( b_hist.at<float>(idx -1)  ) ),
			cv::Point( bin_w*(idx), cvRound( b_hist.at<float>(idx)  ) ),
			cv::Scalar(255, 0, 0), 2, 8, 0);

		cv::line(histImage, cv::Point( bin_w*(idx-1), cvRound( g_hist.at<float>(idx -1)  ) ),
			cv::Point( bin_w*(idx), cvRound( g_hist.at<float>(idx)  ) ),
			cv::Scalar(0, 255, 0), 2, 8, 0);

		cv::line(histImage, cv::Point( bin_w*(idx-1), cvRound( r_hist.at<float>(idx -1)  ) ),
			cv::Point( bin_w*(idx), cvRound( r_hist.at<float>(idx)  ) ),
			cv::Scalar(0, 0, 255), 2, 8, 0);
	}

	cv::Mat gray;
	cvtColor  (src, gray, cv::COLOR_BGR2GRAY);
	cv::Mat dst;
	equalizeHist(gray, dst);

	imshow("Source", src);
	imshow("Histograma", histImage);

	imshow("Gris", gray);
	imshow("Equalizar", dst);

	cv::waitKey(0);

	return 0;
}