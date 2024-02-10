#ifndef LISTAEXCEPCION_HPP_INCLUDED
#define LISTAEXCEPCION_HPP_INCLUDED

#include <exception>
#include <string>

class ListaExcepcion : public std::exception {
    private:
        std::string msg;
    public:
        explicit ListaExcepcion(const char* message):msg(message) {}

        explicit ListaExcepcion(const std::string& message) : msg(message) {}

        virtual ~ListaExcepcion() throw () {}

        virtual const char* what() const throw() {
            return msg.c_str();
            }

    };

#endif // LISTAEXCEPCION_HPP_INCLUDED
