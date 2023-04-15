#include <iostream>
#include "utility.h"


int Utility::xchange(int *a, int *b) {
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}


void Utility::printArray(int *array, int length) {
	for (int i = 0; i < length; ++i) {
		std::cout << array[i] << "\t";
	}
	std::cout << std::endl;
}