#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int main (void)
{
	ifstream input("input.txt");

	double n;
	cout << setprecision(3) << fixed;

	if (input.is_open())
		while (input) {
			input >> n;

			if (input)
				cout << n<< endl;
		}

	return (0);
}
