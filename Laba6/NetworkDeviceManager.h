#pragma once
#include "NetworkDevice.h"
#include "Router.h"
#include "Printer.h"
#include "Modem.h"
#include <fstream>
#include <queue>
#include <stack>
#include <memory>
#include "Manager.h"

using namespace std;
class NetworkDeviceManager: public Manager
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
    void addDeviceStack(shared_ptr<NetworkDevice> device) override;
    void addDeviceQueue(shared_ptr<NetworkDevice> device) override;
    void addDevicePriorityQueue(shared_ptr<NetworkDevice> device) override;

    void removeDeviceStack(const string& deviceName) override;
    void removeDeviceQueue(const string& deviceName) override;
    void removeDevicePriorityQueue(const string& deviceName) override;

    void editDeviceStack(const string& deviceName) override;
    void editDeviceQueue(const string& deviceName) override;
    void editDevicePriorityQueue(const string& deviceName) override;

    void searchDeviceStack(const string& deviceName) override;
    void searchDeviceQueue(const string& deviceName) override;
    void searchDevicePriorityQueue(const string& deviceName) override;

    void filterDeviceStack(const string& deviceType) override;
    void filterDeviceQueue(const string& deviceType) override;
    void filterDevicePriorityQueue(const string& deviceType) override;

    void printDeviceStack() override;
    void printDeviceQueue() override;
    void printDevicePriorityQueue() override;

    void writeToFileDeviceStack() override;
    void writeToFileDeviceQueue() override;
    void writeToFileDevicePriorityQueue() override;

    void sortDeviceStack() override;
    void sortDeviceQueue() override;
    void sortDevicePriorityQueue() override;

    void start() const override;
};

