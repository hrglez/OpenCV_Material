//implementation

#include "collage.hpp"
#include <opencv2/imgcodecs.hpp> //IMREAD_COLOR
#include <opencv2/highgui.hpp>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>
#include <cmath>

#define ENTRENAMIENTO

unsigned int cols (unsigned int total)
{
	unsigned int result;
	unsigned int temp = float(10*sqrt(total));

	if(temp%10 >= 5)
	{
		result = sqrt(total) + 1;
	}
	else result = sqrt(total);

	return result;
}

unsigned int rows(unsigned int cols, unsigned int total)
{
	unsigned int result;
	unsigned int temp = float(10*sqrt(total));

	if (temp%10==0)
	{
		result=sqrt(total);
	}

	else
	{
		if((cols * (total/cols)) < total)
		{
			result=(total/cols)+1;
		}
		else result=total/cols;
	}

	return result;
}

unsigned long menor (std::vector <cv::Mat> &valores, unsigned int cols, unsigned int idy, unsigned int sz)
{
	unsigned long temp = valores[idy*cols].rows;

	for (unsigned int i=1; i < cols;i++)
	{
		if( ((idy*cols)+i) < sz ){
			if(temp > (valores[( (idy*cols) + i )].rows) ) temp = valores[( (idy*cols) +i )].rows;
		}
	}

	return temp;
}

CCollage::CCollage (unsigned int tamano, unsigned char sqr) :
size_(tamano),
cuadrado_(sqr)
{
}

void CCollage::create (void)
{
	unsigned int columnas=0, filas=0, recx=0, recy=0;
	unsigned long distx=0, disty=0, puntx=0, punty=0;

	std::string direccion;
	std::vector <cv::Mat> goku (size_);

	columnas = cols(size_);
	filas = rows(columnas, size_);

	//std::cout<<"Cols: "<<columnas<<"\nRows: "<<filas<<std::endl;

	for(unsigned char i=0; i < size_; i++)
	{
		#ifdef ENTRENAMIENTO
		direccion = (std::string)"training/train" + std::to_string((i+1)) + (std::string)".jpeg";
		goku[i] = imread (direccion, cv::IMREAD_GRAYSCALE);
		#else
		direccion = (std::string)"pics/pic" + std::to_string((i+1)) + (std::string)".jpg";
		goku[i] = imread (direccion, cv::IMREAD_COLOR);
		#endif
		
		/*imshow("Loaded", goku[i]);
		cv::waitKey(0);*/
	}

	for(unsigned char i=0;i<columnas;i++)
	{
		distx += (goku[i].cols);
	}

	for(unsigned char i=0;i<filas;i++)
	{
		disty += (goku[(i*columnas)].rows);
	}

	
	if(cuadrado_=='y')
	{
		if (distx > disty) disty = distx;
		else distx = disty;
	}

	//std::cout<<"Dist en X: "<<distx<<"\nDist en Y: "<<disty<<std::endl;

	#ifdef ENTRENAMIENTO
	cv::Mat collage = cv::Mat::zeros(disty, distx, CV_8UC1);
	#else
	cv::Mat collage = cv::Mat::zeros(disty, distx, CV_8UC3);
	#endif

	for(unsigned int idy=0; idy < filas; idy++)
	{
		for(unsigned int idx=0; idx < columnas; idx++)
		{
			if( (idx+(idy*columnas)) < size_ )
			{
				if( ((distx-puntx) >= goku[idx+(idy*columnas)].cols) ) recx = goku[idx+(idy*columnas)].cols;
				else recx = distx-puntx;
				if( ((disty-punty) >= goku[idx+(idy*columnas)].rows) ) recy = goku[idx+(idy*columnas)].rows;
				else recy = disty-punty;
				(goku[idx+(idy*columnas)](cv::Rect(0,0,recx, recy))).copyTo(collage(cv::Rect(puntx,punty,recx, recy)));
				puntx += goku[idx+(idy*columnas)].cols;
			}
			else break;
		}
		puntx = 0;
		punty += menor(goku, columnas, idy, size_);

	}
		
	if(cuadrado_ == 'n') definitivo_ = collage(cv::Rect(0,0,distx, punty));
	else definitivo_ = collage;

	cv::namedWindow ("Collage", cv::WINDOW_NORMAL);
	imshow ("Collage", definitivo_);

	cv::waitKey(0);

}

void CCollage::write (void)
{
	imwrite("Collage.jpg", definitivo_);
}

void CCollage::setSize(unsigned int nSize)
{
	size_ = nSize;
}

unsigned int CCollage::getSize(void) const
{
	return size_;
}
