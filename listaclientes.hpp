#ifndef LISTACLIENTES_HPP_INCLUDED
#define LISTACLIENTES_HPP_INCLUDED

#include <string>
#include <fstream>
#include "nodocliente.hpp"
#include "listaexcepcion.hpp"

class ListaClientes {
    private:

        NodoCliente* anchor;

        bool isValidPos(NodoCliente*);

        void copyAll(const ListaClientes&);

    public:

        ListaClientes();
        ListaClientes(const ListaClientes&);

        ~ListaClientes();

        bool isEmpty();

        void insertData(NodoCliente*, const Cliente&);

        void insertOrdered(const Cliente&);

        void deleteData(NodoCliente*);

        NodoCliente* getFirstPos();
        NodoCliente* getLastPos();
        NodoCliente* getPrevPos(NodoCliente*);
        NodoCliente* getNextPos(NodoCliente*);

        NodoCliente* findData(const Cliente&);

        Cliente retrieve(NodoCliente*);

        std::string toString() const;

        void deleteAll();

        void writeToDisk(const std::string&);
        void readFromDisk(const std::string&);

        ListaClientes& operator = (const ListaClientes&);


    };

#endif // LISTACLIENTES_HPP_INCLUDED
