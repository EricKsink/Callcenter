#include"listaclientes.hpp"

using namespace std;

//entregable 4

bool ListaClientes::isValidPos(NodoCliente* p) {
    NodoCliente* aux(anchor);

    while(aux!=nullptr) {
        if(aux==p) {
            return true;
            }
        aux=aux->getNext();
        }

    return false;

    }

ListaClientes::ListaClientes() : anchor(nullptr) {}

bool ListaClientes::isEmpty() {
    return anchor==nullptr;
    }

string ListaClientes::toString() const {
    NodoCliente* aux(anchor);
    string result;

    while(aux!=nullptr) {
        result+=aux->getData().toString();
        result+= "\n";

        aux=aux->getNext();
        }


    return result;
    }

void ListaClientes::insertData(NodoCliente* p, const Cliente& e) {
    if(p != nullptr and !isValidPos(p)) {
        throw ListaExcepcion("Posicion invalida, insertData");
        }

    NodoCliente* aux(new NodoCliente(e));

    if(aux==nullptr) {
        throw ListaExcepcion("Memoria no disponible, tratando e insertar");
        }

    if(p==nullptr) {
        aux->setNext(anchor);

        anchor=aux;

        }
    else {
        aux->setNext(p->getNext());

        p->setNext(aux);

        }

    }

void ListaClientes::insertOrdered(const Cliente& e) {
    NodoCliente* aux(anchor);
    NodoCliente* p(nullptr);

    while(aux != nullptr and e.getHoraInicio()>aux->getData().getHoraInicio()) {
        p=aux;
        aux=aux->getNext();
        }
    insertData(p,e);
    }

//***************

//Entregable 5

NodoCliente* ListaClientes::getPrevPos(NodoCliente* p) {
    if(!isValidPos(p) or p==anchor) {
        return nullptr;
        }

    NodoCliente* aux(anchor);


    while(aux->getNext()!=p) {
        aux=aux->getNext();
        }
    return aux;
    }

void ListaClientes::deleteData(NodoCliente* p) {

    if(!isValidPos(p)) {
        throw ListaExcepcion("Posicion invalida, deleteData");
        }

    if(p==anchor) {
        anchor = p->getNext();
        }
    else {
        getPrevPos(p)->setNext(p->getNext());
        }

    delete p;

    }

NodoCliente* ListaClientes::findData(const Cliente& e) {
    NodoCliente* aux(anchor);

    while(aux!=nullptr and aux->getData()!=e) {
        aux=aux->getNext();
        }

    return aux;
    }


void ListaClientes::deleteAll() {
    NodoCliente* aux;


    while(anchor != nullptr) {
        aux = anchor;

        anchor = anchor -> getNext();
        delete aux;
        }
    }


ListaClientes::~ListaClientes() {
    deleteAll();
    }


///**************


void ListaClientes::copyAll(const ListaClientes& l) {
    NodoCliente* aux(l.anchor);
    NodoCliente* prev(nullptr);
    NodoCliente* newNodo;

    while (aux!=nullptr) {
        newNodo = new NodoCliente(aux->getData());

        if(newNodo == nullptr) {
            throw ListaExcepcion("memoria no disponible, copyAll");
            }

        if(prev == nullptr) {
            anchor = newNodo;
            }
        else {
            prev->setNext(newNodo);
            }

        prev = newNodo;

        aux = aux->getNext();
        }

    }



ListaClientes::ListaClientes(const ListaClientes& l) : ListaClientes() {
    copyAll(l);
    }





NodoCliente* ListaClientes::getFirstPos() {
    return anchor;
    }

NodoCliente* ListaClientes::getLastPos() {
    if(isEmpty()) {
        return nullptr;
        }

    NodoCliente* aux(anchor);

    while(aux->getNext() != nullptr) {
        aux = aux->getNext();
        }

    return aux;

    }



NodoCliente* ListaClientes::getNextPos(NodoCliente* p) {

    if(!isValidPos(p)) {
        return nullptr;
        }

    return p->getNext();

    }



Cliente ListaClientes::retrieve(NodoCliente* p) {
    if(!isValidPos(p)) {
        throw ListaExcepcion ("Posicion invalida, retrieve");
        }

    return p->getData();
    }



///Entregable 11

void ListaClientes::writeToDisk(const string& fileName) {
    ofstream myFile;

    myFile.open(fileName, myFile.trunc); // si el archivo ya existe sobre escribe en el archivo

    if(!myFile.is_open()) {
        string msg;
        msg = "El archivo";
        msg +=fileName + "no se pudo abrir para escritura";
        throw ListaExcepcion(msg);
        }

    NodoCliente* aux(anchor);

    while(aux != nullptr) {
        myFile << aux->getData() << endl;

        aux = aux->getNext();
        }

    myFile.close();

    }

void ListaClientes::readFromDisk(const string& fileName) {
    ifstream myFile;

    myFile.open(fileName);

    if(!myFile.is_open()) {
        string msg("Error al abrir el archivo ");
        msg += fileName;
        msg += " para lectura, lloremos";

        throw ListaExcepcion(msg);
        }

    deleteAll();

    Cliente myCliente;
    NodoCliente* last(nullptr);
    NodoCliente* newNode;

    while(myFile >> myCliente) {
        if((newNode = new NodoCliente(myCliente)) == nullptr) {
            myFile.close();

            throw ListaExcepcion("Memoria no dispponible, readFromDisk");
            }

        if(last == nullptr) {
            anchor = newNode;
            }
        else {
            last->setNext(newNode);
            }

        last = newNode;
        }

    myFile.close();
    }

ListaClientes& ListaClientes::operator = (const ListaClientes& l) {
    deleteAll();
    copyAll(l);

    return *this;

    }
