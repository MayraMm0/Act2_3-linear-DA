#pragma once
using namespace std;
#include "Node.h"

template<typename T>
class DoublyLinkedList{
public:
    Node<T>* head;
    Node<T>* tail;
    int length;


    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    ~DoublyLinkedList() {
        Node<T>* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    int getLength() {
        return length;
    }

    Node<T>* getHead() {
        return head;
    }

    Node<T>* getTail() {
        return tail;
    }

    bool isEmpty(){
        if (head == NULL){
            return true;
         } else {
            return false;
        }
    }

    void insertBack(T value){
        Node<T>* newNode = new Node<T>(value);
        if(head==NULL){
            head = newNode;
            tail = newNode;
            length++;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            length++;
        }
    }

    void deleteLast() {
        if (length == 0) return;
        Node<T>* temp = tail;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void insertFront(int value) {
        Node<T>* newNode = new Node<T>(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst() {
        if (length == 0) return;
        Node<T>* temp = head;
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        length--;
    }

};

template <typename T>
ostream& operator<<(ostream& os, const DoublyLinkedList<T>& lista){
    os << "head" << " <-> ";
    Node<T>* temp = lista.head;
    // Recorre la lista e imprime cada dato
    while(temp){
        os << temp -> value<<" <-> ";
        temp = temp -> next;
    }
    os << "nullptr"; // Marca el final de la lista
    return os;
}
