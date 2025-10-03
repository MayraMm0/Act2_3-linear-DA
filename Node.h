#pragma once
#include<iostream>
using namespace std;

template<typename T>
struct Node {
    T value;                // Dato almacenado en el nodo
    Node* next;       // Puntero al siguiente nodo

    // Constructor: inicializa el dato y el puntero siguiente a nullptr
    Node(const T d){
        value = d;
        next = nullptr;
    }
};

// Sobrecarga del operador << para imprimir el dato de un nodo
template<typename Q>
ostream& operator<<(ostream& os, const Node<Q>& nodo) {
    os << nodo.value;
    return os;
}


