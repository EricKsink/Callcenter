#include "agente.hpp"

using namespace std;

Agente::Agente() {}

Agente::Agente(const Agente& s) : nombre(s.nombre), horaInicial(s.horaInicial), horaSalida(s.horaSalida), codigo(s.codigo), numExtencion(s.numExtencion), horasExtras(s.horasExtras), especialidad(s.especialidad), listaClientes(s.listaClientes) { }

Nombre Agente::getNombre() const {
    return nombre;
    }

Tiempo Agente::getHoraInicial() const {
    return horaInicial;
    }

Tiempo Agente::getHoraSalida() const {
    return horaSalida;
    }

int Agente::getCodigo() const {
    return codigo;
    }

int Agente::getNumExtencion() const {
    return numExtencion;
    }

Tiempo Agente::getHorasExtras() const {
    return horasExtras;
    }

string Agente::getEspecialidad() const {
    return especialidad;
    }

ListaClientes& Agente::getListaClientes() {
    return listaClientes;
    }

string Agente::toString(const bool& subList = false) const {
    string result;

    result=nombre.toString();
    result.resize(35,' ');
    result+=" | ";
    result+=especialidad;
    result.resize(51,' ');
    result+=" | ";
    result+=to_string(codigo);
    result.resize(70,' ');
    result+=" | ";
    result+=to_string(numExtencion);
    result.resize(90,' ');
    result+=" | ";
    result+=horaInicial.toString();
    result+=" | ";
    result+=horaSalida.toString();
    result+=" | ";
    result+=horasExtras.toString();
    result+=" | ";

    if(subList) {
        result+="\n";
        result+="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        result+=listaClientes.toString();
        result+="~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        }

    return result;

    }

void Agente::setNombre(const Nombre& n) {
    nombre = n;
    }

void Agente::setHoraInicial(const Tiempo& t) {
    horaInicial = t;
    }

void Agente::setHoraSalida(const Tiempo& t) {
    horaSalida = t;
    }

void Agente::setCodigo(const int& c) {
    codigo = c;
    }

void Agente::setNumExtencion(const int& n) {
    numExtencion = n;
    }

void Agente::setHorasExtras(const Tiempo& t) {
    horasExtras = t;
    }

void Agente::setEspecialidad(const std::string& e) {
    especialidad = e;
    }

void Agente::setListaClientes(const ListaClientes& l) {
    listaClientes = l;
    }

Agente& Agente::operator = (const Agente& s) {
    nombre = s.nombre;
    horaInicial = s.horaInicial;
    horaSalida = s.horaSalida;
    codigo = s.codigo;
    numExtencion = s.numExtencion;
    horasExtras = s.horasExtras;
    especialidad = s.especialidad;
    listaClientes = s.listaClientes;

    return *this;
    }

bool Agente::operator == (const Agente& s) const {
    return nombre == s.nombre;
    }

bool Agente::operator != (const Agente& s) const {
    return nombre != s.nombre;
    }

bool Agente::operator < (const Agente& s) const {
    return nombre < s.nombre;
    }

bool Agente::operator <= (const Agente& s) const {
    return nombre <= s.nombre;
    }

bool Agente::operator > (const Agente& s) const {
    return nombre > s.nombre;
    }

bool Agente::operator >= (const Agente& s) const {
    return nombre >= s.nombre;
    }

    ostream& operator << (ostream& os, const Agente& a){
    char myCodigo[20],myNumExtencion[20];

    string mystr(to_string(a.codigo)), mystr2(to_string(a.numExtencion));

    //sprintf(myCodigo, "0.2i", a.codigo);
    //sprintf(myNumExtencion, "0.2i", a.num_extencion);



    os << a.nombre << endl;
    os << a.especialidad << endl;
    os << mystr << endl;
    os << mystr2 << endl;
    os << a.horaInicial << endl;
    os << a.horaSalida << endl;
    os << a.horasExtras;

    return os;

    }

    istream& operator >> (istream& is, Agente& a){
    string ext,cod;

    is >> a.nombre;
    getline(is, a.especialidad);
    getline(is, cod);
    a.codigo = atoi(cod.c_str());
    getline(is, ext);
    a.numExtencion = atoi(ext.c_str());
    is >> a.horaInicial;
    is >> a.horaSalida;
    is >> a.horasExtras;


    return is;
    }

