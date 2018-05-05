#include <iostream>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

int main ()
{
	int n, i = 0, qty = 0, avg = 0;

	cin >> n;

	vector<int> days(n);
	for (int& day : days)
	{
		cin >> day;
		avg += day;
	}

	avg /= n;

	for (int& day : days)
		if (day > avg)
			qty++;

	cout << qty << endl;

	for (int& day : days)
	{
		if (day > avg)
		{
			if (i + 1 != n)
				cout << i << " ";
			else
				cout << i << endl;
		}
		i++;
	}


	return 0;
}
