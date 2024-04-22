#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"

using namespace std;

Student::Student(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse[], Degree::DegreeProgram degreeProgram)
	: studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress),
	age(age), degreeProgram(degreeProgram) {
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

int* Student::getDaysInCourse() {
	return daysInCourse;
}

Degree::DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::setDegreeProgram(Degree::DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	cout << studentID << "\t";
	cout << "First Name: " << firstName << "\t";
	cout << "Last Name: " << lastName << "\t";
	cout << "Age: " << age << "\t";
	cout << "daysInCourse: {" << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << "}\t";
	cout << "Degree Program: " << Degree::toString(degreeProgram) << endl;
}
