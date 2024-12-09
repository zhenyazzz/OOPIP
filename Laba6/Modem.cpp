#include "Modem.h"

Modem::Modem(const int& id, const string& name, const string& ip, const string& location, int sp) :
	NetworkDevice(id, name, ip, location), speed(sp)
{
}

Modem::Modem()
{
}

Modem::~Modem()
{
}

void Modem::setName(const string& name)
{
	this->name = name;
}

void Modem::setIpAddress(const string& ip)
{
	this->ipAddress = ip;
}

void Modem::setSpeed(int speed)
{
	this->speed = speed;
}

void Modem::setLocation(const string& location)
{
	this->location = location;
}

string Modem::getName() const
{
	return name;
}

string Modem::getIpAddress() const
{
	return ipAddress;
}

int Modem::getSpeed() const
{
	return speed;
}

string Modem::getLocation() const
{
	return location;
}

void Modem::print() const
{
	cout << "Modem [" << id << "] " << name << " (IP: " << ipAddress << ", Speed: " << speed << ", Location: " << location << ")\n";
}

void Modem::edit()
{
	cout << "Редактирование модема:\n";
	cout << "Введите новое имя: ";
	string newName;
	cin >> newName;
	this->setName(newName);
}

string Modem::getType()
{
	return type;
}

void Modem::writeToFile()
{
	ofstream file("modems.dat", ios::app | ios::binary);
	if (file.is_open()) {
		file << *this;
		file.close();
	}
	else {
		cerr << "Unable to open file for writing." << endl;
	}
}

shared_ptr<NetworkDevice> Modem::clone() const
{
	return make_shared<Modem>(*this);

}

ofstream& operator<<(ofstream& os, const Modem& m)
{
	os << static_cast<const NetworkDevice&>(m);
	os.write(reinterpret_cast<const char*>(&m.speed), sizeof(m.speed));
	return os;
}

ifstream& operator>>(ifstream& is, Modem& m)
{
	is >> static_cast<NetworkDevice&>(m);
	is.read(reinterpret_cast<char*>(&m.speed), sizeof(m.speed));
	return is;
}

