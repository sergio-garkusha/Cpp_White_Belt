#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int current_month = 0;
vector<string> tasks(31, "");
vector<int> days_numbers = {
	31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31
};

void ADD (int i, const string& s)
{
	i -= 1; // because we work with indexes

	if (tasks[i].size())
		tasks[i] += " " + s;
	else
		tasks[i] = s;
}

void _remap_days(int prev, int next)
{
	int diff;

	prev -= 1; // because we work with indexes
	diff = (prev - next);

	while (diff >= 0)
	{
		if (tasks[prev - diff].size())
		{
			ADD(next, tasks[prev - diff]);
			tasks[prev - diff] = "";
		}

		diff--;
	}
}

void NEXT ()
{
	int i = current_month;

	if (days_numbers[i] > days_numbers[i + 1])
		_remap_days(days_numbers[i], days_numbers[i + 1]);

	current_month = (current_month != 11)
		? current_month + 1
		: 0;
}

void DUMP (int i)
{
	int counter = 0;

	i = i - 1;
	if (tasks[i].size() > 0)
	{	// counts spaces in the string
		counter = count(tasks[i].begin(), tasks[i].end(), ' ');
		counter = (!counter)
			? 1 // if no spaces, we have 1 task
			: counter + 1; // n spaces + 1 == n tasks

		cout << counter << " " << tasks[i] << endl;
		return;
	}

	cout << counter << endl;
}

int main ()
{
	unsigned int Q;
	string operation;

	cin >> Q;

	// ADD(5, "Salary");
	// ADD(31, "Walk");
	// ADD(30, "WalkPreparations");
	// NEXT();
	// DUMP(5);
	// DUMP(28);
	// NEXT();
	// DUMP(31);
	// DUMP(30);
	// DUMP(28);
	// ADD(28, "Payment");
	// DUMP(28);

	while (Q)
	{
		int day;
		string task;

		cin >> operation;
		if (operation == "ADD")
		{
			cin >> day >> task;
			ADD(day, task);
		}
		else if (operation == "NEXT")
		{
			NEXT();
		}
		else if (operation == "DUMP")
		{
			cin >> day;
			DUMP(day);
		}

		Q--;
	}

	return 0;
}
