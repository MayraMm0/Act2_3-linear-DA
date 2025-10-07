#include "LogManager.h"

/*
Agrega un nuevo registro a la colección
Complejidad: O(1)
*/
void LogManager::addRegister(const Register& reg) {
    logs.insertBack(reg);
}

/*
Ordena todos los registros por IP usando Merge Sort
Complejidad: O(n log n) donde n es el número de registros
*/
void LogManager::sortLogs() {
    logs.mergeSort();
}

/*
Muestra todos los registros en la consola
Complejidad: O(n)
*/
void LogManager::displayAllLogs() {
    Node<Register>* temp = logs.getHead();
    int count = 1;
    
    while (temp) {
        cout << "   " << count << ". " << temp->value << endl;
        temp = temp->next;
        count++;
    }
}

/*
Busca registros en un rango de IPs
Complejidad: O(n)
*/
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