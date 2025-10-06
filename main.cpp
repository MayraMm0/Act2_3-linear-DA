#include "DoublyLinkedList.h"
#include "LogManager.h"
#include "Register.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    cout << "=== SISTEMA DE GESTION DE LOGS DE SEGURIDAD ===" << endl;
    cout << "Iniciando lectura y procesamiento de logs..." << endl << endl;
    
    LogManager manager;
    int registrosLeidos = 0;

    // 1. Leer archivo de logs
    cout << "1. Leyendo archivo bitacora.txt..." << endl;
    ifstream file("bitacora.txt");
    if (!file.is_open()) {
        cout << "ERROR: No se pudo abrir el archivo bitacora.txt" << endl;
        return 1;
    }
    string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            Register reg = Register::fromLinea(line);
            manager.addRegister(reg);
            registrosLeidos++;
        }
    }
    file.close();
    cout << "   Total de registros leidos: " << registrosLeidos << endl << endl;

    // 2. Ordenar por IP
    cout << "2. Ordenando registros por IP usando Merge Sort..." << endl;
    manager.sortLogs();
    cout << "   Ordenamiento completado." << endl << endl;

    // 3. Guardar lista ordenada en archivo
    cout << "3. Guardando lista ordenada en 'Registros_ordenados.txt'..." << endl;
    ofstream archivoOrdenados("Registros_ordenados.txt");
    if (archivoOrdenados.is_open()) {
        Node<Register>* temp = manager.lookupRange("0.0.0.0", "999.999.999.999").getHead();
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

    // 4. Búsqueda por rango de IPs
    cout << "4. Busqueda por rango de IPs:" << endl;
    string startIP, endIP;
    cout << "   Ingresa la IP de inicio del rango: ";
    getline(cin, startIP);
    cout << "   Ingresa la IP de fin del rango: ";
    getline(cin, endIP);
    DoublyLinkedList<Register> results = manager.lookupRange(startIP, endIP);
    cout << "   Registros encontrados: " << results.getLength() << endl;
    cout << endl;

    // 5. Guardar resultados de búsqueda en archivo
    cout << "5. Guardando resultados de busqueda en 'Busqueda_resultados.txt'..." << endl;
    ofstream archivoBusqueda("Busqueda_resultados.txt");
    if (archivoBusqueda.is_open()) {
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