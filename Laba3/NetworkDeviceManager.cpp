#include "NetworkDeviceManager.h"
#include <regex>
#include <conio.h>

NetworkDeviceManager::NetworkDeviceManager()
{

}

NetworkDeviceManager::~NetworkDeviceManager()
{
    for (NetworkDevice* device : deviceVector) {
        delete device;
    }

    deviceVector.clear();
    for (NetworkDevice* device : deviceList) {
        delete device;
    }

    deviceList.clear();

    for (NetworkDevice* device : deviceArray) {
        delete device;
    }

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

NetworkDevice* NetworkDeviceManager::createDevice()
{
    int m, portCount, paperCount, speed, id;
    bool isColor;
    string name, location, ipAddress;
    cout << "1) Printer\n" << "2) Router\n" << "3) Switch\n" <<
        "4) Modem\n" << "���  ������ ��������?" << endl;
    do
    {
        m = inputInt();
    } while (m < 0 || m > 4);
    switch (m) {
    case 1: {
        cout << "������� id:" << endl;
        id = inputInt();
        cout << "������� ��������:" << endl;
        cin >> name;
        cout << "������� ip ������:" << endl;
        cin >> ipAddress;
        cout << "������� ������������:" << endl;
        cin >> location;
        cout << "������� ���������� ������:" << endl;
        paperCount = inputInt();
        isColor = true;
        return new Printer(id, name, ipAddress, location, isColor, paperCount);
    }
    case 2: {
        cout << "������� id:" << endl;
        id = inputInt();
        cout << "������� ��������:" << endl;
        cin >> name;
        cout << "������� ip ������:" << endl;
        cin >> ipAddress;
        cout << "������� ������������:" << endl;
        cin >> location;
        cout << "������� ���������� ������:" << endl;
        portCount = inputInt();
        return new Router(id, name, ipAddress, location, portCount);
    }
    case 3: {
        cout << "������� id:" << endl;
        id = inputInt();
        cout << "������� ��������:" << endl;
        cin >> name;
        cout << "������� ip ������:" << endl;
        cin >> ipAddress;
        cout << "������� ������������:" << endl;
        cin >> location;
        cout << "������� ���������� ������:" << endl;
        portCount = inputInt();
        return new Switch(id, name, ipAddress, location, portCount);
    }
    case 4: {
        cout << "������� id:" << endl;
        id = inputInt();
        cout << "������� ��������:" << endl;
        cin >> name;
        cout << "������� ip ������:" << endl;
        cin >> ipAddress;
        cout << "������� ������������:" << endl;
        cin >> location;
        cout << "������� ��������:" << endl;
        speed = inputInt();
        return new Modem(id, name, ipAddress, location, speed);
    }
    }
}

void NetworkDeviceManager::addDeviceToList()
{
    system("cls");
    deviceList.push_back(createDevice());
    cout << "Device added!\n";
    _getch();
}

void NetworkDeviceManager::removeDeviceFromList()
{
    system("cls");
    cout << "������� id ��� ��������: ";
    int id = inputInt();
    for (auto it = deviceList.begin(); it != deviceList.end(); ++it) {
        if ((*it)->getId() == id) {
            delete* it;  
            deviceList.erase(it);
            cout << "���������� �������.\n";
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}

void NetworkDeviceManager::editDeviceInList()
{
    system("cls");
    cout << "������� id ��� ��������������: ";
    int id = inputInt();
    for (auto it = deviceList.begin(); it != deviceList.end(); ++it) {
        if ((*it)->getId() == id) {
            (*it)->edit();
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}

void NetworkDeviceManager::printList()
{
    system("cls");
    for (auto it = deviceList.begin(); it != deviceList.end(); ++it)
        (*it)->print();
    _getch();
}

void NetworkDeviceManager::sortDevicesListName()
{
    system("cls");
    deviceList.sort([](const NetworkDevice* a, const NetworkDevice* b) {
        return a->getName() < b->getName();
        });
    cout << "������ ������������" << endl;
    _getch();
}

void NetworkDeviceManager::findDeviceBylistID()
{
    system("cls");
    cout << "������� id ��� ������: ";
    int id = inputInt();
    for (auto it = deviceList.begin(); it != deviceList.end(); ++it) {
        if ((*it)->getId() == id) {
            (*it)->print();
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}

void NetworkDeviceManager::saveToFile()
{
    system("cls");
    for (auto& device : deviceList) {
        device->writeToFile();
    }
    cout << "�������� ������ � ����";
    _getch();
}

void NetworkDeviceManager::loadFromFile()
{
    system("cls");
    ifstream routerFile("routers.dat", ios::in | ios::binary);
    ifstream printerFile("printers.dat", ios::in | ios::binary);
    ifstream switchFile("switches.dat", ios::in | ios::binary);
    ifstream modemFile("modems.dat", ios::in | ios::binary);

    if (routerFile.is_open() && printerFile.is_open() && switchFile.is_open() && modemFile.is_open()) {
        for (NetworkDevice* device : deviceList) {
            delete device;
        }
        deviceList.clear();

        while (true) {
            Router* router = new Router();
            if (routerFile >> *router) {
                deviceList.push_back(router);
            }
            else {
                delete router;
                break;
            }
        }

        while (true) {
            Printer* printer = new Printer();
            if (printerFile >> *printer) {
                deviceList.push_back(printer);
                cout << "isdg";
            }
            else {
                delete printer;
                break;
            }
        }

        while (true) {
            Switch* sw = new Switch();
            if (switchFile >> *sw) {
                deviceList.push_back(sw);
            }
            else {
                delete sw;
                break;
            }
        }

        while (true) {
            Modem* modem = new Modem();
            if (modemFile >> *modem) {
                deviceList.push_back(modem);
            }
            else {
                delete modem;
                break;
            }
        }

        routerFile.close();
        printerFile.close();
        switchFile.close();
        modemFile.close();
        cout << "������ ������� ��������� �� �������� ������!" << endl;
        printList();
    }
    else {
        cerr << "������ �������� ������!" << endl;
        _getch();
    }
}


void NetworkDeviceManager::addDeviceToVector()
{
    system("cls");
    deviceVector.push_back(createDevice());
    cout << "Device added!\n";
    _getch();
}

void NetworkDeviceManager::removeDeviceFromVector()
{
    system("cls");
    cout << "������� id ��� ��������: ";
    int id = inputInt();
    for (auto it = deviceVector.begin(); it != deviceVector.end(); ++it) {
        if ((*it)->getId() == id) {
            delete* it;  
            deviceVector.erase(it);
            cout << "���������� �������.\n";
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}

void NetworkDeviceManager::editDeviceInVector()
{
    system("cls");
    cout << "������� id ��� ��������������: ";
    int id = inputInt();
    for (auto it = deviceVector.begin(); it != deviceVector.end(); ++it) {
        if ((*it)->getId() == id) {
            (*it)->edit();
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}

void NetworkDeviceManager::printVector()
{
    system("cls");
    for (auto it = deviceVector.begin(); it != deviceVector.end(); ++it)
        (*it)->print();
    _getch();
}

void NetworkDeviceManager::sortDevicesVectorName()
{
    system("cls");
    sort(deviceVector.begin(), deviceVector.end(), [](const NetworkDevice* a, const NetworkDevice* b) {
        return a->getName() < b->getName();
        });
    _getch();
}

void NetworkDeviceManager::findDeviceByVectorID()
{
    system("cls");
    cout << "������� id ��� ������: ";
    int id = inputInt();
    for (auto it = deviceVector.begin(); it != deviceVector.end(); ++it) {
        if ((*it)->getId() == id) {
            (*it)->print();
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}

void NetworkDeviceManager::addDeviceToArray()
{
    system("cls");
    if (arraySize < deviceArray.size()) {
        deviceArray[arraySize++] = createDevice();
    }
    else {
        cout << "������ �����!\n";
    };
    _getch();
}

void NetworkDeviceManager::removeDeviceFromArray()
{
    system("cls");
    cout << "������� id ��� ��������: ";
    int id = inputInt();
    for (size_t i = 0; i < arraySize; ++i) {
        if (deviceArray[i]->getId() == id) {
            delete deviceArray[i];  
            for (size_t j = i; j < arraySize - 1; ++j) {
                deviceArray[j] = deviceArray[j + 1];  
            }
            deviceArray[--arraySize] = nullptr;
            cout << "���������� �������.\n";
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}

void NetworkDeviceManager::editDeviceInArray()
{
    system("cls");
    cout << "������� id ��� ��������������: ";
    int id = inputInt();
    for (size_t i = 0; i < arraySize; ++i) {
        if (deviceArray[i]->getId() == id) {
            deviceArray[i]->edit();
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}

void NetworkDeviceManager::printArray()
{
    system("cls");
    for (size_t i = 0; i < arraySize; ++i)
        deviceArray[i]->print();
    _getch();
}

void NetworkDeviceManager::sortDevicesArrayName()
{
    sort(deviceArray.begin(), deviceArray.begin() + arraySize, [](const NetworkDevice* a, const NetworkDevice* b) {
        return a->getName() < b->getName();
        });
}

void NetworkDeviceManager::findDeviceByArrayID()
{
    system("cls");
    cout << "������� id ��� ������: ";
    int id = inputInt();
    for (size_t i = 0; i < arraySize; ++i) {
        if (deviceArray[i]->getId() == id) {
            deviceArray[i]->print();
            return;
        }
    }
    cout << "���������� �� �������!\n";
    _getch();
}
