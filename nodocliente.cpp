#include "nodocliente.hpp"

using namespace std;

NodoCliente::NodoCliente() : next(nullptr) {}

NodoCliente::NodoCliente(const Cliente& e) : data(e), next(nullptr) {}

Cliente NodoCliente::getData() const {
    return data;
    }

NodoCliente* NodoCliente::getNext() {
    return next;
    }

void NodoCliente::setData(const Cliente& d) {
    data=d;
    }

void NodoCliente::setNext(NodoCliente* p) {
    next = p;
    }
