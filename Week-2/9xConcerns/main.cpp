#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int current_month = 0;
vector<vector<string>> tasks(31);
vector<int> days_numbers = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void ADD (int i, const string& s)
{
	i -= 1; // because we work with indexes
	tasks[i].push_back(s);
}

void _remap_days(int prev, int next)
{
	int diff;
	int tasks_count;

	prev -= 1; // because we work with indexes
	diff = (prev - next);

	while (diff >= 0)
	{
		if (tasks[prev - diff].size())
		{
			for (auto& task : tasks[prev - diff])
				ADD(next, task);

			tasks[prev - diff].clear();
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
	i -= 1; // because we work with indexes

	int counter = tasks[i].size();

	cout << counter;
	for (const string& task : tasks[i])
		cout << " " << task;

	cout << endl;
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
