#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int> BuildCharCounters(string& s) {
    map<char, int> counter;

    for (const char& c : s)
        counter[c]++;

    return (counter);
}

int main () {
	int Q;

	cin >> Q;

	while (Q) {
		string f, s;

		cin >> f >> s;

		if (BuildCharCounters(f) == BuildCharCounters(s))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		Q--;
	}

	return (0);
}
