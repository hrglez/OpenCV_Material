#include "pendulum.hpp"
#include <iostream>

int main()
{
	CPendulum test_earth; //Prueba constructor
	CPendulum test_moon(17);
	CPendulum test_FFplane(17,0);
	test_earth.setL(17); //Prueba de setL
	test_moon.setG(1.62); //Prueba de setG
	
	std::cout << "Valores para la Tierra: ";
	test_earth.print(); //Prueba print
	std::cout << "Valores para la Luna: ";
	test_moon.print();
	std::cout << "Valores para un avión en caída libre: ";
	test_FFplane.print();

	std::cout<< "\nLongitud general: " << test_earth.getL()<<std::endl; //Prueba getL
	std::cout<< "Gravedad en la Luna (prueba): " <<test_moon.getG()<< "\n\n"; //Prueba getG

	std::cout << "Prueba en la Tierra: \n" << "Periodo = " << test_earth.getPeriod() << std::endl << "Frecuencia = " << test_earth.getFrequency() << "\n\n" ; //Pruebas getPeriod & getFrequency
	std::cout << "Prueba en la Luna: \n" << "Periodo = " << test_moon.getPeriod() << std::endl << "Frecuencia = " << test_moon.getFrequency() << "\n\n";
	std::cout << "Prueba en un avión en caída libre: \n" << "Periodo = " << test_FFplane.getPeriod() << std::endl << "Frecuencia = " << test_FFplane.getFrequency() << "\n\n" ;
	
	test_earth.setLG(21.58, 3.14159); //Prueba setLG
	test_earth.print();

	return 0;
}
