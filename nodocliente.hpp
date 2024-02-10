#ifndef NODOCLIENTE_HPP_INCLUDED
#define NODOCLIENTE_HPP_INCLUDED

#include "cliente.hpp"

class NodoCliente{
private:
    Cliente data;
    NodoCliente* next;

public:

  NodoCliente();
  NodoCliente(const Cliente&);

  Cliente getData() const;
  NodoCliente* getNext();

  void setData(const Cliente&);
  void setNext(NodoCliente*);

};

#endif // NODOCLIENTE_HPP_INCLUDED
