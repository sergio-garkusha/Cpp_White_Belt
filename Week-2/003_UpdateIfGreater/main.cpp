#include <iostream>
using namespace std;

#include "update_if_greater.cpp"

int main()
{
	int a = 4;
	int b = 2;

	UpdateIfGreater(a, b);

	cout << a << endl;
	cout << b << endl;

	return 0;
}
