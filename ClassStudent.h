#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "invalid_input.h"
#include "grade_calculator.h"


// This seems to be a stupid way to do this...
void getGPA(std::vector<std::pair<std::string, double>> studentGradesAndCredits);

class Student
{
public:
	Student() 
		: m_name{ setName() }, m_studentScores{ createVectorForSubjects() }
	{
	};

	std::string setName()
	{
		std::cout << "Enter name: ";
		std::string name{};
		std::getline(std::cin >> std::ws, name);

		return name;
	}


	// tried just pulling it in like this.. should it all be in this class in all reality?
	void getStudentGPA()
	{
		getGPA(m_studentScores);
	}

	// creates a pair vector with the capacity of user input
	std::vector<std::pair<std::string, double>> createVectorForSubjects()
	{
		int numSubjects{};

		while (true)
		{
			std::cout << "Enter number of subjects: ";

			std::cin >> numSubjects;
			if (numSubjects < 0)
			{
				std::cout << "Number of subjects can't be less than 0. Please try again.\n";
				ignoreLine();
				continue;
			}

			if (clearFailedExtraction())
			{
				std::cout << "You must enter an integer. Please try again.\n";
				continue;
			}


			break;
		}

		ignoreLine();
		return std::vector <std::pair<std::string, double>>(static_cast<uint64_t>(numSubjects));

	}

	void getVectorInfo()
	{
		std::cout << "vector size: " << m_studentScores.size() << " vector capacity: " << m_studentScores.capacity();
	}

	std::string_view getName()
	{
		return m_name;
	}

	void setSubjectgrade()
	{
				
		for (uint64_t index{ 0 }; index < m_studentScores.size(); ++index)
		{
			std::cout << "\nEnter grade for subject #" << index + 1<< ": ";
			std::string grade{m_getGrade()};
			
			std::cout << "\nEnter credit for subject #" << index + 1 << ": ";
			double credit{m_getCredit()};
			
			m_studentScores[index].first = grade;
			m_studentScores[index].second = credit;

			//std::cout << "\n---> grade: " << m_studentScores[index].first <<
				//" ---> credit: " << m_studentScores[index].second;
		}
	}

private:
	std::string m_name{ "No data" };
	std::vector<std::pair<std::string, double>> m_studentScores{};
	int m_id{0}; // Sooooo.... I'm not doing anything with this right now 


	std::string m_getGrade()
	{
		std::string grade{};

		while (true)
		{
			std::cout << "Enter grade: ";
			std::cin >> grade;
			
			// should i be user friendly and transform lowercase to uppercase??

			// need to check if input is a valid grade

			if (grade == "A+") break;
			else if (grade == "A") break;
			else if (grade == "A-") break;
			else if (grade == "B+") break;
			else if (grade == "B") break;
			else if (grade == "B-") break;
			else if (grade == "C+") break;
			else if (grade == "C") break;
			else if (grade == "C-") break;
			else if (grade == "D+") break;
			else if (grade == "D") break;
			else if (grade == "D-") break;
			else if (grade == "F") break;

			if (clearFailedExtraction())
			{
				std::cout << "You must enter a valid grade. Please try again.\n";
				continue;
			}

			std::cout << "You must enter a valid grade. Please try again.\n";
			ignoreLine();
			continue;
		}

		ignoreLine();
		return grade;
	}


	double m_getCredit()
	{
		double credit{};

		while (true)
		{
			std::cout << "Enter credit: ";

			std::cin >> credit;
			if (credit < 0)
			{
				std::cout << "Credit can't be less than 0. Please try again.\n";
				ignoreLine();
				continue;
			}

			if (clearFailedExtraction())
			{
				std::cout << "You must enter a number. Please try again.\n";
				continue;
			}

			break;
		}

		ignoreLine();
		return credit;
	}
};