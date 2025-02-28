#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED
void menureportes();
void punto1();
void punto2();
void punto3();
///*********************************************************************************************************

/// PUNTO 1*****************************************************************
void punto1(){
Canciones c;
char Nombre[30];
int pos=0;
char cn[30];
cout<<"Ingrese un nombre autor:";
cargarCadena(Nombre,29);
while(c.LeerDisco(pos++)){
            strcpy(cn,c.getNombreAutor());
        if(strcmp(cn,Nombre)==0){
            if(c.getFechaEstreno().Getanio()<2010){
                c.Mostrar();
                }
            }
}
system("pause");
}
/// PUNTO 2*****************************************************************
void punto2(){
    Canciones c;
    int pos=0,v[12]={0};
    int minn,p=0,i;
    bool b=true;
    while(c.LeerDisco(pos++)){
            if(c.getFechaEstreno().Getanio()==2021){
                v[c.getFechaEstreno().Getmes()-1]++;
            }
    }
    for(i=0;i<12;i++){
          if(v[i]!=0){
            if(b==true || minn>v[i] )b=false,minn=v[i],p=i;
          }

    }
cout<<"-Mes con menor cantidad de canciones em 2021-"<<endl;
cout<<"Mes:"<<p+1<<endl;
system("pause");
}

/// PUNTO 3*****************************************************************
class PUNTO3{
private:
    int ID;
    char Nombre[30];
    Fecha f;
public:
    void setID(int n){ID=n;}
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setf(Fecha n){f=n;}
void Mostrar(){
        cout<<"ID: "<<ID<<endl;
        cout<<"Nombre: "<<Nombre<<endl;
        cout<<"fecha: "<<endl;
        f.MostrarFecha();
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
        }
bool GrabarDisco(){
    FILE *pcan;
    bool Escribio;
    pcan=fopen("punto3.dat","ab");
    if(pcan==NULL){
        cout<<"Error de archivo."<<endl;
        fclose(pcan);
        return false;
    }
    Escribio=fwrite(this,sizeof*this,1,pcan);
    fclose(pcan);
    return Escribio;
}

bool LeerDisco(int pos){
    FILE *pcan;
    bool Leyo;
    pcan=fopen("punto3.dat","rb");
    if(pcan==NULL){
        fclose(pcan);
        return false;
    }
    fseek(pcan,pos*sizeof*this,0);
    Leyo=fread(this,sizeof*this,1,pcan);
    fclose(pcan);
    return Leyo;
}
};

void punto3(){
Canciones c;
PUNTO3 p3;
int a;
int pos=0;
cout<<"Ingrese año:";
cin>>a;
while(c.LeerDisco(pos++)){
if(c.getFechaEstreno().Getanio()==a){
    p3.setID(c.getID_Cancion());
    p3.setNombre(c.getNombre());
    p3.setf(c.getFechaEstreno());
    p3.GrabarDisco();

}
}
int pos2=0;
while(p3.LeerDisco(pos2++)){p3.Mostrar();}
system("pause");

}

///*********************************************************************************************************
void menureportes(){
int n;
bool v=true;
while(v){
system("cls");
cout<<"MENU REPORTE"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"1) PUNTO 1"<<endl;
cout<<"2) PUNTO 2"<<endl;
cout<<"3) PUNTO 3"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
cout<<endl;
cout<<"SELECCIONE UNA DE LAS OPCIONES:";
cin>>n;
system("cls");
switch(n){
case 1:
     punto1();
    break;
case 2:
     punto2();
    break;
case 3:
     punto3();
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

#endif // REPORTES_H_INCLUDED
