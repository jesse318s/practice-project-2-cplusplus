#include <string>
#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"

using namespace std;

Roster::~Roster() {
	for (int i = 0; i <= lastIndex; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram) {
	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

	if (lastIndex < capacity - 1) {
		lastIndex++;
		classRosterArray[lastIndex] = student;
	}
}

void Roster::remove(string studentID) {
	bool found = false;

	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			found = true;
			break;
		}
	}

	if (!found) cout << "Student not found." << endl;
}

void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr) classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;

	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
			found = true;

			int* days = classRosterArray[i]->getDaysInCourse();

			cout << "Average days in course for student " << studentID << ": " << (days[0] + days[1] + days[2]) / 3 << endl;
			break;
		}
	}

	if (!found) cout << "Student not found." << endl;
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] == nullptr) continue;

		string email = classRosterArray[i]->getEmailAddress();

		if (email.find('@') == string::npos || email.find('.') == string::npos
			|| email.find(' ') != string::npos) cout << email << endl;
	}
}

void Roster::printByDegreeProgram(Degree::DegreeProgram degreeProgram) {
	for (int i = 0; i <= lastIndex; i++) {
		if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
}