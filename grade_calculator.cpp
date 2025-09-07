#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "grade_calculator.h"
#include "invalid_input.h"
#include "ClassStudent.h"


enum gradesCode {
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



gradesCode hashit(std::string const& inString)
{
	if (inString == "A+") return Aplus;
	else if (inString == "A") return A;
	else if (inString == "A-") return Aminus;
	else if (inString == "B+") return Bplus;
	else if (inString == "B") return B;
	else if (inString == "B-") return Bminus;
	else if (inString == "C+") return Cplus;
	else if (inString == "C") return C;
	else if (inString == "C-") return Cminus;
	else if (inString == "D+") return Dplus;
	else if (inString == "D") return D;
	else if (inString == "D-") return Dminus;
	else if (inString == "F") return F;
	
	return notfound;
}

template <typename T>
double getGradeDouble(T grade)
{
	switch (grade)
	{
	case Aplus: return 4.0;
	case A: return 3.9;
	case Aminus: return 3.7;
	case Bplus: return 3.3;
	case B: return 3.0;
	case Bminus: return 2.7;
	case Cplus: return 2.3;
	case C: return 2.0;
	case Cminus: return 1.7;
	case Dplus: return 1.3;
	case D: return 1.0;
	case Dminus: return 0.7;
	case F: return 0.0;
	default: 
		std::cout << "No grade found. Returning 404"; 
		return 404;
	}
}

// This *should* get the points from the two helper funcs..
double getGradePoints(std::string letterGrade)
{
	return getGradeDouble(hashit(letterGrade));
}


void getGPA(std::vector<std::pair<std::string, double>> studentGradesAndCredits)
{

	/*
	
	Formula is simplified as:

	numerator	= Gradepoints x Credits
	denominator	= credits 
	
	*/
	double numerator{};
	double denominator{};
	for (uint64_t index{ 0 }; index < studentGradesAndCredits.size(); ++index)
	{
				
		numerator += getGradePoints(studentGradesAndCredits[index].first) * studentGradesAndCredits[index].second;

		denominator += studentGradesAndCredits[index].second;
	}

	std::cout << "Your GPA is: " numerator / denominator << "\nBye";
}
