#pragma once
#include <memory>
#include "Manager.h"
using namespace std;
class ManagerFactory
{
public:
    virtual unique_ptr<Manager> createManager() const = 0;  
    virtual ~ManagerFactory() = default;
};

