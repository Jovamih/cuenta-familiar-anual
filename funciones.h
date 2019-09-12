//Declaracion de funciones
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
void Fecha_total(int&, int& , int&); // pide la fecha actual y la almacena
void update(); //actualiza los datos, que han sido modifcados tras una eliminacion o ingreso
bool Exist_ingresos(struct Anual *, int, int); //recibe mes y año y retorna si hay un dato ocupando esa fecha
bool Exist_egresos(struct Anual*, int, int); //recibe mes y año y retorna si hay un dato ocupando esa fecha
void inicializar(struct Anual*);
struct IngresosM{    //guarda los ingresos en arreglos por un mes (4 integrantes)  
        double sueldo[4];
        double extra[4];
        double total; //suma del sueldo y los ingresos extras del mes   
   };
   struct EgresosM{  //guarda los egresos mensuales por cada tipo de gasto (12 meses)
          double alimentacion;
          double indumentaria;
          double hogar;
          double salud;
          double transporte;
          double educacion;
          double cultura_familiar; 
          double Gastmensual; //suma los gastos totales por mes
   };
   struct Anual{
            IngresosM Ingreso_Mensual[12] ;
            EgresosM Egreso_Mensual[12];
            double balance;
            bool registro_ing[12];
            bool registro_eg[12];
   };
    struct Meses{
         char name[11];
    };
   void registrar_ingresos(struct Anual[], int,int, int); //recibe una struct Cuenta,aparte, el mes y año proporcionado por
                                                           //la funcion Fecha_total()
   void registrar_egresos(struct Anual[],int ,int , int);
   bool Eliminar_datos(struct Anual[]);
   void Mostrar_estadisticas(struct Anual[]);
   bool Mostrar_egresos(struct Anual[]);
   bool Mostrar_ingresos(struct Anual[]);
   bool Estado_general(struct Anual[]);
   int menu();
   //Implementacion de funciones
   struct Meses mes[12]={"enero","febrero","marzo","abril","mayo","junio","julio","agosto","setiembre","octubre","noviembre","diciembre"};
void registrar_ingresos(struct Anual cuenta_anual[],int dia,int mes,int anio){
       int  i=0, j=0;
       double isueldo=0, iextra=0, suma=0;
       j=mes-1; i= anio-2019; //indices de los arreglos a los que se accedera
       cout<<"\n\t\tFamilia>Integrantes                 FECHA: "<<dia<<" / "<<mes<<" / "<<anio<<endl
           <<endl
           <<"\t\t(1) Padre"<<endl
           <<"\t\t(2) Madre"<<endl
           <<"\t\t(3) Hermanos"<<endl
           <<"\t\t(4) Yo"<<endl
           <<endl; //alamacenando los datos en el arreglo de estructuras
                for(int r=0; r<4; r++){
                         cout<<"\t\t\t|Aportante n"<<(r+1)<<" | Indique su sueldo de este mes>"; cin>>isueldo;  
                        cout<<"\t\t\t\t|____Su ingreso extra mensual>";cin>>iextra;
                                 cuenta_anual[i].Ingreso_Mensual[j].sueldo[r]=isueldo; 
                                 cuenta_anual[i].Ingreso_Mensual[j].extra[r]=iextra;
                                 suma=suma+isueldo+iextra;
                                 fflush(stdin);
                } cuenta_anual[i].Ingreso_Mensual[j].total=suma;
                cuenta_anual[i].registro_ing[j]=true;
                cout<<"\n\t\t---------Ingresos completados-------\n";
              return;
}
void registrar_egresos(struct Anual Cuenta_anual[],int dia, int mes, int anio){
            double dato=0; int i=0,j=0; double gasto=0; //almacena los datos en una estructura
            j=mes-1; i=anio-2019; //creamos los indices para mes y año
        cout<<"\t\t\tGASTOS MENSUALES                      FECHA: "<<dia<<" / "<<mes<<" / "<<anio<<endl
            <<"\t\t\t---------------------------------------------------------------------------"<<endl
            <<endl
            <<"\t\t\tAlimentacion ...................... s/"; cin>>dato; fflush(stdin);
            Cuenta_anual[i].Egreso_Mensual[j].alimentacion=dato;
                    gasto=gasto +dato;
        cout<<"\t\t\tRopa y vestido .................... s/"; cin>>dato; fflush(stdin);
            Cuenta_anual[i].Egreso_Mensual[j].indumentaria=dato;
                    gasto=gasto +dato;
        cout<<"\t\t\tHogar (muebles, utensilios, etc) .. s/"; cin>>dato; fflush(stdin);
            Cuenta_anual[i].Egreso_Mensual[j].hogar=dato;
                    gasto=gasto +dato;
        cout<<"\t\t\tSalud ............................. s/"; cin>>dato;fflush(stdin);
            Cuenta_anual[i].Egreso_Mensual[j].salud=dato;
                    gasto=gasto +dato;
        cout<<"\t\t\tTransporte ........................ s/"; cin>>dato; fflush(stdin);
            Cuenta_anual[i].Egreso_Mensual[j].transporte=dato;
                    gasto=gasto +dato;
        cout<<"\t\t\tEduacion .......................... s/"; cin>>dato; fflush(stdin);
            Cuenta_anual[i].Egreso_Mensual[j].educacion=dato;
                    gasto=gasto +dato;
        cout<<"\t\t\tDiversion y recreacion familiar ... s/"; cin>>dato; fflush(stdin);
            Cuenta_anual[i].Egreso_Mensual[j].cultura_familiar=dato;
                    gasto=gasto +dato;
            Cuenta_anual[i].Egreso_Mensual[j].Gastmensual=gasto;
            //indicamos que ya se ingreso el dato una vez, asi que le asignamos verdadera
            Cuenta_anual[i].registro_eg[j]=true;
            return ;
}

void Fecha_total(int& day, int& month, int& year ){ //recibe la fecha y la verifica
        cout<<"\n\t\t\t_______________FECHA DE OPERACION_______________"<<endl
            <<endl;
	do{
		cout<<"\t\tANIO>Ingrese el anio>"; cin>>year;	
	}while(!(year<=2023 && year>=2019));
    cout<<"\t\t _________________________________________________________________"<<endl
	    <<"\t\t|  SELECCIONAR MES                                                |"<<endl
		<<"\t\t|  ---------------                                                |"<<endl
		<<"\t\t| (1)Enero          (2)Febrero      (3)Marzo       (4)Abril       |"<<endl
		<<"\t\t| (5)Mayo           (6)Junio        (7)Julio       (8)Agosto      |"<<endl
		<<"\t\t| (9)Setiembre      (10)Octubre     (11)Noviembre  (12)Diciembre  |"<<endl
		<<"\t\t|_________________________________________________________________|"<<endl
        <<endl;
	do{
		cout<<"\t\tMES>Seleccione el mes>"; cin>>month; fflush(stdin);
	}while(!(month>=1 && month<=12));
	switch(month){
		case 1: case 3 : case 5: case 7: case 8:case 10: case 12:
		do{ 
			    cout<<"\t\tDia>"; cin>>day;
			}while(!(day>=1 && day<=31)); 
		break;
		case 4: case 6: case 9: case 11:
			do{ 
				cout<<"\t\tDia>"; cin>>day;
			}while(!(day>=1 && day<=30)); 
			break;
		case 2: do{ 
			    cout<<"\t\tDia>"; cin>>day;
			}while(!(day>=1 && day<=29)); 
		    break;
		}  cout<<endl;
        return;
}
bool Exist_ingresos(struct Anual *Cuenta_anual, int mes, int anio){
    int i=anio-2019, j=mes-1; //verificamos si el dato ya ha sido ingresado
                            // creamos el indice para cada año// creamos el indice para el mes
            if((Cuenta_anual+i)->registro_ing[j]==true) return true; // si es verdadero retornamos que ya fue ingresado "true"
                    else return false; // al ser falso retornamos false, indicando que esta disponible
}
bool Exist_egresos(struct Anual * Cuenta_anual, int mes, int anio){
    int i=anio-2019, j=mes-1; //verificamos si el dato ya ha sido ingresado
                            // creamos el indice para cada año// creamos el indice para el mes
            if((Cuenta_anual+i)->registro_eg[j]==true) return true; // si es verdadero retornamos que ya fue ingresado "true"
                    else return false; // al ser falso retornamos false, indicando que esta disponible
}
bool Eliminar_datos(struct Anual Cuenta_anual[]){
      int i=0, j=0, opt=0,mes=0, anio=0;
            cout<<"\t\tQue datos desea eliminar ?"<<endl
                <<"\t\t (1) Ingresos"<<endl
                <<"\t\t (2) Egresos "<<endl
                <<"\t\t (3) Salir"<<endl
                <<endl;
                   do{
                       cout<<"\t\tOpcion>"; cin>>opt;
                   }while(opt!=1 && opt!=2 && opt!=3);
                   if(opt==3) return false;
                   do{
		            cout<<"\t\tDe que anio?>"; cin>>anio;	
	                }while(!(anio<=2023 && anio>=2019));
                    do{
                       cout <<"\t\t Mes>"; cin>>mes;
	                }while(!(mes>=1 && mes<=12));
                    i=anio-2019; j=mes-1;
           switch(opt){
               case 1:
                Cuenta_anual[i].Ingreso_Mensual[j]={{0,0,0,0},{0,0,0,0},0};
                Cuenta_anual[i].registro_ing[j]=false;
                break;
                case 2:
                Cuenta_anual[i].Egreso_Mensual[j]={0,0,0,0,0,0,0,0};
                Cuenta_anual[i].registro_eg[j]=false;
                break;
           }
           return true;
}
void Mostrar_estadisticas(struct Anual Cuenta_anual[]){ //se anulara cuando se cambie por un FILE
  //struct Anual Cuenta_anual[11];
  //FILE *data  ... fwrite(Cuenta_anual, sizeof(Cuenta_anual), 1, data);
    int anio=0, i=0, imin=0, imax=0,emin=0, emax=0, limit=0;
    double porcent=0.0, suma_ingresos=0, suma_egresos=0,mayor_ing=0, menor_ing=0, mayor_eg=0,menor_eg=0, data=0;
         cout<<"\n\t\t________ESTADISTICAS TOTALES_________"<<endl
             <<endl;
                do{
                    cout<<"\t\tDe que a"<<char(164)<<"o? >"; cin>>anio; fflush(stdin);
                }while(!(anio<=2023 && anio>=2019));
                i=anio-2019; //obtiene el indice del año establecido
                cout<<"\t\t__INGRESOS!__"<<endl
                    <<endl; //cuenta_anual[i].Ingreso_Mensual[j].IngresoMensual
                    mayor_ing=Cuenta_anual[i].Ingreso_Mensual[0].total;
                    menor_ing=Cuenta_anual[i].Ingreso_Mensual[0].total;
                    mayor_eg= Cuenta_anual[i].Egreso_Mensual[0].Gastmensual;
                    menor_eg=Cuenta_anual[i].Egreso_Mensual[0].Gastmensual;
                for(int u=1; u<12; u++){ //comparamos los ingresos mayores y menores de cada mes como tambien egresos
                    if(Cuenta_anual[i].Ingreso_Mensual[u].total>= mayor_ing) {
                        mayor_ing=Cuenta_anual[i].Ingreso_Mensual[u].total;
                                   imax=u; }
                    if(Cuenta_anual[i].Ingreso_Mensual[u].total<= menor_ing) {
                        menor_ing=Cuenta_anual[i].Ingreso_Mensual[u].total;
                                    imin=u;}
                    if(Cuenta_anual[i].Egreso_Mensual[u].Gastmensual>=mayor_eg) {
                        mayor_eg=Cuenta_anual[i].Egreso_Mensual[u].Gastmensual;
                                    emax=u;
                         } 
                          if(Cuenta_anual[i].Egreso_Mensual[u].Gastmensual<=menor_eg) {
                        menor_eg=Cuenta_anual[i].Egreso_Mensual[u].Gastmensual;
                                    emin=u;
                         } } 
                          //mostramos los resultados
                    cout<<"\t\tMayor ingreso en "<<mes[imax].name<<" con s/"<<mayor_ing<<endl
                        <<"\t\tMenor ingreso en "<<mes[imin].name<<" con s/"<<menor_ing<<endl
                        <<"\t\tResultados:\n";
                for(int j=0; j<12; j++) {
                        suma_ingresos=Cuenta_anual[i].Ingreso_Mensual[j].total+suma_ingresos; //obtenemos la suma de todos los meses
                        suma_egresos=Cuenta_anual[i].Egreso_Mensual[j].Gastmensual+suma_egresos; //obtenemos la suma de egresos anuales
                } 
                        for(int n=0; n<12; n++){
                            data=Cuenta_anual[i].Ingreso_Mensual[n].total;
                                porcent=(data/suma_ingresos);
                                        limit=porcent*60;
                                 cout<<"\t\t"<<setw(9)<<mes[n].name<<"| s/"<<setw(6)<<data <<" |"; for(int s=0; s<limit; s++) cout<<char(223); cout<<" "<<porcent*100<<"%"; 
                                    cout<<endl;
                        } porcent=0;
                cout<<"\n\t\tEGRESOS"<<endl
                    <<endl
                    <<"\t\tMayor egreso en el mes de "<<mes[emax].name<<": s/"<<mayor_eg<<endl
                    <<"\t\tMenor egreso en "<< mes[emin].name<<"con : s/"<<menor_eg<<endl
                    <<"\t\tResultados:\n";
                    for(int n=0; n<12; n++){
                        data=Cuenta_anual[i].Egreso_Mensual[n].Gastmensual;
                            porcent=(data/suma_egresos);
                                limit=porcent*60;
                            cout<<"\t\t "<<setw(9)<<mes[n].name<<" | s/"<<setw(6)<<data<<" |"; for(int s=0; s<limit; s++) cout<<char(223);cout<<" "<<porcent*100<<"%";
                                cout<<endl;
                    }
                    cout<<"\n\t\tEstadisticas mensuales mostradas :')"<<endl;
        }
        bool Mostrar_egresos(struct Anual Cuenta_anual[]){ //se cambiara por 
            //struct Anual Cuenta_anual[12] ... cuando se incorpore un archivo
            // FILE *data; fwrite(Cuenta_anual, sizeof(cuenta_anual),1,data);
            int anio=0,mes=0, i=0, j=0;
                do{
                    cout<<"\t\tDe que a"<<char(164)<<"o? >"; cin>>anio; fflush(stdin);
                }while(!(anio<=2029 && anio>=2019));   
                i=anio-2019;
                do{
                     cout<<"\t\tDe que mes ? >"; cin>>mes; fflush(stdin);
                }while(!(mes>=1 && mes<=12)); j=mes-1;
                if(Cuenta_anual[i].registro_eg[j]==false) return false;
                cout<<"\t\tDatos>"<<endl
                    <<endl
                    <<"\t\tAlimentacion ..... s/"<<Cuenta_anual[i].Egreso_Mensual[j].alimentacion<<endl
                    <<"\t\t Cultura familiar..... s/"<<Cuenta_anual[i].Egreso_Mensual[j].cultura_familiar<<endl
                    <<"\t\tEducacion ..... s/"<<Cuenta_anual[i].Egreso_Mensual[j].educacion<<endl
                    <<"\t\tHogar..... s/"<<Cuenta_anual[i].Egreso_Mensual[j].hogar<<endl
                    <<"\t\tRopas y vestimenta ..... s/"<<Cuenta_anual[i].Egreso_Mensual[j].indumentaria<<endl
                    <<"\t\tSalud ..... s/"<<Cuenta_anual[i].Egreso_Mensual[j].salud<<endl
                    <<"\t\tTransporte ..... s/"<<Cuenta_anual[i].Egreso_Mensual[j].transporte<<endl
                    <<"\t\t\t___ Total............. s/"<<Cuenta_anual[i].Egreso_Mensual[j].Gastmensual<<endl;
                    return true;
     }
        bool Mostrar_ingresos(struct Anual Cuenta_anual[]){
             int anio=0,mes=0, i=0, j=0;
            //struct Anual Cuenta_anual[12] ... cuando se incorpore un archivo
            // FILE *data; fwrite(Cuenta_anual, sizeof(cuenta_anual),1,data);
                do{
                    cout<<"\t\tDe que a"<<char(164)<<"o? >"; cin>>anio; fflush(stdin);
                }while(!(anio<=2029 && anio>=2019));   
                i=anio-2019;
                do{
                     cout<<"\t\tDe que mes ? >"; cin>>mes; fflush(stdin);
                }while(!(mes>=1 && mes<=12));j=mes-1;
                if(Cuenta_anual[i].registro_ing[j]==false) return false;
                cout<<"\t\tDatos >"<<endl
                    <<endl
                    <<"\t\t Ingresos de:"<<endl
                    <<"\t\t Padre s/"<<Cuenta_anual[i].Ingreso_Mensual[j].sueldo[0]<<endl
                                <<"\t\t   |___extra s/"<<Cuenta_anual[i].Ingreso_Mensual[j].extra[0]<<endl
                    <<"\t\t Madre s/"<<Cuenta_anual[i].Ingreso_Mensual[j].sueldo[1]<<endl
                                  <<"\t\t   |___extra s/"<<Cuenta_anual[i].Ingreso_Mensual[j].extra[1]<<endl
                    <<"\t\t Hermanos s/"<<Cuenta_anual[i].Ingreso_Mensual[j].sueldo[2]<<endl
                                   <<"\t\t   |___extra s/"<<Cuenta_anual[i].Ingreso_Mensual[j].extra[2]<<endl
                    <<"\t\t Yo s/"<<Cuenta_anual[i].Ingreso_Mensual[j].sueldo[3]<<endl
                                    <<"\t\t   |___extra s/"<<Cuenta_anual[i].Ingreso_Mensual[j].extra[3]<<endl
                    <<"\t\t ______ Total s/"<<Cuenta_anual[i].Ingreso_Mensual[j].total<<endl
                    <<endl
                    <<"\t\t\t______Ingresos mostrados_____\n"<<endl;
                    return true;
 }
int menu(){
    int op=0;
    cout<<endl
		<<"\t\t _________________________________________________"<<endl
		<<"\t\t| CUENTA FAMILIAR ANUAL (2019 - 2023)             |"<<endl
		<<"\t\t|____________________________________             |"<<endl
		<<"\t\t|             {\\_/}                               |"<<endl
		<<"\t\t|             ( *-*)                              |"<<endl
		<<"\t\t|              />(@)Ten una kangreburguer         |"<<endl
		<<"\t\t|                                                 |"<<endl
		<<"\t\t|             {\\_/}                               |"<<endl
		<<"\t\t|             ( *_*)                              |"<<endl
		<<"\t\t|             (@)<\\   Primero rellena los datos   |"<<endl
		<<"\t\t|                                                 |"<<endl
		<<"\t\t| Bienvenido, por favor escoga una opcion:        |"<<endl
		<<"\t\t|                                                 |"<<endl
        <<"\t\t| (1) Ver que me falta registrar ;-)              |"<<endl
	    <<"\t\t| (2) Registro  de ingresos mensuales             |"<<endl
	    <<"\t\t| (3) Registro de gastos                          |"<<endl
        <<"\t\t| (4) Mostrar datos                               |"<<endl
		<<"\t\t| (5) Eliminar datos de operacion                 |"<<endl
		<<"\t\t| (6) Mostrar estadisticas                        |"<<endl
		<<"\t\t| (7) Salir                                       |"<<endl
		<<"\t\t|_________________________________________________|"<<endl
		<<endl;
		do{
			cout<<"\t\t | Opcion>";cin>>op; fflush(stdin); if(cin.fail()) cin.clear();
		}while(!(op<=7 && op>0));
        return op;
}
bool Estado_general(struct Anual cuenta[]){
    bool ingreso=false, egreso=false;
     cout<<"\n\t| MES \\ A"<<char(164)<<"o"; //Esta parte es diseño de guiones y espacios para una mejor apariencia
    for(int s=0; s<5; s++) {cout<<"   |"<<setw(5)<<(s+2019);} cout<<"| \n"; //despliega los años con diseño
     cout<<"\t|";for(int r=0; r<55; r++) { cout<<"-"; }        cout<<"|\n"; //Diseño
    for(int j=0; j<12;j++){ //Apartir de aqui empieza la funcion UTIL
        cout<<"\t|"<<setw(10); //diseño
            for(int i=0; i<5; i++){
                    if(i==0) cout<<mes[j].name;
                    ingreso=cuenta[i].registro_ing[j];
                    egreso=cuenta[i].registro_eg[j];
              if(ingreso==true){
                    if(egreso==true) cout<<setw(9)<<"|Listo";
                        else cout<<setw(9)<<"| F.E ";
              }else if(egreso==false) cout<<setw(9)<<"|Falta";
                                else cout<<setw(9)<<"| F.I "; //si es false, pues ponemos que falta
            }cout<<"| \n";
    }
    cout<<"\t|";for(int r=0; r<55; r++){cout<<"_"; }     cout<<"|\n"; //despligue guiones para la parte inferior de la tala
    cout<<"\n\tLeyenda: Falta Ingreso (F.I)|  Falta Egreso (F.E)"<<endl;
         return true;
}
void inicializar(struct Anual* cuenta){
for(int i=0; i<5; i++){
        for(int j=0; j<12; j++){
             (cuenta+i)->Ingreso_Mensual[j]={{0,0,0,0},{0,0,0,0},0};
             (cuenta+i)->Egreso_Mensual[j]={0,0,0,0,0,0,0,0};
             (cuenta+i)->registro_eg[j]=false;
             (cuenta+i)->registro_ing[j]=false;
             (cuenta+i)->balance=0.0;
        }
}
return;
}