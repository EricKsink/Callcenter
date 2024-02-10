#include"nombre.hpp"
#include<string>
#include<iostream>

using namespace std;

Nombre::Nombre() {}

Nombre::Nombre(const Nombre& n) : nombre(n.nombre), apm(n.apm), app(n.app) {}

string Nombre::getNombre() const {
    return nombre;
    }

string Nombre::getApp() const {
    return app;
    }

string Nombre::getApm() const {
    return apm;
    }

string Nombre::toString() const {
    return nombre+", "+app+" "+apm;
    }

void Nombre::setNombre(const string&n) {
    nombre=n;
    }

void Nombre::setApp(const string& a) {
    app=a;
    }

void Nombre::setApm(const string& a) {
    apm=a;
    }

Nombre& Nombre::operator=(const Nombre& n) {
    nombre=n.nombre;
    app=n.app;
    apm=n.apm;
    return *this;
    }

bool Nombre::operator==(const Nombre& n) const {
    return toString()==n.toString();
    }

bool Nombre::operator!=(const Nombre& n) const {
    return !(*this==n);
    }

bool Nombre::operator<(const Nombre& n) const {
    return toString()<n.toString();
    }

bool Nombre::operator<=(const Nombre& n) const {
    return !(*this>n);
    }

bool Nombre::operator>(const Nombre& n) const {
    return toString()>n.toString();
    }

bool Nombre::operator>=(const Nombre& n) const {
    return !(*this<n);
    }

ostream& operator << (ostream& os, const Nombre& n) {

    os << n.nombre << endl;
    os << n.app << endl;
    os << n.apm;

    return os;
    }

istream& operator >> (istream& is, Nombre& n) {
    getline(is,n.nombre);
    getline(is,n.app);
    getline(is,n.apm);

    return is;

    }




