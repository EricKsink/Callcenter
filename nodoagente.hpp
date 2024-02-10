#ifndef NODOAGENTE_HPP_INCLUDED
#define NODOAGENTE_HPP_INCLUDED

#include <exception>
#include <string>

#include "agente.hpp"

class NodoExcepcionAgente : public std::exception{
private:
    std::string msg;
public:
    explicit NodoExcepcionAgente(const char* message):msg(message){}

    explicit NodoExcepcionAgente(const std::string& message) : msg(message){}

    virtual ~NodoExcepcionAgente() throw (){}

    virtual const char* what() const throw(){
    return msg.c_str();
    }

};


class NodoAgente{
private:
Agente* dataPtr;
NodoAgente* prev;
NodoAgente* next;


public:
    NodoAgente();
    NodoAgente(const Agente&);

    ~NodoAgente();

    Agente* getDataPtr();
    Agente getData();
    NodoAgente* getPrev();
    NodoAgente* getNext();

    void setDataPtr(Agente*);
    void setData(const Agente&);
    void setPrev(NodoAgente*);
    void setNext(NodoAgente*);

};

#endif // NODOAGENTE_HPP_INCLUDED
