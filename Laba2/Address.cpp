#include "Address.h"
#include <string>
#include <iomanip>
Address::Address() : street(""), city(""), state(""), country(""), postalCode(0) {

}

Address::Address(const string& street, const string& city, const string& state, const string& country, const int postalCode)
	: street(street), city(city), state(state), country(country), postalCode(postalCode) {

}

Address::~Address()
{

}


bool Address::validate()
{
	if (street.empty() || city.empty() || postalCode <= 0 || country.getName().empty() || state.empty()) {
		return false;
	}
	return true;
}

void Address::outputAsLabel()
{
	cout.setf(ios::left);
	cout << setw(20) << "Улица: " << street << endl;
	cout << setw(20) << "Город: "  << city << endl;
	cout << setw(20) << "Штат: " << state << endl;
	cout << setw(20) << "Страна: " << country.getName() << endl;
	cout << setw(20) << "Почтовый индекс: " << postalCode << endl;
	cout.unsetf(ios::left);

}

string Address::getStreet() const
{
	return street;
}

string Address::getCity() const
{
	return city;
}

string Address::getState() const
{
	return state;
}

string Address::getCountry() const
{
	return country.name;
}

int Address::getPostalCode() const
{
	return postalCode;
}

void Address::setCountryName(const string& countryName)
{
	country.setName(countryName);
}

void Address::setStreet(const string& street)
{
	this->street = street;
}

void Address::setCity(const string& city)
{
	this->city = city;
}

void Address::setState(const string& state)
{
	this->state = state;
}


void Address::setPostalCode(const int postalCode)
{
	this->postalCode = postalCode;
}



Address::Country::Country(string name)
{
	this->name = name;
}

Address::Country::~Country()
{
}

string Address::Country::getName()
{
	return name;
}

void Address::Country::setName(string name)
{
	this->name = name;
}

ostream& operator<<(ostream& os, const Address& address)
{
	size_t streetLength = address.street.size();
	size_t cityLength = address.city.size();
	size_t stateLength = address.state.size();
    size_t countryLength = address.country.name.size();

	os.write(reinterpret_cast<const char*>(&streetLength), sizeof(streetLength));
	os.write(address.street.c_str(), streetLength);

	os.write(reinterpret_cast<const char*>(&cityLength), sizeof(cityLength));
	os.write(address.city.c_str(), cityLength);

	os.write(reinterpret_cast<const char*>(&stateLength), sizeof(stateLength));
	os.write(address.state.c_str(), stateLength);

	os.write(reinterpret_cast<const char*>(&countryLength), sizeof(countryLength));
	os.write(address.country.name.c_str(), countryLength);

	os.write(reinterpret_cast<const char*>(&address.postalCode), sizeof(address.postalCode));

	return os;
	
}

istream& operator>>(istream& is, Address& address)
{
    size_t streetLength, cityLength, stateLength, countryLength;
    char* buffer;

    // Чтение длины и улицы
    if (!is.read(reinterpret_cast<char*>(&streetLength), sizeof(streetLength))) {
        cerr << "Ошибка при чтении длины улицы!" << endl;
        return is;
    }
    buffer = new char[streetLength + 1];
    is.read(buffer, streetLength);
    buffer[streetLength] = '\0';
    address.street = buffer;
    delete[] buffer;

    // Чтение длины и города
    if (!is.read(reinterpret_cast<char*>(&cityLength), sizeof(cityLength))) {
        cerr << "Ошибка при чтении длины города!" << endl;
        return is;
    }
    buffer = new char[cityLength + 1];
    is.read(buffer, cityLength);
    buffer[cityLength] = '\0';
    address.city = buffer;
    delete[] buffer;

    // Чтение длины и штата
    if (!is.read(reinterpret_cast<char*>(&stateLength), sizeof(stateLength))) {
        cerr << "Ошибка при чтении длины штата!" << endl;
        return is;
    }
    buffer = new char[stateLength + 1];
    is.read(buffer, stateLength);
    buffer[stateLength] = '\0';
    address.state = buffer;
    delete[] buffer;

    // Чтение длины и страны
    if (!is.read(reinterpret_cast<char*>(&countryLength), sizeof(countryLength))) {
        cerr << "Ошибка при чтении длины страны!" << endl;
        return is;
    }
    buffer = new char[countryLength + 1];
    is.read(buffer, countryLength);
    buffer[countryLength] = '\0';
    address.country.setName(buffer);
    delete[] buffer;

    // Чтение почтового кода
    if (!is.read(reinterpret_cast<char*>(&address.postalCode), sizeof(address.postalCode))) {
        cerr << "Ошибка при чтении почтового кода!" << endl;
        return is;
    }

    return is;

}
