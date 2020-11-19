#include <opencv2/core.hpp> //class Mat
#include <opencv2/imgcodecs.hpp> //IMREAD_COLOR
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("usage must be: ./exeFile <name.extension>\n");
		return -1;
	}
	
	cv::Mat image;
	image = imread (argv[1], cv::IMREAD_COLOR);

	if (!image.data)
	{
		printf("No image data\n");
		return -1;
	}

	cv::Mat image_gray;
	cvtColor(image, image_gray, cv::COLOR_RGB2GRAY);
	imwrite("gray.jpg", image_gray);

	cv::namedWindow ("Display Image", cv::WINDOW_AUTOSIZE);
	imshow ("Display Image", image);
	cv::waitKey(0);

	return 0;
}