#include "Elev.h"
#include "Console.h"

#include <iostream>
#include <string>
#include <conio.h>

//console
void InitLog()
{
	Log("Initializing Log");
}

void Log(const char* message)
{
	std::cout << message << std::endl;
}

void clear()
{
	system("CLS");
}

//options print
void printOptionsMainMenu()
{
	std::cout << "Introduceti unul din numerele de mai jos pentru : " << '\n';
	std::cout << "1. Elevi" << '\n';
	std::cout << "2. Profesori" << '\n';
	std::cout << "3. Scoala" << '\n';
	std::cout << "4. Exit" << '\n';
}

void printOptionsStudentMenu()
{
	std::cout << "Introduceti unul din numerele de mai jos pentru : " << '\n';
	std::cout << "1. Adauga elev" << '\n';
	std::cout << "2. Exmatriculeaza elev" << '\n';
	std::cout << "3. Verifica elev in baza de date" << '\n';
	std::cout << "4. Exit" << '\n';
}

//valid logs
void printConfirmationExpelled()
{
	std::cout << "Elevul a fost exmatriculat cu succes!" << '\n';
}

//error logs
void tryData()
{
	std::cout << "Optiune incorecta! Introduceti o optiune din intervalul [1,4]." << '\n';
}

void ErrorFirstNameLog()
{
	std::cout << "Nume incorect! Introduceti prenumele din nou doar cu prima litera mare." << '\n';
}

void ErrorLastNameLog()
{
	std::cout << "Nume incorect! Introduceti numele de familie din nou doar cu prima litera mare." << '\n';
}

void ErrorAgeLog()
{
	std::cout << "Varsta incorecta! Introduceti varsta din nou, care este cuprinsa intre 14-20." << '\n';
}

void ErrorDayLog()
{
	std::cout << "Ziua incorecta! Introduceti ziua in care s-a nascul eleva/ elevul din nou." << '\n';
}

void ErrorMonthLog()
{
	std::cout << "Luna incorecta! Introduceti luna in care s-a nascul eleva/ elevul din nou." << '\n';
}

void ErrorYearLog()
{
	std::cout << "An incorect! Introduceti anul in care s-a eleva/ elevul elevul din nou." << '\n';
}

void ErrorAddStudent()
{
	std::cout << "Nu mai exista locuri disponile in Liceul Teoretic Grigore Moisil!.";
}

void ErrorCNPLog()
{
	std::cout << "CNP incorect! Introduceti CNP-ul din nou." << '\n';
}

void ErrorExpelledStudent()
{
	std::cout << "Nu exista elevul in baza de date. Incercati din nou sa introduceti CNP-ul!" << '\n';
}

void ErrorNoData()
{
	std::cout << "Nu exista elevi inscrisi in scoala pentru a putea fi exmatriculati!" << '\n';
}

//input data check
bool checkDataMainMenu(int optiune)
{
	return (optiune >= 1 and optiune <= 4);
}
bool checkDataStudentnMenu(int optiune)
{
	return (optiune >= 1 and optiune <= 4);
}

//input data check for elev
bool checkName(std::string name)
{
	if (islower(name[0]))
		return false;

	for (unsigned int i = 1; i < name.size(); ++i)
		if (isupper(name[i]) or isdigit(name[i]) or !(name[i] >= 'a' and name[i] <= 'z'))
			return false;

	return true;
}

bool checkDay(int d, int y)
{
	switch (d)
	{
	case 1:
	{
		return (d >= 1 and d <= 31);
		break;
	}

	case 2:
	{
		if (y == 2003 or y == 2005 or y == 2006 or y == 2007)
			return (d >= 1 and d <= 28);
		else
			return (d >= 1 and d <= 29);
		break;
	}

	case 3:
	{
		return (d >= 1 and d <= 31);

		break;
	}

	case 4:
	{
		return (d >= 1 and d <= 30);

		break;
	}

	case 5:
	{
		return (d >= 1 and d <= 31);

		break;
	}

	case 6:
	{
		return (d >= 1 and d <= 30);

		break;
	}

	case 7:
	{
		return (d >= 1 and d <= 31);

		break;
	}

	case 8:
	{
		return (d >= 1 and d <= 31);

		break;
	}

	case 9:
	{
		return (d >= 1 and d <= 30);

		break;
	}

	case 10:
	{
		return (d >= 1 and d <= 31);

		break;
	}

	case 11:
	{
		return (d >= 1 and d <= 30);

		break;
	}

	case 12:
	{
		return (d >= 1 and d <= 31);

		break;
	}
	}
	return true;
}

bool checkMonth(int m)
{
	return (m >= 1 and m <= 12);
}

bool checkYear(int y)
{
	return (y >= 2002 and y <= 2008);
}

bool checkAge(int age)
{
	return (age >= 14 and age <= 20);
}

//elev functions
void Elev::printData()
{
	std::cout << "Eleva/ Elevul " << firstName << ' ' << lastName << " din clasa " << Class << " a fost adaugat in Liceul Teoretic Grigore Moisil." << '\n';
}

void Elev::setCNP(long long x)
{
	CNP = x;
}

long long Elev::getCNP()
{
	return CNP;
}

bool checkCNP(long long x, int an, int luna, int zi)
{
	int v[14] = { 0 };

	int k = 0;

	while (x)
	{
		int digit = x % 10;

		v[k++] = digit;

		x /= 10;
	}

	if (v[5] != 3 or v[4] != 5)
		return false;

	if (zi < 10 and (v[7] != 0 or v[6] != zi))
		return false;
	else
		if (zi > 9 and (v[7] != (zi / 10) % 10 or v[6] != zi % 10))
			return false;

	if (luna < 10 and (v[9] != 0 or v[8] != luna))
		return false;
	else
		if (luna > 9 and (v[9] != (luna / 10) % 10 or v[8] != luna % 10))
			return false;

	if (v[11] != (an / 10) % 10 or v[10] != an % 10)
		return false;

	return true;
}

