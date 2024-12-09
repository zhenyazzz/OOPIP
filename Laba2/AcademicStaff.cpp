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
        cout << "������� �����: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stod(str);
}
int inputInt() {
    string str;
    regex regex_pattern("^-?[0-9]+$");
    do {
        cout << "������� �����: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stoi(str);
}

string inputPhoneNumber() {
    string phoneNumber;
    while (true) {
        cout << "������� ����� ��������: ";
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
            cout << "�������� ����� ��������. ����������, ��������� ����." << endl;
        }
    }
}
string inputEmailAddress() {
    string emailAddress;
    while (true) {
        cout << "������� ����� ����������� �����: ";
        cin >> emailAddress;
        int atPos = emailAddress.find('@');
        int dotPos = emailAddress.find('.', atPos);
        if (atPos != string::npos && dotPos != string::npos && atPos < dotPos) {
            return emailAddress;
        }
        else {
            cout << "�������� ����� ����������� �����. ����������, ��������� ����." << endl;
        }
    }
}

void setAdrres(Address& address) {
    int postalCode;
    string street, city, state, country;
    cout << "=== ������� ������ ===" << endl;
    cout << "������� ����:" << endl;
    cin >> state;
    cout << "������� ������ :" << endl;
    cin >> country;
    cout << "������� �����:" << endl;
    cin >> city;
    cout << "������� �����:" << endl;
    cin >> street;
    cout << "������� �������� ������" << endl;
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
        "3) Assistant\n" << "���� �� ������ �������?" << endl;
    m = inputInt();
    switch (m) {
    case 1: {
        cout << "������� ���:" << endl;
        cin >> name;
        phoneNumber = inputPhoneNumber();
        emailAddress = inputEmailAddress();
        setAdrres(address);
        cout << "������� ����� ��������:" << endl;
        studentNumber = inputInt();
        cout << "������� ������� ���� ��������:" << endl;
        averageMark = inputDouble();
        persons.push_back(new Student(name, phoneNumber, emailAddress, address, studentNumber, averageMark));
        break;

    }
    case 2: {
        cout << "������� ���:" << endl;
        cin >> name;
        phoneNumber = inputPhoneNumber();
        emailAddress = inputEmailAddress();
        setAdrres(address);
        cout << "������� ��������:" << endl;
        salary = inputDouble();
        cout << "������� ����� �����������:" << endl;
        staffNumber = inputInt();
        cout << "������� ���� � �����:" << endl;
        yearOfService = inputInt();
        cout << "������� ����� ���:" << endl;
        numberOfClasses = inputInt();
        cout << "������� ����� ���������:" << endl;
        numberOfStudents = inputInt();
        persons.push_back(new Professor(name, phoneNumber, emailAddress, address, salary, staffNumber, yearOfService, numberOfClasses, numberOfStudents));
        break;
    }
    case 3: {
        cout << "������� ���:" << endl;
        cin >> name;
        phoneNumber = inputPhoneNumber();
        emailAddress = inputEmailAddress();
        setAdrres(address);
        cout << "������� ��������:" << endl;
        salary = inputDouble();
        cout << "������� ����� �����������:" << endl;
        staffNumber = inputInt();
        cout << "������� ���� � �����:" << endl;
        yearOfService = inputInt();
        cout << "������� ����� ���:" << endl;
        numberOfClasses = inputInt();
        cout << "������� ����� ���������:" << endl;
        numberOfStudents = inputInt();
        cout << "������� ����� ��������:" << endl;
        studentNumber = inputInt();
        cout << "������� ������� ���� ��������:" << endl;
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
        cout << "������ ������� ������� �� ������" << endl;
        _getch();
    }
    else {
        cerr << "Unable to open file for reading." << endl;
    }
}

void AcademicStaff::deleteFromFile()
{
    int choice;
    cout << "�������� �������� ��� ������ ��� ��������:\n";
    cout << "1. ���\n";
    cout << "2. ����� ��������\n";
    cout << "3. Email\n";
    cout << "��� �����: ";
    cin >> choice;

    string searchTerm;
    switch (choice) {
    case 1:
        cout << "������� ��� ��� ������: ";
        cin >> searchTerm;
        break;
    case 2:
        cout << "������� ����� �������� ��� ������: ";
        cin >> searchTerm;
        break;
    case 3:
        cout << "������� email ��� ������: ";
        cin >> searchTerm;
        break;
    default:
        cout << "�������� �����!" << endl;
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
                cout << "����� �������: ";
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
                cout << "����� ���������: ";
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
                cout << "����� ���������: ";
                assistant.printInfo();
                found = true; 
            }
            else {
                tempAssistants << assistant;
            }
        }

        if (!found) {
            cout << "������� � ���������� ������� �� ������." << endl;
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

        cout << "�������� ���������." << endl;
        _getch();
    }
    else {
        cerr << "�� ������� ������� ���� ��� ��������� ������." << endl;
    }
}

void AcademicStaff::editInFile()
{
    int choice;
    cout << "�������� �������� ��� ������:\n";
    cout << "1. ���\n";
    cout << "2. ����� ��������\n";
    cout << "3. Email\n";
    cout << "��� �����: ";
    cin >> choice;

    string searchTerm;
    switch (choice) {
    case 1:
        cout << "������� ��� ��� ������: ";
        cin >> searchTerm;
        break;
    case 2:
        cout << "������� ����� �������� ��� ������: ";
        cin >> searchTerm;
        break;
    case 3:
        cout << "������� email ��� ������: ";
        cin >> searchTerm;
        break;
    default:
        cout << "�������� �����!" << endl;
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
                cout << "������ �������: ";
                student.printInfo();

                string name, number, email;
                cout << "������� ����� ���: ";
                cin >> name;
                cout << "������� ����� ����� ��������: ";
                number = inputPhoneNumber(); 
                cout << "������� ����� email: ";
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
                cout << "������ ���������: ";
                professor.printInfo();

                string name, number, email;
                cout << "������� ����� ���: ";
                cin >> name;
                cout << "������� ����� ����� ��������: ";
                number = inputPhoneNumber();
                cout << "������� ����� email: ";
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
                cout << "������ ���������: ";
                assistant.printInfo();

                string name, number, email;
                cout << "������� ����� ���: ";
                cin >> name;
                cout << "������� ����� ����� ��������: ";
                number = inputPhoneNumber();
                cout << "������� ����� email: ";
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

        cout << "������ ������� ���������." << endl;
        _getch();
    }
    else {
        cerr << "�� ������� ������� ���� ��� ��������� ������." << endl;
    }
}
    


void AcademicStaff::searchInFile()
{
    int choice;
    cout << "�������� �������� ��� ������:\n";
    cout << "1. ���\n";
    cout << "2. ����� ��������\n";
    cout << "3. Email\n";
    cout << "��� �����: ";
    cin >> choice;

    string searchTerm;
    switch (choice) {
    case 1:
        cout << "������� ��� ��� ������: ";
        cin >> searchTerm;
        break;
    case 2:
        cout << "������� ����� �������� ��� ������: ";
        cin >> searchTerm;
        break;
    case 3:
        cout << "������� email ��� ������: ";
        cin >> searchTerm;
        break;
    default:
        cout << "�������� �����!" << endl;
        return;
    }

    std::ifstream students("students.dat", ios::in | ios::binary);
    std::ifstream professors("professors.dat", ios::in | ios::binary);
    std::ifstream assistants("assistants.dat", ios::in | ios::binary);

    if (students.is_open() || professors.is_open() || assistants.is_open()) {
        Student student;
        while (students >> student) { 
            if (student.getName() == searchTerm || student.getPhoneNumber() == searchTerm || student.getEmailAddress() == searchTerm) {
                std::cout << "������ �������: ";
                student.printInfo(); 
            }
        }

        Professor professor;
        while (professors >> professor) {
            if (professor.getName() == searchTerm || professor.getPhoneNumber() == searchTerm || professor.getEmailAddress() == searchTerm) {
                std::cout << "������ ���������: ";
                professor.printInfo();
            }
        }

        Assistant assistant;
        while (assistants >> assistant) {
            if (assistant.getName() == searchTerm || assistant.getPhoneNumber() == searchTerm || assistant.getEmailAddress() == searchTerm) {
                std::cout << "������ ���������: ";
                assistant.printInfo();
            }
        }
        _getch();
        students.close();
        professors.close();
        assistants.close();
    }
    else {
        std::cerr << "�� ������� ������� ���� ��� ��������� ������." << std::endl;
    }
}
