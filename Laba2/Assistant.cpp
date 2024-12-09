#include "Assistant.h"
#include <iomanip>
Assistant::Assistant(const string& name, const string& phoneNumber, const string& emailAdress, const Address& address, const int& salary, const int& staffNumber,
	const int& yearOfService, const int& numberOfClasses, const int& numberOfStudents, const int& studentNumber, const int& averageMark)
	:Professor(name, phoneNumber, emailAdress, address, salary, staffNumber, yearOfService, numberOfClasses, numberOfStudents),
	Student(name, phoneNumber, emailAdress, address, studentNumber, averageMark), Person(name, phoneNumber, emailAdress, address) {}

void Assistant::printInfo()
{
	Professor::printInfo();
	cout.setf(ios::left);

	cout << setw(20) << "Номер студента: " << getStudentNumber() << endl;
	cout << setw(20) << "Средняя оценка: " << getAverageMark() << endl;

	cout.unsetf(ios::left);

}

Assistant::Assistant() :Professor(), Student(), Person()
{
}

Assistant::~Assistant()
{
}

void Assistant::writeToFile()
{
	ofstream file("assistants.dat", ios::out | ios::binary);
	if (file.is_open()) {
		file << *this;
		cout << "Успешная запись в файл" << endl;
		file.close();
	}
	else {
		cerr << "Unable to open file for writing." << endl;
	}
}

ostream& operator<<(ostream& os, const Assistant& assistant)
{
	os << static_cast<const Student&>(assistant);
	os << static_cast<const Professor&>(assistant);
	return os;
}

istream& operator>>(istream& is, Assistant& assistant)
{
	is >> static_cast<Student&>(assistant);
	is >> static_cast<Professor&>(assistant);

	return is;
}
