#ifndef collage_h
#define collage_h
#include <opencv2/core.hpp> //class Mat
//Collage class
class CCollage
{
private:
	unsigned int size_;
	unsigned char cuadrado_;
	cv::Mat definitivo_;
	
public:
	CCollage (unsigned int size_ = 1, unsigned char cuadrado_ = 'n');
	void create(void);
	void write(void);
	void setSize(unsigned int nSize);
	unsigned int getSize(void) const;
};

#endif
