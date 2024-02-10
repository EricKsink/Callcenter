#include "menuagente.hpp"

using namespace std;

void MenuAgente::enterToContinue() {
    fflush(stdin);
    cout << "Enter para continuar...." << endl;
    cin.get();
    }

void MenuAgente::mainMenu() {

    int op;

    do {
        system("cls");

        cout<<"----------------Menu de Agentes------------"<<endl<< endl;

        cout<<"1)Agregar"<<endl;
        cout<<"2)Eliminar"<<endl;
        cout<<"3)Modificar"<<endl;
        cout<<"4)Mostrar"<<endl;
        cout<<"5)Buscar"<<endl;
        cout<<"6)Ordenar"<<endl;
        cout<<"7)Escribir al disco"<<endl;
        cout<<"8)Leer del disco"<<endl;
        cout<<"9)Salir"<<endl;

        cout<<"Selecciona una opcion: ";
        cin>>op;

        switch(op) {
            case 1:
                addAgente();
                break;
            case 2:
                deleteAgente();
                break;
            case 3:
                modifyAgente();
                break;
            case 4:
                showAgente();
                break;
            case 5:
                findAgente();
                break;
            case 6:
                sortAgente();
                break;
            case 7:
                writeToDisk();
                break;
            case 8:
                readFromDisk();
                break;
            case 9:

                cout<<"Guardando cambios...."<<endl;

                writeToDisk();

                break;
            default:
                cout<<"\nOpcion invalida, intente de nuevo..."<<endl;
                enterToContinue();
            }



        }
    while(op!=9);

    }

void MenuAgente::addAgente() {

    Nombre myNombre;
    Agente myAgente;
    string myStr;
    NodoAgente* pos(nullptr);
    Tiempo myTiempo;

    system("cls");

    cout<<"---Agregando clientes---"<<endl<<endl;

    fflush(stdin);
    cout<<"Digite los nombres del agente a ingresar: ";
    getline(cin,myStr);
    myNombre.setNombre(myStr);

    cout<<"Digite los apellidos del agente a ingresar (empezando por apellido paterno): ";
    getline(cin,myStr,' ');
    myNombre.setApp(myStr);
    getline(cin,myStr);
    myNombre.setApm(myStr);

    myAgente.setNombre(myNombre);

    pos = listaAgentesRef->findData(myAgente);

    if(pos != nullptr) {
        char op;

        system("cls");

        cout<<"---Agregando clientes---"<<endl;

        cout<<"Error ese Agente ya esta registrado..."<<endl<<endl;

        cout<<"Nombre y Apellidos                  | Especialidad  | Codigo           | Num Extencion     |Entrada|Salida |Extras |"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;

        cout<<"\n"+listaAgentesRef->retrieve(pos).toString(true)<<endl;

        do {
            cout<<"Desea modificar al agente registrado [S/N]: ";

            cin>>op;

            cin.ignore();

            op = toupper(op);

            }
        while(op != 'S' and op != 'N');

        if(op == 'S') {
            modifyAgente(pos);
            }

        enterToContinue();
        return;
        }

    cout<<"Digite la hora de Entrada del agente [HH:MM]: ";
    getline(cin,myStr,':');
    myTiempo.setHora(stoi(myStr));
    getline(cin,myStr);
    myTiempo.setMinutos(stoi(myStr));

    myAgente.setHoraInicial(myTiempo);

    cout<<"Digite la hora de Salida del agente [HH:MM]: ";
    getline(cin,myStr,':');
    myTiempo.setHora(stoi(myStr));
    getline(cin,myStr);
    myTiempo.setMinutos(stoi(myStr));

    myAgente.setHoraSalida(myTiempo);

    cout<<"Digite el codigo a asignar al agente (solo digitos): ";
    getline(cin,myStr);

    myAgente.setCodigo(stoi(myStr));

    cout<<"Digite el numero de extencion a signar al agente (solo digitos): ";
    getline(cin,myStr);

    myAgente.setNumExtencion(stoi(myStr));

    cout<<"Digite las horas extras [HH:MM]: ";
    getline(cin,myStr,':');
    myTiempo.setHora(stoi(myStr));
    getline(cin,myStr);
    myTiempo.setMinutos(stoi(myStr));

    myAgente.setHorasExtras(myTiempo);

    char op;

    cout<<endl;


    cout<<"---Especialidades disponibles---"<<endl;
    cout<<"1)Servidores"<<endl;
    cout<<"2)De escritorio"<<endl;
    cout<<"3)Portatiles"<<endl;
    cout<<"4)Linux"<<endl;
    cout<<"5)Impresoras "<<endl;
    cout<<"6)Redes "<<endl;

    do {

        cout<<"Digite la opcion deseada: ";
        cin>>op;

        }
    while(op != '1' and op != '2' and op != '3' and op != '4' and op != '5' and op != '6');

    switch(op) {
        case '1':
            myAgente.setEspecialidad("Servidores");
            break;
        case '2':
            myAgente.setEspecialidad("De escritorio");
            break;
        case '3':
            myAgente.setEspecialidad("Portatiles");
            break;
        case '4':
            myAgente.setEspecialidad("Linux");
            break;
        case '5':
            myAgente.setEspecialidad("Impresoras");
            break;
        case '6':
            myAgente.setEspecialidad("Redes");
            break;
        }

    cout<<endl;

    do {
        cout<<"Quieres modificar la lista de clientes? (S/N): ";
        cin>>op;
        cin.ignore();
        op = toupper(op);

        }
    while(op != 'N' and op != 'S');

    cout<<endl<<endl;

    if(op == 'S') {
        new MenuCliente(&myAgente.getListaClientes());
        }

    try {
        listaAgentesRef->insertData(listaAgentesRef->getLastPos(),myAgente); //pos,e
        }
    catch(ListaExcepcion ex) {
        cout<<"woao hubo un problema, increible, asombroso, inimaginable"<<endl;
        cout<<"El sistema informa: "<<ex.what()<<endl;
        cout<<"Si este proble persiste llama"<<endl;
        enterToContinue();
        return;
        }
    system("cls");

    cout<<"---Agregando Clientes---"<<endl;;

    cout<<"Alumno insertado Exitosamente"<<endl<<endl;

    cout<<"Nombre y Apellidos                  | Especialidad  | Codigo           | Num Extencion     |Entrada|Salida |Extras |"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

    cout<<myAgente.toString(true)<<endl;

    enterToContinue();


    }

void MenuAgente::modifyAgente(NodoAgente* pos) {
    int op;

    if(pos == nullptr) {
        cout<<"Agente no encontrado"<<endl;
        enterToContinue();
        return;
        }
    do {

        system("cls");

        cout<<"---Menu edicion---"<<endl<<endl;

        cout<<"Nombre y Apellidos                  | Especialidad  | Codigo           | Num Extencion     |Entrada|Salida |Extras |"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;

        cout<<"\n"+listaAgentesRef->retrieve(pos).toString(true)<<endl;

        do {

            cout<<"1)Nombre"<<endl;
            cout<<"2)Apellidos"<<endl;
            cout<<"3)Hora entrada"<<endl;
            cout<<"4)Hora salida"<<endl;
            cout<<"5)Codigo"<<endl;
            cout<<"6)Numero extencion"<<endl;
            cout<<"7)Horas extras"<<endl;
            cout<<"8)Especialidad"<<endl;
            cout<<"9)Lista Clientes"<<endl;
            cout<<"10)Salir"<<endl;

            cout<<"Digite la opcion deseada: ";
            cin>>op;

            }
        while(op > 10 or op < 1);



        //me falta acabar, mañana que ya tengo sueño, que se preocupe mi yo del futuro

        system("cls");
        cout<<"---Menu edicion---"<<endl<<endl;

        cout<<"Nombre y Apellidos                  | Especialidad  | Codigo           | Num Extencion     |Entrada|Salida |Extras |"<<endl;
        cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

        cout<<listaAgentesRef->retrieve(pos).toString(true)<<endl<<endl;


        switch(op) {
            case 1: {

                Nombre myNombre;
                Agente myAgente;
                string myStr;

                myNombre = listaAgentesRef->retrieve(pos).getNombre();
                myAgente = listaAgentesRef->retrieve(pos);

                fflush(stdin);
                cout<<"Digite el nombre con el cual modificar al agente: ";
                getline(cin,myStr);
                myNombre.setNombre(myStr);

                myAgente.setNombre(myNombre);

                try {
                    pos->setData(myAgente);
                    }
                catch(NodoExcepcionAgente ex) {
                    cout<<"woao hubo un problema, increible, asombroso, inimaginable"<<endl;
                    cout<<"El sistema informa: "<<ex.what()<<endl;
                    cout<<"Si este proble persiste llama"<<endl;
                    enterToContinue();
                    return;
                    }


                }


            break;

            case 2: {
                Nombre myNombre;
                Agente myAgente;
                string myStr;

                myNombre = listaAgentesRef->retrieve(pos).getNombre();
                myAgente = listaAgentesRef->retrieve(pos);

                fflush(stdin);
                cout<<"Digite los nuevos apellidos del agente: ";
                getline(cin,myStr,' ');
                myNombre.setApp(myStr);
                getline(cin,myStr);
                myNombre.setApm(myStr);

                myAgente.setNombre(myNombre);

                pos->setData(myAgente);

                }
            break;
            case 3: {
                Tiempo myHora;
                Agente myAgente;
                string myStr;

                myAgente = listaAgentesRef->retrieve(pos);

                fflush(stdin);
                cout<<"Digite la nueva hora de entrada [HH/MM]: ";
                getline(cin,myStr,':');
                myHora.setHora(stoi(myStr));
                getline(cin,myStr);
                myHora.setMinutos(stoi(myStr));

                myAgente.setHoraInicial(myHora);

                pos->setData(myAgente);

                }
            break;
            case 4: {
                Tiempo myHora;
                Agente myAgente;
                string myStr;

                myAgente = listaAgentesRef->retrieve(pos);

                fflush(stdin);
                cout<<"Digite la nueva hora de Salida [HH/MM]: ";
                getline(cin,myStr,':');
                myHora.setHora(stoi(myStr));
                getline(cin,myStr);
                myHora.setMinutos(stoi(myStr));

                myAgente.setHoraSalida(myHora);

                pos->setData(myAgente);

                }
            break;
            case 5: {
                string myStr;
                Agente myAgente;

                myAgente = listaAgentesRef->retrieve(pos);

                fflush(stdin);
                cout<<"Digite el nuevo codigo (solamente digitos): ";
                getline(cin,myStr);

                myAgente.setCodigo(stoi(myStr));

                pos->setData(myAgente);
                }
            break;
            case 6: {
                string myStr;
                Agente myAgente;

                myAgente = listaAgentesRef->retrieve(pos);

                fflush(stdin);
                cout<<"Digite el nuevo Numero de extencion (solamente digitos): ";
                getline(cin,myStr);

                myAgente.setNumExtencion(stoi(myStr));

                pos->setData(myAgente);

                }

            break;
            case 7: {
                Tiempo myHora;
                Agente myAgente;
                string myStr;

                myAgente = listaAgentesRef->retrieve(pos);

                fflush(stdin);
                cout<<"Digite las horas extas a editar [HH/MM]: ";
                getline(cin,myStr,':');
                myHora.setHora(stoi(myStr));
                getline(cin,myStr);
                myHora.setMinutos(stoi(myStr));

                myAgente.setHorasExtras(myHora);

                pos->setData(myAgente);

                }
            break;
            case 8: {
                Agente myAgente;
                char opcion;
                cout<<endl;

                myAgente = listaAgentesRef->retrieve(pos);

                do {
                    cout<<"---Especialidades disponibles---"<<endl;
                    cout<<"1)Servidores"<<endl;
                    cout<<"2)De escritorio"<<endl;
                    cout<<"3)Portatiles"<<endl;
                    cout<<"4)Linux"<<endl;
                    cout<<"5)Impresoras"<<endl;
                    cout<<"6)Redes"<<endl;

                    cout<<"Digite la opcion deseada: ";
                    cin>>opcion;

                    }
                while(opcion != '1' and opcion != '2' and opcion != '3' and opcion != '4' and opcion != '5' and opcion != '6');

                switch(opcion) {
                    case '1':
                        myAgente.setEspecialidad("Servidores");
                        break;
                    case '2':
                        myAgente.setEspecialidad("De escritorio");
                        break;
                    case '3':
                        myAgente.setEspecialidad("Portatiles");
                        break;
                    case '4':
                        myAgente.setEspecialidad("Linux");
                        break;
                    case '5':
                        myAgente.setEspecialidad("Impresoras");
                        break;
                    case '6':
                        myAgente.setEspecialidad("Redes");
                    }

                pos->setData(myAgente);
                }
            break;
            case 9: {
                Agente myAgente;

                myAgente = listaAgentesRef->retrieve(pos);

                MenuCliente(&myAgente.getListaClientes());

                pos->setData(myAgente);
                }
            break;
            case 10:
                break;
            }


        }
    while(op != 10);

    }

void MenuAgente::deleteAgente() {
    int op;

    system("cls");

    cout<<"---Menu Eliminacion---"<<endl<<endl;

    if(listaAgentesRef->isEmpty()) {

        cout <<"La lista de agentes esta vacia, es imposible eliminar" <<endl<<endl;

        enterToContinue();
        }
    else {


        do {

            cout<<"1)Eliminar agente por nombre"<<endl;
            cout<<"2)Eliminar TODOS los agentes"<<endl;

            cout<<"Digite la opcion deseada: ";
            cin>>op;

            }
        while(op != 1 and op != 2);

        if(op == 1) {
            system("cls");

            cout<<"---Menu Eliminacion---"<<endl<<endl;
            NodoAgente* pos;


            pos = findDataName();

            if(pos == nullptr) {
                cout<<"\nEl agente no se a encontrado..."<< endl<<endl;

                enterToContinue();
                return;
                }

            cout<<"\nNombre y Apellidos                  | Especialidad  | Codigo           | Num Extencion     |Entrada|Salida |Extras |"<<endl;
            cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl;

            cout<<listaAgentesRef->retrieve(pos).toString(true)<<endl;

            listaAgentesRef->deleteData(pos);

            cout<<"Agente Eliminado exitosamente \n"<<endl;
            enterToContinue();

            }
        else {
            char opcion;
            system("cls");

            cout<<"---Menu Eliminacion---"<<endl<<endl;

            do {
                cout<<"Estas SEGURISIMO? [S/N]: ";
                cin>>opcion;

                cin.ignore();

                opcion = toupper(opcion);
                }
            while(opcion != 'S' and opcion != 'N');

            if(opcion == 'S') {
                listaAgentesRef->deleteAll();
                cout<<"Todos los agentes fueron eliminados"<<endl;
                enterToContinue();
                }
            else {
                return;
                }

            }
        }

    }

void MenuAgente::modifyAgente() {
    NodoAgente* pos;

    system("cls");

    cout<<"---Menu edicion---"<<endl<<endl;

    if(listaAgentesRef->isEmpty()) {
        cout<<"La lista esta vacia, es imposible modificar" <<endl<<endl;
        enterToContinue();
        }
    else {

        pos = findDataName();

        modifyAgente(pos);
        }
    }

void MenuAgente::showAgente() {
    char op,op2,op3;
    string especialidad("todo");

    system("cls");

    cout<<">>>>>>>>Listado de estudiantes<<<<<<<<<<"<<endl<<endl;

    do {
        cout<<"Desea ver la lista de llamadas de cada agente? (S/N): ";
        cin>>op;
        cin.ignore();
        op = toupper(op);

        }
    while(op != 'N' and op != 'S');

    do {
        cout<<"Desea ver solo los agentes de una especialidad? (S/N): ";
        cin>>op2;
        cin.ignore();
        op2 = toupper(op2);

        }
    while(op2 != 'N' and op2 != 'S');

    if(op2 == 'S') {
        cout<<endl;


        cout<<"---Especialidades disponibles---"<<endl;
        cout<<"1)Servidores"<<endl;
        cout<<"2)De escritorio"<<endl;
        cout<<"3)Portatiles"<<endl;
        cout<<"4)Linux"<<endl;
        cout<<"5)Impresoras "<<endl;
        cout<<"6)Redes "<<endl;

        do {

            cout<<"Digite la opcion deseada: ";
            cin>>op3;

            }
        while(op3 != '1' and op3 != '2' and op3 != '3' and op3 != '4' and op3 != '5' and op3 != '6');

        switch(op3) {
            case '1':
                especialidad = "Servidores";
                break;
            case '2':
                especialidad = "De escritorio";
                break;
            case '3':
                especialidad = "Portatiles";
                break;
            case '4':
                especialidad = "Linux";
                break;
            case '5':
                especialidad = "Impresoras";
                break;
            case '6':
                especialidad = "Redes";
                break;
            }

        }

    cout<<endl;

    cout<<"Nombre y Apellidos                  | Especialidad  | Codigo           | Num Extencion     |Entrada|Salida |Extras |"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl<<endl;

    cout<<listaAgentesRef->toString(op == 'S',especialidad)<<endl;

    enterToContinue();

    }

void MenuAgente::sortAgente() {
    int op;

    do {

        system("cls");

        cout<<"---Menu ordenamiento---"<<endl<<endl;

        if(listaAgentesRef->isEmpty()) {
            cout<<"La lista de agentes esta vacia, es imposible ordenar"<<endl<<endl;

            enterToContinue();

            return;
            }

        cout<<"1)Ordenar Lista por nombre"<<endl;
        cout<<"2)Ordenar Lista por especialidad"<<endl;
        cout<<"3)Salir"<<endl<<endl;

        cout<<"Digite la opcion deseada: ";

        cin>>op;

        }
    while(op > 3 and op < 1);

    if(op == 3) {
        return;
        }

    if(op == 1) {
        listaAgentesRef->sortByName();
        }
    else {
        listaAgentesRef->sortByEspecialidad();
        }


    }

MenuAgente::MenuAgente(ListaAgentes* p) : listaAgentesRef(p) {
    startMenu();
    mainMenu();
    }

void MenuAgente::startMenu() {

    char op;
    system("cls");

    cout<< R"(
_____/\\\\\\\\\\\____/\\\\\\\\\\\__/\\\\\\\\\\\_____/\\\\\\\\\________/\\\\\\\\\___________/\\\\\\\\\_
 ___/\\\/////////\\\_\/////\\\///__\/////\\\///____/\\\\\\\\\\\\\____/\\\\\\\\\\\\\______/\\\////////__
  __\//\\\______\///______\/\\\_________\/\\\______/\\\/////////\\\__/\\\/////////\\\___/\\\/___________
   ___\////\\\_____________\/\\\_________\/\\\_____\/\\\_______\/\\\_\/\\\_______\/\\\__/\\\_____________
    ______\////\\\__________\/\\\_________\/\\\_____\/\\\\\\\\\\\\\\\_\/\\\\\\\\\\\\\\\_\/\\\_____________
     _________\////\\\_______\/\\\_________\/\\\_____\/\\\/////////\\\_\/\\\/////////\\\_\//\\\____________
      __/\\\______\//\\\______\/\\\_________\/\\\_____\/\\\_______\/\\\_\/\\\_______\/\\\__\///\\\__________
       _\///\\\\\\\\\\\/____/\\\\\\\\\\\__/\\\\\\\\\\\_\/\\\_______\/\\\_\/\\\_______\/\\\____\////\\\\\\\\\_
        ___\///////////_____\///////////__\///////////__\///________\///__\///________\///________\/////////__
    )"<<endl<<endl;

    cout<<"Sistema de Integracion de Informacion y Administracion de Agentes y Clientes"<<endl<<endl;

    cout<<"© 2023 BlaBla-I systems"<<endl<<endl;

    enterToContinue();
    }

NodoAgente* MenuAgente::findDataName() {
    Nombre myNombre;
    Agente myAgente;
    string myStr;
    NodoAgente* pos(nullptr);

    fflush(stdin);
    cout<<"Digite los nombres del agente: ";
    getline(cin,myStr);
    myNombre.setNombre(myStr);


    cout<<"Digite los apellidos del agente (empezando por apellido paterno): ";
    getline(cin,myStr,' ');
    myNombre.setApp(myStr);
    getline(cin,myStr);
    myNombre.setApm(myStr);

    myAgente.setNombre(myNombre);

    pos = listaAgentesRef->findData(myAgente);

    return pos;
    }

void MenuAgente::findAgente() {

    NodoAgente* pos;
    system("cls");

    cout<<"---Menu Busqueda---"<<endl;

    if(listaAgentesRef->isEmpty()) {

        cout << "\nLa lista de agentes esta vacia, es imposible buscar" << endl << endl;

        enterToContinue();

        return;
        }

    pos = findDataName();

    if(pos == nullptr) {
        cout<<"\nAgente no encontrado"<<endl;
        enterToContinue();
        return;
        }

    cout<<"Nombre y Apellidos                  | Especialidad  | Codigo           | Num Extencion     |Entrada|Salida |Extras |"<<endl;
    cout<<"--------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
    cout<<listaAgentesRef->retrieve(pos).toString(true)<<endl;
    enterToContinue();
    }

void MenuAgente::writeToDisk() {
    system("cls");

    cout<<"---Menu de guardado---"<<endl<<endl;

    cout<<"Guardando..."<<endl<<endl;

    try {
        listaAgentesRef->writeToDisk("listadeagentes.agentes");
        }
    catch(const ListaExcepcion& ex) {
        cout<<"Ha sucedido un error, lloremos"<<endl;
        cout<<"El error reportado por el sistema es :"<<endl;
        cout<< ex.what() << endl;

        enterToContinue();

        return;
        }

    cout << "Todo guardado exitosamente WOWOWO celebremos, bailemos, cantemos WOWOOW"<<endl;

    enterToContinue();

    }

void MenuAgente::readFromDisk() {
    system("cls");
    cout << "--- Menu de lectura de datos---"<<endl<<endl;

    try {
        listaAgentesRef->readFromDisk("listadeagentes.agentes");
        }
    catch (ListaExcepcion ex) {
        cout << "Hubo un problema..." << endl;
        cout << ex.what() << endl << endl;

        enterToContinue();
        return;
        }

    cout << "La lectura de datos finalizo todo Gucci"<< endl << endl;

    enterToContinue();


    }

