#pragma once
#include <string>
using namespace std;

class IP {
public:
    IP();                    // IP sin datos iniciales.
    IP(const string& text);  // Construye la IP a partir del texto.

    unsigned short port() const;       // Regresa el puerto asociado.
    const string& original() const;    // Devuelve el texto original de la IP.

    bool operator==(const IP& rhs) const; // Verifica igualdad exacta.
    bool operator<(const IP& rhs) const;  // Compara octeto por octeto.

private:
    void parse(const string& text);    // Convierte el string en valores numéricos.

    string original_;                  // Texto original "A.B.C.D:puerto".
    unsigned short port_ = 0;          // Puerto numérico, 0 si no existe.
    unsigned int octets_[4] = {0, 0, 0, 0}; // Octetos de la IP.
};
