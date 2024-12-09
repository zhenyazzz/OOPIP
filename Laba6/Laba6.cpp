#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <string>
#include <limits>
#include "NetworkDeviceManager.h"
#include <regex>
#include <Windows.h>
#include "ManagerFactory.h"
#include "NetworkDeviceManagerFactory.h"
#include "CustomDeviceFactory.h"
#include "ModemFactory.h"
using namespace std;


int getValidIntInput()
{
    string str;
    regex regex_pattern("^-?[0-9]+$");
    do {
        cout << "Введите число: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stoi(str);
}
shared_ptr<NetworkDevice> createDevice()
{
    system("cls");
    int m, portCount, paperCount, speed, id;
    bool isColor;
    string name, location, ipAddress;
    cout << "1) Printer\n" << "2) Router\n" <<
        "3) Modem\n" << "Что  хотите добавить?" << endl;
    do
    {
        m = getValidIntInput();
    } while (m < 0 || m > 3);
    switch (m) {
    case 1: {
        CustomDeviceFactory customFactory;
        cout << "Введите id:" << endl;
        id = getValidIntInput();
        cout << "Введите название:" << endl;
        cin >> name;
        cout << "Введите ip адресс:" << endl;
        cin >> ipAddress;
        cout << "Введите располажение:" << endl;
        cin >> location;
        cout << "Введите количество бумаги:" << endl;
        paperCount = getValidIntInput();
        isColor = true;
        return customFactory.createDevice(PRINTER,id,name,ipAddress,location,paperCount,isColor);
    }
    case 2: {
        cout << "Введите id:" << endl;
        id = getValidIntInput();
        cout << "Введите название:" << endl;
        cin >> name;
        cout << "Введите ip адресс:" << endl;
        cin >> ipAddress;
        cout << "Введите располажение:" << endl;
        cin >> location;
        cout << "Введите количество портов:" << endl;
        portCount = getValidIntInput();

        return make_shared<Router>(id, name, ipAddress, location, portCount);
    }
    case 3: {
        ModemFactory modemFactory;
        modemFactory.createDevice();
        cout << "Введите id:" << endl;
        id = getValidIntInput();
        cout << "Введите название:" << endl;
        cin >> name;
        cout << "Введите ip адресс:" << endl;
        cin >> ipAddress;
        cout << "Введите располажение:" << endl;
        cin >> location;
        cout << "Введите скорость:" << endl;
        speed = getValidIntInput();
        return make_shared<Modem>(id, name, ipAddress, location, speed);
    }
    }
}
void mainMenu() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    unique_ptr<ManagerFactory> factory = make_unique<NetworkDeviceManagerFactory>();
    unique_ptr<Manager> manager = factory->createManager();
    manager->start();
    do {
        system("cls");
        cout << "\nМеню:\n";
        cout << "1. Добавить устройство\n";
        cout << "2. Удалить устройство\n";
        cout << "3. Редактировать устройство\n";
        cout << "4. Искать устройство\n";
        cout << "5. Фильтровать устройства по типу\n";
        cout << "6. Печать всех устройств\n";
        cout << "7. Запись в файл\n";
        cout << "8. Сортировка\n";
        cout << "9. Выход\n";
        cout << "Введите ваш выбор: ";
        choice = getValidIntInput();

        switch (choice) {
        case 1: {
            // Добавление устройства во все контейнеры
            shared_ptr<NetworkDevice> device = createDevice();
            manager->addDeviceStack(device->clone());
            manager->addDeviceQueue(device->clone());
            manager->addDevicePriorityQueue(device->clone());

            break;
        }
        case 2: {
            // Удаление устройства по имени
            string name;
            cout << "Введите название устройства для поиска: ";
            cin >> name;
            manager->removeDeviceStack(name);
            manager->removeDeviceQueue(name);
            manager->removeDevicePriorityQueue(name);
            break;
        }
        case 3: {
            // Редактирование устройства
            string name;
            cout << "Введите название устройства для поиска: ";
            cin >> name;
            manager->editDeviceStack(name);
            manager->editDeviceQueue(name);
            manager->editDevicePriorityQueue(name);
            break;
        }
        case 4: {
            // Поиск устройства по названию
            string name;
            cout << "Введите название устройства для поиска: ";
            cin >> name;
            manager->searchDeviceStack(name);
            manager->searchDeviceQueue(name);
            manager->searchDevicePriorityQueue(name);
            break;
        }
        case 5: {
            // Фильтрация устройств по типу
            string deviceType;
            cout << "Введите тип устройства для поиска: ";
            cin >> deviceType;
            manager->filterDeviceStack(deviceType);
            manager->filterDeviceQueue(deviceType);
            manager->filterDevicePriorityQueue(deviceType);
            break;
        }
        case 6: {
            // Печать всех устройств
            manager->printDeviceStack();
            manager->printDeviceQueue();
            manager->printDevicePriorityQueue();
            break;
        }
        case 7:
            // Запись в файл
            manager->writeToFileDeviceStack();
            manager->writeToFileDeviceQueue();
            manager->writeToFileDevicePriorityQueue();
            break;
        case 8:
            // Сортировка
            manager->sortDeviceStack();
            manager->sortDeviceQueue();
            manager->sortDevicePriorityQueue();
            break;
        case 9:
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 9);
}

int main() {
    mainMenu();
    return 0;
}

