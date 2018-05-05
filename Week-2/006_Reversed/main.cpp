#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "reversed.cpp"

int main ()
{
	vector<int> source = {1, 2, 3, 4, 5};
	vector<int> result;

	cout << "=== original ===" << endl;
	for (auto w : source)
		cout << w << endl;

	result = Reversed(source);

	cout << "=== returned ===" << endl;
	for (auto w : result)
		cout << w << endl;

	cout << "=== original ===" << endl;
	for (auto w : source)
		cout << w << endl;


	return 0;
}
