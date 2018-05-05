#include <iostream>
#include <vector>
#include <string>
using namespace std;

void Reverse(vector<int>& v)
{
	int temp;
	int len = v.size() - 1;

	for (int i = 0; i <= len; i++)
	{
		tmp = v[i];
		v[i] = v[len - i];
		v[len - i] = tmp;
	}
}
