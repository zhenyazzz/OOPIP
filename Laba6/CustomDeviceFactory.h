#pragma once
#include "DeviceFactory.h"
#include "Router.h"
#include "Printer.h"
#include "Modem.h"
using namespace std;

class CustomDeviceFactory : public DeviceFactory {
public:
    CustomDeviceFactory();
    ~CustomDeviceFactory();
    shared_ptr<NetworkDevice> createDevice() const {
        return nullptr;
    }
    shared_ptr<NetworkDevice> createDevice(const DeviceType& type, const int& id, const string& name, const string& ipAddress, const string& location, bool color, int paper) const override {
        
        switch (type)
        {
        case ROUTER:
            return make_shared<Router>(id,name,ipAddress,location,color,paper);
        case PRINTER:
            return make_shared<Printer>();
        case MODEM:
            return make_shared<Modem>();
        default:
            break;
        }

        return nullptr; 
    }
};

