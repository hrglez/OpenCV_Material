// Preprocess.cpp

#include "Preprocess.h"

///////////////////////////////////////////////////////////////////////////////////////////////////
void preprocess(cv::Mat &imgOriginal, cv::Mat &imgGrayscale, cv::Mat &imgThresh, int &type) {
    cv::Mat imgBlurred;

    if(type)
    {
        cv::Mat imgHSV;
        cv::GaussianBlur(imgOriginal, imgBlurred, GAUSSIAN_SMOOTH_FILTER_SIZE, 0);          // gaussian blur
        cvtColor(imgBlurred, imgHSV, cv::COLOR_BGR2HSV);
        inRange(imgHSV, cv::Scalar(0, 0, 0), cv::Scalar(180, 255, 120), imgThresh);
        erode(imgThresh, imgThresh, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
        dilate(imgThresh, imgThresh, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
        erode(imgThresh, imgThresh, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
        dilate(imgThresh, imgThresh, getStructuringElement(cv::MORPH_RECT, cv::Size(5,5)));
    }
    else
    {
        imgGrayscale = extractValue(imgOriginal);                           // extract value channel only from original image to get imgGrayscale

        cv::Mat imgMaxContrastGrayscale = maximizeContrast(imgGrayscale);       // maximize contrast with top hat and black hat

        cv::GaussianBlur(imgMaxContrastGrayscale, imgBlurred, GAUSSIAN_SMOOTH_FILTER_SIZE, 0);          // gaussian blur
                                                                                                        // call adaptive threshold to get imgThresh
        cv::adaptiveThreshold(imgBlurred, imgThresh, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY_INV, ADAPTIVE_THRESH_BLOCK_SIZE, ADAPTIVE_THRESH_WEIGHT);
        //cv::threshold(imgBlurred, imgThresh, 15, 255, cv::THRESH_BINARY_INV);
    }  
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////
cv::Mat extractValue(cv::Mat &imgOriginal) {
    cv::Mat imgHSV;
    std::vector<cv::Mat> vectorOfHSVImages;
    cv::Mat imgValue;

    cv::cvtColor(imgOriginal, imgHSV, cv::COLOR_BGR2HSV);

    cv::split(imgHSV, vectorOfHSVImages);

    imgValue = vectorOfHSVImages[2];

    return(imgValue);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
cv::Mat maximizeContrast(cv::Mat &imgGrayscale) {
    cv::Mat imgTopHat;
    cv::Mat imgBlackHat;
    cv::Mat imgGrayscalePlusTopHat;
    cv::Mat imgGrayscalePlusTopHatMinusBlackHat;

    cv::Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));

    cv::morphologyEx(imgGrayscale, imgTopHat, cv::MORPH_TOPHAT, structuringElement);
    cv::morphologyEx(imgGrayscale, imgBlackHat, cv::MORPH_BLACKHAT, structuringElement);

    imgGrayscalePlusTopHat = imgGrayscale + imgTopHat;
    imgGrayscalePlusTopHatMinusBlackHat = imgGrayscalePlusTopHat - imgBlackHat;

    return(imgGrayscalePlusTopHatMinusBlackHat);
}


