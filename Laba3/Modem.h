#pragma once
#include <iostream>
#include "NetworkDevice.h"
#include <fstream>
using namespace std;
class Modem: public NetworkDevice
{
private:
    int speed;  

public:
    Modem(const int& id, const string& name, const string& ip,const string& location, int sp);
    Modem();
    void setName(const string& name);
    void setIpAddress(const string& ip);
    void setSpeed(int speed);
    void setLocation(const string& location);

    string getName() const;
    string getIpAddress() const;
    int getSpeed() const;
    string getLocation() const;

    void print() const override;
    void edit() override;
    
    friend ofstream& operator<<(ofstream& os, const Modem& m);
    friend ifstream& operator>>(ifstream& is, Modem& m);

    void writeToFile() override;
};

