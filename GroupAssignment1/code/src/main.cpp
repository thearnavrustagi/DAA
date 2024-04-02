#include "../include/complex.hpp"
#include "../include/heapsort.hpp"
#include "../include/quicksort.hpp"
#include "../include/sortable.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	int testcases;
	std::cin >> testcases;
	std::cout << testcases << std::endl;

	for (int i=0;i<testcases;i++) {
		int len;
		std::cin >> len;

		Complex array[len];
		char input[100];
		for (int i=0; i<len; i++) {
			std::cin >> input;
			array[i] = Complex(input);
		}
		

		int comparisions = (argc-1 ? heapsort<Complex>(array,len) : quicksort<Complex>(array,0,len-1));
		std::cout << len << ' ' 
			<< comparisions
			<< std::endl;
	}

	return 0;
}
