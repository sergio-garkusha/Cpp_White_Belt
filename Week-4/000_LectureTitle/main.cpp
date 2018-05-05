#include <string>
#include <iostream>
using namespace std;

struct Specialization {
	string value;
	explicit Specialization(string new_val) {
		value = new_val;
	}
};

struct Course {
	string value;
	explicit Course(string new_val) {
		value = new_val;
	}
};

struct Week {
	string value;
	explicit Week(string new_val) {
		value = new_val;
	}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(Specialization new_spec,
			Course new_course, Week new_week) {
		specialization = new_spec.value;
		course = new_course.value;
		week = new_week.value;
	}
};
