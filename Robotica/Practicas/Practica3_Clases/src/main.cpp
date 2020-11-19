#include <iostream> //IO functions
#include <string> //Cadenas de caracteres

const static double k_pi = 3.14159;

class cCircle
{
private:
	double radius_; //Data member (variable)
	std::string color_;	//Data member
public:
	
	cCircle(double radius = 1.0, std::string color = "red")
	{
	radius_=radius;
	color_=color;
	}

	double getRadius()	//Member function
	{
	return radius_;
	}

	std::string getColor()
	{
	return color_;
	}

	double getArea()
	{
	return radius_*radius_*k_pi;
	}
};

int main(){

cCircle circle_1 = cCircle(7.0,"green");
std::cout<< "radius : " << circle_1.getRadius() << std::endl;
std::cout<< "color : " << circle_1.getColor() << std::endl;

cCircle circle_2 = cCircle(3.0);
std::cout<< "radius : " << circle_2.getRadius() << std::endl;
std::cout<< "color : " << circle_2.getColor() << std::endl;

cCircle circle_3 = cCircle();
std::cout<< "radius : " << circle_3.getRadius() << std::endl;
std::cout<< "color : " << circle_3.getColor() << std::endl;

return 0;
}
