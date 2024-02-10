#ifndef CLIENTE_HPP_INCLUDED
#define CLIENTE_HPP_INCLUDED

#include <iostream>

#include "nombre.hpp"
#include "tiempo.hpp"

class Cliente{
private:
    Nombre nombre;
    Tiempo horaInicio;
    Tiempo horaFinal;
public:
    Cliente();
    Cliente(const Cliente&);

    Nombre getNombre()const;
    Tiempo getHoraInicio() const;
    Tiempo getHoraFinal() const;

    std::string toString() const;

    void setNombre(const Nombre&);
    void setHoraInicio(const Tiempo&);
    void setHoraFinal(const Tiempo&);

    Cliente& operator=(const Cliente&);

    bool operator ==(const Cliente&) const;
    bool operator !=(const Cliente&) const;
    bool operator <(const Cliente&) const;
    bool operator <=(const Cliente&) const;
    bool operator >(const Cliente&) const;
    bool operator >=(const Cliente&) const;


    friend std::ostream& operator <<(std::ostream&, const Cliente&);
    friend std::istream& operator >>(std::istream&, Cliente&);

};

#endif // CLIENTE_HPP_INCLUDED
