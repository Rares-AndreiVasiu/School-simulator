#pragma once

//console 
void Log(const char* message);

void InitLog();

void clear();

//options print
void printOptionsMainMenu();

void printOptionsStudentMenu();

//input data check
bool checkDataMainMenu(int optiune);

bool checkDataStudentnMenu(int optiune);

//valid logs
void printConfirmationExpelled();

//error logs
void tryData();

void ErrorFirstNameLog();

void ErrorLastNameLog();

void ErrorAgeLog();

void ErrorDayLog();

void ErrorMonthLog();

void ErrorYearLog();

void ErrorAddStudent();

void ErrorCNPLog();

void ErrorExpelledStudent();

void ErrorNoData();