#include <iostream>
#include <map>
#include <string>
using namespace std;


void printMap(const map<string, string>& m) {
	for (auto& item : m)
		cout << item.first
			<< "/"
			<< item.second
			<< " ";

	cout << endl;
}


int main() {
	int Q;
	map<string, string> countries;

	cin >> Q;

	while (Q) {
		string op;

		cin >> op;

		if (op == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;

			if (countries[country] == "") {
				cout << "Introduce new country " << country
					<< " with capital " << new_capital << endl;
				countries.erase(country);
			}
			else if (countries[country] == new_capital)
				cout << "Country " << country
					<< " hasn't changed its capital" << endl;
			else if (countries[country] != new_capital)
				cout << "Country " <<  country
					<< " has changed its capital from "
					<< countries[country]
					<< " to " << new_capital << endl;

			countries[country] = new_capital;
		} else if (op == "RENAME") {
			string old_name, new_name;
			cin >> old_name >> new_name;

			if (new_name == old_name) {
					cout << "Incorrect rename, skip" << endl;
			} else if (countries.count(new_name)) {
				cout << "Incorrect rename, skip" << endl;
			} else if (countries[old_name] == "") {
				cout << "Incorrect rename, skip" << endl;
				countries.erase(old_name);
			} else {
				cout << "Country " << old_name
					<< " with capital "
					<< countries[old_name]
					<< " has been renamed to "
					<< new_name << endl;

				countries[new_name] = countries[old_name];
				countries.erase(old_name);
			}
		} else if (op == "ABOUT") {
			string country;
			cin >> country;

			if (countries[country] == "") {
				cout << "Country " << country
					<< " doesn't exist" << endl;
				countries.erase(country);
			} else
				cout << "Country " << country <<
					" has capital "
					<<  countries[country] << endl;
		} else if (op == "DUMP") {
			if (countries.size() == 0)
				cout << "There are no countries in the world"
				<< endl;
			else
				printMap(countries);
		}
		Q--;
	}

	return (0);
}
