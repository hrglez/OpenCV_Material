#include "otsu.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		printf("usage must be: ./exeFile <name.extension>\n");
		return -1;
	}
	
	COtsu_binarization test(argv);
	test.filtro();
	//test.show();
	test.write();
	

	return 0;

}