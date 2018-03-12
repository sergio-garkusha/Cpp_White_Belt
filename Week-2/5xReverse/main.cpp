#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "reverse.cpp"

int main ()
{
	vector<int> source = {1, 2, 3, 4, 5};

	for (auto w : source)
		cout << w << endl;

	cout << "======" << endl;

	Reverse(source);
	for (auto w : source)
		cout << w << endl;

	return 0;
}
