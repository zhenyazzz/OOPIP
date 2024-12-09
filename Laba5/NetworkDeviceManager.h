#pragma once
#include "NetworkDevice.h"
#include "Router.h"
#include "Printer.h"
#include "Modem.h"
#include <fstream>
#include <queue>
#include <stack>
#include <memory>

using namespace std;
class NetworkDeviceManager
{
private:
    stack<shared_ptr<NetworkDevice>> deviceStack;
    queue<shared_ptr<NetworkDevice>> deviceQueue;
    priority_queue<shared_ptr<NetworkDevice>, vector<shared_ptr<NetworkDevice>>, NetworkDevice::CompareNetworkDevice> devicePriorityQueue;
public:
    NetworkDeviceManager();
    ~NetworkDeviceManager();

    double inputDouble();
    int inputInt();
    void addDeviceStack(shared_ptr<NetworkDevice> device);
    void addDeviceQueue(shared_ptr<NetworkDevice> device);
    void addDevicePriorityQueue(shared_ptr<NetworkDevice> device);
    

    void removeDeviceStack(const string& deviceName);
    void removeDeviceQueue(const string& deviceName);
    void removeDevicePriorityQueue(const string& deviceName);
  
    
    void editDeviceStack(const string& deviceName);
    void editDeviceQueue(const string& deviceName);
    void editDevicePriorityQueue(const string& deviceName);

    void searchDeviceStack(const string& deviceName);
    void searchDeviceQueue(const string& deviceName);
    void searchDevicePriorityQueue(const string& deviceName);
   

    void filterDeviceStack(const string& deviceType);
    void filterDeviceQueue(const string& deviceType);
    void filterDevicePriorityQueue(const string& deviceType);
 

    void printDeviceStack();
    void printDeviceQueue();
    void printDevicePriorityQueue();
   

    void writeToFileDeviceStack();
    void writeToFileDeviceQueue();
    void writeToFileDevicePriorityQueue();
  
    void sortDeviceStack();
    void sortDeviceQueue();
    void sortDevicePriorityQueue();
};

