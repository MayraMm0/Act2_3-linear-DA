/*
Esta clase proporciona funcionalidades para gestionar una colección
de registros de logs de seguridad, incluyendo ordenamiento y búsqueda.
 */

#pragma once
#include <iostream>
#include <string>
#include "Register.h"
#include "DoublyLinkedList.h"


class LogManager {
private: 
    DoublyLinkedList<Register> logs; ///< Lista que almacena todos los registros de logs

public:
    // ===== CONSTRUCTORES Y DESTRUCTOR =====
    LogManager() = default;
    
    ~LogManager() = default;
    
    // ===== MÉTODOS PARA MANEJO DE LOGS =====
    /*
    Agrega un nuevo registro a la colección
    Complejidad: O(1)
     */
    void addRegister(const Register& reg);
    
    /*
    Ordena todos los registros por IP
    Complejidad: O(n log n) donde n es el número de registros
     */
    void sortLogs();
    
    /**
     Muestra todos los registros en la consola
     Complejidad: O(n) donde n es el número de registros
     */
    void displayAllLogs();
    
    /**
    Busca registros en un rango de IPs
    Complejidad: O(n)
     */
    DoublyLinkedList<Register> lookupRange(const string& startIP, const string& endIP);
};