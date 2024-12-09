#pragma once
#include "DeviceFactory.h"
#include "Modem.h"
class ModemFactory: public DeviceFactory
{
public:
	ModemFactory();
	~ModemFactory();
	shared_ptr<NetworkDevice> createDevice(const DeviceType& type, const int& id, const string& name, const string& ipAddress, const string& location, bool color, int paper) const;
	shared_ptr<NetworkDevice> createDevice() const override;
};

