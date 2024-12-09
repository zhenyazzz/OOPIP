#include <iostream>
#include <Windows.h>
#include "Address.h"
#include "Person.h"
void setAdrres(Address& address) {
    int postalCode;
    string street, city, state, country;
    cout << "=== Введите адресс ===" << endl;
    cout << "Введите state:" << endl;
    cin >> state;
    cout << "Введите страну :" << endl;
    cin >> country;
    cout << "Введите город:" << endl;
    cin >> city;
    cout << "Введите улицу:" << endl;
    cin >> street;
    cout << "Введите почтовый индекс" << endl;
    cin >> postalCode;
    address.setCity(city);
    address.setCountry(country);
    address.setPostalCode(postalCode);
    address.setState(state);
    address.setStreet(street);
}
void Menu() {
    cout << "\nМеню:\n" << "1) Ввод массива \n" << "2) Вывод на экран массива \n" <<
        "3) Выход \n" << "Выберите операцию:  ";
}
void fillArray(Person** persons, int& size) {
    int m, studentNumber, averageMark, salary, staffNumber, yearOfService, numberOfClasses, numberOfStudents;
    string name, phoneNumber, emailAddress;
    Address address;
    for (int i = 0; i < size; i++) {   
        cout << "1) Person\n" << "2) Student\n" << "3) Professor\n" <<
            "4) Assistant\n" << "Кого вы хотите создать?" << endl;
        cin >> m;
        switch (m) {
        case 1: {
            cout << "Введите имя:" << endl;
            cin >> name;
            cout << "Введите номер телефона:" << endl;
            cin >> phoneNumber;
            cout << "Введите адрес элктронной почты:" << endl;
            cin >> emailAddress;
            setAdrres(address);
            persons[i] = new Person(name,phoneNumber,emailAddress,address); break;
        }
        case 2: {
            cout << "Введите имя:" << endl;
            cin >> name;
            cout << "Введите номер телефона:" << endl;
            cin >> phoneNumber;
            cout << "Введите адрес элктронной почты:" << endl;
            cin >> emailAddress;
            setAdrres(address);
            cout << "Введите номер студента:" << endl;
            cin >> studentNumber;
            cout << "Введите средний балл студента:" << endl;
            cin >> averageMark;
            persons[i] = new Student(name, phoneNumber, emailAddress, address,studentNumber,averageMark); break;

        }
        case 3: { 
            cout << "Введите имя:" << endl;
            cin >> name;
            cout << "Введите номер телефона:" << endl;
            cin >> phoneNumber;
            cout << "Введите адрес элктронной почты:" << endl;
            cin >> emailAddress;
            setAdrres(address);
            cout << "Введите зарплату:" << endl;
            cin >> salary;
            cout << "Введите число сотрудников:" << endl;
            cin >> staffNumber;
            cout << "Введите стаж в годах:" << endl;
            cin >> yearOfService;
            cout << "Введите число пар:" << endl;
            cin >> numberOfClasses;
            cout << "Введите число студентов:" << endl;
            cin >> numberOfStudents;
            persons[i] = new Professor(name,phoneNumber,emailAddress,address,salary,staffNumber,yearOfService,numberOfClasses,numberOfStudents); break;
        }    
        case 4: {
            cout << "Введите имя:" << endl;
            cin >> name;
            cout << "Введите номер телефона:" << endl;
            cin >> phoneNumber;
            cout << "Введите адрес электронной почты:" << endl;
            cin >> emailAddress;
            setAdrres(address);
            cout << "Введите зарплату:" << endl;
            cin >> salary;
            cout << "Введите число сотрудников:" << endl;
            cin >> staffNumber;
            cout << "Введите стаж в годах:" << endl;
            cin >> yearOfService;
            cout << "Введите число пар:" << endl;
            cin >> numberOfClasses;
            cout << "Введите число студентов:" << endl;
            cin >> numberOfStudents;
            cout << "Введите номер студента:" << endl;
            cin >> studentNumber;
            cout << "Введите средний балл студента:" << endl;
            cin >> averageMark;
            persons[i] = new Assistant(name,phoneNumber,emailAddress,address,salary,staffNumber,yearOfService,numberOfClasses,numberOfStudents,studentNumber,averageMark); break;
        }
        }       
    }
}
void outputArray(Person** persons, int& size) {
    for (int i = 0; i < size; i++) {
        cout << "Человек номер " << i + 1 << ": " << endl;
        persons[i]->printInfo();
    }
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string fileName = "test5.txt";
    cout << " Лаболаторна работа  номер 5: \n" << "Введите размер массива объектов:";
    int size, menu;
    float max;
    cin >> size;
    Person** persons = new Person * [size];
    do {
        Menu();
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            fillArray(persons, size);
            break;
        }
        case 2:
        {
            outputArray(persons, size);
            break;
        }
        case 3: {
            menu = 3; break;
        }
        default:
        {
            printf("Ошибка, проверьте введенные даныые");
            break; }
        }
        }
        while (menu != 3);

        delete[] persons;

        return 0;
}