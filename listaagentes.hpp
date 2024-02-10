#ifndef LISTAAGENTES_HPP_INCLUDED
#define LISTAAGENTES_HPP_INCLUDED

#include <string>
#include <fstream>

#include"nodoagente.hpp"
#include "agente.hpp"

class ListaAgentes {
    private:

        NodoAgente* header;

        bool  isValidPos(NodoAgente*);

        void copyAll(const ListaAgentes&);

        void swapPtr(NodoAgente*, NodoAgente*);

        void sortByName(NodoAgente*, NodoAgente*);
        void sortByEspecialidad(NodoAgente*, NodoAgente*);

    public:

        ListaAgentes();
        ListaAgentes(const ListaAgentes&);

        ~ListaAgentes();

        bool isEmpty();

        void insertData(NodoAgente*, const Agente&);

        void deleteData(NodoAgente*);

        NodoAgente* getFirstPos();
        NodoAgente* getLastPos();
        NodoAgente* getPrevPos(NodoAgente*);
        NodoAgente* getNextPos(NodoAgente*);

        NodoAgente* findData(const Agente&);

        Agente retrieve(NodoAgente*);

        void sortByName();
        void sortByEspecialidad();

        std::string toString(const bool&, const std::string&);

        void deleteAll();

        void writeToDisk(const std::string&);
        void readFromDisk(const std::string&);

        ListaAgentes& operator = (const ListaAgentes&);

    };

#endif // LISTAAGENTES_HPP_INCLUDED
