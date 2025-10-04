#include "Node.h"
#include "DoublyLinkedList.h"
#include "LogManager.h"
#include "Register.h"
#include "IP.h"
#include<iostream>
using namespace std;

int main() {
    DoublyLinkedList<int> list;
    list.insertBack(10);
    list.insertBack(20);
    list.insertFront(5);
    cout << "La longitud de la lista es: " << list.getLength() << endl;
    cout << "Elementos en la lista: ";
    cout << list;
    return 0;
}