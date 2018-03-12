#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "move_strings.cpp"

int main ()
{
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};

	MoveStrings(source, destination);

	for (auto w : destination)
		cout << w << endl;

	cout << "======" << endl;

	for (auto w : source)
		cout << w << endl;

	return 0;
}
