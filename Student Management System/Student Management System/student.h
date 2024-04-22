#pragma once
#include <string>
#include "degree.h"

class Student {
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysInCourse[3];
	Degree::DegreeProgram degreeProgram;

public:
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress,
		int age, int daysInCourse[], Degree::DegreeProgram degreeProgram);

	std::string getStudentID();
	std::string getFirstName();
	std::string getLastName();
	std::string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	Degree::DegreeProgram getDegreeProgram();
	void setStudentID(std::string studentID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmailAddress(std::string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(Degree::DegreeProgram degreeProgram);
	void print();
};

