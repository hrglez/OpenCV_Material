#include "segmentRGB.hpp"
#include "opencv2/highgui.hpp" //GUI
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

int segment (void);

int segment (void)
{
	//Camera constants
	const int camera_id = 0;
	const int width = 640; //Resolución VGA
	const int height = 480;
	const int fps_camera = 15;

	//GUI constants
	const char* window_name = "R, G & B Segmentation";
	const char* window_original = "Original";

	//HSV values
	int lowS=100, highS=255, lowV=30, highV=255;
	int lowH_R=130, highH_R=180;
	int lowH_G=50, highH_G=120;
	int lowH_B=90, highH_B=130;

	cv::VideoCapture input_video;
	cv::Mat frame_original, frame_proc;
	cv::Mat imgHSV;
	cv::Mat maskBGR[3], mask;

	input_video.open(camera_id);	//Abrir cámara
	input_video.set(cv::CAP_PROP_FRAME_WIDTH, width);
	input_video.set(cv::CAP_PROP_FRAME_HEIGHT, height);
	input_video.set(cv::CAP_PROP_FPS, fps_camera);

	if( !input_video.isOpened() )
	{
		printf("Could not open the camera %i, check that is plugged", camera_id);
		return (-1);
	}

	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

	/*cv::createTrackbar("LowH", window_name, &lowH_G, 180);
	cv::createTrackbar("HighH", window_name, &highH_G, 180);

	cv::createTrackbar("LowS", window_name, &lowS, 255);
	cv::createTrackbar("HighS", window_name, &highS, 255);

	cv::createTrackbar("LowV", window_name, &lowV, 255);
	cv::createTrackbar("HighV", window_name, &highV, 255);*/

	//cv::Mat sample = imread("rainbow.jpg",cv::IMREAD_COLOR);

	while(1)
	{
		input_video.read(frame_original);
		//frame_original=sample;
		cvtColor(frame_original, imgHSV, cv::COLOR_BGR2HSV);
		inRange(imgHSV, cv::Scalar(lowH_B, lowS, lowV), cv::Scalar(highH_B, highS, highV), maskBGR[0]);
		inRange(imgHSV, cv::Scalar(lowH_G, lowS, lowV), cv::Scalar(highH_G, highS, highV), maskBGR[1]);
		inRange(imgHSV, cv::Scalar(lowH_R, lowS, lowV), cv::Scalar(highH_R, highS, highV), maskBGR[2]);
		cv::merge(maskBGR,3,mask);
		erode(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		dilate(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		erode(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		dilate(mask, mask, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		//frame_proc=mask;
		cv::bitwise_and(frame_original,mask, frame_proc, cv::noArray());
		//frame_original.copyTo(frame_proc,mask);
		imshow( window_name, frame_proc );
		imshow( window_original, frame_original);
		if(cv::waitKey(30) >= 0) break;
	}

	input_video.release();
	return 0;
}