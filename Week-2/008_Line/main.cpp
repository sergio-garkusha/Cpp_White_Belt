#include <iostream>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

void COME (const int k, vector<bool>& line)
{
	int size = line.size();

	if (k > 0)
		line.resize(size + k);

	if (k < 0)
	{
		size = (size + k > 0) ? size + k : 0;
		line.resize(size);
	}
}

void QUIET (const int i, vector<bool>& line)
{
	if (line.size() >= i)
		line[i] = false;
}

void WORRY (const int i, vector<bool>& line)
{
	if (line.size() >= i)
		line[i] = true;
}

void WORRY_COUNT (const vector<bool>& line)
{
	unsigned int result = 0;
	unsigned int size = line.size();

	if (size)
		for (unsigned int i = 0; i < size; i++)
			if (line[i] == true)
				result += 1;

	cout << result << endl;
	// cout << size << " people total" << endl;
	// cout << result << " worried people" << endl;
}

int main ()
{
	unsigned int Q;
	vector<bool> line;
	string operation;

	cin >> Q;

	while (Q)
	{
		int arg;

		cin >> operation;
        	if (operation == "COME")
		{
			cin >> arg;
        		COME(arg, line);
		}
        	else if (operation == "WORRY")
		{
			cin >> arg;
        		WORRY(arg, line);
		}
        	else if (operation == "QUIET")
		{
			cin >> arg;
        		QUIET(arg, line);
		}
        	else if (operation == "WORRY_COUNT")
        		WORRY_COUNT(line);

		Q--;
	}

	return 0;
}
