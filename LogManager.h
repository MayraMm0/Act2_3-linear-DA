#pragma once
#include <iostream>
#include <string>
#include "Register.h"
#include "DoublyLinkedList.h"


class LogManager {
private: 
    DoublyLinkedList<Register> logs;

public:
    LogManager() = default;
    ~LogManager() = default;
    
    // Métodos para manejo de logs
    void addRegister(const Register& reg);
    void sortLogs();
    void displayAllLogs();
    DoublyLinkedList<Register> lookupRange(const string& startIP, const string& endIP);
};