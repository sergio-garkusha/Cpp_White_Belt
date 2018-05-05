#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string FindNameByYear(int year, const map<int, string>& names) {
	string name;

	for (const auto& itm : names)
		if (itm.first <= year)
			name = itm.second;
		else
			break;

	return (name);
}

string GetHistory(int year, const map<int, string>& names) {
	vector<string> history;
	string curr_name = "", h = "";

	for (const auto& item : names)
		if (item.first <= year) {
			if (item.second != curr_name) {
				vector<string> v = {item.second};
				history.insert(begin(history), begin(v), end(v));
				curr_name = item.second;
			}
		}
		else
			break;

	for (int i = 1; i < history.size(); i++)
		if (h.size() == 0)
			h += history[i];
		else
			h = h + ", " + history[i];

	return (h);
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		firstname[year] = first_name;
	}

	void ChangeLastName(int year, const string& last_name) {
		lastname[year] = last_name;
	}

	string GetFullName(int year) {
		const string first_name = FindNameByYear(year, firstname);
		const string last_name = FindNameByYear(year, lastname);
		string full_name = first_name + " " + last_name;

		if (first_name.size() == 0 && last_name.size() == 0)
			full_name = "Incognito";
		else if (first_name.size() == 0)
			full_name = last_name + " with unknown first name";
		else if (last_name.size() == 0)
			full_name = first_name + " with unknown last name";

		return (full_name);
	}

	string GetFullNameWithHistory(int year) {
		const string first_name = FindNameByYear(year, firstname);
		const string last_name = FindNameByYear(year, lastname);
		const string history_first_name = GetHistory(year, firstname);
		const string history_last_name = GetHistory(year, lastname);

		string full_name = first_name + " (" + history_first_name + ")" + " " + last_name + " (" + history_last_name + ")";

		if (first_name.size() == 0 && last_name.size() == 0)
				full_name = "Incognito";
		else if (first_name.size() == 0)
			if (history_last_name.size() == 0)
				full_name = last_name + " with unknown first name";
			else
				full_name = last_name + " (" + history_last_name + ")" + " with unknown first name";
		else if (last_name.size() == 0)
			if (history_first_name.size() == 0)
				full_name = first_name + " with unknown last name";
			else
				full_name = first_name + " (" + history_first_name + ")" + " with unknown last name";
		else if (history_first_name.size() == 0 && history_last_name.size() == 0)
			full_name = first_name + " " + last_name;
		else if (history_first_name.size() == 0)
			full_name = first_name + " " + last_name + " (" + history_last_name + ")" ;
		else if (history_last_name.size() == 0)
			full_name = first_name + " (" + history_first_name + ") " + last_name;

	return (full_name);
}

private:
	map<int, string> firstname;
	map<int, string> lastname;
};
