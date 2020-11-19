#include "edge.hpp"
#include "opencv2/highgui.hpp" //GUI
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"

int videoContrast (void);
cv::Mat BrightContrast(cv::Mat input);
int Comparison (void);
void Sobel_Edge (void);
void Canny_Edge (void);
unsigned char Otsu_Mask (void);
void ShowOriginal (void);

int alpha = 10; //Contrast constant
int beta = 0;	//Brightness vconstant
cv::Mat sample;

int videoContrast (void)
{
	//Camera constants
	const int camera_id = 0;
	const int width = 640; //Resolución VGA
	const int height = 480;
	const int fps_camera = 15;

	//GUI constants
	const char* window_name = "Video Contrast/Brightness";
	const char* trackbar_brightness = "Brightness Value";
	const char* trackbar_contrast = "Contrast Value * 10";

	const int max_alpha = 100;
	const int max_beta = 100;

	cv::VideoCapture input_video;  
	cv::Mat frame_input;
	cv::Mat frame_proc;

	input_video.open(camera_id);	//Abrir cámara
	input_video.set(cv::CAP_PROP_FRAME_WIDTH, width);
	input_video.set(cv::CAP_PROP_FRAME_HEIGHT, height);
	input_video.set(cv::CAP_PROP_FPS, fps_camera);

	if( !input_video.isOpened() )
	{
		printf("Could not open the camera %i, check that is plugged", camera_id);
		return (-1);
	}

	cv::namedWindow( window_name, cv::WINDOW_AUTOSIZE);

	//trackbars
	cv::createTrackbar(trackbar_contrast, window_name, &alpha, max_alpha);
	cv::createTrackbar(trackbar_brightness, window_name, &beta, max_beta);

	while(1)
	{
		input_video.read(frame_input);
		frame_proc = BrightContrast(frame_input);
		imshow( window_name, frame_proc );
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
				output.at<cv::Vec3b>(y,x)[c] = cv::saturate_cast<uchar>( (alpha/10)*input.at<cv::Vec3b>(y,x)[c] + beta );
			}
		}
	}
	return output;   
}

int Comparison (void)
{
	//Camera constants
	const int camera_id = 0;
	const int width = 640; //Resolución VGA
	const int height = 480;
	const int fps_camera = 15;

	cv::destroyAllWindows();

	cv::VideoCapture input_video;  

	input_video.open(camera_id);	//Abrir cámara
	input_video.set(cv::CAP_PROP_FRAME_WIDTH, width);
	input_video.set(cv::CAP_PROP_FRAME_HEIGHT, height);
	input_video.set(cv::CAP_PROP_FPS, fps_camera);

	if( !input_video.isOpened() )
	{
		printf("Could not open the camera %i, check that is plugged", camera_id);
		return -1;
	}

	input_video.read(sample);
	/*sample = imread("plant.jpeg",cv::IMREAD_GRAYSCALE);
	cv::resize(sample, sample, cv::Size(), 0.7, 0.7);*/

	if( !sample.data )
		{ return -1; }

	GaussianBlur( sample, sample, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT ); //filter

  /// Convert it to gray
	//cvtColor( sample, sample, cv::COLOR_RGB2GRAY);

	ShowOriginal();
	Sobel_Edge();
	Canny_Edge();
}

void Sobel_Edge (void)
{
	cv::Mat result;
	const char* window_name = "Sobel (simplified)";
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;

  /// Generate grad_x and grad_y
	cv::Mat grad_x, grad_y;

  /// Gradient X
  //Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
	Sobel( sample, grad_x, ddepth, 1, 0, 3, scale, delta, cv::BORDER_DEFAULT );
	convertScaleAbs( grad_x, grad_x );

  /// Gradient Y
  //Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
	Sobel( sample, grad_y, ddepth, 0, 1, 3, scale, delta, cv::BORDER_DEFAULT );
	convertScaleAbs( grad_y, grad_y );

  /// Total Gradient (approximate)
	addWeighted( grad_x, 0.5, grad_y, 0.5, 0, result);

	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
	imshow( window_name, result);

	cv::waitKey(100);
}

void Canny_Edge (void)
{
	cv::Mat mask_edges;
	//cv::Mat dst;

	//const char* trackbar_name = "Threshold";
	const char* window_name = "Canny";
	int edgeThresh = 1;
	unsigned char lowThreshold = Otsu_Mask();
	int kernel_size = 3;
	unsigned char histeresis = 5;

	//sample.copyTo(mask_edges);
	//dst.create( sample.size(), sample.type() );
	
	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
	//cv::createTrackbar(trackbar_name, window_name, &lowThreshold, max_lowThreshold);

	/// Canny detector
	Canny( sample, mask_edges, lowThreshold-histeresis, lowThreshold+histeresis, kernel_size );

	//dst = cv::Scalar::all(0);

	//Using Canny's output as a mask, we display our result
	//sample.copyTo( dst, mask_edges);
	imshow( window_name, mask_edges);
	cv::waitKey(100);

}

unsigned char Otsu_Mask (void)
{
	unsigned char maxVal = 255, umbralReal=0;
	double N = sample.cols * sample.rows;
	unsigned int histSz=256, maxSigma=0;
	unsigned int hist[256];
	float histNorm[256];
	int threshold_type = 0;
	unsigned char rango = 5;

	cv::Mat otsu = cv::Mat::zeros(sample.rows, sample.cols, CV_8UC1);

	for (unsigned int ite=0;ite<histSz;ite++)
	{
		hist[ite]=0;
	}

	for (unsigned int idy=1;idy<=sample.rows;idy++)
	{
		for (unsigned int idx=1;idx<=sample.cols;idx++)
		{
			hist[sample.at<uchar>(idy,idx)]++;
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
			umbralReal = umbral;
		}

	}

	threshold(sample, otsu, umbralReal, maxVal, threshold_type);

	//Canny( sample, otsu, umbralReal, umbralReal, 3 );

	cv::namedWindow ("Otsu mask", cv::WINDOW_AUTOSIZE);
	imshow ("Otsu mask", otsu);
	cv::waitKey(100);
	
	return(umbralReal);
}

void ShowOriginal (void)
{
	cv::namedWindow("Original", cv::WINDOW_AUTOSIZE);
	imshow( "Original", sample);
	cv::waitKey(100);
}