#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{
	int secret;
	int guess;

	srand(time(NULL));
	secret = 10*((float)rand() / (float)RAND_MAX);

	printf("Please guess a number between 0-10\n");
do
{	
	scanf("%i", &guess);

	if(secret < guess)
	{
		printf("The number is lower \n");
	} else if(secret > guess)
	{
		printf("The number is higher \n");
	}

}while(secret != guess);

	printf("Correct\n");
	return 0;
}
