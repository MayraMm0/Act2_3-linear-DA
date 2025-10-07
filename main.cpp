/*
A01736199 Mayra Miranda Moreno
A01739714 Juan Pablo Gavidia Alvarez
6 Oct 2025
Este programa lee logs de seguridad desde un archivo, los ordena por IP
usando Merge Sort, y permite realizar búsquedas por rango de IPs.
*/

#include "DoublyLinkedList.h"
#include "LogManager.h"
#include "Register.h"
#include <iostream>
#include <fstream>
using namespace std;

/**
 * Función principal del programa
 * Ejecuta el flujo completo del sistema de gestión de logs:
 *   1. Lee logs desde bitacora.txt
 *   2. Los ordena por IP usando Merge Sort
 *   3. Guarda la lista ordenada en un archivo
 *   4. Permite búsqueda por rango de IPs
 *   5. Guarda los resultados de búsqueda
 */
int main() {
    cout << "=== SISTEMA DE GESTION DE LOGS DE SEGURIDAD ===" << endl;
    cout << "Iniciando lectura y procesamiento de logs..." << endl << endl;
    
    // Inicialización de variables
    LogManager manager;           // Gestor de logs principal
    int registrosLeidos = 0;      // Contador de registros procesados

    // ===== PASO 1: LECTURA DEL ARCHIVO DE LOGS =====
    cout << "1. Leyendo archivo bitacora.txt..." << endl;
    ifstream file("bitacora.txt");
    
    // Verificación de apertura del archivo
    if (!file.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo bitacora.txt" << endl;
        return 1; // Código de error
    }
    
    // Lectura línea por línea del archivo
    string line;
    while (getline(file, line)) {
        // Procesar solo líneas no vacías
        if (!line.empty()) {
            Register reg = Register::fromLinea(line);  // Crear registro desde línea
            manager.addRegister(reg);                  // Agregar a la lista
            registrosLeidos++;                         // Incrementar contador
        }
    }
    file.close();
    cout << "   Total de registros leidos: " << registrosLeidos << endl << endl;

    // ===== PASO 2: ORDENAMIENTO POR IP =====
    cout << "2. Ordenando registros por IP usando Merge Sort..." << endl;
    manager.sortLogs();  // Aplicar algoritmo de ordenamiento
    cout << "   Ordenamiento completado." << endl << endl;

    // ===== PASO 3: GUARDAR LISTA ORDENADA =====
    cout << "3. Guardando lista ordenada en 'Registros_ordenados.txt'..." << endl;
    ofstream archivoOrdenados("Registros_ordenados.txt");
    
    if (archivoOrdenados.is_open()) {
        // Obtener todos los registros ordenados (rango completo)
        DoublyLinkedList<Register> todos = manager.lookupRange("0.0.0.0", "999.999.999.999");
        
        // Recorrer la lista y escribir cada registro al archivo
        Node<Register>* temp = todos.getHead();
        while (temp) {
            archivoOrdenados << temp->value << endl;
            temp = temp->next;
        }
        archivoOrdenados.close();
        cout << "   Lista ordenada guardada exitosamente." << endl;
    } else {
        cout << "   ERROR: No se pudo crear 'Registros_ordenados.txt'" << endl;
    }
    cout << endl;

    // ===== PASO 4: BÚSQUEDA POR RANGO DE IPs =====
    cout << "4. Busqueda por rango de IPs:" << endl;
    string startIP, endIP;
    
    // Solicitar IPs de inicio y fin del rango
    cout << "   Ingresa la IP de inicio del rango: ";
    getline(cin, startIP);
    cout << "   Ingresa la IP de fin del rango: ";
    getline(cin, endIP);
    
    // Realizar búsqueda en el rango especificado
    DoublyLinkedList<Register> results = manager.lookupRange(startIP, endIP);
    cout << "   Registros encontrados: " << results.getLength() << endl;
    cout << endl;

    // ===== PASO 5: GUARDAR RESULTADOS DE BÚSQUEDA =====
    cout << "5. Guardando resultados de busqueda en 'Busqueda_resultados.txt'..." << endl;
    ofstream archivoBusqueda("Busqueda_resultados.txt");
    
    if (archivoBusqueda.is_open()) {
        // Recorrer resultados y escribir al archivo
        Node<Register>* temp = results.getHead();
        while (temp) {
            archivoBusqueda << temp->value << endl;
            temp = temp->next;
        }
        archivoBusqueda.close();
        cout << "   Resultados de busqueda guardados exitosamente." << endl;
    } else {
        cout << "   ERROR: No se pudo crear 'Busqueda_resultados.txt'" << endl;
    }
    cout << endl;
    return 0;
}
