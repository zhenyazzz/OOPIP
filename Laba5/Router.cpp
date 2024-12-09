#include "Router.h"

Router::Router(const int& id, const string& name, const string& ipAddress, const string& location, int ports) :
	NetworkDevice(id, name, ipAddress, location), portCount(ports) { }

Router::Router()
{
}

Router::~Router()
{
}

void Router::setName(const string& name)
{
	this->name = name;
}

void Router::setIpAddress(const string& ip)
{
	this->ipAddress = ip;
}

void Router::setPortCount(int ports)
{
	this->portCount = ports;
}

void Router::setLocation(const string& location)
{
	this->location = location;
}

string Router::getName() const
{
	return name;
}

string Router::getIpAddress() const
{
	return ipAddress;
}

string Router::getLocation() const
{
	return location;
}

int Router::getPortCount() const
{
	return portCount;
}

void Router::print() const
{
	cout << "Router [" << id << "] " << name << " (IP: " << ipAddress << ", Ports: " << portCount << ", Location: " << location << ")\n";
}

void Router::edit()
{
	cout << "Редактирование роутера:\n";
	cout << "Введите новое имя: ";
	string newName;
	cin >> newName;
	this->setName(newName);
}

string Router::getType()
{
	return type;
}

shared_ptr<NetworkDevice> Router::clone() const
{
	return make_shared<Router>(*this);
}

void Router::writeToFile()
{
	ofstream file("routers.dat", ios::app | ios::binary);
	if (file.is_open()) {
		file << *this;
		file.close();
	}
	else {
		cerr << "Unable to open file for writing." << endl;
	}
}

ofstream& operator<<(ofstream& os, const Router& r)
{
	os << static_cast<const NetworkDevice&>(r);
	os.write(reinterpret_cast<const char*>(&r.portCount), sizeof(r.portCount));
	return os;
}

ifstream& operator>>(ifstream& is, Router& r)
{
	is >> static_cast<NetworkDevice&>(r);
	is.read(reinterpret_cast<char*>(&r.portCount), sizeof(r.portCount));
	return is;
}

