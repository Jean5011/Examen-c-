#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED
void MenuConfiguracion();
bool Copia_segurida_Cancion();
bool Copia_segurida_Interprete();
bool Copia_segurida_Genero();

bool Cancion_bkp();
bool Interprete_bkp();
bool Genero_bkp();

void Datos_inicio();
///******************************************************************************************************
bool Copia_segurida_Cancion(){
FILE *p;
p=fopen("Canciones.bkp","wb");
if(p==NULL ){cout<<"ERROR"<<endl;fclose(p);system("pause");return false;}
system("copy Canciones.dat Canciones.bkp");
fclose(p);
system("pause");
return true;
}

bool Copia_segurida_Interprete(){
FILE *p;
p=fopen("Interpretes.bkp","wb");
if(p==NULL ){cout<<"ERROR"<<endl;fclose(p);system("pause");return false;}
system("copy Interpretes.dat Interpretes.bkp");
fclose(p);
system("pause");
return true;
}

bool Copia_segurida_Genero(){
FILE *p;
p=fopen("Genero.bkp","wb");
if(p==NULL ){cout<<"ERROR"<<endl;fclose(p);system("pause");return false;}
system("copy Genero.dat Genero.bkp");
fclose(p);
system("pause");
return true;
}

/*** BKP ***/
bool Cancion_bkp(){
system("copy Canciones.bkp Canciones.dat");
system("pause");
return true;
}

bool Interprete_bkp(){
system("copy Interpretes.bkp Interpretes.dat");
system("pause");
return true;
}

bool Genero_bkp(){
system("copy Genero.bkp Genero.dat");
system("pause");
return true;
}
/*** ESTABLECER DATOS DE INICIO ***/
void Datos_inicio(){
system("copy InicioCanciones.txt Canciones.dat");
system("copy InicioInterpretes.txt Interpretes.dat");
system("copy GeneroInicio.txt Genero.dat");
system("pause");
}
///******************************************************************************************************
void MenuConfiguracion(){
int n;
bool v=true;
while(v){
system("cls");
cout<<"MENU COMFIGURACION"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE CANCIONES"<<endl;
cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE INTERPRETES"<<endl;
cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<<endl;
cout<<"4) RESTAURAR EL ARCHIVO DE CANCIONES"<<endl;
cout<<"5) RESTAURAR EL ARCHIVO DE INTERPRETES"<<endl;
cout<<"6) RESTAURAR EL ARCHIVO DE GENEROS"<<endl;
cout<<"7) ESTABLECER DATOS DE INICIO"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cout<<endl;
cout<<"SELECCIONE UNA DE LAS OPCIONES:";
cin>>n;
system("cls");
switch(n){
case 1:
    Copia_segurida_Cancion();
    break;
case 2:
    Copia_segurida_Interprete();
    break;
case 3:
    Copia_segurida_Genero();
    break;
case 4:
    Cancion_bkp();
    break;
case 5:
    Interprete_bkp();
    break;
case 6:
    Genero_bkp();
    break;
case 7:
    Datos_inicio();
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

#endif // CONFIGURACION_H_INCLUDED
