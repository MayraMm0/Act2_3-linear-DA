#include "IP.h"

IP::IP() : ipValue_(0), port_(0) {}

IP::IP(const string& text) : ipValue_(0), port_(0) {
    parse(text);
}

unsigned int IP::value() const {
    return ipValue_;
}

unsigned short IP::port() const {
    return port_;
}

const string& IP::original() const {
    return original_;
}

bool IP::operator==(const IP& rhs) const {
    return ipValue_ == rhs.ipValue_ && port_ == rhs.port_;
}

bool IP::operator!=(const IP& rhs) const {
    return !(*this == rhs);
}

bool IP::operator<(const IP& rhs) const {
    if (ipValue_ != rhs.ipValue_) {
        return ipValue_ < rhs.ipValue_;
    }
    return port_ < rhs.port_;
}

bool IP::operator>(const IP& rhs) const {
    return rhs < *this;
}

bool IP::operator<=(const IP& rhs) const {
    return !(*this > rhs);
}

bool IP::operator>=(const IP& rhs) const {
    return !(*this < rhs);
}

void IP::parse(const string& text) {
    original_ = text;

    string ipPart = text;
    string portPart;
    size_t colonPos = text.find(':');

    // Detecta el puerto si la cadena contiene un ':'
    if (colonPos != string::npos) {
        ipPart = text.substr(0, colonPos);
        portPart = text.substr(colonPos + 1);
    }

    unsigned int parts[4] = {0, 0, 0, 0};
    bool hasFourParts = true;
    size_t position = 0;

    // Recorre cada bloque separado por '.' y lo convierte a entero
    for (int index = 0; index < 4; ++index) {
        size_t dotPos = ipPart.find('.', position);
        string piece;

        if (dotPos == string::npos) {
            piece = ipPart.substr(position);
            position = ipPart.size();
        } else {
            piece = ipPart.substr(position, dotPos - position);
            position = dotPos + 1;
        }

        if (piece.empty()) {
            hasFourParts = false;
            break;
        }

        parts[index] = static_cast<unsigned int>(stoi(piece));
    }

    // Combina los cuatro bloques en un entero de 32 bits
    if (hasFourParts && position == ipPart.size()) {
        const unsigned int SHIFT_ONE = 24;
        const unsigned int SHIFT_TWO = 16;
        const unsigned int SHIFT_THREE = 8;

        ipValue_ = (parts[0] << SHIFT_ONE) |
                   (parts[1] << SHIFT_TWO) |
                   (parts[2] << SHIFT_THREE) |
                   parts[3];
    } else {
        ipValue_ = 0;
    }

    // Convierte el puerto si venía en el texto; de lo contrario queda en cero
    if (!portPart.empty()) {
        port_ = static_cast<unsigned short>(stoi(portPart));
    } else {
        port_ = 0;
    }
}
