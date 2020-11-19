#include "edge.hpp"
//#include <stdio.h>
#include <iostream>

int main(void)
{	
	char ans;

	/*printf("Welcome. Please choose an option:\n1.Play with Contrast and Brightness from computer's camera.\n2.Compare edge detection methods.\n");
	scanf("%c", &ans);*/

	std::cout<<"Welcome. Please choose an option:\n1.Play with Contrast and Brightness from computer's camera.\n2.Compare edge detection methods.\n";
	std::cin>>ans;

	if(ans=='1') videoContrast();

	else if (ans=='2')
	{
		//printf("Type 't' any time you want to take a photograph.\nType anything else to finish\n");
		std::cout<<"Type 't' any time you want to take a photograph.\nType anything else to finish\n";
		while(1)
		{
			//scanf("%c", &ans);
			std::cin>>ans;
			if(ans=='t') Comparison();
			else break;
		}
	}

	return 0;
}