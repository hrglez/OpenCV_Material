#include "placas.hpp"
#include "opencv2/highgui.hpp" //GUI
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

int segment (void);

int segment (void)
{
	/*//Camera constants
	const int camera_id = 0;
	const int width = 640; //Resolución VGA
	const int height = 480;
	const int fps_camera = 15;*/

	//GUI constants
	const char* window_name = "Plate Segmentation";
	//const char* window_original = "Original";

	//HSV values
	int lowH=0, highH=180, lowS=0, highS=255, lowV=0, highV=120;

	//cv::VideoCapture input_video;
	cv::Mat frame_proc;
	cv::Mat imgHSV;
	cv::Mat maskBGR[3], mask;

	int size = 1;
	int thr=0;
	//cv::Mat originales[size];
	cv::Mat originales;
	std::string direccion;

	/*input_video.open(camera_id);	//Abrir cámara
	input_video.set(cv::CAP_PROP_FRAME_WIDTH, width);
	input_video.set(cv::CAP_PROP_FRAME_HEIGHT, height);
	input_video.set(cv::CAP_PROP_FPS, fps_camera);

	if( !input_video.isOpened() )
	{
		printf("Could not open the camera %i, check that is plugged", camera_id);
		return (-1);
	}*/

	//cv::namedWindow(window_original, cv::WINDOW_NORMAL);

	/*for(unsigned char i=0; i < size; i++)
	{
		direccion = (std::string)"fotos/pic" + std::to_string((i+1)) + (std::string)".jpeg";
		originales[i] = imread (direccion, cv::IMREAD_COLOR);
	}*/

	/*for(unsigned char i=0; i < size; i++)
	{
		cv::resize(originales[i], originales[i], cv::Size(), 0.1, 0.1);
	}*/

	cv::namedWindow(window_name, cv::WINDOW_NORMAL);

	/*cv::createTrackbar("LowH", window_name, &lowH, 180);
	cv::createTrackbar("HighH", window_name, &highH, 180);

	cv::createTrackbar("LowS", window_name, &lowS, 255);
	cv::createTrackbar("HighS", window_name, &highS, 255);

	cv::createTrackbar("LowV", window_name, &lowV, 255);
	cv::createTrackbar("HighV", window_name, &highV, 255);*/

	cv::createTrackbar("Imagen", window_name, &size, 14);
	//cv::createTrackbar("Threshold", window_name, &thr,255);

	while(size<12)
	{
		originales = imread ((std::string)"fotos/ext" + std::to_string(size) + (std::string)".png", cv::IMREAD_GRAYSCALE);
		originales = originales(cv::Rect(originales.cols/3,originales.rows/3,originales.cols/3,originales.rows/3));
		//resize(originales, originales, cv::Size(), 0.5, 0.5);
		/*cvtColor(originales, imgHSV, cv::COLOR_BGR2HSV);
		inRange(imgHSV, cv::Scalar(lowH, lowS, lowV), cv::Scalar(highH, highS, highV), mask);
		erode(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		dilate(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		erode(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		dilate(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		//cv::bitwise_and(frame_original,mask, frame_proc, cv::noArray());*/
		
		cv::adaptiveThreshold(originales, mask, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, 41, 9);
		//cv::threshold(originales, mask, thr, 255, cv::THRESH_BINARY_INV);
		
		//imshow( window_name, mask );
		imwrite("train"+ std::to_string(size+14)+".jpeg",mask);
		size++;
		//if(cv::waitKey(30) >= 0) break;
	}

	//input_video.release();


	/*cvtColor(originales[0], imgHSV, cv::COLOR_BGR2HSV);
	inRange(imgHSV, cv::Scalar(lowH, lowS, lowV), cv::Scalar(highH, highS, highV), mask);
	erode(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
	dilate(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
	erode(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
	dilate(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
	imshow( window_name, mask );
	cv::waitKey(0);*/

	return 0;
}