#include <iostream>
#include <vector>
#include <string>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination)
{
	for (auto w : source)
		destination.push_back(w);

	source.clear();
}
