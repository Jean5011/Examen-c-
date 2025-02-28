#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
void MenuCanciones();
void MenuInterpretes();
void MenuGeneros();
///*****************************************************************
/*** Menu Canciones ***/
void MenuCanciones(){
int opc;
bool usar=true;

    while(usar){
        system("cls");
        cout<<"MENU CANCIONES"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"1) AGREGAR CANCION"<<endl;
        cout<<"2) LISTAR CANCION POR ID"<<endl;
        cout<<"3) LISTAR TODAS LAS CANCIONES"<<endl;
        cout<<"4) MODIFICAR FECHA DE ESTRENO"<<endl;
        cout<<"5) ELIMINAR CANCION"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<endl<<"OPCION: ";
        cin>>opc;
        system("cls");

        switch(opc){
            case 1: AgregarCancion();
                break;
            case 2: ListarCancionID();
                break;
            case 3: ListarTodas();
                break;
            case 4: ModificarFechaEstreno();
                break;
            case 5: EliminarCancion();
                break;
            case 0: usar=false;
                break;
            default: cout<<"-OPCION INCORRECTA. INGRESE UNA OPCION DEL MENU-"<<endl;
                    system("pause");
                break;
        }
    }
}

/*** Menu Interpretes ***/
void MenuInterpretes(){
int n;
bool v=true;
while(v){
system("cls");
cout<<"MENU INTERPRETE"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"1) AGREGAR INTERPRETE"<<endl;
cout<<"2) LISTAR INTERPRETE POR ID"<<endl;
cout<<"3) LISTAR TODOS LOS INTERPRETES"<<endl;
cout<<"4) MODIFICAR GENERO MUSICAL PRINCIPAL"<<endl;
cout<<"5) ELIMINAR INTERPRETE"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
cout<<endl;
cout<<"SELECCIONE UNA DE LAS OPCIONES:";
cin>>n;
system("cls");
switch(n){
case 1:
    AgregarInterprete();
    break;
case 2:
    Listar_X_ID();
    break;
case 3:
    ListarInterpretes();
    break;
case 4:
    ModificarGeneroMusical();
    break;
case 5:
    EliminarInterprete();
    break;
    case 0:
     v=false;
    break;
    default:
    cout<<"-OPCION INCORRECTA. INGRESE UNA OPCION DEL MENU-"<<endl<<endl;
    system("pause");
    system("cls");
    break;
}
}
}

/*** Menu Generos ***/
void MenuGeneros(){
int n;
bool v=true;
while(v){
system("cls");
cout<<"MENU GENEROS"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"1) AGREGAR GENERO"<<endl;
cout<<"2) LISTAR GENERO POR ID"<<endl;
cout<<"3) LISTAR TODOS LOS GENEROS"<<endl;
cout<<"4) MODIFICAR TIPO DE INSTRUMENTACIÓN"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
cout<<endl;
cout<<"SELECCIONE UNA DE LAS OPCIONES:";
cin>>n;
system("cls");
switch(n){
case 1:
    AgregarGenero();
    break;
case 2:
    Listar_X_IDGenero();
    break;
case 3:
    ListarGenero();
    break;
case 4:
    ModificarInstrumentacion();
    break;
    case 0:
     v=false;
    break;
    default:
    cout<<"-OPCION INCORRECTA. INGRESE UNA OPCION DEL MENU-"<<endl<<endl;
    system("pause");
    system("cls");
    break;
}
}
}

#endif // MENU_H_INCLUDED
