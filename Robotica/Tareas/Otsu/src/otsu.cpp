#include "otsu.hpp"
#include <opencv2/opencv.hpp>
#include <cmath>

COtsu_binarization::COtsu_binarization (char** dir)
{
	raiz_ = imread(dir[1],cv::IMREAD_GRAYSCALE);
}

void COtsu_binarization::filtro (void)
{
	unsigned int maxVal = 255, histSz=256, threshold=0, maxSigma=0;
	double N = raiz_.cols * raiz_.rows;
	double hist[histSz];
	float histNorm[histSz];

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

	for (unsigned int idy=1;idy<=raiz_.rows;idy++)
	{
		for (unsigned int idx=1;idx<=raiz_.cols;idx++)
		{
			if ( raiz_.at<uchar>(idy,idx) >= threshold ) otsu.at<uchar>(idy,idx)=255;
			else otsu.at<uchar>(idy,idx)=0;
		}

	}

	otsu.copyTo(raiz_);
}

void COtsu_binarization::show (void)
{
	cv::namedWindow ("Otsu filter", cv::WINDOW_NORMAL);
	imshow ("Otsu filter", raiz_);
	cv::waitKey(0);
}

void COtsu_binarization::write (void)
{
	imwrite("Otsu.jpg", raiz_);
}