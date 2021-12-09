#pragma once

#include <string>

class Elev
{
public:
	std::string firstName;
	std::string lastName;
	std::string Class;
	int Age;
	int DayB;
	int MonthB;
	int YearB;
private:
	long long CNP;

public:
	void setCNP(long long x);

	long long getCNP();

	void printData();

	Elev()
	{
		firstName = "";
		lastName = "";
		Class = "";

		Age = 0;
		DayB = 0;
		MonthB = 0;
		YearB = 0;
		CNP = 0;
	}
};

//input data check for elev
bool checkName(std::string name);

bool checkAge(int age);

bool checkDay(int d, int y);

bool checkMonth(int m);

bool checkYear(int y);

bool checkCNP(long long x, int an, int luna, int zi);

