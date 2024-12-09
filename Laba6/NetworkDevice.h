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
    const string type = "Device";
public:

    NetworkDevice(const int& id, const string& name, const string& ipAddress, const string& location);
    NetworkDevice();
    virtual ~NetworkDevice();
    void setId(const int& id);
    void setName(const string& name);
    void setIpAddress(const string& ipAddress);
    void setLocation(const string& location);
    int getId() const;
    string getName() const;
    string getIpAddress() const;
    string getLocation() const;

    class CompareNetworkDevice {
    public:
        bool operator()(shared_ptr<NetworkDevice> a, shared_ptr<NetworkDevice> b) {
            return a->getName() > b->getName();
        }
    };
    virtual void print() const = 0;
    virtual void edit() = 0;
    virtual void writeToFile() = 0;
    virtual string getType() = 0;
    virtual shared_ptr<NetworkDevice> clone() const = 0;
    friend ostream& operator<<(ostream& os, const NetworkDevice& device);
    friend istream& operator>>(istream& is, NetworkDevice& device);

};



