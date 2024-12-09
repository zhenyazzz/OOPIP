#pragma once
#include <iostream>
#include "Person.h"
class Student : public virtual Person {
private:
    int studentNumber;
    int averageMark;
public:
    Student();
    Student(const string& name, const string& phoneNumber, const string& emailAdress, const Address& address, const int& studentNumber, const int& averageMark);
    ~Student();
    int getStudentNumber() const;
    int getAverageMark() const;
    void printInfo() override;
    void setStudentNumber(const int& studentNumber);
    void setAverageMark(const int& averageMark);
    bool isEligibleToEnroll(string& str);
    void writeToFile() override;
    friend ostream& operator<<(ostream& os, const Student& student);
    friend istream& operator>>(istream& is, Student& student);

};

