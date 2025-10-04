#pragma once
#include <string>
using namespace std;

class IP {
public:
    IP();                    // IP sin datos iniciales.
    IP(const string& text);            // Construye la IP a partir del texto.

    unsigned int value() const;        // Regresa la IP convertido como entero.
    unsigned short port() const;       // Regresa el puerto asociado.
    const string& original() const;    // Devuelve el texto original de la IP.

    bool operator==(const IP& rhs) const; // Verifica igualdad exacta.
    bool operator!=(const IP& rhs) const; // Verifica diferencia.
    bool operator<(const IP& rhs) const;  // Compara priorizando la IP numérica.
    bool operator>(const IP& rhs) const;  // Compara en sentido contrario.
    bool operator<=(const IP& rhs) const; // Evalúa menor o igual.
    bool operator>=(const IP& rhs) const; // Evalúa mayor o igual.

private:
    void parse(const string& text);    // Convierte el string en valores numéricos.

    string original_;                  // Texto original "A.B.C.D:puerto".
    unsigned int ipValue_ = 0;         // IP convertida a un entero de 32 bits.
    unsigned short port_ = 0;          // Puerto numérico, 0 si no existe.
};
