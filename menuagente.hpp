#ifndef MENUAGENTE_HPP_INCLUDED
#define MENUAGENTE_HPP_INCLUDED

#include "agente.hpp"
#include "tiempo.hpp"
#include "nombre.hpp"
#include "listaclientes.hpp"
#include "listaagentes.hpp"
#include "menucliente.hpp"


class MenuAgente {
    public:

        MenuAgente(ListaAgentes*);

    private:

        void startMenu();
        void enterToContinue();
        void mainMenu();
        void addAgente();
        void deleteAgente();
        void modifyAgente();
        void modifyAgente(NodoAgente*);
        void showAgente();
        void sortAgente();
        void findAgente();
        void writeToDisk();
        void readFromDisk();

        NodoAgente* findDataName();

        ListaAgentes* listaAgentesRef;


    };

#endif // MENUAGENTE_HPP_INCLUDED
