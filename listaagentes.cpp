#include "listaagentes.hpp"

using namespace std;

/// Entregable 7
ListaAgentes::ListaAgentes() : header(new NodoAgente) {
    if(header == nullptr) {
        throw ListaExcepcion("Memoria no disponible, inicializando lista");
        }

    header->setPrev(header);
    header->setNext(header);
    }

bool ListaAgentes::isEmpty() {
    return header->getNext() == header;
    }

string ListaAgentes::toString(const bool& withListaClientes, const string& filtrado) {
    NodoAgente* aux(header->getNext());
    string result;

    if(filtrado == "todo") {

        while(aux != header) {
            result+=aux->getData().toString(withListaClientes);
            result+= "\n";

            aux = aux->getNext();
            }

        }
    else {

        while(aux != header) {

            if(filtrado == aux->getData().getEspecialidad()) {
                result+=aux->getData().toString(withListaClientes);
                result+= "\n";
                }

            aux = aux->getNext();
            }
        }

    return result;
    }

bool ListaAgentes::isValidPos(NodoAgente* p) {
    NodoAgente* aux(header->getNext());

    while(aux != header) {
        if(p == aux) {
            return true;
            }

        aux = aux->getNext();
        }

    return false;
    }

void ListaAgentes::insertData(NodoAgente* p, const Agente& e) {
    if(p != nullptr and !isValidPos(p)) {
        throw ListaExcepcion("Posicion invalida, insertData");
        }

    if(p == nullptr) {
        p = header;
        }

    NodoAgente* aux(new NodoAgente(e));
    if(aux == nullptr) {
        throw ListaExcepcion("Memoria no disponible, insertData");
        }

    aux->setPrev(p);
    aux->setNext(p->getNext());

    p->getNext()->setPrev(aux);
    p->setNext(aux);

    }

//////////////////////////

///Entregable 8 //Revisar en videos todo el entregable 8

NodoAgente* ListaAgentes::getPrevPos(NodoAgente* p) {
    if(!isValidPos(p) or p == header->getNext()) {
        return nullptr;
        }

    return p->getPrev();
    }

NodoAgente* ListaAgentes::getNextPos(NodoAgente* p) {
    if(!isValidPos(p) or p == header->getPrev()) {
        return nullptr;
        }

    return p->getNext();
    }

void ListaAgentes::deleteData(NodoAgente* p) {
    if(!isValidPos(p)) {
        throw ListaExcepcion("Posicion invalida, deleteData");
        }

    p->getPrev()->setNext(p->getNext());
    p->getNext()->setPrev(p->getPrev());

    delete p;

    }

NodoAgente* ListaAgentes::findData(const Agente& e) {
    NodoAgente* aux(header->getNext());

    while(aux != header) {
        if(aux->getData() == e) {
            return aux;
            }

        aux = aux->getNext();
        }

    return nullptr;
    }

void ListaAgentes::deleteAll() {
    NodoAgente *aux;

    while(header->getNext() != header) {
        aux = header->getNext();

        header->setNext(aux->getNext());

        delete aux;
        }

    header->setPrev(header);

    }

ListaAgentes::~ListaAgentes() {
    deleteAll();

    delete header;
    }

////////////////////////////////////////////////////////


void ListaAgentes::copyAll(const ListaAgentes& l) {
    NodoAgente *aux(l.header->getNext());
    NodoAgente *newNode;

    while(aux != l.header) {

        try {
            newNode = new NodoAgente(aux->getData());
            }
        catch (const NodoExcepcionAgente& ex) {
            string msg;

            msg = "Ha ocurrido un error, el error reportado es: \n";
            msg += ex.what();
            msg += "\n Si esto ocurre continuamente, reportelo";

            throw ListaExcepcion(msg);
            }


        if(newNode == nullptr) {
            throw ListaExcepcion("Memoria no disponible, copyAll");
            }

        newNode->setPrev(header->getNext());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();


        }

    }

void ListaAgentes::swapPtr(NodoAgente* a, NodoAgente* b) {
    /*
    Agente* aux(a->getDataPtr());

    a->setDataPtr(b->getDataPtr());

    b->setDataPtr(aux);
    */

    if(a != b) {
        Agente* aux(a->getDataPtr());
        a->setDataPtr(b->getDataPtr());
        b->setDataPtr(aux);
        }

    }

void ListaAgentes::sortByName() {

    sortByName(header->getNext(), header->getPrev());

    }

void ListaAgentes::sortByEspecialidad() {

    sortByEspecialidad(header->getNext(), header->getPrev());

    }

void ListaAgentes::sortByName(NodoAgente* leftEdge, NodoAgente* rightEdge) {

    if(leftEdge == rightEdge) {
        return;
        }

    if(leftEdge->getNext() == rightEdge) { ///son solo dos elementos
        if(leftEdge->getData().getNombre() > rightEdge->getData().getNombre()) {
            swapPtr(leftEdge, rightEdge);
            }

        return;
        }

///Separacion


    NodoAgente* i(leftEdge);
    NodoAgente* j(rightEdge);

    while(i != j) {
        while(i != j and i->getData().getNombre() <= rightEdge->getData().getNombre()) {
            i = i->getNext();
            }

        while(i != j and j->getData().getNombre() >= rightEdge->getData().getNombre()) {
            j = j->getPrev();
            }

        swapPtr(i,j);
        }

    swapPtr(i, rightEdge);

    if(i != leftEdge) {
        sortByName(leftEdge, i->getPrev());
        }

    if(i != rightEdge) {
        sortByName(i->getNext(),rightEdge);
        }
    }

void ListaAgentes::sortByEspecialidad(NodoAgente* leftEdge, NodoAgente* rightEdge) {

    if(leftEdge == rightEdge) {
        return;
        }

    if(leftEdge->getNext() == rightEdge) { ///son solo dos elementos
        if(leftEdge->getData().getEspecialidad() > rightEdge->getData().getEspecialidad()) {
            swapPtr(leftEdge, rightEdge);
            }

        return;
        }

///Separacion


    NodoAgente* i(leftEdge);
    NodoAgente* j(rightEdge);

    while(i != j) {
        while(i != j and i->getData().getEspecialidad() <= rightEdge->getData().getEspecialidad()) {
            i = i->getNext();
            }

        while(i != j and j->getData().getEspecialidad() >= rightEdge->getData().getEspecialidad()) {
            j = j->getPrev();
            }

        swapPtr(i,j);
        }

    swapPtr(i, rightEdge);

    if(i != leftEdge) {
        sortByEspecialidad(leftEdge, i->getPrev());
        }

    if(i != rightEdge) {
        sortByEspecialidad(i->getNext(),rightEdge);
        }
    }

ListaAgentes::ListaAgentes(const ListaAgentes& l) : ListaAgentes() {
    copyAll(l);
    }

NodoAgente* ListaAgentes::getFirstPos() {
    if(isEmpty()) {
        return nullptr;
        }

    return header->getNext();
    }

NodoAgente* ListaAgentes::getLastPos() {
    if(isEmpty()) {
        return nullptr;
        }

    return header->getPrev();
    }

Agente ListaAgentes::retrieve(NodoAgente* p) {
    if(!isValidPos(p)) {
        throw ListaExcepcion("Posicion invalida, retrieve");
        }

    return p->getData();
    }

/// Entregable 11

void ListaAgentes::writeToDisk(const string& fileName) {
    ofstream myFile;

    myFile.open(fileName, myFile.trunc);

    if(!myFile.is_open()) {
        string msg("El archivo ");
        msg += fileName + " no se pudo arbrir para escritura";
        throw ListaExcepcion(msg);

        }

    NodoAgente* aux(header->getNext());



    while(aux != header) {
        myFile << aux->getData() << endl;

        try {
            aux->getData().getListaClientes().writeToDisk(to_string(aux->getData().getCodigo())+".cliente");
            }
        catch(ListaExcepcion ex) {
            cout << ex.what() << endl;
            }
        aux = aux->getNext();
        }

    myFile.close();

    }

void ListaAgentes::readFromDisk(const std::string& fileName) {
    ifstream myFile;

    myFile.open(fileName);

    if(!myFile.is_open()) {
        string msg("Error al tratar de abrir el archivo ");
        msg += fileName;
        msg += " para lectura";

        throw ListaExcepcion(msg);
        }

    Agente myAgente;
    NodoAgente* aux;

    deleteAll();

    while(myFile >> myAgente) { ///se le el archivo y lo mandamos a la variable estudiante
        try {
            myAgente.getListaClientes().readFromDisk(to_string(myAgente.getCodigo()) + ".cliente");
            }
        catch(ListaExcepcion ex) {
            cout << ex.what() << endl;
            }

        if((aux = new NodoAgente(myAgente)) == nullptr) {
            myFile.close();

            throw ListaExcepcion("Memoria no disponible, readFromDisk");
            }

        aux->setPrev(header->getPrev());
        aux->setNext(header);

        header->getPrev()->setNext(aux);
        header->setPrev(aux);
        }

    myFile.close();
    }

ListaAgentes& ListaAgentes::operator = (const ListaAgentes& l) {
    deleteAll();
    copyAll(l);

    return *this;
    }
