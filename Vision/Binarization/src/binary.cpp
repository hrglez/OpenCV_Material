#include "binary.hpp"
#include <opencv2/opencv.hpp>
#include <cmath>

CBinary::CBinary (std::string dir)
{
	raiz_ = imread(dir, cv::IMREAD_GRAYSCALE);
}

int CBinary::check (void)
{
	if(!raiz_.data)
	{
		std::cout<< "\nNo image data...\n";
		return -1;
	}
	else return 0;
}

void CBinary::hist (void)
{
	// número de conglomerados (bins)
	int histSize = 256;

	//Rango
	float rango[] = {0, 256};
	const float* histRange = {rango};

	//constantes del histograma
	bool uniform = true;
	bool accumulate = true;

	//Calcular histograma
	cv::Mat grayHist;
	calcHist(&raiz_, 1, 0, cv::Mat(), grayHist, 1, &histSize, &histRange, uniform, accumulate);

	int hist_h=600, hist_w = 768;
	int bin_w = cvRound( (double)hist_w/histSize );

	cv::Mat histImage( hist_h, hist_w, CV_8UC1, cv::Scalar(255) );

	//normalizar
	normalize( grayHist, grayHist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );

	for(int idx=1; idx < histSize; idx++)
	{
		cv::line(histImage, cv::Point( bin_w*(idx-1), cvRound( grayHist.at<float>(idx -1)  ) ),
			cv::Point( bin_w*(idx), cvRound( grayHist.at<float>(idx)  ) ),
			cv::Scalar(0), 2, 8, 0);
	}
	
	cv::namedWindow ("Histogram (grayscale)", cv::WINDOW_AUTOSIZE);
	imshow ("Histogram (grayscale)", histImage);
	cv::waitKey(0);
}

void CBinary::threshold (unsigned int umbral)
{
	if(umbral>255) std::cout<<"\nThreshold value out of range.";
	else{
		cv::Mat temp = cv::Mat::zeros(raiz_.rows, raiz_.cols, CV_8UC1);
		
		cv::threshold(raiz_,temp,umbral,255,cv::THRESH_BINARY);
		
		cv::namedWindow ("Threshold binarization", cv::WINDOW_NORMAL);
		imshow ("Threshold binarization", temp);
		cv::waitKey(0);
	}
}

void CBinary::otsu (void)
{
	unsigned char maxVal = 255, threshold=0;
	double N = raiz_.cols * raiz_.rows;
	unsigned int histSz=256, maxSigma=0;
	unsigned int hist[256];
	float histNorm[256];

	cv::Mat otsu = cv::Mat::zeros(raiz_.rows, raiz_.cols, CV_8UC1);

	for (unsigned int ite=0;ite<histSz;ite++)
	{
		hist[ite]=0;
	}

	for (unsigned int idy=1;idy<=raiz_.rows;idy++)
	{
		for (unsigned int idx=1;idx<=raiz_.cols;idx++)
		{
			hist[raiz_.at<uchar>(idy,idx)]++;
		}
	}

	for (unsigned int idx=0;idx<histSz;idx++)
	{
		histNorm[idx] = (hist[idx]/N);
	}

	for(unsigned int umbral=0;umbral<=maxVal;umbral++)
	{
		float qA=0, qB=0, uA=0, uB=0, sigmaA=0, sigmaB=0;
		double pruebaSigma;

		//Creacion de q1 y uA
		for(unsigned int idx=0; idx<=umbral; idx++)
		{
			qA += histNorm[idx];
			uA += (idx+1)*histNorm[idx];
		}
		//Creacion de q2 y uB
		for(unsigned int idx=(umbral+1); idx<=maxVal; idx++)
		{
			qB += histNorm[idx];
			uB += (idx+1)*histNorm[idx];
		}

		if(qA!=0) uA /= qA;
		if(qB!=0) uB /= qB;

		pruebaSigma = qA*qB*pow(uA-uB,2);

		if(pruebaSigma > maxSigma)
		{
			maxSigma = pruebaSigma;
			threshold = umbral;
		}

	}

	//std::cout<<"t: "<<threshold<<std::endl;

	cv::threshold(raiz_,otsu,threshold,255,cv::THRESH_BINARY);

	cv::namedWindow ("Otsu filter", cv::WINDOW_NORMAL);
	imshow ("Otsu filter", otsu);
	cv::waitKey(0);
}