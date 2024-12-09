#include "NetworkDeviceManager.h"
#include <regex>
#include <conio.h>



NetworkDeviceManager::NetworkDeviceManager()
{
}

NetworkDeviceManager::~NetworkDeviceManager() {
    deviceMap.clear();
    deviceSet.clear();
    deviceMultimap.clear();
    deviceMultiset.clear();
    deviceUnorderedMap.clear();
    deviceUnorderedSet.clear();
    deviceUnorderedMultimap.clear();
    deviceUnorderedMultiset.clear();
}

double NetworkDeviceManager::inputDouble()
{
    string str;
    regex regex_pattern("-?[0-9]+.?[0-9]+");
    do
    {
        cout << "������� �����: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stod(str);
}

int NetworkDeviceManager::inputInt()
{
    string str;
    regex regex_pattern("^-?[0-9]+$");
    do {
        cout << "������� �����: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stoi(str);
}

void NetworkDeviceManager::addDeviceMap(shared_ptr<NetworkDevice> device) {
    string deviceName = device->getName();

    if (deviceMap.find(deviceName) != deviceMap.end()) {
        cout << "Device with name '" << deviceName << "' already exists in the map.\n";
    }
    else {
        deviceMap[deviceName] = device;
        cout << "Device '" << deviceName << "' added to the map.\n";
    }
}

void NetworkDeviceManager::addDeviceSet(shared_ptr<NetworkDevice> device) {

    if (deviceSet.find(device) != deviceSet.end()) {
        cout << "Device already exists in the set.\n";
    }
    else {
        deviceSet.insert(device);
        cout << "Device added to the set.\n";
    }
}

void NetworkDeviceManager::addDeviceMultimap(shared_ptr<NetworkDevice> device) {
    deviceMultimap.insert({ device->getName(), device });
}

void NetworkDeviceManager::addDeviceMultiSet(shared_ptr<NetworkDevice> device) {
    deviceMultiset.insert(device);
}

void NetworkDeviceManager::addDeviceUmap(shared_ptr<NetworkDevice> device) {
    deviceUnorderedMap[device->getName()] = device;
}

void NetworkDeviceManager::addDeviceUset(shared_ptr<NetworkDevice> device) {
    deviceUnorderedSet.insert(device);
}

void NetworkDeviceManager::addDeviceUmultimap(shared_ptr<NetworkDevice> device) {
    deviceUnorderedMultimap.insert({ device->getName(), device });
}

void NetworkDeviceManager::addDeviceUmultiset(shared_ptr<NetworkDevice> device) {
    deviceUnorderedMultiset.insert(device);
}

void NetworkDeviceManager::removeDeviceMap(const string& deviceName) {
    
    system("cls");
    auto it = deviceMap.find(deviceName);
    if (it != deviceMap.end()) {
        deviceMap.erase(it);
        cout << "���������� '" << deviceName << "' ������� �� �����.\n";
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � �����.\n";
    }_getch();
}


void NetworkDeviceManager::removeDeviceSet(const string& deviceName) {
    system("cls");
    bool found = false; 

    for (auto it = deviceSet.begin(); it != deviceSet.end(); ) {
        if ((*it)->getName() == deviceName) { 
            it = deviceSet.erase(it); 
            cout << "���������� � ������ \"" << deviceName << "\" ������� �� ���������.\n";
            found = true; 
        }
        else {
            ++it; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ���������.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceMultimap(const string& deviceName) {
    system("cls");
    auto range = deviceMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        for (auto it = range.first; it != range.second; ++it) {
        }
        deviceMultimap.erase(range.first, range.second);
        cout << "��� ���������� � ������ '" << deviceName << "' ������� �� ����������.\n";
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ����������.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceMultiSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto it = deviceMultiset.begin(); it != deviceMultiset.end(); ) {
        if ((*it)->getName() == deviceName) { 
            it = deviceMultiset.erase(it); 
            cout << "���������� � ������ \"" << deviceName << "\" ������� �� ����������.\n";
            found = true; 
        }
        else {
            ++it; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ����������.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceUmap(const string& deviceName) {
    system("cls");
    auto it = deviceUnorderedMap.find(deviceName);
    if (it != deviceUnorderedMap.end()) {
        deviceUnorderedMap.erase(it);
        cout << "���������� '" << deviceName << "' ������� �� ��������������� �����.\n";
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ��������������� �����.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceUset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto it = deviceUnorderedSet.begin(); it != deviceUnorderedSet.end(); ++it) {
        if ((*it)->getName() == deviceName) { 
            deviceUnorderedSet.erase(it); 
            cout << "���������� � ������ \"" << deviceName << "\" ������� �� ���������������� ���������.\n";
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ��������������� ���������.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceUmultimap(const string& deviceName) {
    system("cls");
    auto range = deviceUnorderedMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        for (auto it = range.first; it != range.second; ++it) {
        }
        deviceUnorderedMultimap.erase(range.first, range.second);
        cout << "��� ���������� � ������ '" << deviceName << "' ������� �� ��������������� ����������.\n";
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ��������������� ����������.\n";
    }_getch();
}


void NetworkDeviceManager::removeDeviceUmultiset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto it = deviceUnorderedMultiset.begin(); it != deviceUnorderedMultiset.end(); ++it) {
        if ((*it)->getName() == deviceName) { 
            deviceUnorderedMultiset.erase(it); 
            cout << "���������� � ������ \"" << deviceName << "\" ������� �� ���������������� ����������.\n";
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ��������������� ����������.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceMap(const string& deviceName) {
    system("cls");
    auto it = deviceMap.find(deviceName);
    if (it != deviceMap.end()) {
        cout << "�������������� ���������� '" << deviceName << "'.\n";
        it->second->edit(); 
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � �����.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto& device : deviceSet) {
        if (device->getName() == deviceName) {
            cout << "���������� ������� � ���������. �������������� ����������.\n";
            device->edit(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ���������.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceMultimap(const string& deviceName) {
    system("cls");
    auto range = deviceMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        cout << "�������������� ���� ��������� � ������ '" << deviceName << "'.\n";
        for (auto it = range.first; it != range.second; ++it) {
            it->second->edit(); 
        }
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ����������.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceMultiSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto& device : deviceMultiset) {
        if (device->getName() == deviceName) { 
            cout << "���������� ������� � ����������. �������������� ����������.\n";
            device->edit(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ����������.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceUmap(const string& deviceName) {
    system("cls");
    auto it = deviceUnorderedMap.find(deviceName);
    if (it != deviceUnorderedMap.end()) {
        cout << "�������������� ���������� '" << deviceName << "'.\n";
        it->second->edit(); 
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ��������������� �����.\n";
    }_getch();
}


void NetworkDeviceManager::editDeviceUset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto& device : deviceUnorderedSet) {
        if (device->getName() == deviceName) {
            cout << "���������� ������� � ��������������� ���������. �������������� ����������.\n";
            device->edit(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ��������������� ���������.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceUmultimap(const string& deviceName) {
    system("cls");
    auto range = deviceUnorderedMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        cout << "�������������� ���� ��������� � ������ '" << deviceName << "'.\n";
        for (auto it = range.first; it != range.second; ++it) {
            it->second->edit();
        }
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ��������������� ����������.\n";
    }
    _getch();
}


void NetworkDeviceManager::editDeviceUmultiset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto& device : deviceUnorderedMultiset) {
        if (device->getName() == deviceName) { 
            cout << "���������� ������� � ��������������� ����������. �������������� ����������.\n";
            device->edit();
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ��������������� ����������.\n";
    }
    _getch();
}

void NetworkDeviceManager::searchDeviceMap(const string& deviceName) {
    system("cls");
    auto it = deviceMap.find(deviceName);
    if (it != deviceMap.end()) {
        cout << "���������� '" << deviceName << "' ������� � �����.\n";
        it->second->print(); 
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � �����.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (const auto& device : deviceSet) {
        if (device->getName() == deviceName) { 
            cout << "���������� ������� � ���������: \n";
            device->print(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ���������.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceMultimap(const string& deviceName) {
    system("cls");
    auto range = deviceMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        cout << "���������� � ������ '" << deviceName << "' ������� � ����������:\n";
        for (auto it = range.first; it != range.second; ++it) {
            it->second->print(); 
        }
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ����������.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceMultiSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (const auto& device : deviceMultiset) {
        if (device->getName() == deviceName) { 
            cout << "���������� ������� � ����������: \n";
            device->print(); 
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ����������.\n";
    }_getch();
}


void NetworkDeviceManager::searchDeviceUmap(const string& deviceName) {
    system("cls");
    auto it = deviceUnorderedMap.find(deviceName);
    if (it != deviceUnorderedMap.end()) {
        cout << "���������� '" << deviceName << "' ������� � ��������������� �����.\n";
        it->second->print(); 
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ��������������� �����.\n";
    }_getch();
}


void NetworkDeviceManager::searchDeviceUset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (const auto& device : deviceUnorderedSet) {
        if (device->getName() == deviceName) { 
            cout << "���������� ������� � ��������������� ���������: \n";
            device->print(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ��������������� ���������.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceUmultimap(const string& deviceName) {
    system("cls");
    auto range = deviceUnorderedMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        cout << "���������� � ������ '" << deviceName << "' ������� � ��������������� ����������:\n";
        for (auto it = range.first; it != range.second; ++it) {
            it->second->print(); 
        }
    }
    else {
        cout << "���������� � ������ '" << deviceName << "' �� ������� � ��������������� ����������.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceUmultiset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (const auto& device : deviceUnorderedMultiset) {
        if (device->getName() == deviceName) { 
            cout << "���������� �������: \n";
            device->print(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "���������� � ������ \"" << deviceName << "\" �� ������� � ��������������� ����������.\n";
    }_getch();
}

void NetworkDeviceManager::filterDeviceMap(const string& deviceType) {
    system("cls");
    cout << "���������� � ����� '" << deviceType << "' � �����:\n";
    bool found = false;
    for (const auto& pair : deviceMap) {
        if (pair.second->getType() == deviceType) {
            pair.second->print(); 
            found = true;
        }
    }
    if (!found) {
        cout << "���������� � ����� '" << deviceType << "' �� ������� � �����.\n";
    }_getch();
}

void NetworkDeviceManager::filterDeviceSet(const string& deviceType) {
    system("cls");
    cout << "���������� � ����� '" << deviceType << "' � ���������:\n";
    bool found = false;
    for (const auto& device : deviceSet) {
        if (device->getType() == deviceType) { 
            device->print();
            found = true;
        }
    }
    if (!found) {
        cout << "���������� � ����� '" << deviceType << "' �� ������� � ���������.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceMultimap(const string& deviceType) {
    system("cls");
    cout << "���������� � ����� '" << deviceType << "' � ����������:\n";
    bool found = false;
    for (const auto& pair : deviceMultimap) {
        if (pair.second->getType() == deviceType) { 
            pair.second->print();
            found = true;
        }
    }
    if (!found) {
        cout << "���������� � ����� '" << deviceType << "' �� ������� � ����������.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceMultiSet(const string& deviceType) {
    system("cls");
    cout << "���������� � ����� '" << deviceType << "' � ����������:\n";
    bool found = false;
    for (const auto& device : deviceMultiset) {
        if (device->getType() == deviceType) { 
            device->print(); 
            found = true;
        }
    }
    if (!found) {
        cout << "���������� � ����� '" << deviceType << "' �� ������� � ����������.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceUmap(const string& deviceType) {
    system("cls");
    cout << "���������� � ����� '" << deviceType << "' � ��������������� �����:\n";
    bool found = false;
    for (const auto& pair : deviceUnorderedMap) {
        if (pair.second->getType() == deviceType) {
            pair.second->print();
            found = true;
        }
    }
    if (!found) {
        cout << "���������� � ����� '" << deviceType << "' �� ������� � ��������������� �����.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceUset(const string& deviceType) {
    system("cls");
    cout << "���������� � ����� '" << deviceType << "' � ��������������� ���������:\n";
    bool found = false;
    for (const auto& device : deviceUnorderedSet) {
        if (device->getType() == deviceType) {
            device->print(); 
            found = true;
        }
    }
    if (!found) {
        cout << "���������� � ����� '" << deviceType << "' �� ������� � ��������������� ���������.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceUmultimap(const string& deviceType) {
    system("cls");
    cout << "���������� � ����� '" << deviceType << "' � ��������������� ����������:\n";
    bool found = false;
    for (const auto& pair : deviceUnorderedMultimap) {
        if (pair.second->getType() == deviceType) { 
            pair.second->print();
            found = true;
        }
    }
    if (!found) {
        cout << "���������� � ����� '" << deviceType << "' �� ������� � ��������������� ����������.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceUmultiset(const string& deviceType) {
    system("cls");
    cout << "���������� � ����� '" << deviceType << "' � ��������������� ����������:\n";
    bool found = false;
    for (const auto& device : deviceUnorderedMultiset) {
        if (device->getType() == deviceType) { 
            device->print(); 
            found = true;
        }
    }
    if (!found) {
        cout << "���������� � ����� '" << deviceType << "' �� ������� � ��������������� ����������.\n";
    }_getch();
}

void NetworkDeviceManager::printDeviceMap() {
    system("cls");
    cout << "������ ���� ��������� � �����:\n";
    if (deviceMap.empty()) {
        cout << "����� ��������� �����.\n";
        _getch();
        return;
    }

    for (const auto& pair : deviceMap) {
        pair.second->print();
    }_getch();
}


void NetworkDeviceManager::printDeviceSet() {
    system("cls");
    cout << "������ ���� ��������� � ���������:\n";
    if (deviceSet.empty()) {
        cout << "��������� ��������� �����.\n";
        _getch();
        return;
    }

    for (const auto& device : deviceSet) {
        device->print();
    }_getch();
}

void NetworkDeviceManager::printDeviceMultimap() {
    system("cls");
    cout << "������ ���� ��������� � ����������:\n";
    if (deviceMultimap.empty()) {
        cout << "���������� ��������� �����.\n";
        _getch();
        return;
    }

    for (const auto& pair : deviceMultimap) {
        pair.second->print();
    }_getch();
}


void NetworkDeviceManager::printDeviceMultiSet() {
    system("cls");
    cout << "������ ���� ��������� � ����������:\n";
    if (deviceMultiset.empty()) {
        cout << "��������� ��������� ����.\n";
        _getch();
        return;
    }

    for (const auto& device : deviceMultiset) {
        device->print(); 
    }_getch();
}


void NetworkDeviceManager::printDeviceUmap() {
    system("cls");
    cout << "������ ���� ��������� � ��������������� �����:\n";
    if (deviceUnorderedMap.empty()) {
        cout << "��������������� ����� ��������� �����.\n";
        _getch();
        return;
    }

    for (const auto& pair : deviceUnorderedMap) {
        pair.second->print(); 
    }_getch();
}


void NetworkDeviceManager::printDeviceUset() {
    system("cls");
    cout << "������ ���� ��������� � ��������������� ���������:\n";
    if (deviceUnorderedSet.empty()) {
        cout << "��������������� ��������� ��������� �����.\n";
        _getch();
        return;
    }

    for (const auto& device : deviceUnorderedSet) {
        device->print(); 
    }_getch();
}

void NetworkDeviceManager::printDeviceUmultimap() {
    system("cls");
    cout << "������ ���� ��������� � ��������������� ����������:\n";
    if (deviceUnorderedMultimap.empty()) {
        cout << "��������������� ���������� ��������� �����.\n";
        _getch();
        return;
    }

    for (const auto& pair : deviceUnorderedMultimap) {
        pair.second->print(); 
    }
    _getch();
}

void NetworkDeviceManager::printDeviceUmultiset() {
    system("cls");
    cout << "������ ���� ��������� � ��������������� ���������������:\n";
    if (deviceUnorderedMultiset.empty()) {
        cout << "��������������� ��������� ��������� ����.\n";
        _getch();
        return;
    }

    for (const auto& device : deviceUnorderedMultiset) {
        device->print(); 
    }
    _getch();
}

void NetworkDeviceManager::writeToFileDeviceMap() {
    system("cls");

    for (const auto& pair : deviceMap) {
        pair.second->writeToFile(pair.first); 
    }

}

void NetworkDeviceManager::writeToFileDeviceSet() {
    system("cls");

    for (const auto& device : deviceSet) {
        device->writeToFile(); 
    }
    cout << "�������� ������ ��������� �� ��������� � ���� \n";
}

void NetworkDeviceManager::writeToFileDeviceMultimap() {
    system("cls");

    for (const auto& pair : deviceMultimap) {
        pair.second->writeToFile(pair.first); 
    }
    cout << "�������� ������ ��������� �� ���������� � ���� deviceMultimap.bin.\n";
}

void NetworkDeviceManager::writeToFileDeviceMultiSet() {
    system("cls");

    for (const auto& device : deviceMultiset) {
        device->writeToFile(); 
    }

}

void NetworkDeviceManager::writeToFileDeviceUmap() {
    system("cls");
    
    for (const auto& pair : deviceUnorderedMap) {
        pair.second->writeToFile(pair.first); 
    }
    cout << "�������� ������ ��������� �� ��������������� ����� � ���� deviceUmap.bin.\n";
}

void NetworkDeviceManager::writeToFileDeviceUset() {
    system("cls");

    for (const auto& device : deviceUnorderedSet) {
        device->writeToFile(); 
    }

}

void NetworkDeviceManager::writeToFileDeviceUmultimap() {
    system("cls");

    for (const auto& pair : deviceUnorderedMultimap) {
        pair.second->writeToFile(pair.first);
    }
}

void NetworkDeviceManager::writeToFileDeviceUmultiset() {
    system("cls");

    for (const auto& device : deviceUnorderedMultiset) {
        device->writeToFile(); 
    }
}



