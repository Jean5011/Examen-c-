#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED
/*********** Cancion ***********/
class Canciones{
private:
    int ID_Cancion, ID_Interprete, GeneroMusical;
    char Nombre[30], NombreAutor[30];
    Fecha FechaEstreno;
    bool Estado;
    float Duracion;
public:
    Canciones(int id_c=0, int id_i=0, int gm=0, const char *n="0000", const char *na="0000", bool est=true, float dur=0){
        ID_Cancion=id_c;
        ID_Interprete=id_i;
        GeneroMusical=gm;
        strcpy(Nombre,n);
        strcpy(NombreAutor,na);
        Estado=est;
        Duracion=dur;
    }
///---Gets---
    int getID_Cancion(){return ID_Cancion;}
    int getID_Interprete(){return ID_Interprete;}
    int getGeneroMusical(){return GeneroMusical;}
    char *getNombre(){return Nombre;}
    char *getNombreAutor(){return NombreAutor;}
    Fecha getFechaEstreno(){return FechaEstreno;}
    bool getEstado(){return Estado;}
    float getDuracion(){return Duracion;}
///---Sets---
    void setID_Cancion(int id){ID_Cancion=id;}
    void setID_Interprete(int id){ID_Interprete=id;}
    void setGeneroMusical(int gm){
        if((gm>=1)&&(gm<=10)){
            GeneroMusical=gm;
        } else{
            while(!((gm>=1)&&(gm<=10))){
                cout<<"CARGUE NUEVAMENTE EL NUMERO DE GENERO MUSICAL: ";
                cin>>gm;
            }
            GeneroMusical=gm;
        }
    }
    void setNombre(const char *n){strcpy(Nombre,n);}
    void setNombreAutor(const char *na){strcpy(NombreAutor,na);}
    void setFechaEstreno(Fecha f){
        while(FechaActual(f)==false){cout<<"Ingrese fecha antes de la actual"<<endl;f.CargarFecha();}
        FechaEstreno=f;}
    void setEstado(bool e){Estado=e;}
    void setDuracion(float d){Duracion=d;}
///Funciones
    void Cargar(int ID);
    void Mostrar();
    bool GrabarDisco(); // agregar archivos.
    bool LeerDisco(int pos); // leer archivos.
    bool ModificarDisco(int pos); // modificar archivos.

};

void Canciones::Cargar(int ID){
    ID_Cancion=ID;
    int gm;
    Fecha f;
    cout<<"Ingrese nombre: ";
    cargarCadena(Nombre,30);
    setNombre(Nombre);
    cout<<"Ingrese nombre autor o compositor: ";
    cargarCadena(NombreAutor,30);
    setNombreAutor(NombreAutor);
    cout<<"ID interprete: ";
    cin>>ID_Interprete;
    cout<<"Ingrese fecha de estreno:"<<endl;
    f.CargarFecha();
    setFechaEstreno(f);
    cout<<"Ingrese duracion de la cancion (Minutos): ";
    cin>>Duracion;
    cout<<"Ingrese genero musica: ";
    cin>>gm;
    setGeneroMusical(gm);
}

void Canciones::Mostrar(){
        cout<<"ID cancion: "<<ID_Cancion<<endl;
        cout<<"Nombre: "<<Nombre<<endl;
        cout<<"Nombre autor o compositor: "<<NombreAutor<<endl;
        cout<<"ID interprete: "<<ID_Interprete<<endl;
        cout<<"Fecha de estreno: ";
        FechaEstreno.MostrarFecha();
        cout<<"Duracion de la cancion (Minutos): "<<Duracion<<endl;
        cout<<"Genero musical: "<<GeneroMusical<<endl;
        cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
}

bool Canciones::GrabarDisco(){
    FILE *pcan;
    bool Escribio;
    pcan=fopen("Canciones.dat","ab");
    if(pcan==NULL){
        cout<<"Error de archivo."<<endl;
        fclose(pcan);
        return false;
    }
    Escribio=fwrite(this,sizeof(Canciones),1,pcan);
    fclose(pcan);
    return Escribio;
}

bool Canciones::LeerDisco(int pos){
    FILE *pcan;
    bool Leyo;
    pcan=fopen("Canciones.dat","rb");
    if(pcan==NULL){
        fclose(pcan);
        return false;
    }
    fseek(pcan,pos*sizeof(Canciones),0);
    Leyo=fread(this,sizeof(Canciones),1,pcan);
    fclose(pcan);
    return Leyo;
}

bool Canciones::ModificarDisco(int pos){
    FILE *pcan;
    bool Modifico;
    pcan=fopen("Canciones.dat","rb+");
    if(pcan==NULL){
        fclose(pcan);
        return false;
    }
    fseek(pcan,pos*sizeof(Canciones),0);
    Modifico=fwrite(this,sizeof(Canciones),1,pcan);
    fclose(pcan);
    return Modifico;
}

/*********** Interpretes ***********/
class Interpretes{
private:
    int IDInterprete;
    char NombreInterprete[40]; ///(persona o grupo musical)
    int Nacionalidad;///Entero entre 1 y 100
    int TipoInterprete;///Entero entre 1 y 5
    int GeneroMusicalPrincipal; ///Entero entre 1 y 10
    Fecha FechaInicioActividad;
    bool EstadoInterprete;
public:
    Interpretes(int ID=0,const char *Nom="000",int Nac=0,int T=0,int G=0,bool est=true){
    IDInterprete=ID;
    strcmp(NombreInterprete,Nom);
    Nacionalidad=Nac;
    TipoInterprete=T;
    GeneroMusicalPrincipal=G;
    EstadoInterprete=est;
    }
    ///---Sets---
    void SetsIDInterprete(int n){IDInterprete=n;}
    void SetsNombreInterprete(const char *n){strcpy(NombreInterprete,n);}
    void SetsNacionalidad(int n){
        bool v=true;
        while(v){
           if(n>=1 && n<=100){Nacionalidad=n;v=false;}
           else{cout<<"Ingrese nacionalidad correctamente(Entero entre 1 y 100):";
                cin>>n;}
                }
                }
    void SetsTipoInterprete(int n){
        bool v=true;
        while(v){
           if(n>=1 && n<=5){TipoInterprete=n;v=false;}
           else{cout<<"Ingrese tipo de intérprete correctamente(Entero entre 1 y 5):";cin>>n;}
                }
                }
    void SetsGeneroMusicalPrincipal(int n){
        bool v=true;
        while(v){
           if(n>=1 && n<=10){GeneroMusicalPrincipal=n,v=false;}
           else{cout<<"Ingrese género musical principal (Entero entre 1 y 10):";cin>>n;}
                }
                }
    void SetsFechaInicioActividad(Fecha f){
        while(FechaActual(f)==false){cout<<"Ingrese fecha antes de la actual"<<endl;f.CargarFecha();}
        FechaInicioActividad=f;}
    void SetsEstadoInterprete(bool n){EstadoInterprete=n;}
    ///---Gets---
    int GetsIDInterprete(){return IDInterprete;}
    char *GetsNombreInterprete(){return NombreInterprete;}
    int GetsNacionalidad(){return Nacionalidad;}
    int GetsTipoInterprete(){return TipoInterprete;}
    int GetsGeneroMusicalPrincipal(){return GeneroMusicalPrincipal;}
    Fecha GetsFechaInicioActividad(){return FechaInicioActividad;}
    bool GetsEstadoInterprete(){return EstadoInterprete;}
   ///Funciones
    void Cargar(int ID);
    void Mostrar();
    bool GrabarDisco();
    bool Leerdisco(int pos);
    bool ModificarDisco(int pos);
};
    void Interpretes::Cargar(int ID){
    Fecha n;
    IDInterprete=ID;
    int Nacionalidad_1,TipoInterprete_1,GeneroMusicalPrincipal_1;
    cout<<"Ingrese nombre (persona o grupo musical):";
    cargarCadena(NombreInterprete,39);
    cout<<"Ingrese nacionalidad (Entero entre 1 y 100):";
    cin>>Nacionalidad_1;
    SetsNacionalidad(Nacionalidad_1);
    cout<<"Ingrese tipo de intérprete (Entero entre 1 y 5):";
    cin>>TipoInterprete_1;
    SetsTipoInterprete(TipoInterprete_1);
    cout<<"Ingrese género musical principal (Entero entre 1 y 10):";
    cin>>GeneroMusicalPrincipal_1;
    SetsGeneroMusicalPrincipal(GeneroMusicalPrincipal_1);
    cout<<"Ingrese Fecha de inicio actividad:"<<endl;
    n.CargarFecha();
    SetsFechaInicioActividad(n);
    EstadoInterprete=true;
    }
    void Interpretes::Mostrar(){
    cout<<"ID de intérprete:"<<IDInterprete<<endl;
    cout<<"Nombre (persona o grupo musical):"<<NombreInterprete<<endl;
    cout<<"Nacionalidad (Entero entre 1 y 100):"<<Nacionalidad<<endl;
    cout<<"Tipo de Intérprete (Entero entre 1 y 5):"<<TipoInterprete<<endl;
    cout<<"Género musical principal (Entero entre 1 y 10):"<<GeneroMusicalPrincipal<<endl;
    cout<<"Fecha de inicio actividad:"<<endl;
    FechaInicioActividad.MostrarFecha();
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    }
    bool Interpretes::GrabarDisco(){
    FILE *p;
    p=fopen("Interpretes.dat","ab");///wb
    if(p==NULL){fclose(p);return false;}
    bool escribio=fwrite(this,sizeof(Interpretes),1,p);
    fclose(p);
    return escribio;
    }

    bool Interpretes::Leerdisco(int pos){
    FILE *p;
    p=fopen("Interpretes.dat","rb");
    if(p==NULL){fclose(p);return false;}
    fseek(p,pos*sizeof(Interpretes),0);
    bool leyo=fread(this,sizeof(Interpretes),1,p);
    fclose(p);
    return leyo;
    }

    bool Interpretes::ModificarDisco(int pos){
    FILE *p;
    p=fopen("Interpretes.dat","rb+");
    if(p==NULL){fclose(p);return false;}
    fseek(p,pos*sizeof(Interpretes),0);
    bool modifico=fwrite(this,sizeof(Interpretes),1,p);
    fclose(p);
    return modifico;
    }

/*********** Genero ***********/

class Genero{
private:
    int IDGenero;
    char NombreGenero[40];
    int PaisOrigen;///pais de origen 1 y 100
    int TipoInstrumentacion;///Entero entre 1 y 5
    bool EstadoGenero;
public:
    Genero(int ID=0,const char *Nom="000",int P=0,int T=0,int G=0,bool est=true){
    IDGenero=ID;
    strcmp(NombreGenero,Nom);
    PaisOrigen=P;
    TipoInstrumentacion=T;
    EstadoGenero=est;
    }
    ///---Sets---
    void SetsIDGenero(int n){IDGenero=n;}
    void SetsNombreGenero(const char *n){strcpy(NombreGenero,n);}
    void SetsPaisOrigen(int n){
        bool v=true;
        while(v){
           if(n>=1 && n<=100){PaisOrigen=n;v=false;}
           else{cout<<"Ingrese nacionalidad correctamente(Entero entre 1 y 100):";
                cin>>n;}
                }
                }
    void SetsTipoInstrumentacion(int n){
        bool v=true;
        while(v){
           if(n>=1 && n<=5){TipoInstrumentacion=n;v=false;}
           else{cout<<"Ingrese tipo de intérprete correctamente(Entero entre 1 y 5):";cin>>n;}

                }
                }
    void SetsEstadoGenero(bool n){EstadoGenero=n;}
    ///---Gets---
    int GetsIDGenero(){return IDGenero;}
    char *GetsNombreGenero(){return NombreGenero;}
    int GetsPaisOrigen(){return PaisOrigen;}
    int GetsTipoInstrumentacion(){return TipoInstrumentacion;}
    bool GetsEstadoGenero(){return EstadoGenero;}
   ///Funciones
    void Cargar(int ID);
    void Mostrar();
    bool GrabarDisco();
    bool Leerdisco(int pos);
    bool ModificarDisco(int pos);
};
    void Genero::Cargar(int ID){
    IDGenero=ID;
    int p,t;
    cout<<"Ingrese nombre genero:";
    cargarCadena(NombreGenero,39);
    cout<<"Ingrese país de origen (entre 1 y 100):";
    cin>>p;
    SetsPaisOrigen(p);
    cout<<"Ingrese tipo de instrumentación (entre 1 y 5):";
    cin>>t;
    SetsTipoInstrumentacion(t);
    EstadoGenero=true;
    }
    void Genero::Mostrar(){
    cout<<"ID de genero:"<<IDGenero<<endl;
    cout<<"Nombre genero:"<<NombreGenero<<endl;
    cout<<"País de origen:"<<PaisOrigen<<endl;
    cout<<"Tipo de instrumentacion:"<<TipoInstrumentacion<<endl;
    EstadoGenero=true;
    cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
    }
    bool Genero::GrabarDisco(){
    FILE *p;
    p=fopen("Genero.dat","ab");
    if(p==NULL){fclose(p);return false;}
    bool escribio=fwrite(this,sizeof(Genero),1,p);
    fclose(p);
    return escribio;
    }

    bool Genero::Leerdisco(int pos){
    FILE *p;
    p=fopen("Genero.dat","rb");
    if(p==NULL){fclose(p);return false;}
    fseek(p,pos*sizeof(Genero),0);
    bool leyo=fread(this,sizeof(Genero),1,p);
    fclose(p);
    return leyo;
    }

    bool Genero::ModificarDisco(int pos){
    FILE *p;
    p=fopen("Genero.dat","rb+");
    if(p==NULL){fclose(p);return false;}
    fseek(p,pos*sizeof(Genero),0);
    bool modifico=fwrite(this,sizeof(Genero),1,p);
    fclose(p);
    return modifico;
    }
#endif // CLASES_H_INCLUDED
