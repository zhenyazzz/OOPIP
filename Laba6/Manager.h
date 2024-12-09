#pragma once
#include <memory>
#include <string>
#include "NetworkDevice.h"
using namespace std;
class Manager
{
public:
    virtual void start() const = 0;

    virtual void addDeviceStack(shared_ptr<NetworkDevice> device) = 0;
    virtual void addDeviceQueue(shared_ptr<NetworkDevice> device) = 0;
    virtual void addDevicePriorityQueue(shared_ptr<NetworkDevice> device) = 0;

    virtual void removeDeviceStack(const string& deviceName) = 0;
    virtual void removeDeviceQueue(const string& deviceName) = 0;
    virtual void removeDevicePriorityQueue(const string& deviceName) = 0;

    virtual void editDeviceStack(const string& deviceName) = 0;
    virtual void editDeviceQueue(const string& deviceName) = 0;
    virtual void editDevicePriorityQueue(const string& deviceName) = 0;

    virtual void searchDeviceStack(const string& deviceName) = 0;
    virtual void searchDeviceQueue(const string& deviceName) = 0;
    virtual void searchDevicePriorityQueue(const string& deviceName) = 0;

    virtual void filterDeviceStack(const string& deviceType) = 0;
    virtual void filterDeviceQueue(const string& deviceType) = 0;
    virtual void filterDevicePriorityQueue(const string& deviceType) = 0;

    virtual void printDeviceStack() = 0;
    virtual void printDeviceQueue() = 0;
    virtual void printDevicePriorityQueue() = 0;

    virtual void writeToFileDeviceStack() = 0;
    virtual void writeToFileDeviceQueue() = 0;
    virtual void writeToFileDevicePriorityQueue() = 0;

    virtual void sortDeviceStack() = 0;
    virtual void sortDeviceQueue() = 0;
    virtual void sortDevicePriorityQueue() = 0;

    virtual ~Manager() = default; 
	
};

