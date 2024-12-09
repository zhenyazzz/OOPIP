#include "Person.h"
#include <string>
#include <iomanip>
Person::Person() :name(""), phoneNumber(""), emailAddress(""), address() {}


Person::Person(const string& name, const string& phoneNumber, string emailAdress, const Address& address)
	:name(name), phoneNumber(phoneNumber), emailAddress(emailAdress), address(address) {}

Person::~Person()
{
}

void Person::purchaseParkingPass()
{
	cout << "������� ������� ������������ ���������� �����." << endl;

	cout << "����������� ��������� ������� ����������!" << endl;
}

string Person::getName() const
{
	return name;
}

string Person::getPhoneNumber() const
{
	return phoneNumber;
}

string Person::getEmailAddress() const
{
	return emailAddress;
}

Address Person::getAddress() const
{
	return address;
}

void Person::printInfo()
{
	cout.setf(ios::left);
	cout << setw(20) << "���: "  << name << endl;
	cout << setw(20) << "�������: "  << phoneNumber << endl;
	cout << setw(20) << "����������� �����: " << emailAddress << endl;

	cout.unsetf(ios::left);
	address.outputAsLabel();
}

void Person::setName(const string& name)
{
	this->name = name;
}

void Person::setPhoneNumber(const string& phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Person::setEmailAddress(const string& emailAddress)
{
	this->emailAddress = emailAddress;
}

void Person::setAddress(Address address)
{
	this->address = address;
}

void Person::writeToFile()
{
}


ostream& operator<<(ostream& os, const Person& person)
{
	size_t nameLength = person.name.size();
	size_t phoneNumberLength = person.phoneNumber.size();
	size_t emailAddressLength = person.emailAddress.size();

	os.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
	os.write(person.name.c_str(), nameLength);

	os.write(reinterpret_cast<const char*>(&phoneNumberLength), sizeof(phoneNumberLength));
	os.write(person.phoneNumber.c_str(), phoneNumberLength);

	os.write(reinterpret_cast<const char*>(&emailAddressLength), sizeof(emailAddressLength));
	os.write(person.emailAddress.c_str(), emailAddressLength);

	os << person.getAddress();

	return os;
}

istream& operator>>(istream& is, Person& person)
{
	/*size_t nameLength, phoneNumberLength, emailAddressLength, addressLength;
	char* buffer;

	is.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
	cout << nameLength;
	buffer = new char[nameLength + 1];
	is.read(buffer, nameLength);
	buffer[nameLength] = '\0'; 
	person.name = buffer;
	delete[] buffer;

	is.read(reinterpret_cast<char*>(&phoneNumberLength), sizeof(phoneNumberLength));
	buffer = new char[phoneNumberLength + 1];
	is.read(buffer, phoneNumberLength);
	buffer[phoneNumberLength] = '\0';
	person.phoneNumber = buffer;
	delete[] buffer;

	is.read(reinterpret_cast<char*>(&emailAddressLength), sizeof(emailAddressLength));
	buffer = new char[emailAddressLength + 1];
	is.read(buffer, emailAddressLength);
	buffer[emailAddressLength] = '\0';
	person.emailAddress = buffer;
	delete[] buffer;

	Address address;
	is >> address;
	person.setAddress(address);

	return is;*/

	size_t nameLength, phoneNumberLength, emailAddressLength;

	// ������ ����� �����
	if (!is.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength))) {
		return is;
	}

	// �������� ������������ ����� ������
	if (nameLength > 1000) {  // ������ �������� ������ ��� ����� ������, ��������, 1000 ��������
		std::cerr << "������: ������������ ����� �����!" << std::endl;
		return is;
	}

	
	char* buffer = new char[nameLength + 1];
	if (!is.read(buffer, nameLength)) {
		std::cerr << "������ ��� ������ �����!" << std::endl;
		delete[] buffer;  
		return is;
	}

	buffer[nameLength] = '\0'; 
	person.name = buffer;  
	delete[] buffer;  

	if (!is.read(reinterpret_cast<char*>(&phoneNumberLength), sizeof(phoneNumberLength))) {
		std::cerr << "������ ��� ������ ����� ����������� ������!" << std::endl;
		return is;
	}

	buffer = new char[phoneNumberLength + 1];
	if (!is.read(buffer, phoneNumberLength)) {
		std::cerr << "������ ��� ������ ����������� ������!" << std::endl;
		delete[] buffer;
		return is;
	}
	buffer[phoneNumberLength] = '\0';
	person.phoneNumber = buffer;
	delete[] buffer;

	if (!is.read(reinterpret_cast<char*>(&emailAddressLength), sizeof(emailAddressLength))) {
		std::cerr << "������ ��� ������ ����� email!" << std::endl;
		return is;
	}

	buffer = new char[emailAddressLength + 1];
	if (!is.read(buffer, emailAddressLength)) {
		std::cerr << "������ ��� ������ email!" << std::endl;
		delete[] buffer;
		return is;
	}
	buffer[emailAddressLength] = '\0';
	person.emailAddress = buffer;
	delete[] buffer;

	// ������ � �������������� ������� Address
	Address address;
	is >> address;
	person.setAddress(address);

	return is;
}
