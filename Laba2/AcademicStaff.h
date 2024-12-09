#pragma once
#include "Person.h"
#include <iostream>
#include <vector>

using namespace std;

class AcademicStaff
{
private:
	vector<Person*> persons;
	string filename;
public:
	AcademicStaff(const string& filleName);
	~AcademicStaff();
	void addPerson();
	void removePerson();
	void printAcademicStaff();
	void writeToFile();
	void readFromFile();
	void deleteFromFile();
	void editInFile();
	void searchInFile();
};

