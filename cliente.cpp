#include "cliente.hpp"
#include <iostream>

using namespace std;

Cliente::Cliente() {}

Cliente::Cliente(const Cliente& c):nombre(c.nombre), horaFinal(c.horaFinal), horaInicio(c.horaInicio) {}

Nombre Cliente::getNombre() const {
    return nombre;
    }

Tiempo Cliente::getHoraInicio() const {
    return horaInicio;
    }

Tiempo Cliente::getHoraFinal() const {
    return horaFinal;
    }

string Cliente::toString() const {
    string result;

    result="\t"+nombre.toString();
    result.resize(40,' ');
    result+=" | ";
    result+=horaInicio.toString();
    result+=" | ";
    result+=horaFinal.toString();
    result+=" | ";

    return result;
    }

void Cliente::setNombre(const Nombre& n) {
    nombre=n;
    }

void Cliente::setHoraInicio(const Tiempo& t) {
    horaInicio=t;
    }

void Cliente::setHoraFinal(const Tiempo& t) {
    horaFinal=t;
    }

Cliente& Cliente::operator=(const Cliente& c) {
    nombre=c.nombre;
    horaFinal=c.horaFinal;
    horaInicio=c.horaInicio;

    return *this;
    }

bool Cliente::operator==(const Cliente& c) const {
    return nombre.toString()==c.nombre.toString();
    }

bool Cliente::operator!=(const Cliente& c) const {
    return nombre.toString()!=c.nombre.toString();
    }

bool Cliente::operator<(const Cliente& c) const {
    return nombre.toString()<c.nombre.toString();
    }

bool Cliente::operator<=(const Cliente&c) const {
    return nombre.toString()<=c.nombre.toString();
    }

bool Cliente::operator>(const Cliente& c) const {
    return nombre.toString()>c.nombre.toString();
    }

bool Cliente::operator>=(const Cliente& c) const {
    return nombre.toString()>=c.nombre.toString();
    }

ostream& operator << (ostream& os, const Cliente& c) {
    os << c.nombre<<endl;
    os << c.horaInicio<<endl;
    os << c.horaFinal;

    return os;
    }

istream& operator >> (istream& is, Cliente& c) {
    is>>c.nombre;
    is>>c.horaInicio;
    is>>c.horaFinal;

    return is;
    }




