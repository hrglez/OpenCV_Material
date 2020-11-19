#ifndef binary_h
#define binary_h
#include <opencv2/core.hpp> //class Mat
#include <string>

class CBinary
{
private:
	cv::Mat raiz_;
	
public:
	CBinary (std::string dir = 0);
	int check (void);
	void hist (void);
	void otsu (void);
	void threshold (unsigned int umbral= 0);
};

#endif