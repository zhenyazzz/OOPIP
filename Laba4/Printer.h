#pragma once
#include <iostream>
#include "NetworkDevice.h"
#include <fstream>
using namespace std;
class Printer : public NetworkDevice
{
private:
    bool isColor;
    int paperCount;
    const string type = "Printer";
public:
    Printer(const int& id, const string& name, const string& ipAddress, const string& location, bool color, int paper);
    Printer();
    ~Printer();
    void setName(const string& name);
    void setIpAddress(const string& ip);
    void setIsColor(bool color);
    void setPaperCount(int paper);

    string getName() const;
    string getIpAddress() const;
    bool getIsColor() const;
    int getPaperCount() const;
    string getType() override;
    void print() const override;

    void edit() override;
    
    friend ofstream& operator<<(ofstream& os, const Printer& p);
    friend ifstream& operator>>(ifstream& is, Printer& p);

    void writeToFile() override;
    void writeToFile(const string& name) override;

    shared_ptr<NetworkDevice> clone() const override;
};


