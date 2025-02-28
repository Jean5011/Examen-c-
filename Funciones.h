#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
/*** CANCION ***/
int CantidadCanciones();
int BuscarIDcancion(int);
void AgregarCancion();///AGREGAR CANCION
void ListarCancionID();///LISTAR CANCION POR ID
void ListarTodas();///LISTAR TODAS LAS CANCION
bool ModificarFechaEstreno();///MODIFICAR FECHA DE ESTRENO
bool EliminarCancion();///ELIMINAR CANCION
/*** INTERPRETES ***/
int BuscarIDInterprete(int ID);
int CantidadInterprete();
void AgregarInterprete();///AGREGAR INTERPRETE
void Listar_X_ID();///LISTAR INTERPRETE POR ID
void ListarInterpretes();///LISTAR TODOS LOS INTERPRETES
bool ModificarGeneroMusical();///MODIFICAR GENERO MUSICAL PRINCIPAL
bool EliminarInterprete();///ELIMINAR INTERPRETE
/*** GENERO ***/
int BuscarIDGenero(int ID);
int CantidadGenero();
void AgregarGenero();///AGREGAR GENERO
void Listar_X_IDGenero();///LISTAR GENERO POR ID
void ListarGenero();///LISTAR TODOS LOS GENERO
bool ModificarInstrumentacion();///MODIFICAR MODIFICAR TIPO DE INSTRUMENTACION
///*************************************************************************************************************************************************
/****** CANCION ******/

int BuscarIDcancion(int ID){
    Canciones c;
    int pos=0;
    while(c.LeerDisco(pos)){
        if(c.getID_Cancion()==ID){
            return pos;
        }
            pos++;
    }
    return -1;
}

int CantidadCanciones(){
    Canciones c;
    int pos=0;
    while(c.LeerDisco(pos)){
        pos++;
    }
    return pos;
}

void AgregarCancion(){///AGREGAR CANCION
    Canciones c;
    int pos, ID;
    pos=CantidadCanciones();
    ID=pos+1;
    cout<<"ID de cancion: "<<ID<<endl;
    c.Cargar(ID);
    c.GrabarDisco();
    cout<<"Archivo guardado."<<endl;
    system("pause");
}

void ListarCancionID(){///LISTAR CANCION POR ID
    Canciones c;
    int ID, pos;
    cout<<"Ingresar ID de cancion: ";
    cin>>ID;
    pos=BuscarIDcancion(ID);
    if(pos!=-1){
    if(c.LeerDisco(pos)){
        if(c.getEstado()){
            c.Mostrar();
        }
    }
    }
    else{
        cout<<"No exite el archivo."<<endl;

    }
    system("pause");
}

void ListarTodas(){///LISTAR TODAS LAS CANCION
    Canciones c;
    int ID, pos=0;
    bool existe=false;
    while(c.LeerDisco(pos++)){
        if(c.getEstado()==true){
            c.Mostrar();
        }
        existe=true;
    }
    if(existe==false){
        cout<<"No exite el archivo."<<endl;
    }
    system("pause");
}

bool ModificarFechaEstreno(){///MODIFICAR FECHA DE ESTRENO
Fecha f;
Canciones c;
int ID, pos;
cout<<"Ingresar ID de cancion: ";
cin>>ID;
system("cls");
pos=BuscarIDcancion(ID);
if(pos==-1){
        cout<<"No exite el archivo."<<endl;
        return false;
    }
c.LeerDisco(pos);
if(c.getEstado()==false){
    cout<<"-El archivo fue eliminado-"<<endl;
        system("pause");
        return false;
        }
cout<<"Ingrese nueva fecha"<<endl;
f.CargarFecha();
c.setFechaEstreno(f);
system("cls");
if(c.ModificarDisco(pos)){
        cout<<"Fecha cambiada"<<endl;
    }
else{
        cout<<"Error de archivo."<<endl;
    }
system("pause");
return true;
}

bool EliminarCancion(){///ELIMINAR CANCION
    Canciones c;
    int ID, pos;
    cout<<"Ingresar ID de cancion: ";
    cin>>ID;
    system("cls");
    pos=BuscarIDcancion(ID);
    if(pos==-1){
        cout<<"No exite el archivo."<<endl;
        return false;
    }
    c.LeerDisco(pos);
    if(c.getEstado()==false){
        cout<<"-El archivo fue eliminado-"<<endl;
        system("pause");
        return false;
        }
    c.setEstado(false);
    if(c.ModificarDisco(pos)){
        cout<<"Archivo eliminado."<<endl;
    } else{
        cout<<"Error al eliminar archivo."<<endl;
    }
    system("pause");
    return true;
}
///*************************************************************************************************************************************************
/****** INTERPRETES ******/
int BuscarIDInterprete(int ID){
Interpretes n;
int pos=0;
while(n.Leerdisco(pos)){
    if(n.GetsIDInterprete()==ID){return pos;}
    pos++;
}
return -1;
}
int CantidadInterprete(){
Interpretes n;
int pos=0;
while(n.Leerdisco(pos)){pos++;}
return pos;
}

void AgregarInterprete(){///AGREGAR INTERPRETE
Interpretes n;
int pos,ID;
pos=CantidadInterprete();
ID=pos+1;
cout<<"ID de intérprete:"<<ID<<endl;
n.Cargar(ID);
n.GrabarDisco();
cout<<"Archivo Guardado"<<endl;
}

void Listar_X_ID(){///LISTAR INTERPRETE POR ID
Interpretes n;
int ID,pos;
cout<<"Ingrese ID de intérprete a buscar:";
cin>>ID;
pos=BuscarIDInterprete(ID);
if(pos!=-1){
if(n.Leerdisco(pos)){
        if(n.GetsEstadoInterprete()){
            n.Mostrar();
}
}
}
else {cout<<"Archivo no exite"<<endl;}
system("pause");
}

void ListarInterpretes(){///LISTAR TODOS LOS INTERPRETES
Interpretes n;
int pos=0;
bool v=false;
while(n.Leerdisco(pos++)){
        if(n.GetsEstadoInterprete()){n.Mostrar();}
        v=true;
        }
if(v==false){cout<<"Archivos no exiten"<<endl;}
system("pause");
}

bool ModificarGeneroMusical(){///MODIFICAR GENERO MUSICAL PRINCIPAL
int ID,pos,g;
Interpretes n;
cout<<"Ingrese ID de intérprete:";
cin>>ID;
system("cls");
pos=BuscarIDInterprete(ID);
if(pos==-1){cout<<"ID no exitente"<<endl;system("pause");return false;}
n.Leerdisco(pos);
if(n.GetsEstadoInterprete()==false){cout<<"-El archivo fue eliminado-"<<endl;system("pause");return false;}
cout<<"Ingrese un nuevo Genero musical (entre el 1 y 10):";
cin>>g;
system("cls");
n.SetsGeneroMusicalPrincipal(g);
if(n.ModificarDisco(pos)){cout<<"Genero musical modificado"<<endl;}
else{cout<<"ERROR"<<endl;}
system("pause");
return true;
}

bool EliminarInterprete(){///ELIMINAR INTERPRETE
int ID,pos;
Interpretes n;
cout<<"Ingrese ID de intérprete a eliminar:";
cin>>ID;
system("cls");
if(pos==-1){cout<<"ID no exitente"<<endl;system("pause");return false;}
pos=BuscarIDInterprete(ID);
if(n.GetsEstadoInterprete()==false){cout<<"EL ARCHIVO YA FUE ELIMINADO"<<endl;system("pause");return false;}
n.Leerdisco(pos);
n.SetsEstadoInterprete(false);
if(n.ModificarDisco(pos)){cout<<"Archivo eliminado"<<endl;}
else{cout<<"ERROR"<<endl;}
system("pause");
return true;
}
///*************************************************************************************************************************************************
/****** GENEROS ******/
int BuscarIDGenero(int ID){
Genero n;
int pos=0;
while(n.Leerdisco(pos)){
    if(n.GetsIDGenero()==ID){return pos;}
    pos++;
}
return -1;
}
int CantidadGenero(){
Genero n;
int pos=0;
while(n.Leerdisco(pos)){pos++;}
return pos;
}

void AgregarGenero(){///AGREGAR GENERO
Genero n;
int pos,ID;
pos=CantidadGenero();
ID=pos+1;
cout<<"ID de genero:"<<ID<<endl;
n.Cargar(ID);
n.GrabarDisco();
cout<<"Archivo Guardado"<<endl;
}

void Listar_X_IDGenero(){///LISTAR GENERO POR ID
Genero n;
int ID,pos;
cout<<"Ingrese ID de Genero a buscar:";
cin>>ID;
pos=BuscarIDGenero(ID);
if(pos!=-1){
if(n.Leerdisco(pos)){if(n.GetsEstadoGenero()){n.Mostrar();}}
}
else{cout<<"Archivo no exite"<<endl;}
system("pause");
}

void ListarGenero(){///LISTAR TODOS LOS GENEROS
Genero n;
int pos=0;
bool v=false;
while(n.Leerdisco(pos++)){
        if(n.GetsEstadoGenero()){n.Mostrar();}
        v=true;
        }
if(v==false){cout<<"Archivos no exiten"<<endl;}
system("pause");
}

bool ModificarInstrumentacion(){///MODIFICAR TIPO DE MINSTRUMENTACION
int ID,pos,t;
Genero n;
cout<<"Ingrese ID de genero:";
cin>>ID;
system("cls");
pos=BuscarIDInterprete(ID);
if(pos==-1){cout<<"ID no exitente"<<endl;system("pause");return false;}
n.Leerdisco(pos);
if(n.GetsEstadoGenero()==false){cout<<"El archivo no valido"<<endl;system("pause");return false;}
cout<<"Ingrese nuevo tipo de instrumentacion (entre 1 y 5) :";
cin>>t;
system("cls");
n.SetsTipoInstrumentacion(t);
if(n.ModificarDisco(pos)){cout<<"tipo de instrumentacion modificado"<<endl;}
else{cout<<"ERROR"<<endl;}
system("pause");
return true;
}


#endif // FUNCIONES_H_INCLUDED
