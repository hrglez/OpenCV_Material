#ifndef otsu_h
#define otsu_h
#include "opencv2/core.hpp"

int videoContrast (void);
cv::Mat BrightContrast(cv::Mat input);
int Comparison (void);
void Sobel_Edge (void);
void Canny_Edge (void);
unsigned char Otsu_Mask (void);
void ShowOriginal (void);

#endif