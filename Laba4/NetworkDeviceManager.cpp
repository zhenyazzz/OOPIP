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
        cout << "Введите число: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stod(str);
}

int NetworkDeviceManager::inputInt()
{
    string str;
    regex regex_pattern("^-?[0-9]+$");
    do {
        cout << "Введите число: ";
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
        cout << "Устройство '" << deviceName << "' удалено из карты.\n";
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в карте.\n";
    }_getch();
}


void NetworkDeviceManager::removeDeviceSet(const string& deviceName) {
    system("cls");
    bool found = false; 

    for (auto it = deviceSet.begin(); it != deviceSet.end(); ) {
        if ((*it)->getName() == deviceName) { 
            it = deviceSet.erase(it); 
            cout << "Устройство с именем \"" << deviceName << "\" удалено из множества.\n";
            found = true; 
        }
        else {
            ++it; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в множестве.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceMultimap(const string& deviceName) {
    system("cls");
    auto range = deviceMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        for (auto it = range.first; it != range.second; ++it) {
        }
        deviceMultimap.erase(range.first, range.second);
        cout << "Все устройства с именем '" << deviceName << "' удалены из мультимапы.\n";
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в мультимапе.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceMultiSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto it = deviceMultiset.begin(); it != deviceMultiset.end(); ) {
        if ((*it)->getName() == deviceName) { 
            it = deviceMultiset.erase(it); 
            cout << "Устройство с именем \"" << deviceName << "\" удалено из мультисета.\n";
            found = true; 
        }
        else {
            ++it; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в мультисете.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceUmap(const string& deviceName) {
    system("cls");
    auto it = deviceUnorderedMap.find(deviceName);
    if (it != deviceUnorderedMap.end()) {
        deviceUnorderedMap.erase(it);
        cout << "Устройство '" << deviceName << "' удалено из неупорядоченной карты.\n";
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в неупорядоченной карте.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceUset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto it = deviceUnorderedSet.begin(); it != deviceUnorderedSet.end(); ++it) {
        if ((*it)->getName() == deviceName) { 
            deviceUnorderedSet.erase(it); 
            cout << "Устройство с именем \"" << deviceName << "\" удалено из неупорядоченного множества.\n";
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в неупорядоченном множестве.\n";
    }_getch();
}

void NetworkDeviceManager::removeDeviceUmultimap(const string& deviceName) {
    system("cls");
    auto range = deviceUnorderedMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        for (auto it = range.first; it != range.second; ++it) {
        }
        deviceUnorderedMultimap.erase(range.first, range.second);
        cout << "Все устройства с именем '" << deviceName << "' удалены из неупорядоченной мультимапы.\n";
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в неупорядоченной мультимапе.\n";
    }_getch();
}


void NetworkDeviceManager::removeDeviceUmultiset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto it = deviceUnorderedMultiset.begin(); it != deviceUnorderedMultiset.end(); ++it) {
        if ((*it)->getName() == deviceName) { 
            deviceUnorderedMultiset.erase(it); 
            cout << "Устройство с именем \"" << deviceName << "\" удалено из неупорядоченного мультисета.\n";
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в неупорядоченном мультисете.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceMap(const string& deviceName) {
    system("cls");
    auto it = deviceMap.find(deviceName);
    if (it != deviceMap.end()) {
        cout << "Редактирование устройства '" << deviceName << "'.\n";
        it->second->edit(); 
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в карте.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto& device : deviceSet) {
        if (device->getName() == deviceName) {
            cout << "Устройство найдено в множестве. Редактирование устройства.\n";
            device->edit(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в множестве.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceMultimap(const string& deviceName) {
    system("cls");
    auto range = deviceMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        cout << "Редактирование всех устройств с именем '" << deviceName << "'.\n";
        for (auto it = range.first; it != range.second; ++it) {
            it->second->edit(); 
        }
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в мультимапе.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceMultiSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto& device : deviceMultiset) {
        if (device->getName() == deviceName) { 
            cout << "Устройство найдено в мультисете. Редактирование устройства.\n";
            device->edit(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в мультисете.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceUmap(const string& deviceName) {
    system("cls");
    auto it = deviceUnorderedMap.find(deviceName);
    if (it != deviceUnorderedMap.end()) {
        cout << "Редактирование устройства '" << deviceName << "'.\n";
        it->second->edit(); 
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в неупорядоченной карте.\n";
    }_getch();
}


void NetworkDeviceManager::editDeviceUset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto& device : deviceUnorderedSet) {
        if (device->getName() == deviceName) {
            cout << "Устройство найдено в неупорядоченном множестве. Редактирование устройства.\n";
            device->edit(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в неупорядоченном множестве.\n";
    }_getch();
}

void NetworkDeviceManager::editDeviceUmultimap(const string& deviceName) {
    system("cls");
    auto range = deviceUnorderedMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        cout << "Редактирование всех устройств с именем '" << deviceName << "'.\n";
        for (auto it = range.first; it != range.second; ++it) {
            it->second->edit();
        }
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в неупорядоченной мультимапе.\n";
    }
    _getch();
}


void NetworkDeviceManager::editDeviceUmultiset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (auto& device : deviceUnorderedMultiset) {
        if (device->getName() == deviceName) { 
            cout << "Устройство найдено в неупорядоченном мультисете. Редактирование устройства.\n";
            device->edit();
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в неупорядоченном мультисете.\n";
    }
    _getch();
}

void NetworkDeviceManager::searchDeviceMap(const string& deviceName) {
    system("cls");
    auto it = deviceMap.find(deviceName);
    if (it != deviceMap.end()) {
        cout << "Устройство '" << deviceName << "' найдено в карте.\n";
        it->second->print(); 
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в карте.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (const auto& device : deviceSet) {
        if (device->getName() == deviceName) { 
            cout << "Устройство найдено в множестве: \n";
            device->print(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в множестве.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceMultimap(const string& deviceName) {
    system("cls");
    auto range = deviceMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        cout << "Устройства с именем '" << deviceName << "' найдены в мультимапе:\n";
        for (auto it = range.first; it != range.second; ++it) {
            it->second->print(); 
        }
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в мультимапе.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceMultiSet(const string& deviceName) {
    system("cls");
    bool found = false;

    for (const auto& device : deviceMultiset) {
        if (device->getName() == deviceName) { 
            cout << "Устройство найдено в мультисете: \n";
            device->print(); 
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в мультисете.\n";
    }_getch();
}


void NetworkDeviceManager::searchDeviceUmap(const string& deviceName) {
    system("cls");
    auto it = deviceUnorderedMap.find(deviceName);
    if (it != deviceUnorderedMap.end()) {
        cout << "Устройство '" << deviceName << "' найдено в неупорядоченной карте.\n";
        it->second->print(); 
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в неупорядоченной карте.\n";
    }_getch();
}


void NetworkDeviceManager::searchDeviceUset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (const auto& device : deviceUnorderedSet) {
        if (device->getName() == deviceName) { 
            cout << "Устройство найдено в неупорядоченном множестве: \n";
            device->print(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в неупорядоченном множестве.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceUmultimap(const string& deviceName) {
    system("cls");
    auto range = deviceUnorderedMultimap.equal_range(deviceName);
    if (range.first != range.second) {
        cout << "Устройства с именем '" << deviceName << "' найдены в неупорядоченной мультимапе:\n";
        for (auto it = range.first; it != range.second; ++it) {
            it->second->print(); 
        }
    }
    else {
        cout << "Устройство с именем '" << deviceName << "' не найдено в неупорядоченной мультимапе.\n";
    }_getch();
}

void NetworkDeviceManager::searchDeviceUmultiset(const string& deviceName) {
    system("cls");
    bool found = false;

    for (const auto& device : deviceUnorderedMultiset) {
        if (device->getName() == deviceName) { 
            cout << "Устройство найдено: \n";
            device->print(); 
            found = true;
            break; 
        }
    }

    if (!found) {
        cout << "Устройство с именем \"" << deviceName << "\" не найдено в неупорядоченном мультисете.\n";
    }_getch();
}

void NetworkDeviceManager::filterDeviceMap(const string& deviceType) {
    system("cls");
    cout << "Устройства с типом '" << deviceType << "' в карте:\n";
    bool found = false;
    for (const auto& pair : deviceMap) {
        if (pair.second->getType() == deviceType) {
            pair.second->print(); 
            found = true;
        }
    }
    if (!found) {
        cout << "Устройства с типом '" << deviceType << "' не найдены в карте.\n";
    }_getch();
}

void NetworkDeviceManager::filterDeviceSet(const string& deviceType) {
    system("cls");
    cout << "Устройства с типом '" << deviceType << "' в множестве:\n";
    bool found = false;
    for (const auto& device : deviceSet) {
        if (device->getType() == deviceType) { 
            device->print();
            found = true;
        }
    }
    if (!found) {
        cout << "Устройства с типом '" << deviceType << "' не найдены в множестве.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceMultimap(const string& deviceType) {
    system("cls");
    cout << "Устройства с типом '" << deviceType << "' в мультимапе:\n";
    bool found = false;
    for (const auto& pair : deviceMultimap) {
        if (pair.second->getType() == deviceType) { 
            pair.second->print();
            found = true;
        }
    }
    if (!found) {
        cout << "Устройства с типом '" << deviceType << "' не найдены в мультимапе.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceMultiSet(const string& deviceType) {
    system("cls");
    cout << "Устройства с типом '" << deviceType << "' в мультисете:\n";
    bool found = false;
    for (const auto& device : deviceMultiset) {
        if (device->getType() == deviceType) { 
            device->print(); 
            found = true;
        }
    }
    if (!found) {
        cout << "Устройства с типом '" << deviceType << "' не найдены в мультисете.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceUmap(const string& deviceType) {
    system("cls");
    cout << "Устройства с типом '" << deviceType << "' в неупорядоченной карте:\n";
    bool found = false;
    for (const auto& pair : deviceUnorderedMap) {
        if (pair.second->getType() == deviceType) {
            pair.second->print();
            found = true;
        }
    }
    if (!found) {
        cout << "Устройства с типом '" << deviceType << "' не найдены в неупорядоченной карте.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceUset(const string& deviceType) {
    system("cls");
    cout << "Устройства с типом '" << deviceType << "' в неупорядоченном множестве:\n";
    bool found = false;
    for (const auto& device : deviceUnorderedSet) {
        if (device->getType() == deviceType) {
            device->print(); 
            found = true;
        }
    }
    if (!found) {
        cout << "Устройства с типом '" << deviceType << "' не найдены в неупорядоченном множестве.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceUmultimap(const string& deviceType) {
    system("cls");
    cout << "Устройства с типом '" << deviceType << "' в неупорядоченной мультимапе:\n";
    bool found = false;
    for (const auto& pair : deviceUnorderedMultimap) {
        if (pair.second->getType() == deviceType) { 
            pair.second->print();
            found = true;
        }
    }
    if (!found) {
        cout << "Устройства с типом '" << deviceType << "' не найдены в неупорядоченной мультимапе.\n";
    }_getch();
}


void NetworkDeviceManager::filterDeviceUmultiset(const string& deviceType) {
    system("cls");
    cout << "Устройства с типом '" << deviceType << "' в неупорядоченном мультисете:\n";
    bool found = false;
    for (const auto& device : deviceUnorderedMultiset) {
        if (device->getType() == deviceType) { 
            device->print(); 
            found = true;
        }
    }
    if (!found) {
        cout << "Устройства с типом '" << deviceType << "' не найдены в неупорядоченном мультисете.\n";
    }_getch();
}

void NetworkDeviceManager::printDeviceMap() {
    system("cls");
    cout << "Печать всех устройств в карте:\n";
    if (deviceMap.empty()) {
        cout << "Карта устройств пуста.\n";
        _getch();
        return;
    }

    for (const auto& pair : deviceMap) {
        pair.second->print();
    }_getch();
}


void NetworkDeviceManager::printDeviceSet() {
    system("cls");
    cout << "Печать всех устройств в множестве:\n";
    if (deviceSet.empty()) {
        cout << "Множество устройств пусто.\n";
        _getch();
        return;
    }

    for (const auto& device : deviceSet) {
        device->print();
    }_getch();
}

void NetworkDeviceManager::printDeviceMultimap() {
    system("cls");
    cout << "Печать всех устройств в мультимапе:\n";
    if (deviceMultimap.empty()) {
        cout << "Мультимапа устройств пуста.\n";
        _getch();
        return;
    }

    for (const auto& pair : deviceMultimap) {
        pair.second->print();
    }_getch();
}


void NetworkDeviceManager::printDeviceMultiSet() {
    system("cls");
    cout << "Печать всех устройств в мультисете:\n";
    if (deviceMultiset.empty()) {
        cout << "Мультисет устройств пуст.\n";
        _getch();
        return;
    }

    for (const auto& device : deviceMultiset) {
        device->print(); 
    }_getch();
}


void NetworkDeviceManager::printDeviceUmap() {
    system("cls");
    cout << "Печать всех устройств в неупорядоченной карте:\n";
    if (deviceUnorderedMap.empty()) {
        cout << "Неупорядоченная карта устройств пуста.\n";
        _getch();
        return;
    }

    for (const auto& pair : deviceUnorderedMap) {
        pair.second->print(); 
    }_getch();
}


void NetworkDeviceManager::printDeviceUset() {
    system("cls");
    cout << "Печать всех устройств в неупорядоченном множестве:\n";
    if (deviceUnorderedSet.empty()) {
        cout << "Неупорядоченное множество устройств пусто.\n";
        _getch();
        return;
    }

    for (const auto& device : deviceUnorderedSet) {
        device->print(); 
    }_getch();
}

void NetworkDeviceManager::printDeviceUmultimap() {
    system("cls");
    cout << "Печать всех устройств в неупорядоченном мультимапе:\n";
    if (deviceUnorderedMultimap.empty()) {
        cout << "Неупорядоченная мультимапа устройств пуста.\n";
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
    cout << "Печать всех устройств в неупорядоченном мультимножестве:\n";
    if (deviceUnorderedMultiset.empty()) {
        cout << "Неупорядоченный мультисет устройств пуст.\n";
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
    cout << "Успешная запись устройств из множества в файл \n";
}

void NetworkDeviceManager::writeToFileDeviceMultimap() {
    system("cls");

    for (const auto& pair : deviceMultimap) {
        pair.second->writeToFile(pair.first); 
    }
    cout << "Успешная запись устройств из мультимапы в файл deviceMultimap.bin.\n";
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
    cout << "Успешная запись устройств из неупорядоченной карты в файл deviceUmap.bin.\n";
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



