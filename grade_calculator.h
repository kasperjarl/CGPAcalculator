#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "grade_calculator.h"
#include "invalid_input.h"
#include "ClassStudent.h"



enum string_code {
	Aplus,
	A,
	Aminus,
	Bplus,
	B,
	Bminus,
	Cplus,
	C,
	Cminus,
	Dplus,
	D,
	Dminus,
	F,
	notfound,
};


string_code hashit(std::string const& inString)
{
	if (inString == "A+") return Aplus;
	if (inString == "A") return A;
	if (inString == "A-") return Aminus;

	return notfound;
}

template <typename T>
double getGradeDouble(T grade)
{
	switch (grade)
	{
	case Aplus: return 4.0;
	case A: return 3.9;
	case Aminus: return 3.5;


	}
	return 0.0;
}


double getGPA(std::vector<std::pair<std::string, double>> studentGradesAndCredits)
{
	for (uint64_t index{ 0 }; index < studentGradesAndCredits.size(); ++index)
	{
		// I need the GPA for each letter grade
		// then I need to store the GPA
		// 
		// I need to store the credits

		// then I need to calculate the total GPA
	}
}