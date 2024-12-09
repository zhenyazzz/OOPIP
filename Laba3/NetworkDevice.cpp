#include "NetworkDevice.h"


NetworkDevice::NetworkDevice(const int& id, const string& name, const string& ipAddress, const string& location):
	id(id) , name(name), ipAddress(ipAddress), location(location) {}

NetworkDevice::NetworkDevice()
{

}

void NetworkDevice::setId(const int& id)
{
	this->id = id;
}

void NetworkDevice::setName(const string& name)
{
	this->name = name;
}

void NetworkDevice::setIpAddress(const string& ipAddress)
{
	this->ipAddress = ipAddress;
}

void NetworkDevice::setLocation(const string& location)
{
	this->location = location;
}

int NetworkDevice::getId() const
{
	return id;
}

string NetworkDevice::getName() const
{
	return name;
}

string NetworkDevice::getIpAddress() const
{
	return ipAddress;
}

string NetworkDevice::getLocation() const
{
	return location;
}

void NetworkDevice::print() const
{
	cout << "Name: " << name << ", IP: " << ipAddress
		<< ", Location: " << location << '\n';
}

void NetworkDevice::edit()
{
}

void NetworkDevice::writeToFile()
{
}

ostream& operator<<(ostream& os, const NetworkDevice& device)
{
	os.write(reinterpret_cast<const char*>(&device.id), sizeof(device.id));
	size_t nameLength = device.name.size();
	size_t ipLength = device.ipAddress.size();
	size_t locationLength = device.location.size();

	os.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
	os.write(device.name.c_str(), nameLength);

	os.write(reinterpret_cast<const char*>(&ipLength), sizeof(ipLength));
	os.write(device.ipAddress.c_str(), ipLength);

	os.write(reinterpret_cast<const char*>(&locationLength), sizeof(locationLength));
	os.write(device.location.c_str(), locationLength);
	return os;
}

istream& operator>>(istream& is, NetworkDevice& device)
{
	if (!is.read(reinterpret_cast<char*>(&device.id), sizeof(device.id))) {
		cerr << "Ошибка при чтении id!" << endl;
		return is;
	}

	size_t nameLength, ipLength, locationLength;

	if (!is.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength))) {
		cerr << "Ошибка при чтении длины имени!" << endl;
		return is;
	}
	device.name.resize(nameLength);
	if (!is.read(&device.name[0], nameLength)) {
		cerr << "Ошибка при чтении имени!" << endl;
		return is;
	}

	if (!is.read(reinterpret_cast<char*>(&ipLength), sizeof(ipLength))) {
		cerr << "Ошибка при чтении длины IP-адреса!" << endl;
		return is;
	}
	device.ipAddress.resize(ipLength);
	if (!is.read(&device.ipAddress[0], ipLength)) {
		cerr << "Ошибка при чтении IP-адреса!" << endl;
		return is;
	}

	if (!is.read(reinterpret_cast<char*>(&locationLength), sizeof(locationLength))) {
		cerr << "Ошибка при чтении длины локации!" << endl;
		return is;
	}
	device.location.resize(locationLength);
	if (!is.read(&device.location[0], locationLength)) {
		cerr << "Ошибка при чтении локации!" << endl;
		return is;
	}

	return is;

	
}
