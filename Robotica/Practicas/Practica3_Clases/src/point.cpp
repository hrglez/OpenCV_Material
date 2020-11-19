//point class implementation

#include "point.hpp"
#include <cmath>
#include <iostream>

//constructor class
CPoint::CPoint(int var_x, int var_y) :
	x_(var_x), //x_ = var_x
	y_(var_y)  //y_ = var_y
{
}

int CPoint::getX(void) const
{
	return x_;
}

int CPoint::getY(void) const
{
	return y_;
}

void CPoint::setX(int var_x)
{
	x_=var_x;
}

void CPoint::setY(int var_y)
{
	y_=var_y;
}

void CPoint::setXY(int var_x, int var_y)
{
	x_=var_x;
	y_=var_y;
}

double CPoint::getMagnitude(void) const
{	
return sqrt(x_ * x_ + y_ * y_);
}

double CPoint::getArgument(void) const
{
	return atan2(y_, x_) * 180/M_PI;
}

void CPoint::print() const
{
	std::cout << "(" << x_ << " , " << y_ << ")" << std::endl;
}
