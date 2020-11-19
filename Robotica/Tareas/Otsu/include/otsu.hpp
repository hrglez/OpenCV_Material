#ifndef otsu_h
#define otsu_h
#include <opencv2/core.hpp> //class Mat

class COtsu_binarization
{
private:
	cv::Mat raiz_;
	
public:
	COtsu_binarization (char** dir = 0);
	void filtro (void);
	void show (void);
	void write (void);
};

#endif
