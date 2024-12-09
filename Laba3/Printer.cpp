#include "Printer.h"



Printer::Printer(const int& id, const string& name, const string& ipAddress, const string& location, bool color, int paper):
	NetworkDevice(id,name,ipAddress,location), isColor(color), paperCount(paper) {}

Printer::Printer()
{
}



void Printer::setName(const string& n)
{
	this->name = name;
}

void Printer::setIpAddress(const string& ip)
{
	this->ipAddress = ipAddress;
}

void Printer::setIsColor(bool color)
{
	this->isColor = color;
}

void Printer::setPaperCount(int paper)
{
	this->paperCount = paperCount;
}

string Printer::getName() const
{
	return name;
}

string Printer::getIpAddress() const
{
	return ipAddress;
}

bool Printer::getIsColor() const
{
	return isColor;
}

int Printer::getPaperCount() const
{
	return paperCount;
}

void Printer::print() const
{
	cout << "Printer [" << id << "] " << name << " (IP: " << ipAddress << ", Color: " << (isColor ? "Yes" : "No") << ", Paper: " << paperCount << ", Location: " << location << ")\n";
}

void Printer::edit()
{
	cout << "Редактирование принтера:\n";
	cout << "Введите новое имя: ";
	string newName;
	cin >> newName;
	setName(newName);
}

void Printer::writeToFile()
{
	ofstream file("printers.dat", ios::out | ios::binary);
	if (file.is_open()) {
		file << *this;
		file.close();
	}
	else {
		cerr << "Unable to open file for writing." << endl;
	}
}

ofstream& operator<<(ofstream& os, const Printer& p)
{
	os << static_cast<const NetworkDevice&>(p);

	
	os.write(reinterpret_cast<const char*>(&p.isColor), sizeof(p.isColor));
	os.write(reinterpret_cast<const char*>(&p.paperCount), sizeof(p.paperCount));

	return os;
	
}

ifstream& operator>>(ifstream& is, Printer& p)
{
	is >> static_cast<NetworkDevice&>(p);

	
	is.read(reinterpret_cast<char*>(&p.isColor), sizeof(p.isColor));
	is.read(reinterpret_cast<char*>(&p.paperCount), sizeof(p.paperCount));

	return is;

	
}
