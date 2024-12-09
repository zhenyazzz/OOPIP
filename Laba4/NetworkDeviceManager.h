#pragma once
#include "NetworkDevice.h"
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include "Router.h"
#include "Printer.h"
#include "Modem.h"
#include <fstream>
#include <memory>

using namespace std;
class NetworkDeviceManager
{
private:
    map<string, shared_ptr<NetworkDevice>> deviceMap;
    set<shared_ptr<NetworkDevice>> deviceSet;
    multimap<string, shared_ptr<NetworkDevice>> deviceMultimap;
    multiset<shared_ptr<NetworkDevice>> deviceMultiset;
    unordered_map<string, shared_ptr<NetworkDevice>> deviceUnorderedMap;
    unordered_set<shared_ptr<NetworkDevice>> deviceUnorderedSet;
    unordered_multimap<string, shared_ptr<NetworkDevice>> deviceUnorderedMultimap;
    unordered_multiset<shared_ptr<NetworkDevice>> deviceUnorderedMultiset;
public:
    NetworkDeviceManager();
    ~NetworkDeviceManager();

    double inputDouble();
    int inputInt();
    void addDeviceMap(shared_ptr<NetworkDevice>);
    void addDeviceSet(shared_ptr<NetworkDevice>);
    void addDeviceMultimap(shared_ptr<NetworkDevice>);
    void addDeviceMultiSet(shared_ptr<NetworkDevice>);
    void addDeviceUmap(shared_ptr<NetworkDevice>);
    void addDeviceUset(shared_ptr<NetworkDevice>);
    void addDeviceUmultimap(shared_ptr<NetworkDevice>);
    void addDeviceUmultiset(shared_ptr<NetworkDevice>);

    void removeDeviceMap(const string& deviceName);
    void removeDeviceSet(const string& deviceName);
    void removeDeviceMultimap(const string& deviceName);
    void removeDeviceMultiSet(const string& deviceName);
    void removeDeviceUmap(const string& deviceName);
    void removeDeviceUset(const string& deviceName);
    void removeDeviceUmultimap(const string& deviceName);
    void removeDeviceUmultiset(const string& deviceName);

    void editDeviceMap(const string& deviceName);
    void editDeviceSet(const string& deviceName);
    void editDeviceMultimap(const string& deviceName);
    void editDeviceMultiSet(const string& deviceName);
    void editDeviceUmap(const string& deviceName);
    void editDeviceUset(const string& deviceName);
    void editDeviceUmultimap(const string& deviceName);
    void editDeviceUmultiset(const string& deviceName);

    void searchDeviceMap(const string& deviceName);
    void searchDeviceSet(const string& deviceName);
    void searchDeviceMultimap(const string& deviceName);
    void searchDeviceMultiSet(const string& deviceName);
    void searchDeviceUmap(const string& deviceName);
    void searchDeviceUset(const string& deviceName);
    void searchDeviceUmultimap(const string& deviceName);
    void searchDeviceUmultiset(const string& deviceName);

    void filterDeviceMap(const string& deviceType);
    void filterDeviceSet(const string& deviceType);
    void filterDeviceMultimap(const string& deviceType);
    void filterDeviceMultiSet(const string& deviceType);
    void filterDeviceUmap(const string& deviceType);
    void filterDeviceUset(const string& deviceType);
    void filterDeviceUmultimap(const string& deviceType);
    void filterDeviceUmultiset(const string& deviceType);

    void printDeviceMap();
    void printDeviceSet();
    void printDeviceMultimap();
    void printDeviceMultiSet();
    void printDeviceUmap();
    void printDeviceUset();
    void printDeviceUmultimap();
    void printDeviceUmultiset();

    void writeToFileDeviceMap();
    void writeToFileDeviceSet();
    void writeToFileDeviceMultimap();
    void writeToFileDeviceMultiSet();
    void writeToFileDeviceUmap();
    void writeToFileDeviceUset();
    void writeToFileDeviceUmultimap();
    void writeToFileDeviceUmultiset();
};
