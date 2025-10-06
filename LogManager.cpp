#include "LogManager.h"

void LogManager::addRegister(const Register& reg) {
    logs.insertBack(reg);
}

void LogManager::sortLogs() {
    logs.mergeSort();
}

void LogManager::displayAllLogs() {
    Node<Register>* temp = logs.getHead();
    int count = 1;
    
    while (temp) {
        cout << "   " << count << ". " << temp->value << endl;
        temp = temp->next;
        count++;
    }
}

DoublyLinkedList<Register> LogManager::lookupRange(const std::string& startIP, const std::string& endIP) {
    IP start(startIP);
    IP end(endIP);

    DoublyLinkedList<Register> result;
    Node<Register>* temp = logs.getHead();

    while (temp) {
        IP tempIP = temp->value.getIP();
        // Si tempIP está en el rango [start, end]
        if (!(tempIP < start) && !(end < tempIP)) {
            result.insertBack(temp->value);
        }
        temp = temp->next;
    }

    return result;
}