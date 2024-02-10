#ifndef AGENTE_HPP_INCLUDED
#define AGENTE_HPP_INCLUDED

#include <string>
#include <iostream>

#include "tiempo.hpp"
#include "nombre.hpp"
#include "listaclientes.hpp"


class Agente{
private:

    Nombre nombre;
    Tiempo horaInicial;
    Tiempo horaSalida;
    int codigo;
    int numExtencion;
    Tiempo horasExtras;
    std::string especialidad;
    ListaClientes listaClientes;

public:
    Agente();
    Agente(const Agente&);

    Nombre getNombre() const;
    Tiempo getHoraInicial() const;
    Tiempo getHoraSalida() const;
    int getCodigo() const;
    int getNumExtencion() const;
    Tiempo getHorasExtras() const;
    std::string getEspecialidad() const;
    ListaClientes& getListaClientes();

    std::string toString(const bool&)const;

    void setNombre(const Nombre&);
    void setHoraInicial(const Tiempo&);
    void setHoraSalida(const Tiempo&);
    void setCodigo(const int&);
    void setNumExtencion(const int&);
    void setHorasExtras(const Tiempo&);
    void setEspecialidad(const std::string&);
    void setListaClientes(const ListaClientes&);

    Agente& operator=(const Agente&);

    bool operator == (const Agente&) const;
    bool operator != (const Agente&) const;
    bool operator < (const Agente&) const;
    bool operator <= (const Agente&) const;
    bool operator > (const Agente&) const;
    bool operator >= (const Agente&) const;

    friend std::ostream& operator << (std::ostream&, const Agente&);
    friend std::istream& operator >> (std::istream&, Agente&);

};

#endif // AGENTE_HPP_INCLUDED
