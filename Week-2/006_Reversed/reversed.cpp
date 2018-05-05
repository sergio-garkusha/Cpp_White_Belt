#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
	vector<int> result;
	int len = v.size() - 1;

	for (int i = len; i >= 0; i--)
		result.push_back(v[i]);

	return result;
}
