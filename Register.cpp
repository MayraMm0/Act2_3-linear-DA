//Implementacion de la clase 'Registro'.
#include "Register.h"
#include <sstream>

// Constructores 

Register::Register(): ip(IP()), falla(""), fecha(""){}

Register::Register(IP _ip, string _falla, string _fecha){
    ip = _ip;
    falla = _falla;
    fecha = _fecha;
}

// Getters

string Register::get_iP() const{
    return ip.original();
}

string Register::get_falla() const{
    return falla;
}

string Register::get_fecha() const{
    return fecha;
}

// Setters

void Register::set_iP(string _iP){
    ip = _iP;
}

void Register::set_falla(string _falla){
    falla = _falla;
}

void Register::set_fecha(string _fecha){
    fecha = _fecha;
}

// Métodos estáticos
Register Register::fromLinea(const std::string& linea){
    // Realiza la lectura de la línea de texto
    stringstream iss(linea);

    // Declara las variables necesarias
    std::string mesStr,dia, horaStr, iP, falla;

    // Leer valores iniciales
    iss >> mesStr >> dia >> horaStr >> iP;

    // Convierte fecha y hora en uno solo
    std::string fecha = mesStr +" "+ dia +" "+ horaStr;

    // Leer el mensaje de falla
    getline(iss, falla);
    if (!falla.empty() && falla[0] == ' ') {
        falla.erase(0, 1); // Eliminar espacio inicial si existe
    }

    // Retorna el registro creado
    return Register(IP(iP), falla, fecha);
}

// Operadores de comparación por IP

bool Register::operator<=(const Register& R1) const{
    return ip <= R1.ip;
}

bool Register::operator>=(const Register& R1) const{
    return ip >= R1.ip;
}

// Implementación del operador de inserción de flujo
std::ostream& operator<<(std::ostream& os, const Register& reg) {
    // Aquí defines el formato de salida. Por ejemplo:
    os << "[" << reg.get_fecha() << " "
       << reg.get_iP() << " - "
       << reg.get_falla() << "]";

    // Si la clase IP también tiene su propio operator<<, úsalo:
    // os << "[" << reg.get_fecha() << " " << reg.ip << " - " << reg.get_falla() << "]";

    return os;
}