#include "ModemFactory.h"


ModemFactory::ModemFactory()
{
}

ModemFactory::~ModemFactory()
{
}

shared_ptr<NetworkDevice> ModemFactory::createDevice(const DeviceType& type, const int& id, const string& name, const string& ipAddress, const string& location, bool color, int paper) const
{
    return nullptr;
}

shared_ptr<NetworkDevice> ModemFactory::createDevice() const
{
    return make_shared<Modem>();
}
