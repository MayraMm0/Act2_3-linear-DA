#pragma once
#include <iostream>
#include <string>
#include "Register.h"
#include "DoublyLinkedList.h"
#include "IP.h"

class LogManager {
private: 
    DoublyLinkedList<Register> logs;

public:
    LogManager() = default;
    ~LogManager() = default;
    void lookupRange(DoublyLinkedList<Register>& list, const string& startIP, const string& endIP);
};