#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

set<string>BuildMapValuesSet(const map<int, string>& m)
{
	set<string> s;

	for (const auto& pair : m)
		s.insert(pair.second);

	return (s);
}
