#include "collage.hpp"
#include <iostream>

int main(void)
{
	unsigned int size = 0;
	unsigned char seguir='y', xx, escribir=0;
	
	while(1){
		if(seguir=='y'){
			std::cout<<"\nInsert amount of pictures to include in the collage: ";
			std::cin >> size;
			std::cout<<"\nWould you like to get a square? (please don't, the result is awful) (y/n): ";
			std::cin >> xx;

			CCollage test(size,xx);
			test.create();

			std::cout<<"\nWould you like to save the image you just created? (y/n): ";
			std::cin >> escribir;

			if(escribir=='y') test.write();

			std::cout<<"\nWould you like to try again? (y/n): ";
			std::cin >> seguir;
		}
		else break;
	}

	return 0;

}