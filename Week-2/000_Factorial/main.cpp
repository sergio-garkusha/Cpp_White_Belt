#include <iostream>

#include "factorial.cpp"

int main (void) {

	std::cout << Factorial(1) << std::endl;
	std::cout << Factorial(-2) << std::endl;
	std::cout << Factorial(4) << std::endl;

	return 0;
}
