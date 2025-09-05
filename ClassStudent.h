#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "invalid_input.h"


class Student
{
public:
	Student() 
		: m_name{ setName() }, m_studentScores{ createVectorForSubjects() }
	{
	};
	//~Student();

	std::string setName()
	{
		std::cout << "Enter name: ";
		std::string name{};
		std::getline(std::cin >> std::ws, name);

		return name;
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

		std::cout << m_studentScores[0][0];
		/*for (auto index : m_studentScores)
		{
			std::cout << "Enter grade for " << index << ": ";
		}*/
	}

private:
	std::string m_name{ "No data" };
	std::vector<std::pair<std::string, double>> m_studentScores{};
	int m_id{0};
	
	
	

};

//Student::Student() 
//	: m_name {setName()}, m_studentScores{createVectorForSubjects()}
//{
//}
//
//Student::~Student()
//{
//}
