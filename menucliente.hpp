#ifndef MENUCLIENTE_HPP_INCLUDED
#define MENUCLIENTE_HPP_INCLUDED


#include "listaclientes.hpp"
#include "nodocliente.hpp"
#include "cliente.hpp"
#include "tiempo.hpp"
#include "menuagente.hpp"

class MenuCliente {
    private:

        ListaClientes* listaClientesRef;

        void enterToContinue();



    public:

        MenuCliente(ListaClientes*);
        void mainMenu();
        void addCliente();
        void deleteCliente();
        void modifyCliente();
        void showCliente();


    };

#endif // MENUCLIENTE_HPP_INCLUDED
