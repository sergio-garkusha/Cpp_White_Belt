#include <iostream>
#include "names.cpp"
using namespace std;

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");

	for (int year : {1900, 1965, 1990})
		cout << person.GetFullName(year) << endl;

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970})
		cout << person.GetFullName(year) << endl;

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970})
		cout << person.GetFullName(year) << endl;

return (0);
}
