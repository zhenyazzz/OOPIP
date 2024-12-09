#pragma once
#include <iostream>
#include "NetworkDevice.h"
#include <fstream>
using namespace std;
class Switch: public NetworkDevice
{
private:

    int portCount;  

public:
    Switch(const int& id,const string& name, const string& ipAddress, const string& location, int ports);
    Switch();
    void setName(const string& name);
    void setIpAddress(const string& ip);
    void setPortCount(int ports);
    void setLocation(const string& location);

    string getName() const;
    string getIpAddress() const;
    string getLocation() const;
    int getPortCount() const;


    void print() const override;
        
    void edit() override;

    friend ofstream& operator<<(ofstream& os, const Switch& s);
    friend ifstream& operator>>(ifstream& is, Switch& s);

    void writeToFile() override;
};

