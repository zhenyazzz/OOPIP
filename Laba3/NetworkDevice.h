#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class NetworkDevice
{
protected:
    int id;
    string name;
    string ipAddress;
    string location;

public:

    NetworkDevice(const int& id,const string& name, const string& ipAddress, const string& location);
    NetworkDevice();
    void setId(const int& id);
    void setName(const string& name);
    void setIpAddress(const string& ipAddress);
    void setLocation(const string& location);
    int getId() const;
    string getName() const;
    string getIpAddress() const;
    string getLocation() const;

    virtual void print() const = 0;
    virtual void edit() = 0;
    virtual void writeToFile() = 0;
    friend ostream& operator<<(ostream& os, const NetworkDevice& device);
    friend istream& operator>>(istream& is, NetworkDevice& device);

};

