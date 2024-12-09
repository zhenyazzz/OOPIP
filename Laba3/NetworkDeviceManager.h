#pragma once
#include <list>
#include <vector>
#include "NetworkDevice.h"
#include <array>
#include "Router.h"
#include "Printer.h"
#include "Modem.h"
#include "Switch.h"
#include <fstream>

using namespace std;
class NetworkDeviceManager
{
private:
    list<NetworkDevice*> deviceList;
    vector<NetworkDevice*> deviceVector;
    array<NetworkDevice*, 100> deviceArray;
    size_t arraySize = 0;
public:
    NetworkDeviceManager();
    ~NetworkDeviceManager();

    double inputDouble();
    int inputInt();
    NetworkDevice* createDevice();
    void addDeviceToList();
    void removeDeviceFromList();
    void editDeviceInList();
    void printList();
    void sortDevicesListName();
    void findDeviceBylistID();
    void saveToFile();
    void loadFromFile();

    void addDeviceToVector();
    void removeDeviceFromVector();
    void editDeviceInVector();
    void printVector();
    void sortDevicesVectorName();
    void findDeviceByVectorID();

    void addDeviceToArray();
    void removeDeviceFromArray();
    void editDeviceInArray();
    void printArray();
    void sortDevicesArrayName();
    void findDeviceByArrayID();

};