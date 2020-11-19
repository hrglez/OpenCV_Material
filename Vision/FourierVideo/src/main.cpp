#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

cv::Mat magI;
cv::Mat frame_proc;

int Fourier (void);

int main(void)
{
    const char* window_video = "Video Input";
    const char* window_fourier = "Fourier Spectrum";

    //Camera constants
    const int camera_id = 0;
    const int width = 640; //Resolución VGA
    const int height = 480;
    const int fps_camera = 15;

    cv::VideoCapture input_video;  //Abrir cámara
    cv::Mat frame_input;

    input_video.open(camera_id);
    input_video.set(cv::CAP_PROP_FRAME_WIDTH, width);
    input_video.set(cv::CAP_PROP_FRAME_HEIGHT, height);
    input_video.set(cv::CAP_PROP_FPS, fps_camera);

    if( !input_video.isOpened() )
    {
        printf("Could not open the camera %i, check that is plugged", camera_id);
        return (-1);
    }

    cv::namedWindow( window_video, cv::WINDOW_AUTOSIZE );
    cv::namedWindow (window_fourier, cv::WINDOW_AUTOSIZE );

    while(1)
    {
        input_video.read(frame_input);
        cv::cvtColor(frame_input, frame_proc, cv::COLOR_RGB2GRAY);
        Fourier();

        imshow( window_video, frame_input );
        imshow( window_fourier, magI );
        if(cv::waitKey(30) >= 0) break;
    }

    input_video.release();
    return 0;
}

int Fourier (void)
{
    if( frame_proc.empty()) return -1;

    cv::Mat padded;                            //expand input image to optimal size
    int m = cv::getOptimalDFTSize( frame_proc.rows );
    int n = cv::getOptimalDFTSize( frame_proc.cols ); // on the border add zero values
    copyMakeBorder(frame_proc, padded, 0, m - frame_proc.rows, 0, n - frame_proc.cols, cv::BORDER_CONSTANT, cv::Scalar::all(0));

    cv::Mat planes[] = {cv::Mat_<float>(padded), cv::Mat::zeros(padded.size(), CV_32F)};
    cv::Mat complexI;
    merge(planes, 2, complexI);         // Add to the expanded another plane with zeros

    dft(complexI, complexI);            // this way the result may fit in the source matrix

    // compute the magnitude and switch to logarithmic scale
    // => log(1 + sqrt(Re(DFT(I))^2 + Im(DFT(I))^2))
    split(complexI, planes);                   // planes[0] = Re(DFT(I), planes[1] = Im(DFT(I))
    magnitude(planes[0], planes[1], planes[0]);// planes[0] = magnitude
    magI = planes[0];

    magI += cv::Scalar::all(1);                    // switch to logarithmic scale
    log(magI, magI);

    // crop the spectrum, if it has an odd number of rows or columns
    magI = magI(cv::Rect(0, 0, magI.cols & -2, magI.rows & -2));

    // rearrange the quadrants of Fourier image  so that the origin is at the image center
    int cx = magI.cols/2;
    int cy = magI.rows/2;

    cv::Mat q0(magI, cv::Rect(0, 0, cx, cy));   // Top-Left - Create a ROI per quadrant
    cv::Mat q1(magI, cv::Rect(cx, 0, cx, cy));  // Top-Right
    cv::Mat q2(magI, cv::Rect(0, cy, cx, cy));  // Bottom-Left
    cv::Mat q3(magI, cv::Rect(cx, cy, cx, cy)); // Bottom-Right

    cv::Mat tmp;                           // swap quadrants (Top-Left with Bottom-Right)
    q0.copyTo(tmp);
    q3.copyTo(q0);
    tmp.copyTo(q3);

    q1.copyTo(tmp);                    // swap quadrant (Top-Right with Bottom-Left)
    q2.copyTo(q1);
    tmp.copyTo(q2);

    normalize(magI, magI, 0, 1, cv::NORM_MINMAX); // Transform the matrix with float values into a viewable image form (float between values 0 and 1).

    return 0;
}