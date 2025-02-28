#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<time.h>
using namespace std;
#include "Funciones_globales_y_fecha.h"
#include "Clases.h"
#include "Funciones.h"
#include "Menu.h"
#include "Configuracion.h"
#include "reportes.h"
int main(){
setlocale(LC_ALL,"spanish");
int n;
while(true){
system("cls");
cout<<"MENU PRINCIPAL"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"1) MENU CANCIONES"<<endl;
cout<<"2) MENU INTERPRETES"<<endl;
cout<<"3) MENU GENEROS"<<endl;
cout<<"4) REPORTES"<<endl;
cout<<"5) CONFIGURACION"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) FIN DEL PROGRAMA"<<endl;
cout<<endl;
cout<<"SELECCIONE UNA DE LAS OPCIONES:";
cin>>n;
system("cls");
switch(n){
case 1:
    MenuCanciones();
    break;
case 2:
    MenuInterpretes();
    break;
case 3:
    MenuGeneros();
    break;
case 4:
    menureportes();
    break;
case 5:
    MenuConfiguracion();
    break;
    case 0:
     return 0;
    break;
    default:
    cout<<"-OPCION INCORRECTA. INGRESE UNA OPCION DEL MENU-"<<endl<<endl;
    system("pause");
    system("cls");
    break;
}
}
}
