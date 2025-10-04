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

    //Función auxiliar para encontrar la mitad de la lista
    void splitList(Node<T>* headRef, Node<T>** secondRef) {
        // Puntero lento (slow) avanza 1, puntero rápido (fast) avanza 2.
        Node<T>* slow = headRef;
        Node<T>* fast = headRef->next;

        // Fast se mueve dos pasos, slow se mueve uno, hasta que fast llega al final.
        while (fast != nullptr) {
            fast = fast->next;
            if (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // slow es el último nodo de la primera mitad.
        *secondRef = slow->next;

        // Cortar el enlace entre las dos mitades.
        if (*secondRef != nullptr) {
            (*secondRef)->prev = nullptr;
        }
        slow->next = nullptr;
    }

    // Función auxiliar para mergeSort
    Node<T>* merge(Node<T>* left, Node<T>* right) {
        // Caso base: si una lista está vacía, devuelve la otra.
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        // La comparación se basa en el operador sobrecargado de Register (por IP).
        // Se ordena ascendentemente por IP (menor a mayor).
        if (left->value <= right->value) {
            // El nodo izquierdo es el nuevo head de la lista combinada.
            left->next = merge(left->next, right);
            left->next->prev = left; // Ajusta el puntero 'prev' del nodo siguiente.
            left->prev = nullptr;    // Asegura que el nuevo head no tenga prev.
            return left;
        } else {
            // El nodo derecho es el nuevo head de la lista combinada.
            right->next = merge(left, right->next);
            right->next->prev = right; // Ajusta el puntero 'prev' del nodo siguiente.
            right->prev = nullptr;     // Asegura que el nuevo head no tenga prev.
            return right;
        }
    }

    // Es la función recursiva que se usa durante el proceso de ordenamiento
    void mergeSortRecursive(Node<T>** headRef) {
        Node<T>* head = *headRef;
        Node<T>* a; // Primera mitad
        Node<T>* b; // Segunda mitad

        // Caso base: 0 o 1 nodo. La lista ya está ordenada.
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // 1. Dividir la lista en 'a' y 'b'.
        a = head;
        splitList(a, &b);

        // 2. Llamada recursiva para ordenar las mitades.
        mergeSortRecursive(&a);
        mergeSortRecursive(&b);

        // 3. Fusionar las dos listas ordenadas y actualizar el head.
        *headRef = merge(a, b);
    }


    // Verifica condiciones previas y actualiza después de ordenar
    void mergeSort() {
        // Si la lista está vacía o tiene un solo elemento, no hacemos nada.
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        // Llamar a la función recursiva y actualizar el head y tail.
        mergeSortRecursive(&head);

        // 4. Actualizar el puntero 'tail' después de que la lista esté completamente fusionada.
        Node<T>* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        tail = current;
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
