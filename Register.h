#pragma once
#include <string>
#include <sstream>
#include "DoublyLinkedList.h"
#include "IP.h"
using namespace std;

class Register {

    private:
    IP ip;
    string falla;
    string fecha;

    public:
    Register();
    Register(IP iP, string falla, string fecha);
    ~Register() = default;

    // Getters
    string get_iP() const;
    string get_falla() const;
    string get_fecha() const;

    // Setters
    void set_iP(string _iP);
    void set_falla(string _falla);
    void set_fecha(string _fecha);

    // Métodos estáticos
    static Register fromLinea(const string& linea);

    // Sobrecarga operadores de comparación
    bool operator<=(const Register& R1) const;
    bool operator>=(const Register& R1) const;

    // Declaración del operador de inserción de flujo
    friend std::ostream& operator<<(std::ostream& os, const Register& reg);

};

