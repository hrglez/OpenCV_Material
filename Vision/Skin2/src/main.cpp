#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace cv;
using namespace std;

Mat src; Mat bw;
int thresh = 100;
int max_thresh = 255;
RNG rng(12345);

/// Function header
void thresh_callback(int, void* );

/** @function main */
int main( void )
{
  /// Load source image and convert it to gray
  src = imread("people.jpg",IMREAD_COLOR);

  Mat hsv;
  cvtColor(src, hsv, COLOR_BGR2HSV);

  inRange(hsv, Scalar(0, 50, 60), Scalar(13, 150, 255), bw);

  /// Convert image to gray and blur it
  blur( bw, bw, Size(3,3) );

  /// Create Window
  char* source_window = "Source";
  namedWindow( source_window, WINDOW_AUTOSIZE );
  imshow( source_window, src );
  imshow( "mask", bw);
  createTrackbar( " Canny thresh:", "Source", &thresh, max_thresh, thresh_callback );
  thresh_callback( 0, 0 );

  waitKey(0);
  return(0);
}

/** @function thresh_callback */
void thresh_callback(int, void* )
{
  Mat canny_output;
  vector<vector<Point> > contours;
  vector<Vec4i> hierarchy;

  /// Detect edges using canny
  Canny( bw, canny_output, thresh, thresh*2, 3 );
  /// Find contours
  findContours( canny_output, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0) );

  /// Draw contours
  Mat drawing = Mat::zeros( canny_output.size(), CV_8UC3 );
  for( int i = 0; i< contours.size(); i++ )
  {
   Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
   drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, Point() );
 }

  /// Show in a window
 namedWindow( "Contours", WINDOW_AUTOSIZE );
 imshow( "Contours", drawing );
}