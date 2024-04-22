#pragma once
#include <string>
#include "student.h"
#include "degree.h"

class Roster {
public:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	int lastIndex = -1;
	int capacity = 5;

	~Roster();

	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree::DegreeProgram degreeProgram);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree::DegreeProgram degreeProgram);
};

