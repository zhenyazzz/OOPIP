#pragma once
#include <iostream>
#include "NetworkDevice.h"
#include <fstream>
using namespace std;
class Router: public NetworkDevice
{
private:
    int portCount;

public:
    Router(const int& id, const string& name, const string& ipAddress, const string& location, int ports);
    Router();
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

    friend ofstream& operator<<(ofstream& os, const Router& r);
    friend ifstream& operator>>(ifstream& is, Router& r);

    void writeToFile() override;
};

