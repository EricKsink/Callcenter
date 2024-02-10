#include"menucliente.hpp"

using namespace std;
MenuCliente::MenuCliente(ListaClientes* p) : listaClientesRef(p) {
    mainMenu();
    }

void MenuCliente::mainMenu() {
    char op;
    do {
        system("cls");

        cout<<"---Menu Clientes---"<<endl;
        cout<<"1)Agregar"<<endl;
        cout<<"2)Eliminar"<<endl;
        cout<<"3)Editar"<<endl;
        cout<<"4)Mostrar clientes"<<endl;

        cout<<"5)Salir"<<endl;

        cout<<"Digite la opcion deseada: ";

        cin>>op;
        cin.ignore();// limpiar el teclado solamente aplicarlo cuando se captura un char


        //op=toupper(op);// el caracter lo cambia a mayuscula

        switch(op) {
            case '1':
                addCliente();
                break;
            case '2':
                deleteCliente();
                break;
            case '3':
                modifyCliente();
                break;
            case '4':
                showCliente();
                break;
            case '5':
                cout<<"Regresando..."<<endl;
                break;
            default:
                cout<<"Opcion invalida"<<endl<<endl;
                enterToContinue();
            }

        }
    while(op != '5');
    }

void MenuCliente::addCliente() {
    system("cls");


    Tiempo myTime;
    NodoCliente* pos(nullptr);
    Nombre myNombre;
    Cliente myCliente;
    string myStr;

    cout << "---Alta de nuevo cliente---" << endl <<endl;

    cout <<"Nombre's: ";
    getline(cin,myStr);
    myNombre.setNombre(myStr);
    cout<<"Digite sus apellidos, empezando por el apellido paterno (Apellido Paterno |Espacio| Apellido Materno): ";
    getline(cin,myStr,' ');
    myNombre.setApp(myStr);
    getline(cin,myStr);
    myNombre.setApm(myStr);

    myCliente.setNombre(myNombre);

    pos = listaClientesRef->findData(myCliente);

    if(pos != nullptr) {
        cout<<"Error ese Cliente ya esta registrado"<<endl;
        enterToContinue();
        return;
        }



    cout<<"Hora de inicio de llamada (HH:MM): ";
    getline(cin, myStr, ':');
    myTime.setHora(stoi(myStr));
    getline(cin, myStr);
    myTime.setMinutos(stoi(myStr));

    myCliente.setHoraInicio(myTime);

    cout<<"Hora de fin de llamada (HH:MM): ";
    getline(cin, myStr, ':');
    myTime.setHora(stoi(myStr));
    getline(cin, myStr);
    myTime.setMinutos(stoi(myStr));

    myCliente.setHoraFinal(myTime);

    try {
        listaClientesRef->insertOrdered(myCliente);
        }
    catch (const ListaExcepcion& ex) {
        cout<<"Ha ocurrido un problema" << endl;
        cout<<"El sistema ha reportado: "<<ex.what()<<endl;
        cout<<"Estamos jodidos" << endl;
        enterToContinue();
        return;
        }

    cout<<"Cliente insertado exitosamente" << endl;

    enterToContinue();

    }

void MenuCliente::deleteCliente() {
    char op;

    system("cls");

    cout<<"---Eliminacion de clientes---"<<endl<<endl;

    cout<<"1) Eliminar Cliente por nombre"<<endl;
    cout<<"2) Eliminar todos los clientes"<<endl;
    cout<<"3) Salir"<<endl;

    cout<<"Digite la opcion deseada: ";

    cin>>op;
    cin.ignore();// limpiar el teclado solamente aplicarlo cuando se captura un char


    //op=toupper(op);// el caracter lo cambia a mayuscula

    switch(op) {
        case '1': {
            NodoCliente* pos(nullptr);
            string myStr;
            Nombre myNombre;
            Cliente myCliente;

            system("cls");


            cout<<"Eliminacion de clientes"<<endl<<endl;

            cout<<"Nombre's de la persona a eliminar: ";
            getline(cin,myStr);
            myNombre.setNombre(myStr);

            cout<<"Digite sus apellidos, empezando por el apellido paterno (Apellido Paterno |Espacio| Apellido Materno): ";
            getline(cin,myStr,' ');
            myNombre.setApp(myStr);
            getline(cin,myStr);
            myNombre.setApm(myStr);

            myCliente.setNombre(myNombre);

            pos = listaClientesRef ->findData(myCliente);

            if(pos == nullptr) {
                cout<<"No se puede eliminar por que no existe ese Nombre en la lista"<<endl;
                enterToContinue();
                return;
                }

            listaClientesRef->deleteData(pos);

            cout<<"Cliente eliminado..."<<endl;

            enterToContinue();

            break;
            }

        case '2': {
            system("cls");
            cout<<"Eliminacion de clientes"<<endl<<endl;

            cout<<"Esta seguro que desea eliminar todos los agentes [S/N]: ";

            do {
                cin>>op;
                cin.ignore();// limpiar el teclado solamente aplicarlo cuando se captura un char

                op=toupper(op);// el caracter lo cambia a mayuscula
                }
            while(op != 'S' and op != 'N');


            switch(op) {
                case 'S':
                    listaClientesRef->deleteAll();
                    cout<<"Se han eliminado todos los clientes"<<endl;
                    enterToContinue();
                    break;
                case 'N':
                    cout<<"Regresando..."<<endl;
                    enterToContinue();
                }



            break;
            }
        case '3':
            cout<<"Regresando..."<<endl;
            enterToContinue();
            break;
        default :
            cout<<"Porfavor ingrese una opcion valida"<<endl;
            enterToContinue();
        }



    }

void MenuCliente::modifyCliente() {
    char op;
    string myStr;
    Nombre myNombre;
    Cliente myCliente;
    Tiempo myTiempo;
    NodoCliente* pos(nullptr);

    system("cls");

    cout<<"Modificar Cliente"<<endl<<endl;

    cout<<"Digite los nombres del cliente a modificar: ";
    getline(cin,myStr);
    myNombre.setNombre(myStr);

    cout<<"Digite los Apellidos del cliente a modificar: ";
    getline(cin,myStr,' ');
    myNombre.setApp(myStr);
    getline(cin,myStr);
    myNombre.setApm(myStr);

    myCliente.setNombre(myNombre);

    pos = listaClientesRef->findData(myCliente);

    if(pos == nullptr) {
        cout<<"No se encontro dicho cliente"<<endl;
        enterToContinue();
        return;
        }
    system("cls");
    cout<<"Menu de modificacion"<<endl<<endl;

    cout<<"1) Modificar Nombres"<<endl;
    cout<<"2) Modificar Hora del inicio de llamada"<<endl;
    cout<<"3) Modificar Hora de fin de llamada"<<endl;
    cout<<"4) Salir"<<endl;

    cout<<"Digite la opcion deseada: ";
    cin>>op;
    cin.ignore();// limpiar el teclado solamente aplicarlo cuando se captura un char

    //op=toupper(op);// el caracter lo cambia a mayuscula

    switch(op) {
        case '1': {

            system("cls");
            cout<<"---Modificar Nombres---"<<endl;
            cout<<"\n";
            cout<<listaClientesRef->retrieve(pos).toString()<<endl;
            cout<<"\n";

            cout<<"Digite el nuevo Nombre: ";
            getline(cin,myStr);
            myNombre.setNombre(myStr);

            cout<<"Diigite los Apellidos: ";
            getline(cin,myStr,' ');
            myNombre.setApp(myStr);
            getline(cin,myStr);
            myNombre.setApm(myStr);

            myCliente=listaClientesRef->retrieve(pos);

            myCliente.setNombre(myNombre);

            listaClientesRef->deleteData(pos);

            listaClientesRef->insertOrdered(myCliente);

            break;
            }
        case '2': {

            system("cls");
            cout<<"---Modificar Hora del inicio de llamada---"<<endl;
            cout<<"\n";
            cout<<listaClientesRef->retrieve(pos).toString()<<endl;
            cout<<"\n";

            cout<<"Digite la nueva hora del inicio de llamada (HH:MM): ";
            getline(cin, myStr, ':');
            myTiempo.setHora(stoi(myStr));
            getline(cin, myStr);
            myTiempo.setMinutos(stoi(myStr));

            myCliente=listaClientesRef->retrieve(pos);

            myCliente.setHoraInicio(myTiempo);

            listaClientesRef->deleteData(pos);

            listaClientesRef->insertOrdered(myCliente);

            break;
            }
        case '3': {

            system("cls");
            cout<<"---Modificar Hora de fin de llamada---"<<endl;
            cout<<"\n";
            cout<<listaClientesRef->retrieve(pos).toString()<<endl;
            cout<<"\n";

            cout<<"Digite la nueva hora de fin de llamada (HH:MM): ";
            getline(cin, myStr, ':');
            myTiempo.setHora(stoi(myStr));
            getline(cin, myStr);
            myTiempo.setMinutos(stoi(myStr));

            myCliente=listaClientesRef->retrieve(pos);

            myCliente.setHoraFinal(myTiempo);

            listaClientesRef->deleteData(pos);

            listaClientesRef->insertOrdered(myCliente);

            break;
            }
        case '4': {
            cout<<"Regresando..."<<endl;
            enterToContinue();
            break;
            }
        default:
            cout<<"Opcion no valida"<<endl;
            cout<<"Regresando..."<<endl;
            enterToContinue();
        }





    }

void MenuCliente::showCliente() {

    system("cls");

    cout<<"Listado de clientes" << endl << endl;

    cout<< listaClientesRef->toString();

    cout<< endl << endl;
    enterToContinue();
    }

void MenuCliente::enterToContinue() {
    cout << "Enter para continuar...." << endl;
    cin.get();
    }


