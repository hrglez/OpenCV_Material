#include "opencv2/highgui.hpp" //GUI
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

//Camera constants
const int camera_id = 0;
const int width = 640; //Resolución VGA
const int height = 480;
const int fps_camera = 15;

//GUI constants
const char* window_name = "Image Pipeline";
const char* filter_type_name = "FILTER TYPE\n 0: Default\n 1: Threshold\n 2: Logarithm\n 3: Smoothing\n4:Kernel\n 5: Laplacian\n 6: Erode";
const char* trackbar_type = "Threshold type\n 0: Binary\n 1: Binary Inverted\n 2: Truncate\n 3: To Zero\n4:Kernel By Hand";
const char* trackbar_value = "Threshold value";
const char* trackbar_type_smo = "Smoothign type:\n 0: Homogeneous\n 1:Gaussian\n 2:Median\n 3:Bilateral";
const char* trackbar_value_smo = "Kernel size";


const int max_filter = 6;
const int max_type = 4;
const int max_value = 255;
const int max_smo = 3;
const int max_kernel_sz = 30;

//laplacian const
const int lap_kernel_size = 3;
const int scale = 1;
const int delta = 0;
const int la_depth = CV_16S;

int smoothing(cv::Mat &src, cv::Mat dst, int type, int kernel);

int main(int argc, char** argv)
{
	cv::VideoCapture input_video;  //Abrir cámara
	cv::Mat frame_input;
	cv::Mat frame_proc;
	int filter_type = 6;
	int threshold_type = 0;
	int threshold_value = 100;
	int smo_type = 0;
	int kernel_sz = 3;

	//for color segmentation
	int iLowH = 0;
	int iHighH = 179;

	int iLowS = 0;
	int iHighS = 255;

	int iLowV = 0;
	int iHighV = 255;


	input_video.open(camera_id);

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
	/*
	cv::createTrackbar(filter_type_name, window_name, &filter_type, max_filter);
	cv::createTrackbar(trackbar_type, window_name, &threshold_type, max_type);
	cv::createTrackbar(trackbar_value, window_name, &threshold_value, max_value);
	cv::createTrackbar(trackbar_type_smo, window_name, &smo_type, max_smo);
	cv::createTrackbar(trackbar_value_smo, window_name, &kernel_sz, max_kernel_sz);*/
	
	cv::createTrackbar("LowH", window_name, &iLowH, 179);
	cv::createTrackbar("HighH", window_name, &iHighH, 179);

	cv::createTrackbar("LowS", window_name, &iLowS, 255);
	cv::createTrackbar("HighS", window_name, &iHighS, 255);

	cv::createTrackbar("LowV", window_name, &iLowV, 255);
	cv::createTrackbar("HighV", window_name, &iHighV, 255);


	
	while(1)
	{
		input_video.read(frame_input);
		if(filter_type==0)
		{
			frame_proc=frame_input;
		}
		else if(filter_type==1)
		{
			cv::cvtColor(frame_input, frame_proc, cv::COLOR_RGB2GRAY);
			threshold(frame_proc, frame_proc, threshold_value, max_value, threshold_type);
		}
		else if(filter_type==2)
		{
			frame_input.convertTo(frame_input, CV_64F);
			frame_proc = frame_proc + 1;
			cv::log(frame_proc, frame_proc);
			cv::convertScaleAbs(frame_proc, frame_proc);
			cv::normalize(frame_proc, frame_proc, 0, 255, cv::NORM_MINMAX);
		}
		else if(filter_type==3)
		{
			smoothing(frame_input, frame_proc, smo_type, kernel_sz+1);
		}
		else if(filter_type==4)
		{
			cv::Mat kern=(cv::Mat_<char>(3,3)<<0, -1, 0, -1, 80, -1, 0, -1, 0);
			filter2D(frame_input, frame_proc, frame_input.depth(), kern);
		}
		else if(filter_type==5)
		{
			cv::Mat dst;
			//Remove noise by blurring with gaussian
			GaussianBlur(frame_input, dst, cv::Size(3,3),0 ,0, cv::BORDER_DEFAULT);
			//convert gray
			cvtColor(dst, dst, cv::COLOR_RGB2GRAY);
			//apply laplace
			Laplacian(dst, frame_proc, la_depth, lap_kernel_size, scale, delta, cv::BORDER_DEFAULT);
			cv::convertScaleAbs(frame_proc, frame_proc);
		}
		else if(filter_type==6)
		{
			cv::Mat imgHSV;
			cvtColor(frame_input, imgHSV, cv::COLOR_BGR2HSV);
			inRange(imgHSV, cv::Scalar(iLowH, iLowS, iLowV), cv::Scalar(iHighH, iHighS, iHighV), frame_proc);

			erode(frame_proc, frame_proc, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
			dilate(frame_proc, frame_proc, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
			erode(frame_proc, frame_proc, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
			dilate(frame_proc, frame_proc, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		}

		imshow( window_name, frame_proc );
		if(cv::waitKey(30) >= 0) break;
	}

	input_video.release();
	return 0;
}

int smoothing(cv::Mat &src, cv::Mat dst, int type, int kernel)
{
	if(kernel%2==0)
	{
		if(type==0)
		{
			blur(src, dst, cv::Size(kernel, kernel), cv::Point(-1,-1));
		}
		else if(type==1)
		{
			GaussianBlur(src, dst, cv::Size(kernel, kernel), kernel, 0, 0);
		}
		else if(type==2)
		{
			medianBlur(src, dst, kernel);
		}
		else if(type==3)
		{
			bilateralFilter(src, dst, kernel, kernel*2, kernel/2);
		}
	}
}