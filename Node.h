/**
Implementación de un nodo para listas doblemente enlazadas
Este archivo define la estructura Node que representa un nodo
 */

#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct Node {
    T value;        ///< Dato almacenado en el nodo
    Node* next;     ///< Puntero al siguiente nodo en la lista
    Node* prev;     ///< Puntero al nodo anterior en la lista

    // Constructor del nodo
     
    Node(const T d){
        value = d;
        next = nullptr;
        prev = nullptr;
    }
};

// Sobrecarga del operador << para imprimir el dato de un nodo
template<typename Q>
ostream& operator<<(ostream& os, const Node<Q>& nodo) {
    os << nodo.value;
    return os;
}


