#include <iostream>
#include <vector>
#include <limits>
#include "ClassStudent.h"
#include "invalid_input.h"





int main()
{

	Student kajar{};

	std::cout << "Student name: " << kajar.getName() << '\n';
	kajar.getVectorInfo();

	std::cout << '\n';

	kajar.setSubjectgrade(); // error: jeg tror det er fordi jeg forsøger at printe "pair<>". Må undersøge dette.
	/*
	* 1. How many subjects ?
	* -> make a std::vector in that size.
	* 2. For each subject:
	*		1. What was your grade
	*		1.1 Convert Char grade to int score
	*		2. What was the credit
	* 
	* 3. Put into the formula
	*/ 
	

	return 0;
}