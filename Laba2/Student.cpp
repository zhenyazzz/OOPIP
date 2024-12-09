#include "Student.h"
#include <iomanip>
Student::Student() :Person(), studentNumber(0), averageMark(0)
{
}

Student::Student(const string& name, const string& phoneNumber, const string& emailAdress, const Address& address, const int& studentNumber, const int& averageMark)
	: Person(name, phoneNumber, emailAdress, address), studentNumber(studentNumber), averageMark(averageMark) {}

Student::~Student()
{
}

int Student::getStudentNumber() const
{
	return studentNumber;
}

int Student::getAverageMark() const
{
	return averageMark;
}

void Student::printInfo()
{
	Person::printInfo();
    cout.setf(ios::left);

    cout << setw(20) << "Номер студента: " << studentNumber << endl;
    cout << setw(20) << "Средняя оценка: " << averageMark << endl;

    cout.unsetf(ios::left);
}

void Student::setStudentNumber(const int& studentNumber)
{
	this->studentNumber = studentNumber;
}

void Student::setAverageMark(const int& averageMark)
{
	this->averageMark = averageMark;
}

bool Student::isEligibleToEnroll(string& str)
{
	if (str == "верующий") return true;
	else return false;
}

void Student::writeToFile()
{
    ofstream file("students.dat", ios::out | ios::binary);
    if (file.is_open()) {
        file << *this;
        cout << "Успешная запись в файл" << endl;
        file.close();
    }
    else {
        cerr << "Unable to open file for writing." << endl;
    }
}



ostream& operator<<(ostream& os, const Student& student)
{
    os << static_cast<const Person&>(student);

  
    os.write(reinterpret_cast<const char*>(&student.studentNumber), sizeof(student.studentNumber));
    os.write(reinterpret_cast<const char*>(&student.averageMark), sizeof(student.averageMark));

    return os;
}

istream& operator>>(istream& is, Student& student)
{
    is >> static_cast<Person&>(student);
    is.read(reinterpret_cast<char*>(&student.studentNumber), sizeof(student.studentNumber));
    is.read(reinterpret_cast<char*>(&student.averageMark), sizeof(student.averageMark));


    return is;
}
