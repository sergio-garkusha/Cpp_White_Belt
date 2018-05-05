#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main (void)
{
	int Q;
	map<set<string>, int> buses;
	string stop;

	cin >> Q;
	while (Q)
	{
		int i;
		cin >> i;
		// re-declares variable on each step
		set<string> stops;

		while (i) {
			cin >> stop;
			stops.insert(stop);
			--i;
		}

		if (buses.count(stops) == 0) {
			int num = buses.size() + 1;
			buses[stops] = num;
			cout << "New bus " << num << endl;
		} else
			cout << "Already exists for " << buses[stops] << endl;

		Q--;
	}

	return (0);
}
