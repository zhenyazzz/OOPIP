#pragma once
#include <iostream>
#include "Student.h"
#include "Professor.h"
#include "Address.h"
class Assistant : public Student, public Professor {
public:
    Assistant(const string& name, const string& phoneNumber, const string& emailAdress, const Address& address, const int& salary, const int& staffNumber,
        const int& yearOfService, const int& numberOfClasses, const int& numberOfStudents, const int& studentNumber, const int& averageMark);
    void printInfo() override;
    Assistant();
    ~Assistant();
    void writeToFile() override;
    friend ostream& operator<<(ostream& os, const Assistant& assistant);
    friend istream& operator>>(istream& is, Assistant& assistant);
};

