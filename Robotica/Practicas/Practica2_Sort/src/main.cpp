#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctime>

void printList(int *numbers); //Print a list
void sortList(int *numbers); //Sort the list
void Ordenar(int *numbers, int idx_start, int idx_end); //Version propia de sortList
int Particion(int *numbers, int ind_start, int ind_end); //Funcion auxiliar para version personal

static const int k_list_size = 1000; //Tamaño de la lista
char one=1, zero=0;

int main()
{
	int random_numbers[k_list_size]; //Arreglo con tamaño definido
	int limit_random = 1000;	 //Límite de número a generar, intervalo de cero a limit_random
	int exp_num=1000;		//Veces que se ejecuta el acomodo de arreglos
	double time_sum=0.0;		//suma de tiempo
	double suma=0.0;		//Suma de tiempo de solucion personal

	clock_t begin; //Variable tipo "reloj". Mide el tiempo del sistema.
	clock_t end;
	clock_t inicio;
	clock_t fin;

	srand(time(NULL));

	for (int exp=0; exp < exp_num; exp++)
	{
		for(int idx=0; idx < k_list_size ; idx++)
		{
		random_numbers[idx] = (int)(limit_random*((float)rand() / (float)RAND_MAX));
		}

		begin = clock();
		sortList(random_numbers);
		end = clock();
		time_sum += double(end-begin) / CLOCKS_PER_SEC;//CLOCKS PER SEC convierte pulsos en segundos

		inicio = clock();
		Ordenar(random_numbers, zero, k_list_size - one);
		fin = clock();
		suma += double(fin-inicio) / CLOCKS_PER_SEC;

	}
	

	std::cout<<"Class average: "<<time_sum/(double)(exp_num)<< std::endl;
	std::cout<<"My average: "<<suma/(double)(exp_num)<< std::endl;
	//printList(random_numbers);

	/*sstd::cout<<"Prueba chacalosa:\n";
	for(int idx=0; idx < k_list_size ; idx++)
		{
		random_numbers[idx] = (int)(limit_random*((float)rand() / (float)RAND_MAX));
		}
	Ordenar(random_numbers, zero, k_list_size - one);
	printList(random_numbers);*/
	
	return 0;
}

void printList (int *numbers)
{
	for(int idx=0; idx < k_list_size ; idx++)
	{
	std::cout<<numbers[idx]<<" ";
	}
	std::cout<<std::endl;
}

void sortList (int *numbers)
{
	for(int idx=0; idx < k_list_size ; idx++)
	{
		for(int idy= idx + 1; idy < k_list_size ; idy++)
		{
			if(numbers[idx] > numbers [idy])
			{
			int temp = numbers[idx];
			numbers[idx] = numbers[idy];
			numbers[idy] = temp;
			}	
		}
	}
}

void Ordenar(int *numbers, int idx_start, int idx_end)
{
	if(idx_start < idx_end)
	{
	int part_idx = Particion(numbers, idx_start, idx_end); //Partir el arreglo las veces que sea necesario
	Ordenar(numbers, idx_start, part_idx - one);
	Ordenar(numbers, part_idx + one, idx_end);
	}
}

int Particion(int *numbers, int ind_start, int ind_end)
{
int pivote = numbers[ind_end]; //Valor a pivotear, ubicado en el indice final
int idx_part = ind_start; //Valor del indice (no del valor) de comienzo
int temp; //Variable temporal de almacenamiento 

	for(int idx = ind_start; idx < ind_end ; idx++)
	{
		if(numbers[idx] <= pivote) //Modifica los valores a la der o a la izq segun su valor respecto al pivote
		{
		temp = numbers[idx];
		numbers[idx] = numbers[idx_part];
		numbers[idx_part] = temp;
		idx_part++;
		}
	}
	temp = numbers[idx_part]; //Cambiar el pivote al lugar donde termino el indice de particion
	numbers[idx_part] = numbers[ind_end];
	numbers[ind_end] = temp;

return idx_part;
}
