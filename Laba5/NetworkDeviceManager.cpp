#include "NetworkDeviceManager.h"
#include <regex>
#include <conio.h>
#include <functional>


NetworkDeviceManager::NetworkDeviceManager()
{
}

NetworkDeviceManager::~NetworkDeviceManager() {
    
}

double NetworkDeviceManager::inputDouble()
{
    string str;
    regex regex_pattern("-?[0-9]+.?[0-9]+");
    do
    {
        cout << "Введите число: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stod(str);
}

int NetworkDeviceManager::inputInt()
{
    string str;
    regex regex_pattern("^-?[0-9]+$");
    do {
        cout << "Введите число: ";
        cin >> str;
    } while (!regex_match(str, regex_pattern));

    return stoi(str);
}

void NetworkDeviceManager::addDeviceStack(shared_ptr<NetworkDevice> device) {
    deviceStack.push(device);
}
void NetworkDeviceManager::addDeviceQueue(shared_ptr<NetworkDevice> device) {
    deviceQueue.push(device);
}
void NetworkDeviceManager::addDevicePriorityQueue(shared_ptr<NetworkDevice> device) {
    devicePriorityQueue.push(device);  
}


void NetworkDeviceManager::removeDeviceStack(const string& deviceName) {

    stack<shared_ptr<NetworkDevice>> tempStack;
    bool found = false;
    system("cls");
    while (!deviceStack.empty()) {
        shared_ptr<NetworkDevice>  topDevice = deviceStack.top();
        deviceStack.pop();

        if (topDevice->getName() == deviceName) {
            topDevice.reset();
            found = true;
            break;
        }
        tempStack.push(topDevice);
    }

    while (!tempStack.empty()) {
        deviceStack.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        cout << "Устройство не найдено в стеке.\n";
    }
    else
    {
        cout << "Устройство удалено  из стека.\n";
    }
    _getch();
}
void NetworkDeviceManager::removeDeviceQueue(const string& deviceName) {
    queue<shared_ptr<NetworkDevice>> tempQueue;
    bool found = false;
    system("cls");
    while (!deviceQueue.empty()) {
        shared_ptr<NetworkDevice> frontDevice = deviceQueue.front();
        deviceQueue.pop();

        if (frontDevice->getName() == deviceName) {
            frontDevice.reset();
            found = true;
            break;
        }
        tempQueue.push(frontDevice);
    }

    while (!tempQueue.empty()) {
        deviceQueue.push(tempQueue.front());
        tempQueue.pop();
    }

    if (!found) {
        cout << "Устройство не найдено в очереди.\n";
    }
    else
    {
        cout << "Устройство удалено  из очереди.\n";
    }
    _getch();
}
void NetworkDeviceManager::removeDevicePriorityQueue(const string& deviceName) {
    priority_queue<shared_ptr<NetworkDevice>, vector<shared_ptr<NetworkDevice>>, NetworkDevice::CompareNetworkDevice> tempQueue(devicePriorityQueue);
    bool found = false;
    system("cls");
    while (!devicePriorityQueue.empty()) {
        shared_ptr <NetworkDevice> topDevice = devicePriorityQueue.top();
        devicePriorityQueue.pop();

        if (topDevice->getName() == deviceName) {
            topDevice.reset();
            found = true;
            break;
        }
        tempQueue.push(topDevice);
    }

    devicePriorityQueue = tempQueue;

    if (!found) {
        cout << "Устройство не найдено в приоритетной очереди.\n";
    }
    else
    {
        cout << "Устройство удалено  из приоритетной очереди.\n";
    }
    _getch();
}


void NetworkDeviceManager::editDeviceStack(const string& deviceName) {
    stack<shared_ptr<NetworkDevice>> tempStack;
    bool found = false;
    system("cls");
    while (!deviceStack.empty()) {
        shared_ptr<NetworkDevice> topDevice = deviceStack.top();
        deviceStack.pop();

        if (topDevice->getName() == deviceName) {
            cout << "Редактирование устройства.\n";
            topDevice->edit();
            found = true;
        }
        tempStack.push(topDevice);
    }

    while (!tempStack.empty()) {
        deviceStack.push(tempStack.top());
        tempStack.pop();
    }

    if (!found) {
        cout << "Устройство с именем " << deviceName << " не найдено в стеке.\n";
    }
    else
    {
        cout << "Устройство с именем " << deviceName << " успешно отредактированно  в стеке.\n";
    }
    _getch();
}
void NetworkDeviceManager::editDeviceQueue(const string& deviceName) {
    queue<shared_ptr<NetworkDevice>> tempQueue;
    bool found = false;
    system("cls");
    while (!deviceQueue.empty()) {
        shared_ptr<NetworkDevice> frontDevice = deviceQueue.front();
        deviceQueue.pop();

        if (frontDevice->getName() == deviceName) {
            cout << "Редактирование устройства.\n";
            frontDevice->edit();
            frontDevice->print();
            found = true;
        }
        tempQueue.push(frontDevice);
    }

    while (!tempQueue.empty()) {
        deviceQueue.push(tempQueue.front());
        tempQueue.pop();
    }

    if (!found) {
        cout << "Устройство с именем " << deviceName << " не найдено в очереди.\n";
    }
    else
    {
        cout << "Устройство с именем " << deviceName << " успешно отредактированно  в очереди.\n";
    }
    _getch();
}
void NetworkDeviceManager::editDevicePriorityQueue(const string& deviceName) {
    priority_queue<shared_ptr<NetworkDevice>, vector<shared_ptr<NetworkDevice>>, NetworkDevice::CompareNetworkDevice> tempQueue;
    bool found = false;
    system("cls");

    while (!devicePriorityQueue.empty()) {
        shared_ptr<NetworkDevice> topDevice = devicePriorityQueue.top();
        devicePriorityQueue.pop();

        if (topDevice->getName() == deviceName) {
            cout << "Редактирование устройства.\n";
            topDevice->edit();  
            found = true;
        }
        tempQueue.push(topDevice);  
    }

    devicePriorityQueue = std::move(tempQueue);

    if (!found) {
        cout << "Устройство с именем " << deviceName << " не найдено в приоритетной очереди.\n";
    }
    else {
        cout << "Устройство с именем " << deviceName << " успешно отредактировано в приоритетной очереди.\n";
    }
    _getch();
}




void NetworkDeviceManager::searchDeviceStack(const string& deviceName) {
    stack<shared_ptr<NetworkDevice>> tempStack = deviceStack;
    system("cls");
    while (!tempStack.empty()) {
        shared_ptr<NetworkDevice> device = tempStack.top();
        tempStack.pop();

        if (device->getName() == deviceName) {
            cout << "Устройство найдено в стеке:\n";
            device->print();
            _getch();
            return;
        }
    }

    cout << "Устройство с именем '" << deviceName << "' не найдено в стеке.\n";
    _getch();
}
void NetworkDeviceManager::searchDeviceQueue(const string& deviceName) {
    queue<shared_ptr<NetworkDevice>> tempQueue = deviceQueue;
    system("cls");
    while (!tempQueue.empty()) {
        shared_ptr<NetworkDevice> device = tempQueue.front();
        tempQueue.pop();

        if (device->getName() == deviceName) {
            cout << "Устройство найдено в очереди:\n";
            device->print();
            _getch();
            return;
        }
    }

    cout << "Устройство с именем '" << deviceName << "' не найдено в очереди.\n";
    _getch();
}
void NetworkDeviceManager::searchDevicePriorityQueue(const string& deviceName) {
    priority_queue<shared_ptr<NetworkDevice>, vector<shared_ptr<NetworkDevice>>, NetworkDevice::CompareNetworkDevice> tempQueue(devicePriorityQueue);
    system("cls");
    while (!tempQueue.empty()) {
        shared_ptr<NetworkDevice> device = tempQueue.top();
        tempQueue.pop();

        if (device->getName() == deviceName) {
            cout << "Устройство найдено в приоритетной очереди:\n";
            device->print();
            _getch();
            return;
        }
    }

    cout << "Устройство с именем '" << deviceName << "' не найдено в приоритетной очереди.\n";
    _getch();
}



void NetworkDeviceManager::filterDeviceStack(const string& deviceType) {
    stack<shared_ptr<NetworkDevice>> tempStack = deviceStack;
    system("cls");
    cout << "Фильтрация устройств типа '" << deviceType << "' в стеке:\n";
    while (!tempStack.empty()) {
        shared_ptr<NetworkDevice> device = tempStack.top();
        tempStack.pop();

        if (device->getType() == deviceType) {
            device->print();
        }
    }
    _getch();
}
void NetworkDeviceManager::filterDeviceQueue(const string& deviceType) {
    queue<shared_ptr<NetworkDevice>> tempQueue = deviceQueue;
    system("cls");
    cout << "Фильтрация устройств типа '" << deviceType << "' в очереди:\n";
    while (!tempQueue.empty()) {
        shared_ptr<NetworkDevice> device = tempQueue.front();
        tempQueue.pop();

        if (device->getType() == deviceType) {
            device->print();
        }
    }
    _getch();
}
void NetworkDeviceManager::filterDevicePriorityQueue(const string& deviceType) {
    priority_queue<shared_ptr<NetworkDevice>, vector<shared_ptr<NetworkDevice>>, NetworkDevice::CompareNetworkDevice> tempQueue(devicePriorityQueue);
    system("cls");
    cout << "Фильтрация устройств типа '" << deviceType << "' в приоритетной очереди:\n";
    while (!tempQueue.empty()) {
        shared_ptr<NetworkDevice> device = tempQueue.top();
        tempQueue.pop();

        if (device->getType() == deviceType) {
            device->print();
        }
    }
    _getch();
}



void NetworkDeviceManager::printDeviceStack() {
    stack<shared_ptr<NetworkDevice>> tempStack = deviceStack;
    system("cls");
    cout << "Устройства в стеке:\n";
    if (tempStack.empty()) {
        cout << "Стек пуст.\n";
        _getch();
        return;
    }

    while (!tempStack.empty()) {
        shared_ptr<NetworkDevice> device = tempStack.top();
        tempStack.pop();
        device->print();
    }
    _getch();
}
void NetworkDeviceManager::printDeviceQueue() {
    queue<shared_ptr<NetworkDevice>> tempQueue = deviceQueue;
    system("cls");
    cout << "Устройства в очереди:\n";
    if (tempQueue.empty()) {
        cout << "Очередь пуста.\n";
        _getch();
        return;
    }

    while (!tempQueue.empty()) {
        shared_ptr<NetworkDevice> device = tempQueue.front();
        tempQueue.pop();
        device->print();
    }
    _getch();
}
void NetworkDeviceManager::printDevicePriorityQueue() {
    priority_queue<shared_ptr<NetworkDevice>, vector<shared_ptr<NetworkDevice>>, NetworkDevice::CompareNetworkDevice> tempQueue(devicePriorityQueue);
    system("cls");
    cout << "Устройства в приоритетной очереди:\n";
    if (tempQueue.empty()) {
        cout << "Приоритетная очередь пуста.\n";
        _getch();
        return;
    }

    while (!tempQueue.empty()) {
        shared_ptr<NetworkDevice> device = tempQueue.top();
        tempQueue.pop();
        device->print();
    }
    _getch();
}


void NetworkDeviceManager::writeToFileDeviceStack() {
    stack<shared_ptr<NetworkDevice>> tempStack = deviceStack;

    while (!tempStack.empty()) {
        shared_ptr<NetworkDevice> device = tempStack.top();
        device->writeToFile();
        tempStack.pop();  
    }

}
void NetworkDeviceManager::writeToFileDeviceQueue() {
    queue<shared_ptr<NetworkDevice>> tempQueue = deviceQueue;

    while (!tempQueue.empty()) {
        shared_ptr<NetworkDevice> device = tempQueue.front();
        device->writeToFile();
        tempQueue.pop();
    }
}
void NetworkDeviceManager::writeToFileDevicePriorityQueue() {
    priority_queue<shared_ptr<NetworkDevice>, vector<shared_ptr<NetworkDevice>>, NetworkDevice::CompareNetworkDevice> tempQueue(devicePriorityQueue);

    while (!tempQueue.empty()) {
        shared_ptr<NetworkDevice> device = tempQueue.top();
        device->writeToFile();
        tempQueue.pop();
    }

}


void NetworkDeviceManager::sortDeviceStack() {
    vector<shared_ptr<NetworkDevice>> tempVec;

    while (!deviceStack.empty()) {
        tempVec.push_back(deviceStack.top());
        deviceStack.pop();
    }

    sort(tempVec.begin(), tempVec.end(), [](const shared_ptr<NetworkDevice>& a, const shared_ptr<NetworkDevice>& b) {
        return a->getName() > b->getName();
        });

    for (const auto& device : tempVec) {
        deviceStack.push(device);
    }

    cout << "Стек устройств отсортирован.\n";
}
void NetworkDeviceManager::sortDeviceQueue() {
    vector<shared_ptr<NetworkDevice>> tempVec;

    while (!deviceQueue.empty()) {
        tempVec.push_back(deviceQueue.front());
        deviceQueue.pop();
    }

    sort(tempVec.begin(), tempVec.end(), [](const shared_ptr<NetworkDevice>& a, const shared_ptr<NetworkDevice>& b) {
        return a->getName() < b->getName();
        });

    for (const auto& device : tempVec) {
        deviceQueue.push(device);
    }

    cout << "Очередь устройств отсортирована.\n";
}
void NetworkDeviceManager::sortDevicePriorityQueue() {
    cout << "Приоритетная очередь устройств сама по себе отсортирована.\n";
}







