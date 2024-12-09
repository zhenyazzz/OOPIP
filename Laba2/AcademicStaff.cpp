#include "AcademicStaff.h"
#include "Address.h"
#include <regex>
#include "Student.h"
#include "Professor.h"
#include "Assistant.h"
#include <conio.h>



double inputDouble()
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
int inputInt() {
    string str;
    regex regex_pattern("^-?[0-9]+$");
    do {
        cout << "Введите число: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stoi(str);
}

string inputPhoneNumber() {
    string phoneNumber;
    while (true) {
        cout << "Введите номер телефона: ";
        cin >> phoneNumber;
        bool valid = true;
        for (char c : phoneNumber) {
            if (!isdigit(c) && c != '+' && c != '-' && c != ' ') {
                valid = false;
                break;
            }
        }
        if (valid && phoneNumber.length() >= 10) {
            return phoneNumber;
        }
        else {
            cout << "Неверный номер телефона. Пожалуйста, повторите ввод." << endl;
        }
    }
}
string inputEmailAddress() {
    string emailAddress;
    while (true) {
        cout << "Введите адрес электронной почты: ";
        cin >> emailAddress;
        int atPos = emailAddress.find('@');
        int dotPos = emailAddress.find('.', atPos);
        if (atPos != string::npos && dotPos != string::npos && atPos < dotPos) {
            return emailAddress;
        }
        else {
            cout << "Неверный адрес электронной почты. Пожалуйста, повторите ввод." << endl;
        }
    }
}

void setAdrres(Address& address) {
    int postalCode;
    string street, city, state, country;
    cout << "=== Введите адресс ===" << endl;
    cout << "Введите штат:" << endl;
    cin >> state;
    cout << "Введите страну :" << endl;
    cin >> country;
    cout << "Введите город:" << endl;
    cin >> city;
    cout << "Введите улицу:" << endl;
    cin >> street;
    cout << "Введите почтовый индекс" << endl;
    postalCode = inputInt();
    address.setCity(city);
    address.setCountryName(country);
    address.setPostalCode(postalCode);
    address.setState(state);
    address.setStreet(street);
}
AcademicStaff::AcademicStaff(const string& filleName)
{
	this->filename = filleName;
	
}

AcademicStaff::~AcademicStaff()
{
    for (Person* person : persons) {
        delete person;
    }

    persons.clear();
}

void AcademicStaff::addPerson()
{
    int m, studentNumber, staffNumber, yearOfService, numberOfClasses, numberOfStudents;
    float averageMark, salary;
    string name, phoneNumber, emailAddress;
    Address address;
    cout <<  "1) Student\n" << "2) Professor\n" <<
        "3) Assistant\n" << "Кого вы хотите создать?" << endl;
    m = inputInt();
    switch (m) {
    case 1: {
        cout << "Введите имя:" << endl;
        cin >> name;
        phoneNumber = inputPhoneNumber();
        emailAddress = inputEmailAddress();
        setAdrres(address);
        cout << "Введите номер студента:" << endl;
        studentNumber = inputInt();
        cout << "Введите средний балл студента:" << endl;
        averageMark = inputDouble();
        persons.push_back(new Student(name, phoneNumber, emailAddress, address, studentNumber, averageMark));
        break;

    }
    case 2: {
        cout << "Введите имя:" << endl;
        cin >> name;
        phoneNumber = inputPhoneNumber();
        emailAddress = inputEmailAddress();
        setAdrres(address);
        cout << "Введите зарплату:" << endl;
        salary = inputDouble();
        cout << "Введите число сотрудников:" << endl;
        staffNumber = inputInt();
        cout << "Введите стаж в годах:" << endl;
        yearOfService = inputInt();
        cout << "Введите число пар:" << endl;
        numberOfClasses = inputInt();
        cout << "Введите число студентов:" << endl;
        numberOfStudents = inputInt();
        persons.push_back(new Professor(name, phoneNumber, emailAddress, address, salary, staffNumber, yearOfService, numberOfClasses, numberOfStudents));
        break;
    }
    case 3: {
        cout << "Введите имя:" << endl;
        cin >> name;
        phoneNumber = inputPhoneNumber();
        emailAddress = inputEmailAddress();
        setAdrres(address);
        cout << "Введите зарплату:" << endl;
        salary = inputDouble();
        cout << "Введите число сотрудников:" << endl;
        staffNumber = inputInt();
        cout << "Введите стаж в годах:" << endl;
        yearOfService = inputInt();
        cout << "Введите число пар:" << endl;
        numberOfClasses = inputInt();
        cout << "Введите число студентов:" << endl;
        numberOfStudents = inputInt();
        cout << "Введите номер студента:" << endl;
        studentNumber = inputInt();
        cout << "Введите средний балл студента:" << endl;
        averageMark = inputDouble();
        persons.push_back(new Assistant(name, phoneNumber, emailAddress, address, salary, staffNumber, yearOfService, numberOfClasses, numberOfStudents, studentNumber, averageMark));
        break;
    }
    }
}

void AcademicStaff::removePerson()
{
}

void AcademicStaff::printAcademicStaff()
{
    system("cls");
    for (auto person : persons)
    {
        person->printInfo();
        cout << endl;
    }
    _getch();
}

void AcademicStaff::writeToFile()
{
    for (auto& person : persons) {
        person->writeToFile();
    }
    _getch();
}

void AcademicStaff::readFromFile()
{
    ifstream assistants("assistants.dat", ios::in | ios::binary);
    ifstream professors("professors.dat", ios::in | ios::binary);
    ifstream students("students.dat", ios::in | ios::binary);
    if (assistants.is_open() && professors.is_open() && students.is_open()) {
        for (auto& person : persons) {
            delete person;
        }
        persons.clear();
        while (true) {
            Student* student = new Student();  
            if (students >> *student) { 
                persons.push_back(student);  
            }
            else {
                delete student;  
                break;  
            }
        }

        while (true) {
            Professor* professor = new Professor(); 
            if (professors >> *professor) {
                persons.push_back(professor);
            }
            else {
                delete professor; 
                break;
            }
        }

        while (true) {
            Assistant* assistant = new Assistant();  
            if (assistants >> *assistant) {
                persons.push_back(assistant);
            }
            else {
                delete assistant;  
                break;
            }
        }
       
        assistants.close();
        professors.close();
        students.close();
        cout << "Данные успешно считаны из файлов" << endl;
        _getch();
    }
    else {
        cerr << "Unable to open file for reading." << endl;
    }
}

void AcademicStaff::deleteFromFile()
{
    int choice;
    cout << "Выберите критерий для поиска для удаления:\n";
    cout << "1. Имя\n";
    cout << "2. Номер телефона\n";
    cout << "3. Email\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    string searchTerm;
    switch (choice) {
    case 1:
        cout << "Введите имя для поиска: ";
        cin >> searchTerm;
        break;
    case 2:
        cout << "Введите номер телефона для поиска: ";
        cin >> searchTerm;
        break;
    case 3:
        cout << "Введите email для поиска: ";
        cin >> searchTerm;
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return;
    }

    ifstream students("students.dat", ios::in | ios::binary);
    ifstream professors("professors.dat", ios::in | ios::binary);
    ifstream assistants("assistants.dat", ios::in | ios::binary);

    

    if (students.is_open() && professors.is_open() && assistants.is_open()) {
        bool found = false;

        ofstream tempStudents("temp_students.dat", ios::out | ios::binary);
        ofstream tempProfessors("temp_professors.dat", ios::out | ios::binary);
        ofstream tempAssistants("temp_assistants.dat", ios::out | ios::binary);

        Student student;
        while (students >> student) {
            if (student.getName() == searchTerm || student.getPhoneNumber() == searchTerm || student.getEmailAddress() == searchTerm) {
                cout << "Удалён студент: ";
                student.printInfo();
                found = true; 
            }
            else {
                tempStudents << student;
            }
        }

        Professor professor;
        while (professors >> professor) {
            if (professor.getName() == searchTerm || professor.getPhoneNumber() == searchTerm || professor.getEmailAddress() == searchTerm) {
                cout << "Удалён профессор: ";
                professor.printInfo();
                found = true; 
            }
            else {
                tempProfessors << professor;
            }
        }

        Assistant assistant;
        while (assistants >> assistant) {
            if (assistant.getName() == searchTerm || assistant.getPhoneNumber() == searchTerm || assistant.getEmailAddress() == searchTerm) {
                cout << "Удалён ассистент: ";
                assistant.printInfo();
                found = true; 
            }
            else {
                tempAssistants << assistant;
            }
        }

        if (!found) {
            cout << "Человек с указанными данными не найден." << endl;
        }

        students.close();
        professors.close();
        assistants.close();
        tempStudents.close();
        tempProfessors.close();
        tempAssistants.close();

        remove("students.dat");
        rename("temp_students.dat", "students.dat");
        remove("professors.dat");
        rename("temp_professors.dat", "professors.dat");
        remove("assistants.dat");
        rename("temp_assistants.dat", "assistants.dat");

        cout << "Удаление завершено." << endl;
        _getch();
    }
    else {
        cerr << "Не удалось открыть один или несколько файлов." << endl;
    }
}

void AcademicStaff::editInFile()
{
    int choice;
    cout << "Выберите критерий для поиска:\n";
    cout << "1. Имя\n";
    cout << "2. Номер телефона\n";
    cout << "3. Email\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    string searchTerm;
    switch (choice) {
    case 1:
        cout << "Введите имя для поиска: ";
        cin >> searchTerm;
        break;
    case 2:
        cout << "Введите номер телефона для поиска: ";
        cin >> searchTerm;
        break;
    case 3:
        cout << "Введите email для поиска: ";
        cin >> searchTerm;
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return;
    }

    ifstream students("students.dat", ios::in | ios::binary);
    ifstream professors("professors.dat", ios::in | ios::binary);
    ifstream assistants("assistants.dat", ios::in | ios::binary);

    if (students.is_open() || professors.is_open() || assistants.is_open()) {
        ofstream tempStudents("temp_students.dat", ios::out | ios::binary);
        ofstream tempProfessors("temp_professors.dat", ios::out | ios::binary);
        ofstream tempAssistants("temp_assistants.dat", ios::out | ios::binary);

        Student student;
        while (students >> student) {
            if (student.getName() == searchTerm || student.getPhoneNumber() == searchTerm || student.getEmailAddress() == searchTerm) {
                cout << "Найден студент: ";
                student.printInfo();

                string name, number, email;
                cout << "Введите новое имя: ";
                cin >> name;
                cout << "Введите новый номер телефона: ";
                number = inputPhoneNumber(); 
                cout << "Введите новый email: ";
                email = inputEmailAddress(); 

                student.setName(name);
                student.setPhoneNumber(number);
                student.setEmailAddress(email);
            }
            tempStudents << student;
        }

        Professor professor;
        while (professors >> professor) {
            if (professor.getName() == searchTerm || professor.getPhoneNumber() == searchTerm || professor.getEmailAddress() == searchTerm) {
                cout << "Найден профессор: ";
                professor.printInfo();

                string name, number, email;
                cout << "Введите новое имя: ";
                cin >> name;
                cout << "Введите новый номер телефона: ";
                number = inputPhoneNumber();
                cout << "Введите новый email: ";
                email = inputEmailAddress();

                professor.setName(name);
                professor.setPhoneNumber(number);
                professor.setEmailAddress(email);
            }
            tempProfessors << professor;
        }

        Assistant assistant;
        while (assistants >> assistant) {
            if (assistant.getName() == searchTerm || assistant.getPhoneNumber() == searchTerm || assistant.getEmailAddress() == searchTerm) {
                cout << "Найден ассистент: ";
                assistant.printInfo();

                string name, number, email;
                cout << "Введите новое имя: ";
                cin >> name;
                cout << "Введите новый номер телефона: ";
                number = inputPhoneNumber();
                cout << "Введите новый email: ";
                email = inputEmailAddress();

                assistant.setName(name);
                assistant.setPhoneNumber(number);
                assistant.setEmailAddress(email);
            }
            tempAssistants << assistant;
        }

        students.close();
        professors.close();
        assistants.close();
        tempStudents.close();
        tempProfessors.close();
        tempAssistants.close();

        remove("students.dat");
        rename("temp_students.dat", "students.dat");
        remove("professors.dat");
        rename("temp_professors.dat", "professors.dat");
        remove("assistants.dat");
        rename("temp_assistants.dat", "assistants.dat");

        cout << "Данные успешно обновлены." << endl;
        _getch();
    }
    else {
        cerr << "Не удалось открыть один или несколько файлов." << endl;
    }
}
    


void AcademicStaff::searchInFile()
{
    int choice;
    cout << "Выберите критерий для поиска:\n";
    cout << "1. Имя\n";
    cout << "2. Номер телефона\n";
    cout << "3. Email\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    string searchTerm;
    switch (choice) {
    case 1:
        cout << "Введите имя для поиска: ";
        cin >> searchTerm;
        break;
    case 2:
        cout << "Введите номер телефона для поиска: ";
        cin >> searchTerm;
        break;
    case 3:
        cout << "Введите email для поиска: ";
        cin >> searchTerm;
        break;
    default:
        cout << "Неверный выбор!" << endl;
        return;
    }

    std::ifstream students("students.dat", ios::in | ios::binary);
    std::ifstream professors("professors.dat", ios::in | ios::binary);
    std::ifstream assistants("assistants.dat", ios::in | ios::binary);

    if (students.is_open() || professors.is_open() || assistants.is_open()) {
        Student student;
        while (students >> student) { 
            if (student.getName() == searchTerm || student.getPhoneNumber() == searchTerm || student.getEmailAddress() == searchTerm) {
                std::cout << "Найден студент: ";
                student.printInfo(); 
            }
        }

        Professor professor;
        while (professors >> professor) {
            if (professor.getName() == searchTerm || professor.getPhoneNumber() == searchTerm || professor.getEmailAddress() == searchTerm) {
                std::cout << "Найден профессор: ";
                professor.printInfo();
            }
        }

        Assistant assistant;
        while (assistants >> assistant) {
            if (assistant.getName() == searchTerm || assistant.getPhoneNumber() == searchTerm || assistant.getEmailAddress() == searchTerm) {
                std::cout << "Найден ассистент: ";
                assistant.printInfo();
            }
        }
        _getch();
        students.close();
        professors.close();
        assistants.close();
    }
    else {
        std::cerr << "Не удалось открыть один или несколько файлов." << std::endl;
    }
}
