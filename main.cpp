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

	kajar.setSubjectgrade();


	kajar.getStudentGPA();
	

	return 0;
}