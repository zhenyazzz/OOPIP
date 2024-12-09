#include "NetworkDeviceManagerFactory.h"

unique_ptr<Manager> NetworkDeviceManagerFactory::createManager() const
{
    return make_unique<NetworkDeviceManager>();
}
