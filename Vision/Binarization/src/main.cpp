//El programa comenzó como prueba utilizando sólo imágenes. Al añadir video se desecharon los archivos binary.hpp y binary.cpp

//#include "binary.hpp"
#include <iostream>
#include <string>
#include "opencv2/highgui.hpp" //GUI
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

unsigned char otsuThreshold (cv::Mat imagen);
cv::Mat histogram (cv::Mat imagen);

int main(void)
{	
	std::string pic;
	unsigned char answ, keep='y', option;
	unsigned int thr;
	
	std::cout<<"Do you want to work with video or an image? v/i.\n";
	std::cin>> option;
	
	if(option=='i')
	{
		cv::Mat result;
		std::string window_name;

		std::cout<<"Please enter the image you want to work with.\n";
		std::cin>> pic;
		cv::Mat raiz = imread(pic, cv::IMREAD_GRAYSCALE);

		if(!raiz.data)
		{
			std::cout<< "\nNo image data...\n";
			return -1;
		}

		while(1)
		{
			if(keep=='y')
			{
				std::cout<<"What do you want to get?\n1.Histogram\n2.Otsu binarization\n3.Threshold binarization\n";
				std::cin>>answ;

				if(answ == '1')
				{
					result = histogram(raiz);
					window_name = "Histogram (grayscale)";
				}
				else if(answ == '2')
				{
					thr = otsuThreshold(raiz);
					cv::threshold(raiz,result,thr,255,cv::THRESH_BINARY);

					window_name = "Otsu filter";
				}
				else if(answ == '3')
				{
					std::cout<<"\nInsert the thershold value (0-255): ";
					std::cin>>thr;
					cv::threshold(raiz,result,thr,255,cv::THRESH_BINARY);

					window_name = "Threshold Binarization";
				}
				else std::cout<<"\nInvalid option\n";

				cv::namedWindow ("Original", cv::WINDOW_NORMAL);
				imshow ("Original", raiz);
				cv::namedWindow (window_name, cv::WINDOW_NORMAL);
				imshow (window_name, result);
				cv::waitKey(0);

				std::cout<<"\nDo you want to try another option? y/n: ";
				std::cin>>keep;	
			}

			else break;

		}
	}
	else if(option=='v')
	{
		//Camera constants
		const int camera_id = 0;
		const int width = 640; //Resolución VGA
		const int height = 480;
		const int fps_camera = 1;

		//GUI constants
		const char* window_name = "Video Processing Test";
		const char* filter_type_name = "FILTER TYPE\n 0: Default\n 1: Threshold Binarization\n 2: Otsu";
		const char* trackbar_value = "Threshold value";

		const int max_filter = 2;
		const int max_value = 255;

		cv::VideoCapture input_video;  
		cv::Mat frame_input;
		cv::Mat frame_proc;

		int filter_type = 0;
		int threshold_type = 0;
		int threshold_value = 100;

		input_video.open(camera_id);	//Abrir cámara
		input_video.set(cv::CAP_PROP_FRAME_WIDTH, width);
		input_video.set(cv::CAP_PROP_FRAME_HEIGHT, height);
		input_video.set(cv::CAP_PROP_FPS, fps_camera);

		if( !input_video.isOpened() )
		{
			printf("Could not open the camera %i, check that is plugged", camera_id);
			return (-1);
		}

		cv::namedWindow( window_name, cv::WINDOW_AUTOSIZE );

		//trackbars
		cv::createTrackbar(filter_type_name, window_name, &filter_type, max_filter);
		cv::createTrackbar(trackbar_value, window_name, &threshold_value, max_value);

		while(1)
		{
			input_video.read(frame_input);
			if(filter_type==0)
			{
				cv::cvtColor(frame_input, frame_proc, cv::COLOR_RGB2GRAY);
			}
			else if(filter_type==1)
			{
				cv::cvtColor(frame_input, frame_proc, cv::COLOR_RGB2GRAY);
				threshold(frame_proc, frame_proc, threshold_value, max_value, threshold_type);
			}
			else if(filter_type==2)
			{
				unsigned char lim;
				cv::cvtColor(frame_input, frame_proc, cv::COLOR_RGB2GRAY);
				lim = otsuThreshold(frame_proc);
				threshold(frame_proc, frame_proc, lim, max_value, threshold_type);
			}
			/*else if(filter_type==3)
			{
				frame_proc = histogram(frame_input);
			}*/
			

			imshow( window_name, frame_proc );
			if(cv::waitKey(30) >= 0) break;
		}

		input_video.release();
		return 0;

	}


	else std::cout<<"\nInvalid option\n";


	return 0;

}

unsigned char otsuThreshold (cv::Mat imagen)
{
	unsigned char maxVal = 255, threshold=0;
	double N = imagen.cols * imagen.rows;
	unsigned int histSz=256, maxSigma=0;
	unsigned int hist[256];
	float histNorm[256];

	cv::Mat otsu = cv::Mat::zeros(imagen.rows, imagen.cols, CV_8UC1);

	for (unsigned int ite=0;ite<histSz;ite++)
	{
		hist[ite]=0;
	}

	for (unsigned int idy=1;idy<=imagen.rows;idy++)
	{
		for (unsigned int idx=1;idx<=imagen.cols;idx++)
		{
			hist[imagen.at<uchar>(idy,idx)]++;
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
	
	return(threshold);

}

cv::Mat histogram (cv::Mat imagen)
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
	calcHist(&imagen, 1, 0, cv::Mat(), grayHist, 1, &histSize, &histRange, uniform, accumulate);

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
	
	return histImage;
}