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
        return make_shared<Printer>(id, name, ipAddress, location, isColor, paperCount);
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
    NetworkDeviceManager manager;
    do {
        system("cls");
        cout << "\nМеню:\n";
        cout << "1. Добавить устройство\n";
        cout << "2. Удалить устройство\n";
        cout << "3. Редактировать устройство\n";
        cout << "4. Искать устройство\n";
        cout << "5. Фильтровать устройства по названию\n";
        cout << "6. Печать всех устройств\n";
        cout << "7. Запись в файл\n";
        cout << "8. Выход\n";
        cout << "Введите ваш выбор: ";
        choice = getValidIntInput();

        switch (choice) {
        case 1: {
            // Добавление устройства во все контейнеры
            shared_ptr<NetworkDevice> device = createDevice();

            manager.addDeviceMap(device->clone());
            manager.addDeviceSet(device->clone());
            manager.addDeviceMultimap(device->clone());
            manager.addDeviceMultiSet(device->clone());
            manager.addDeviceUmap(device->clone());
            manager.addDeviceUset(device->clone());
            manager.addDeviceUmultimap(device->clone());
            manager.addDeviceUmultiset(device->clone());
            break;
        }
        case 2: {
            // Удаление устройства по имени
            string name;
            cout << "Введите название устройства для поиска: ";
            cin >> name;
            manager.removeDeviceMap(name);
            manager.removeDeviceSet(name);
            manager.removeDeviceMultimap(name);
            manager.removeDeviceUmap(name);
            manager.removeDeviceUset(name);
            manager.removeDeviceUmultimap(name);
            manager.removeDeviceUmultiset(name);
            break;
        }
        case 3: {
            // Редактирование устройства
            string name;
            cout << "Введите название устройства для поиска: ";
            cin >> name;
            manager.editDeviceMap(name);
            manager.editDeviceSet(name);
            manager.editDeviceMultimap(name);
            manager.editDeviceUmap(name);
            manager.editDeviceUset(name);
            manager.editDeviceUmultimap(name);
            manager.editDeviceUmultiset(name);
            break;
        }
        case 4: {
            // Поиск устройства по названию
            string name;
            cout << "Введите название устройства для поиска: ";
            cin >> name;
            manager.searchDeviceMap(name);
            manager.searchDeviceSet(name);
            manager.searchDeviceMultimap(name);
            manager.searchDeviceUmap(name);
            manager.searchDeviceUset(name);
            manager.searchDeviceUmultimap(name);
            manager.searchDeviceUmultiset(name);
            break;
        }
        case 5: {
            // Фильтрация устройств по типу
            string deviceType;
            cout << "Введите тип устройства для поиска: ";
            cin >> deviceType;
            manager.filterDeviceMap(deviceType);
            manager.filterDeviceSet(deviceType);
            manager.filterDeviceMultimap(deviceType);
            manager.filterDeviceUmap(deviceType);
            manager.filterDeviceUset(deviceType);
            manager.filterDeviceUmultimap(deviceType);
            manager.filterDeviceUmultiset(deviceType);
            break;
        }
        case 6: {
            // Печать всех устройств
            manager.printDeviceMap();
            manager.printDeviceSet();
            manager.printDeviceMultimap();
            manager.printDeviceMultiSet();
            manager.printDeviceUmap();
            manager.printDeviceUset();
            manager.printDeviceUmultimap();
            manager.printDeviceUmultiset();
            break;
        }
        case 7:
            // Запись в файл
            manager.writeToFileDeviceMap();
            manager.writeToFileDeviceSet();
            manager.writeToFileDeviceMultimap();
            manager.writeToFileDeviceMultiSet();
            manager.writeToFileDeviceUmap();
            manager.writeToFileDeviceUset();
            manager.writeToFileDeviceUmultimap();
            manager.writeToFileDeviceUmultiset();
            break;
            
        case 8:
            cout << "Выход...\n";
            break;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 8);
}

int main() {
    mainMenu();
    return 0;
}

