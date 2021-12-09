#include "Elev.h"
#include "Console.h"

#include <iostream>
#include <string>
#include <stdlib.h> // clear()
#include <thread>
#include <chrono>

int optionMainMenu;
int optionStudentMenu;
int positionStudent;

int age, year, day, month;

long long cnp;

int ct, clasa;

std::string first_name, last_name;

Elev eleviMoisil[800];

int main()
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;

	do
	{
		printOptionsMainMenu();

		std::cin >> optionMainMenu;

		while (!checkDataMainMenu(optionMainMenu))
		{
			tryData();

			std::cin >> optionMainMenu;
		}

		switch (optionMainMenu)
		{

		case 1:
		{
			clear();

			printOptionsStudentMenu();

			std::cin >> optionStudentMenu;

			while (!checkDataStudentnMenu(optionStudentMenu))
			{
				tryData();

				std::cin >> optionStudentMenu;
			}

			switch (optionStudentMenu)
			{
				clear();

			case 1:
			{
				//adauga elev
				if (positionStudent <= 580)
				{
					clear();

					std::cout << "Introduceti prenumele elevei/ elevului: ";

					std::cin >> first_name;

					while (!checkName(first_name))
					{
						ErrorFirstNameLog();

						std::cin >> first_name;
					}

					std::cout << "Introduceti numele elevei/ elevului: ";

					std::cin >> last_name;

					while (!checkName(last_name))
					{
						ErrorLastNameLog();

						std::cin >> last_name;
					}

					std::cout << "Introduceti anul nasterii elevei/ elevului:";

					std::cin >> year;

					while (!checkYear(year))
					{
						ErrorYearLog();

						std::cin >> year;
					}

					std::cout << "Introduceti luna nasterii elevei/ elevului:";

					std::cin >> month;

					while (!checkMonth(month))
					{
						ErrorMonthLog();

						std::cin >> month;
					}

					std::cout << "Introduceti ziua nasterii elevei/ elevului:";

					std::cin >> day;

					while (!checkDay(day, year))
					{
						ErrorDayLog();

						std::cin >> day;
					}

					std::cout << "Introduceti varsta elevei/ elevului: ";

					std::cin >> age;

					while (!checkAge(age))
					{
						ErrorAgeLog();

						std::cin >> age;
					}

					std::cout << "Introduceti cu mare atentie CNP-ul elevei/ elevului: ";

					std::cin >> cnp;

					while (!checkCNP(cnp, year, month, day))
					{
						ErrorCNPLog();

						std::cin >> cnp;
					}

					ct++;

					if (ct % 29 == 0 and clasa < 5)
						clasa++, ct = 0;

					positionStudent++;

					eleviMoisil[positionStudent].firstName = first_name;
					eleviMoisil[positionStudent].lastName = last_name;
					eleviMoisil[positionStudent].YearB = year;
					eleviMoisil[positionStudent].MonthB = month;
					eleviMoisil[positionStudent].DayB = day;
					eleviMoisil[positionStudent].Age = age;
					eleviMoisil[positionStudent].setCNP(cnp);

					if (clasa == 0)
						eleviMoisil[positionStudent].Class = "A";
					else
					{
						if (clasa == 1)
							eleviMoisil[positionStudent].Class = "B";
						else
						{
							if (clasa == 2)
								eleviMoisil[positionStudent].Class = "C";
							else
							{
								if (clasa == 3)
									eleviMoisil[positionStudent].Class = "D";
								else
									eleviMoisil[positionStudent].Class = "E";
							}
						}
					}
					eleviMoisil[positionStudent].printData();
				}
				else
				{
					ErrorAddStudent();
				}

				sleep_for(4s);

				clear();

				break;
			}

			case 2:
			{
				//exmatriculeaza elev pe baza cheii primare - cnp
				if (positionStudent > 0)
				{
					std::cout << "Introduceti CNP-ul elevei/ elevului pe care doriti sa va fi exmatriculat: ";

					std::cin >> cnp;

					bool found = false;

					for (int i = 1; i <= positionStudent; ++i)
					{
						if (eleviMoisil[i].getCNP() == cnp)
						{
							for (int j = i; j < positionStudent; j++)
								eleviMoisil[j] = eleviMoisil[j + 1];

							found = true;
							positionStudent--;
						}
					}
					if (!found)
						ErrorExpelledStudent();
					else
						printConfirmationExpelled();

				}
				else
					ErrorNoData();

				sleep_for(4s);

				clear();

				break;
			}

			case 3:
			{
				break;
			}
			case 4:
			{
				break;
			}
			}
		}

		case 4:
		{
			return 0;
		}

		}
	} while (optionMainMenu);

	return 0;
}