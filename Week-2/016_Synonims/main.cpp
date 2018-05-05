#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main (void)
{
	int Q;
	map<string, set<string>> synonyms;

	cin >> Q;

	while (Q)
	{
		string op, first, second, word;

		cin >> op;

		if (op == "ADD") {
			cin >> first >> second;

			synonyms[first].insert(second);
			synonyms[second].insert(first);
		} else if (op == "CHECK") {
			cin >> first >> second;

		if (synonyms[first].count(second) == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		} else if (op == "COUNT") {
			cin >> word;

			cout << synonyms[word].size() << endl;
		}

		Q--;
	}

	return (0);
}
