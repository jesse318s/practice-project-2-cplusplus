#pragma once
#include <string>

class Degree {
public:
	enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };

	static std::string toString(DegreeProgram degreeProgram) {
		if (degreeProgram == SECURITY) return "SECURITY";

		if (degreeProgram == NETWORK) return "NETWORK";

		if (degreeProgram == SOFTWARE) return "SOFTWARE";

		return "UNKNOWN";
	}
};