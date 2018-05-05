#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
	Student(string fn, string ln, int d, int m, int y) {
		firstname = fn;
		lastname = ln;
		day = d;
		month = m;
		year = y;
	}

	string firstname = "";
	string lastname = "";

	int month = 0;
	int day = 0;
	int year = 0;
};

int main (void)
{
	string firstname, lastname;
	int day, month, year;
	vector<Student> students;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> firstname >> lastname >> day >> month >> year;
		Student student{firstname, lastname, day, month, year};
		students.push_back(student);
	}

	int m;
	cin >> m;

	for (int j = 0; j < m; ++j) {
		string op;
		int k;
		cin >> op >> k;

		if (op == "name" && k > 0 && k <= students.size())
		    cout << students[k - 1].firstname
			<< " "
			<< students[k - 1].lastname
			<< endl;
		else if (op == "date" && k > 0 && k <= students.size())
		    cout << students[k - 1].day
			<< "."
			<< students[k - 1].month
			<< "."
			<< students[k - 1].year
			<< endl;
		else
		    cout << "bad request" << endl;
	}

	return (0);
}
