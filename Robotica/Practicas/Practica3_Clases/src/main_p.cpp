#include "point.hpp"
#include <iostream>

int main()
{
	CPoint point_1(3,4);
	point_1.print();

	std::cout << "get X: " << point_1.getX() << "\n";
	std::cout << "get Y: " << point_1.getY() << "\n";

	std::cout << "magnitude: " << point_1.getMagnitude() << "\n";
	std::cout << "argument: " << point_1.getArgument() << "\n";

	point_1.setXY(5, 6);
	point_1.print();

	return 0;
}
