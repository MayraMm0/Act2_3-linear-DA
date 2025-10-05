#include "LogManager.h"

DoublyLinkedList<Register> lookupRange(DoublyLinkedList<Register>& list, const std::string& startIP, const std::string& endIP) {
    IP start(startIP);
    IP end(endIP);

    DoublyLinkedList<Register> result;
    Node<Register>* temp = list.getHead();

    while (temp) {
        unsigned int regIPValue = temp->value.getIP().value(); // Access numeric IP value
        if (regIPValue >= start.value() && regIPValue <= end.value()) {
            result.insertBack(temp->value);
        }
        temp = temp->next;
    }

    return result;
}