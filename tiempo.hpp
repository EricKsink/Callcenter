#ifndef TIEMPO_HPP_INCLUDED
#define TIEMPO_HPP_INCLUDED

#include <string>
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <chrono>

class Tiempo{
private:
    int hora;
    int minutos;

    int toInt() const;

    bool isValid(const int&, const int&);

public:

    Tiempo();
    Tiempo(const Tiempo&);
    Tiempo(const int&, const int&);

    int getHora() const;
    int getMinutos() const;

    std::string toString() const;

    void setHora(const int&);
    void setMinutos(const int&);

    Tiempo& operator=(const Tiempo&);

    bool operator ==(const Tiempo&) const;
    bool operator !=(const Tiempo&) const;
    bool operator <(const Tiempo&) const;
    bool operator <=(const Tiempo&) const;
    bool operator >(const Tiempo&) const;
    bool operator >=(const Tiempo&) const;

    friend std::ostream& operator <<(std::ostream&, const Tiempo&);
    friend std::istream& operator >>(std::istream&, Tiempo&);
};


#endif // TIEMPO_HPP_INCLUDED
