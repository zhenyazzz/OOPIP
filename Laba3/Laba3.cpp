#include <iostream>
#include <conio.h>
#include <regex>
#include <windows.h>
#include "NetworkDevice.h"
#include "NetworkDeviceManager.h"
#include <algorithm>
#include <iomanip>

using namespace std;


void showMenu() {
    cout << "\n--- Меню системы управления сетевыми устройствами ---\n";
    cout << "1. Добавить сетевое устройство в список\n";
    cout << "2. Удалить сетевое устройство из списка\n";
    cout << "3. Редактировать сетевое устройство в списке\n";
    cout << "4. Вывести список сетевых устройств\n";
    cout << "5. Отсортировать сетевые устройства по названию\n";
    cout << "6. Найти сетевое устройство по ID\n";
    cout << "7. Сохранить список сетевых устройств в файл\n";
    cout << "8. Загрузить список сетевых устройств из файла\n";
    cout << "9. Добавить сетевое устройство в вектор\n";
    cout << "10. Удалить сетевое устройство из вектора\n";
    cout << "11. Редактировать сетевое устройство в векторе\n";
    cout << "12. Вывести вектор сетевых устройств\n";
    cout << "13. Отсортировать сетевые устройства по названию в векторе\n";
    cout << "14. Найти сетевое устройство по ID в векторе\n";
    cout << "15. Добавить сетевое устройство в массив\n";
    cout << "16. Удалить сетевое устройство из массива\n";
    cout << "17. Редактировать сетевое устройство в массиве\n";
    cout << "18. Вывести массив сетевых устройств\n";
    cout << "19. Отсортировать сетевые устройства по названию в массиве\n";
    cout << "20. Найти сетевое устройство по ID в массиве\n";
    cout << "0. Выход\n";
    cout << "Введите ваш выбор: ";
}
int getValidInt() {
    string str;
    regex regex_pattern("^-?[0-9]+$");
    do {
        cout << "Введите число: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stoi(str);
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int option;
    NetworkDeviceManager manager;
    do {
        system("cls");
        showMenu();
        option = getValidInt();

        switch (option) {
        case 1: manager.addDeviceToList(); break;
        case 2: manager.removeDeviceFromList(); break;    
        case 3: manager.editDeviceInList(); break;
        case 4: manager.printList(); break;
        case 5: manager.sortDevicesListName(); break;
        case 6: manager.findDeviceBylistID(); break;
        case 7: manager.saveToFile(); break;
        case 8: manager.loadFromFile(); break;
        case 9: manager.addDeviceToVector(); break;
        case 10: manager.removeDeviceFromVector(); break;
        case 11: manager.editDeviceInVector(); break;
        case 12: manager.printVector(); break;
        case 13: manager.sortDevicesVectorName(); break;
        case 14: manager.findDeviceByVectorID(); break;
        case 15: manager.addDeviceToArray(); break;
        case 16: manager.removeDeviceFromArray(); break;
        case 17:manager.editDeviceInArray(); break;
        case 18: manager.printArray(); break;
        case 19: manager.sortDevicesArrayName(); break;
        case 20: manager.findDeviceByArrayID(); break;
        case 0: cout << "Exiting...\n"; break;
        default: cout << "Invalid option, please try again.\n"; break;
        }
    } while (option != 0);

    return 0;
}