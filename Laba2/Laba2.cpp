#include <iostream>
#include <Windows.h>
#include "Address.h"
#include "Person.h"
#include "Professor.h"
#include "Student.h"
#include "Assistant.h"
#include "AcademicStaff.h"


using namespace std;






void Menu() {
    cout << "\nМеню:\n" << "1) Добавление человека \n" << "2) Вывод на экран массива \n" <<
        "3) Запись массива в файл \n" <<"4) Чтение массива из файла\n"<< "5) Удаление объекта из файла\n"<<
        "6) Изменение объекта в файле\n"<< "7) Поиск объекта в файле\n" << "8) Выход\n" << "Выберите операцию : ";
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string fileName = "test2.dat";
    cout << " Лаболаторна работа  номер 2: \n";
    int menu;
    AcademicStaff academicStaff("test2.dat");
    do {
        system("cls");
        Menu();
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            academicStaff.addPerson();
            break;
        }
        case 2:
        {
            academicStaff.printAcademicStaff();
            break;
        }
        case 3: {
            academicStaff.writeToFile();
            break;
        }
        case 4: {
            academicStaff.readFromFile();
            break;
        }
        case 5: {
            academicStaff.deleteFromFile();
            break;
        }
        case 6: {
            academicStaff.editInFile();
            break;
        }
        case 7: {
            academicStaff.searchInFile();
            break;
        }
        case 8: {
            menu = 8; break;
        }
        default:
        {
            printf("Ошибка, проверьте введенные даныые");
            break;
        }
        }
    } while (menu != 8);


    return 0;
}