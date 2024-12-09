#pragma once
#include <iostream>
#include "Address.h"
#include <fstream>
using namespace std;
class Person {
private:
    string name;
    string phoneNumber;
    string emailAddress;
    Address address;

public:
    Person();
    Person(const string& name, const string& phoneNumber, string emailAddress, const Address& address);
    virtual ~Person();
    void purchaseParkingPass();
    string getName() const;
    string getPhoneNumber() const;
    string getEmailAddress() const;
    Address getAddress() const;
    virtual void printInfo();
    void setName(const string& name);
    void setPhoneNumber(const string& phoneNumber);
    void setEmailAddress(const string& emailAddress);
    void setAddress(Address address);
    friend ostream& operator<<(ostream& os, const Person& person);
    friend istream& operator>>(istream& is, Person& person);
    virtual void writeToFile();
};

