#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main (void)
{
	ifstream input("input.txt");

	string line;

	if (input.is_open())
		while (getline(input, line))
			cout << line << endl;

	return (0);
}
