//implementation

#include "pendulum.hpp"
#include <cmath>
#include <iostream>

//constructor class
CPendulum::CPendulum (double var_l, double var_g) :
	length_(var_l), //length_ = var_l
	gravity_(var_g)  //gravity_ = var_g
{
}

double CPendulum::getL(void) const
{
	return length_;
}

double CPendulum::getG(void) const
{
	return gravity_;
}

void CPendulum::setL(double var_l)
{
	length_ = var_l;
}

void CPendulum::setG(double var_g)
{
	gravity_ = var_g;
}

void CPendulum::setLG(double var_l, double var_g)
{
	length_ = var_l;
	gravity_ = var_g;
}

double CPendulum::getPeriod(void) const
{	
	return 2*M_PI*sqrt(length_ / gravity_);
}

double CPendulum::getFrequency(void) const
{
	return (0.5/M_PI)*sqrt(gravity_ / length_);
}

void CPendulum::print() const
{
	std::cout << "Longitud = " << length_ << " & Gravedad = " << gravity_ << std::endl;
}
