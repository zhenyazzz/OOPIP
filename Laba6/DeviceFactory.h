#pragma once
#include <memory>
#include <string>
#include "NetworkDevice.h"

enum DeviceType
{
	ROUTER,
	PRINTER,
	MODEM
};
using namespace std;
class DeviceFactory
{	
public:
	virtual shared_ptr<NetworkDevice> createDevice(const DeviceType& type, const int& id, const string& name, const string& ipAddress, const string& location, bool color, int paper) const = 0;
	virtual shared_ptr<NetworkDevice> createDevice() const = 0;
	virtual ~DeviceFactory() = default;
};

