#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

static vector<string> split(const string& s, char delimiter) {
	istringstream tokenStream(s);
	string token;
	vector<string> tokens;

	while (getline(tokenStream, token, delimiter)) {
		tokens.emplace_back(token);
	}

	return tokens;
}

static Degree::DegreeProgram convertToDegreeProgram(string degreeProgram) {
	if (degreeProgram == "SECURITY") return Degree::DegreeProgram::SECURITY;

	if (degreeProgram == "NETWORK") return Degree::DegreeProgram::NETWORK;

	return Degree::DegreeProgram::SOFTWARE;
}

static tuple<string, string, string, string, int, int*, Degree::DegreeProgram>
parseStudentData(const string& studentData) {
	vector<string> studentInfo = split(studentData, ',');
	int daysInCourse[3] = {
		stoi(studentInfo[5]),
		stoi(studentInfo[6]),
		stoi(studentInfo[7])
	};

	return make_tuple(studentInfo[0], studentInfo[1], studentInfo[2], studentInfo[3],
		stoi(studentInfo[4]), daysInCourse, convertToDegreeProgram(studentInfo[8]));
}

static void loadStudents(Roster* classRoster) {
	const string studentData[] = {
		"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99@yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Jesse,Sites,jesse318s@gmail.com,25,50,58,40,SOFTWARE"
	};

	for (const string& data : studentData) {
		auto [studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram] = parseStudentData(data);

		classRoster->add(
			studentID,
			firstName,
			lastName,
			emailAddress,
			age,
			daysInCourse[0],
			daysInCourse[1],
			daysInCourse[2],
			degreeProgram
		);
	}
}

int main() {
	cout << "C++ Tutoring\nJesse Sites" << endl;

	try {
		Roster* classRoster = new Roster();

		loadStudents(classRoster);

		cout << "\nAll students:" << endl;
		classRoster->printAll();

		cout << "\nAverage days in course for each student:" << endl;
		for (Student* student : classRoster->classRosterArray) {
			classRoster->printAverageDaysInCourse(student->getStudentID());
		}

		cout << "\nInvalid emails:" << endl;
		classRoster->printInvalidEmails();

		cout << "\nStudents in the SOFTWARE degree program:" << endl;
		classRoster->printByDegreeProgram(Degree::DegreeProgram::SOFTWARE);

		cout << "\nRemoving student A3..." << endl;
		classRoster->remove("A3");

		cout << "\nAll students:" << endl;
		classRoster->printAll();

		cout << "\nRemoving student A3..." << endl;
		classRoster->remove("A3");

		cout << "\nRemoving all students..." << endl;
		delete classRoster;
	}
	catch (exception& e) {
		cout << "An error occurred: " << e.what() << endl;
	}

	return 0;
}
