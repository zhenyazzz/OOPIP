#include "Switch.h"

Switch::Switch(const int& id,const string& name, const string& ipAddress, const string& location, int ports):
	NetworkDevice(id,name, ipAddress, location), portCount(ports) {}

Switch::Switch()
{
}

void Switch::setName(const string& name)
{
	this->name = name;
}

void Switch::setIpAddress(const string& ip)
{
	ipAddress = ip;
}

void Switch::setPortCount(int ports)
{
	portCount = ports;
}

void Switch::setLocation(const string& location)
{
	this->location = location;
}

string Switch::getName() const
{
	return name;
}

string Switch::getIpAddress() const
{
	return ipAddress;
}

string Switch::getLocation() const
{
	return location;
}

int Switch::getPortCount() const
{
	return portCount;
}

void Switch::print() const
{
	cout << "Switch [" << id << "] " << name << " (IP: " << ipAddress << ", Ports: " << portCount << ", Location: " << location << ")\n";
}

void Switch::edit()
{
	cout << "Редактирование коммутатора:\n";
	cout << "Введите новое имя: ";
	string newName;
	cin >> newName;
	setName(newName);
}

void Switch::writeToFile()
{
	ofstream file("switches.dat", ios::out | ios::binary);
	if (file.is_open()) {
		file << *this;
		file.close();
	}
	else {
		cerr << "Unable to open file for writing." << endl;
	}
}

ofstream& operator<<(ofstream& os, const Switch& s)
{
	os << static_cast<const NetworkDevice&>(s);
	os.write(reinterpret_cast<const char*>(&s.portCount), sizeof(s.portCount));
	return os;
}

ifstream& operator>>(ifstream& is, Switch& s)
{
	is >> static_cast<NetworkDevice&>(s);
	is.read(reinterpret_cast<char*>(&s.portCount), sizeof(s.portCount));
	return is;
}
