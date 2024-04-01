#include "../include/complex.hpp"
#include "../include/heapsort.hpp"
#include "../include/quicksort.hpp"
#include "../include/sortable.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	int testcases;
	std::cin >> testcases;

	for (int i=0;i<testcases;i++) {
		int len;
		std::cin >> len;

		Complex array[len];
		char input[100];
		for (int i=0; i<len; i++) {
			std::cin >> input;
			array[i] = Complex(input);
		}

		std::cout << len << ' ' 
			<< (argc-1 ? heapsort<Complex>(array,len) : quicksort<Complex>(array,0,len))
			<< std::endl;
	}

	return 0;
}
