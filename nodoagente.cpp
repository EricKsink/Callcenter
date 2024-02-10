#include "nodoagente.hpp"

using namespace std;

NodoAgente::NodoAgente() : dataPtr(nullptr), prev(nullptr), next(nullptr) {}

NodoAgente::NodoAgente(const Agente& e) : dataPtr(new Agente(e)), prev(nullptr), next(nullptr) {
    if(dataPtr == nullptr) {
        throw NodoExcepcionAgente("Memoria no disponible, creando Nodo_agente");
        }
    }

NodoAgente::~NodoAgente() {
    delete dataPtr;
    }

Agente NodoAgente::getData() {
    if(dataPtr == nullptr) {
        throw NodoExcepcionAgente("Error el dato no existe, getDataPtr");
        }

    return *dataPtr;
    }

Agente* NodoAgente::getDataPtr() {
    return dataPtr;
    }

NodoAgente* NodoAgente::getPrev() {
    return prev;
    }

NodoAgente* NodoAgente::getNext() {
return next;
    }

void NodoAgente::setDataPtr(Agente* a) {
dataPtr = a;
    }

void NodoAgente::setData(const Agente& e) {
    delete dataPtr;

    dataPtr = new Agente(e);

    if(dataPtr ==  nullptr){
        throw NodoExcepcionAgente("Memoria no disponible, setData");
    }

    }

void NodoAgente::setPrev(NodoAgente* a) {
prev = a;
    }

void NodoAgente::setNext(NodoAgente* a) {
next = a;
    }
