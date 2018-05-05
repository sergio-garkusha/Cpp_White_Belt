#include <iostream>
#include "sorted_string.cpp"
using namespace std;

void PrintSortedStrings(SortedStrings& strings)
{
	int i = 0;

	for (const string& s : strings.GetSortedStrings()) {
		if (i != 0)
			cout << " ";

		cout << s;
		i++;
	}

	cout << endl;
}

int main()
{
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	return (0);
}
