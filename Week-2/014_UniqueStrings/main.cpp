#include <iostream>
#include <set>
using namespace std;

int main (void)
{
	int Q;
	set<string> nums;

	cin >> Q;

	while (Q)
	{
		string n;
		cin >> n;
		nums.insert(n);

		Q--;
	}

	cout << nums.size() << endl;

	return (0);
}
