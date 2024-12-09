#pragma once
#include <iostream>
#include "Person.h"
#include "Student.h"
class Professor : public virtual Person {
private:
    int salary;
    int staffNumber;
    int yearOfService;
    int numberOfClasses;
    int numberOfStudents;
public:
    Professor();
    Professor(const string& name, const string& phoneNumber, string emailAdress, const Address& address, const int& salary, const int& staffNumber,
        const int& yearOfService, const int& numberOfClasses, const int& numberOfStudents);
    int getSalary() const;
    int getStaffNumber() const;
    int getYearOfService() const;
    int getNumberOfClasses() const;

    void addStudent(const Student& student);
    void removeStudent(const Student& student);

    void printInfo() override;

    void setSalary(const int& salary);
    void setStaffNumber(const int& staffNumber);
    void setYearOfService(const int& yearOfService);
    void setNumberOfClasses(const int& numberOfClasses);

    void writeToFile() override;
    friend ostream& operator<<(ostream& os, const Professor& professor);
    friend istream& operator>>(istream& is, Professor& professor);
};

