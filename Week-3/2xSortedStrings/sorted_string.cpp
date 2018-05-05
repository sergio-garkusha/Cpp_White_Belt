#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
	void AddString(const string& s) {
		v.push_back(s);
	}

	vector<string> GetSortedStrings() {
		sort(begin(v), end(v));
		return v;
	}

private:
	vector<string> v;
};
