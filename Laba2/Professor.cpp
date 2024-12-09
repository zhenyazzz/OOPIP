#include "Professor.h"
#include <iomanip>
Professor::Professor() :Person(), salary(0), staffNumber(0), yearOfService(0), numberOfClasses(0), numberOfStudents(0)
{
}

Professor::Professor(const string& name, const string& phoneNumber, string emailAdress, const Address& address, const int& salary,
	const int& staffNumber, const int& yearOfService, const int& numberOfClasses, const int& numberOfStudents)
	: Person(name, phoneNumber, emailAdress, address), salary(salary), staffNumber(staffNumber), yearOfService(yearOfService),
	numberOfClasses(numberOfClasses), numberOfStudents(numberOfStudents) { }

int Professor::getSalary() const
{
	return salary + (numberOfClasses + numberOfStudents) * yearOfService;
}

int Professor::getStaffNumber() const
{
	return staffNumber;
}

int Professor::getYearOfService() const
{
	return yearOfService;
}

int Professor::getNumberOfClasses() const
{
	return numberOfClasses;
}

void Professor::addStudent(const Student& student)
{
	numberOfStudents++;
}

void Professor::removeStudent(const Student& student)
{
	numberOfStudents--;
}

void Professor::printInfo() {
	Person::printInfo();
	cout.setf(ios::left);
	cout << setw(20) << "Зарплата: " << getSalary() << endl;
	cout << setw(20) << "Номер сотрудника: " << staffNumber << endl;
	cout << setw(20) << "Стаж работы: " << yearOfService << endl;
	cout << setw(20) << "Количество классов: " << numberOfClasses << endl;
	cout << setw(20) << "Количество студентов: " << numberOfStudents << endl;
	cout.unsetf(ios::left);
}

void Professor::setSalary(const int& salary)
{
	this->salary = salary;
}

void Professor::setStaffNumber(const int& staffNumber)
{
	this->staffNumber = staffNumber;
}

void Professor::setYearOfService(const int& yearOfService)
{
	this->yearOfService = yearOfService;
}

void Professor::setNumberOfClasses(const int& numberOfClasses)
{
	this->numberOfClasses = numberOfClasses;
}

void Professor::writeToFile()
{
	ofstream file("professors.dat", ios::out | ios::binary);
	if (file.is_open()) {
		file << *this;
		cout << "Успешная запись в файл" << endl;
		file.close();
	}
	else {
		cerr << "Unable to open file for writing." << endl;
	}
}

ostream& operator<<(ostream& os, const Professor& professor)
{
	
	os << static_cast<const Person&>(professor);
	os.write(reinterpret_cast<const char*>(&professor.salary), sizeof(professor.salary));	
	os.write(reinterpret_cast<const char*>(&professor.staffNumber), sizeof(professor.staffNumber));	
	os.write(reinterpret_cast<const char*>(&professor.yearOfService), sizeof(professor.yearOfService));
	os.write(reinterpret_cast<const char*>(&professor.numberOfClasses), sizeof(professor.numberOfClasses));
	os.write(reinterpret_cast<const char*>(&professor.numberOfStudents), sizeof(professor.numberOfStudents));

	return os;
}

istream& operator>>(istream& is, Professor& professor)
{

	is >> static_cast<Person&>(professor);
	is.read(reinterpret_cast<char*>(&professor.salary), sizeof(professor.salary));
	is.read(reinterpret_cast<char*>(&professor.staffNumber), sizeof(professor.staffNumber));
	is.read(reinterpret_cast<char*>(&professor.yearOfService), sizeof(professor.yearOfService));
	is.read(reinterpret_cast<char*>(&professor.numberOfClasses), sizeof(professor.numberOfClasses));
	is.read(reinterpret_cast<char*>(&professor.numberOfStudents), sizeof(professor.numberOfStudents));

	return is;
}
