#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		f[year] = first_name;
	}

	void ChangeLastName(int year, const string& last_name) {
		l[year] = last_name;
	}

	string GetFullName(int year) {
		string fn = GetFirstName(year, f);
		string ln = GetLastName(year, l);
		string full = fn + " " + ln;
		unsigned int fn_size = fn.size();
		unsigned int ln_size = ln.size();

		if (!fn_size && !ln_size)
			full = "Incognito";
		else if (!fn_size)
			full = ln + " with unknown first name";
		else if (!ln_size)
			full = fn + " with unknown last name";

		return (full);
	}

private:
	string GetFirstName(int year, map<int, string>& f) {
		while (!f.count(year) && year > 0)
			year--;

		return (f[year]);
	}

	string GetLastName(int year, map<int, string>& l) {
		while (!l.count(year) && year > 0)
			year--;

		return (l[year]);
	}

	map<int, string> f;
	map<int, string> l;
};
