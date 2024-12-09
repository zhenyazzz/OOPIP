#pragma once
#include "ManagerFactory.h"
#include "NetworkDeviceManager.h"
class NetworkDeviceManagerFactory: public ManagerFactory
{	public:
	unique_ptr<Manager> createManager() const;
};

