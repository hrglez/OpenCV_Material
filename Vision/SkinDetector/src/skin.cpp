#include "skin.hpp"
#include "opencv2/highgui.hpp" //GUI
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

int segment (void);
cv::Mat BrightContrast(cv::Mat input);

int beta=0; //brightness constant

int segment (void)
{
	//Camera constants
	const int camera_id = 0;
	const int width = 640; //Resolución VGA
	const int height = 480;
	const int fps_camera = 15;

	//GUI constants
	const char* window_name = "Skin Segmentation";
	const char* window_original = "Original";

	//HSV values
	int lowH=0, highH=13, lowS=50, highS=150, lowV=60, highV=255;

	cv::VideoCapture input_video;
	cv::Mat frame_original, frame_proc;
	cv::Mat imgHSV;
	cv::Mat mask[3], mask3C;

	input_video.open(camera_id);	//Abrir cámara
	input_video.set(cv::CAP_PROP_FRAME_WIDTH, width);
	input_video.set(cv::CAP_PROP_FRAME_HEIGHT, height);
	input_video.set(cv::CAP_PROP_FPS, fps_camera);

	if( !input_video.isOpened() )
	{
		printf("Could not open the camera %i, check that is plugged", camera_id);
		return (-1);
	}

	cv::namedWindow(window_name, cv::WINDOW_NORMAL);
	cv::namedWindow(window_original, cv::WINDOW_NORMAL);

	/*cv::createTrackbar("LowH", window_name, &lowH, 180);
	cv::createTrackbar("HighH", window_name, &highH, 180);

	cv::createTrackbar("LowS", window_name, &lowS, 255);
	cv::createTrackbar("HighS", window_name, &highS, 255);

	cv::createTrackbar("LowV", window_name, &lowV, 255);
	cv::createTrackbar("HighV", window_name, &highV, 255);*/

	cv::createTrackbar("Calibration", window_name, &beta, 100);

	int option=2;
	cv::createTrackbar("Option", window_name, &option, 2);

	//cv::Mat sample = imread("people.jpg",cv::IMREAD_COLOR);

	while(1)
	{
		if(option==0){
			input_video.read(frame_original);
		}
		else if(option==1){
			frame_original = imread("test_1.jpg",cv::IMREAD_COLOR);
		}
		else if(option==2){
			frame_original = imread("test_2.jpg",cv::IMREAD_COLOR);
		}

		//input_video.read(frame_original);
		//frame_original=sample;
		frame_original = BrightContrast(frame_original);
		
		cvtColor(frame_original, imgHSV, cv::COLOR_BGR2HSV);
		inRange(imgHSV, cv::Scalar(lowH, lowS, lowV), cv::Scalar(highH, highS, highV), mask[0]);
		//imshow("before blur", mask[0]);
		//blur( mask[0], mask[0], cv::Size(3,3) );
		//GaussianBlur(frame_original, frame_original, cv::Size(5,5),0 ,0, cv::BORDER_DEFAULT);
		//imshow("before morph", mask[0]);
		erode	(mask[0], mask[0], getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));		//opening
		dilate	(mask[0], mask[0], getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));	
		dilate	(mask[0], mask[0], getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));		//closing (2)
		erode	(mask[0], mask[0], getStructuringElement(cv::MORPH_RECT, cv::Size(3,3)));
		dilate	(mask[0], mask[0], getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		erode	(mask[0], mask[0], getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
		//imshow("after morph", mask[0]);
		//cv::waitKey(0);
		mask[1]=mask[0];
		mask[2]=mask[0];
		cv::merge(mask,3,mask3C);
		//frame_proc=mask;
		cv::bitwise_and(frame_original,mask3C, frame_proc, cv::noArray());
		//frame_original.copyTo(frame_proc,mask[0]);
		imshow( window_name, frame_proc );
		imshow( window_original, frame_original);
		if(cv::waitKey(30) >= 0) break;
	}

	input_video.release();
	return 0;
}

cv::Mat BrightContrast(cv::Mat input)
{
	cv::Mat output = cv::Mat::zeros(input.rows, input.cols, CV_8UC3);

	for( int y = 0; y < output.rows; y++ ){
		for( int x = 0; x < output.cols; x++ ){
			for( unsigned char c = 0; c < output.channels(); c++ ){
				output.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>(input.at<cv::Vec3b>(y,x)[c] + beta );
			}
		}
	}
	return output;   
}