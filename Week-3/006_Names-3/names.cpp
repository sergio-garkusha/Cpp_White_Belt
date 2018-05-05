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

    return name;
}

string GetHistory(int year, const map<int, string>& names) {
    vector<string> names_history;
    string current_name = "";

    for (const auto& item : names)
        if (item.first <= year)
            if (item.second != current_name) {
                vector<string> v = {item.second};
                names_history.insert(begin(names_history), begin(v), end(v));
                current_name = item.second;
            }
        else
            break;

    string history = "";

    for (int i = 1; i < names_history.size(); ++i)
        if (history.size() == 0)
            history += names_history[i];
        else
            history = history + ", " + names_history[i];

    return (history);
}

class Person {
public:
    Person (const string& first_name, const string& last_name, int year) {
        year_of_birth = year;
        firstname[year] = first_name;
        lastname[year] = last_name;
    }

    void ChangeFirstName(int year, const string& first_name) {
        if (!(year < year_of_birth))
            firstname[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        if (!(year < year_of_birth))
            lastname[year] = last_name;
    }

    string GetFullName(int year) const {
        if (year < year_of_birth)
            return ("No person");

        const string first_name = FindNameByYear(year, firstname);
        const string last_name = FindNameByYear(year, lastname);
        string full_name = first_name + " " + last_name;

        if (!first_name.size() && !last_name.size())
            full_name = "Incognito";
        else if (!first_name.size())
            full_name = last_name + " with unknown first name";
        else if (!last_name.size())
            full_name = first_name + " with unknown last name";

        return (full_name);
    }

    string GetFullNameWithHistory(int year) const {
        if (year < year_of_birth)
            return ("No person");

        const string first_name = FindNameByYear(year, firstname);
        const string last_name = FindNameByYear(year, lastname);
        const string history_fn = GetHistory(year, firstname);
        const string history_ln = GetHistory(year, lastname);
        string full_name = first_name + " (" + history_fn + ")" + " " + last_name + " (" + history_ln + ")";
	int fs = first_name.size();
	int ls = last_name.size();
	int hfn = history_fn.size();
	int hln = history_ln.size();

        if (!fs && !ls)
            full_name = "Incognito";
        else if (!fs)
            if (!hfn)
                full_name = last_name + " with unknown first name";
            else
                full_name = last_name + " (" + history_ln + ")" + " with unknown first name";
        else if (!ls)
            if (!hln)
                full_name = first_name + " with unknown last name";
            else
                full_name = first_name + " (" + history_fn + ")" + " with unknown last name";
        else if (!hfn && !hln)
            full_name = first_name + " " + last_name;
        else if (!hfn)
            full_name = first_name + " " + last_name + " (" + history_ln + ")" ;
        else if (!hln)
            full_name = first_name + " (" + history_fn + ") " + last_name;

        return (full_name);
    }

private:
    map<int, string> firstname;
    map<int, string> lastname;
    int year_of_birth;
};
