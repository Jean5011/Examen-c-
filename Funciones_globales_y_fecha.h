#ifndef FUNCIONES_GLOBALES_Y_FECHA_H_INCLUDED
#define FUNCIONES_GLOBALES_Y_FECHA_H_INCLUDED
/*********** Fecha ***********/
class Fecha{
protected:
    int dia;
    int mes;
    int anio;
public:
  ///--construtores--
   Fecha(int d=0,int m=0,int a=0){
   dia=d;
   mes=m;
   anio=a;
   }
   ///--Set--
   void Setdia(int n){
   do{
    if(n>=1 && n<=31) dia=n;
    else{
    cout<<"ingrese denuevo el día:";
    cin>>n;
    }
   }while(dia==0);
   }
    void Setmes(int n){
   do{
    if(n>=1 && n<=12) mes=n;
    else{
    cout<<"ingrese denuevo el Mes:";
    cin>>n;
    }
   }while(mes==0);
   }
   void Setanio(int n){anio=n;}
   ///--Gets--
   int Getdia(){return dia;}
   int Getmes(){return mes;}
   int Getanio(){return anio;}
   ///--Funciones--
   void CargarFecha();
   void MostrarFecha();
};
   void Fecha::CargarFecha(){
    int d,m,a;
    cout<<"Ingrese Día:";
    cin>>d;
    Setdia(d);
    cout<<"Ingrese mes:";
    cin>>m;
    Setmes(m);
    cout<<"Ingrese año:";
    cin>>a;
    Setanio(a);
   }
   void Fecha::MostrarFecha(){
   cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
   ///system("pause>nul");
   }
/*****************************/
void cargarCadena(char *pal, int tam);
bool FechaActual(int n);
/*********** Funciones generales ***********/
void cargarCadena(char *pal, int tam)
{
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
bool FechaActual(Fecha n){
        time_t tiempo;
        struct tm *tmPtr;
        tiempo=time(NULL);
        tmPtr=localtime(&tiempo);
        int AnioActual=tmPtr->tm_year+1900;
        int mesActual=tmPtr->tm_mon+1;
        int diaActual=tmPtr->tm_mday;
        if(n.Getanio()>=AnioActual){
            if(n.Getmes()>=mesActual){
                if(n.Getdia()>=diaActual){return false;}
        }
        }
        return true;
}

#endif // FUNCIONES_GLOBALES_Y_FECHA_H_INCLUDED
