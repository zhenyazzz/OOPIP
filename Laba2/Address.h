#pragma once
#include <iostream>
using namespace std;
class Address {
private:
    string street;
    string city;
    string state;
    class Country
    {
    public:
        Country(string name);
        ~Country();

        string getName();
        void setName(string name);
        string name;
    };
    Country country;
    int postalCode;

public:
    Address();
    Address(const string& street, const string& city, const string& state, const string& country, const int postalCode);
    ~Address();
    bool validate();
    void outputAsLabel();

    string getStreet() const;
    string getCity() const;
    string getState() const;
    string getCountry() const;
    int getPostalCode() const;
    void setCountryName(const string& countryName);
    void setStreet(const string& street);
    void setCity(const string& city);
    void setState(const string& state);
    void setPostalCode(const int postalCode);


    friend ostream& operator<<(ostream& os, const Address& address);
    friend istream& operator>>(istream& is, Address& address);
};


