#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <set>
#include <map>
#include <stdexcept>
#include <vector>

using namespace std;

string FormatDate (int n, char type)
{
	string result = to_string(n);
	int len = (type == 'y') ? 4 : 2;

	while (result.size() != len)
		result.insert(0, 1, '0');

	return (result);
}

class Date {
public:
	Date (int _m, int _d, int _y) {
		if (_m < 1 || _m > 12)
			throw logic_error("Month value is invalid: "
				+ to_string(_m)); // month is out of range

		if (_d < 1 || _d > 31)
			throw logic_error("Day value is invalid: "
				+ to_string(_d)); // day is out of range

		m = _m;
		d = _d;
		y = _y;
	}

	int GetYear () const {
		return (y);
	}

	int GetMonth () const {
		return (m);
	}

	int GetDay () const {
		return (d);
	}

private:
	int m;
	int d;
	int y;
};

bool operator < (const Date& lhs, const Date& rhs) {
	int ly = lhs.GetYear();
	int lm = lhs.GetMonth();
	int ld = lhs.GetDay();

	int ry = rhs.GetYear();
	int rm = rhs.GetMonth();
	int rd = rhs.GetDay();

	return (vector<int>{ly, lm, ld} < vector<int>{ry, rm, rd});
}

class Database {
public:
	bool RunCommand (const string& line) {
		stringstream stream(line);

		string cmd;
		stream >> cmd;

		string dateStr = "";
		string event = "";

		if (cmd == "Add")
		{
			// cout << "Command: " << cmd << endl;
			stream.ignore(1);
			stream >> dateStr;
			const Date date = ParseDate(dateStr);

			stream.ignore(1);
			stream >> event;

			AddEvent(date, event);
			event = "";
		}
		else if (cmd == "Del")
		{
			// cout << "Command: " << cmd << endl;
			stream.ignore(1);
			stream >> dateStr;
			const Date date = ParseDate(dateStr);

			stream.ignore(1);
			stream >> event;

			// cout << "EVT: " << event << endl;
			// cout << "EVT: " << event.size() << endl;

			if (!event.size()) // !!!!!!!
				DeleteDate(date);
			else
				DeleteEvent(date, event);
			event = "";
		}
		else if (cmd == "Find")
		{
			// cout << "Command: " << cmd << endl;
			stream.ignore(1);
			stream >> dateStr;
			const Date date = ParseDate(dateStr);

			for (const string& evt : Find(date))
				cout << evt << endl;
		}
		else if (cmd == "Print")
		{
			// cout << "Command: " << cmd << endl;
			Print();
		}
		else if (!line.size())
		{
			return (false);
		}
		else
		{
			throw logic_error("Unknown command: " + cmd);
		}

		return (true);
	}

	void AddEvent (const Date& date, const string& event) {
		if (!event.empty())
			db[date].insert(event);
	}

	bool DeleteEvent (const Date& date, const string& event) {
		if (db.count(date) > 0 && db[date].count(event) > 0)
		{
			db[date].erase(event);

			cout << "Deleted successfully" << endl;

			return (true);
		}

		cout << "Event not found" << endl;

	        return (false);
	}

	int  DeleteDate (const Date& date) {
		if (!db.count(date))
			return (0);

		int c = db[date].size();
		db.erase(date);

		cout << "Deleted " << c << " events" << endl;

		return (c);
	}

	set<string> Find (const Date& date) const {
		if (db.count(date) > 0)
			return (db.at(date));
		else
			return {};
	}

	void Print () const {
		for (const auto& record : db)
			for (auto& event : record.second)
				cout << FormatDate(record.first.GetYear(), 'y')
					<< "-"
				<< FormatDate(record.first.GetMonth(), 'm')
					<< "-"
				<< FormatDate(record.first.GetDay(), 'd')
					<< " "
				<< event
					<< endl;
	}

private:
	map<Date, set<string>> db;

	Date ParseDate(string date) {
		stringstream stream(date);

		int y;
		stream >> y;

		if (stream.peek() != '-')
			throw logic_error("Wrong date format: " + date);
		// cout << "Year: " << y << endl;
		int m;
		stream.ignore(1);
		stream >> m;

		if (stream.peek() != '-')
			throw logic_error("Wrong date format: " + date);
		// cout << "Month: " << m << endl;
		int d;
		stream.ignore(1);
		stream >> d;

		if (!stream.eof())
			throw logic_error("Wrong date format: " + date);
		// cout << "Day: " << d << endl;

		return (Date(m, d, y));
	}
};

int main (void) {
	Database db;
	string command;

	try
	{
		while (getline(cin, command))
			if (!db.RunCommand(command))
				break;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	return (0);
}
