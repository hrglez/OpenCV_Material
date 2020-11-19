#include <stdio.h>
#include <iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/xfeatures2d/nonfree.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "object.hpp"

int SURF_test (void);
int Match_test (void);
void match (int, void*);


/// Global Variables
cv::Mat img, templ, result;
const char* image_window = "Source Image";
const char* result_window = "Result window";

int match_method;
int max_Trackbar = 5;


int SURF_test( void )
{
    //Camera constants
    const int camera_id = 0;
    const int width = 640; //Resolución VGA
    const int height = 480;
    const int fps_camera = 15;

    //GUI constants
    const char* window_name = "SURF test";

    cv::VideoCapture input_video;

    int minHessian = 1000;
    cv::Ptr<cv::xfeatures2d::SURF> detector = cv::xfeatures2d::SURF::create(minHessian);
    cv::Ptr<cv::xfeatures2d::SURF> extractor = cv::xfeatures2d::SURF::create();
    cv::Mat descriptors_1, descriptors_2;
    cv::Mat img_matches;

    std::vector<cv::KeyPoint> keypoints_1, keypoints_2;
    std::vector< cv::DMatch > matches;
    cv::BFMatcher matcher(cv::NORM_L2);

    input_video.open(camera_id);    //Abrir cámara
    input_video.set(cv::CAP_PROP_FRAME_WIDTH, width);
    input_video.set(cv::CAP_PROP_FRAME_HEIGHT, height);
    input_video.set(cv::CAP_PROP_FPS, fps_camera);

    if( !input_video.isOpened() )
    {
        printf("Could not open the camera %i, check that is plugged", camera_id);
        return (-1);
    }

    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    cv::Mat img_1 = imread( "test.jpeg", cv::IMREAD_GRAYSCALE );
    cv::resize(img_1,img_1,cv::Size(),.5,.5);
    cv::Mat img_2;

    //-- Step 1: Detect the keypoints using SURF Detector
    detector->detect( img_1, keypoints_1 );
    //-- Step 2: Calculate descriptors (feature vectors)
    extractor->compute( img_1, keypoints_1, descriptors_1 );

    img_2 = imread("background.jpeg", cv::IMREAD_GRAYSCALE);
    cv::resize(img_2,img_2,cv::Size(),.5,.5);
    
    while(1)
    {
        /*input_video.read(img_2);
        cv::cvtColor(img_2,img_2,cv::COLOR_BGR2GRAY);*/
        detector->detect( img_2, keypoints_2 );
        extractor->compute( img_2, keypoints_2, descriptors_2 );

        //-- Step 3: Matching descriptor vectors with a brute force matcher
        matcher.match( descriptors_1, descriptors_2, matches );

        //-- Draw matches
        drawMatches( img_1, keypoints_1, img_2, keypoints_2, matches, img_matches );

        //-- Show detected matches
        cv::imshow(window_name, img_matches );

        if(cv::waitKey(30) >= 0) break;
    }

    return 0;
}

int Match_test (void)
{
  /// Load image and template
    img = imread( "fondo.jpeg", cv::IMREAD_GRAYSCALE );
    templ = imread( "test.jpeg", cv::IMREAD_GRAYSCALE );
    cv::resize(img,img,cv::Size(),.7,.7);
    cv::resize(templ,templ,cv::Size(),.3,.3);

  /// Create windows
    cv::namedWindow( image_window, cv::WINDOW_AUTOSIZE );
    cv::namedWindow( result_window, cv::WINDOW_AUTOSIZE );

  /// Create Trackbar
    const char* trackbar_label = "Method: \n 0: SQDIFF \n 1: SQDIFF NORMED \n 2: TM CCORR \n 3: TM CCORR NORMED \n 4: TM COEFF \n 5: TM COEFF NORMED";
    cv::createTrackbar( trackbar_label, image_window, &match_method, max_Trackbar, match) ;
    cv::waitKey(0);
    return 0;
}

void match (int, void*)
{
    cv::Mat img_display;
    img.copyTo( img_display );

  /// Create the result matrix
    int result_cols =  img.cols - templ.cols + 1;
    int result_rows = img.rows - templ.rows + 1;

    result.create( result_rows, result_cols, CV_32FC1 );

  /// Do the Matching and Normalize
    matchTemplate( img, templ, result, match_method );
    normalize( result, result, 0, 1, cv::NORM_MINMAX, -1, cv::Mat() );

  /// Localizing the best match with minMaxLoc
    double minVal; double maxVal; cv::Point minLoc; cv::Point maxLoc;
    cv::Point matchLoc;

    minMaxLoc( result, &minVal, &maxVal, &minLoc, &maxLoc, cv::Mat() );

  /// For SQDIFF and SQDIFF_NORMED, the best matches are lower values. For all the other methods, the higher the better
    if( match_method  == cv::TM_SQDIFF || match_method == cv::TM_SQDIFF_NORMED )
        { matchLoc = minLoc; }
    else
        { matchLoc = maxLoc; }

  /// Show me what you got
    rectangle( img_display, matchLoc, cv::Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), cv::Scalar(255), 2, 8, 0 );
    rectangle( result, matchLoc, cv::Point( matchLoc.x + templ.cols , matchLoc.y + templ.rows ), cv::Scalar(255), 2, 8, 0 );

    cv::imshow( image_window, img_display );
    cv::imshow( result_window, result );
}