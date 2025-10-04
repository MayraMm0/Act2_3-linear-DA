#include "Node.h"
#include "DoublyLinkedList.h"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

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