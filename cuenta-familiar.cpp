#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<conio.h>
#include "funciones.h"
#define MAX 5
using namespace std;
int main(){
	system("title Cuenta Familiar v1.0");
	FILE *data=NULL;
   char opchar;
   struct Anual cuenta[MAX];
   int op=0, op3=0, dia=0, mes=0, anio=0; 
   bool exist=false, salir=false, found=false;
    data=fopen("cuenta.txt", "rb+");
	inicializar(cuenta);
		if(data==NULL){ 
				cout<<"\tNo se hallo registro anterior, se procedera a crear uno nuevo\n";
				fclose(data); //cerramos el anterior y abrimos a modo crear
				data=fopen("cuenta.txt", "wb+"); //se crea un archivo de escritura binaria
					if(data==NULL) cout<<"\tError de escritura, verfifique si tiene los permisos necesarios dicha operacion\n";
		}else {cout<<"\tSe hallo un registro... (ok)\n";
			fread(cuenta, sizeof(Anual),MAX,data);
		} getch();
   do{
	   	rewind(data);
	   		system("cls");
	      op=menu();
		  	
	switch(op){
		case 1:
			system("cls");
		cout<<"\n\n\t\t TABLA DE REGISTROS ANUALES> CUENTA FAMILIAR\n";
			Estado_general(cuenta);
		 break;
		case 2: 
				do{ system("cls");
		  	 cout<<"\t\t\t __________________________________________________"<<endl
		  	 	 <<"\t\t\t|...............  INGRESOS FAMILIARES   ...........|"<<endl
			 	 <<"\t\t\t|__________________________________________________|"<<endl;
          Fecha_total(dia, mes, anio); 					//solicito la fecha
			exist=Exist_ingresos(cuenta,mes,anio); 		//verifico si ya se registro un dato con esa fecha
					if(exist==true){ 					//uso el IF para verificar y si existe doy un aviso
						cout<<"\t\t!Ya existe Registro en esta fecha, si continua se reemplazaran por la informacion actual\n";
						do{
						cout<<"\t\tDesea continuar y reemplazarla? (s/n) >"; cin>>opchar; fflush(stdin); //bucle para dato correcto	
						}while(opchar!='s' &&opchar!='n');
					}else opchar='s'; 						//si no existe, rompo el bucle do-while, para pasar a las siguientes operacione de "registro"
				}while(opchar!='s' &&opchar!='n');
					if(opchar!='n'){ 					// si ha existido y no deseo continuar, me arrojara la tabla inicial
					system("cls");
				cout<<"\n\t\t____________ Listo para registrar datos de ingreso!  ___________"<<endl;
			registrar_ingresos(cuenta,dia, mes, anio);	//FUNCION PRINCIPAL DE LA OPERACION!
					}
			break;
		case 3: 
		          do{ system("cls");
		  cout<<"\t\t\t __________________________________________________"<<endl
		  	  <<"\t\t\t|...............  GASTOS FAMILIARES   .............|"<<endl
			  <<"\t\t\t|__________________________________________________|"<<endl;
				Fecha_total(dia, mes, anio); 				//solicito la fecha del EGRESO
			     exist=Exist_egresos(cuenta,mes,anio);	 	//verifico si ya se registro un dato de egreso con esa fecha
					if(exist==true){						//uso el IF para verificar y si existe doy un aviso
						cout<<"\t\t!Ya existe Registro en esta fecha, si continua se reemplazaran por la informacion actual\n";
						do{
						cout<<"\t\tDesea continuar y reemplazarla? (s/n) >"; cin>>opchar; fflush(stdin); //bucle para dato correcto	
						}while(opchar!='s' &&opchar!='n');
					}else opchar='s'; 							//si no existeregistro anterior, rompo el bucle do-while, para pasar a las siguientes operacione de "registro"
				}while(opchar!='n' &&opchar!='s');
				 						// si ha existido un registro y no deseo continuar, me arrojara la tabla inicial
				if(opchar!='n'){system("cls");
				cout<<"\n\t\t____________ Listo para registrar datos de egreso!  ___________"<<endl;
				registrar_egresos(cuenta, dia, mes, anio);
				}
			break;	
		case 4:do{	system("cls"); found=false;
		  cout<<"\t\t\t __________________________________________________"<<endl
		  	  <<"\t\t\t|............... MOSTRAR DATOS          ...........|"<<endl
			  <<"\t\t\t|__________________________________________________|"<<endl
			  <<endl
			  <<"\t\t\t (1) Mostrar Ingresos"<<endl
			  <<"\t\t\t (2) Mostrar Egresos"<<endl
			  <<"\t\t\t (3) Salir"<<endl
			  <<endl;
			  do{
				  cout<<"\t\t\t Opcion>"; cin>>op3;
			  }while(op3!=1 &&op3!=2 &&op3!=3);
			  if(op3!=3){
			  switch(op3){
				  case 1:
				   	found=Mostrar_ingresos(cuenta); break;
				  case 2:
				    found=Mostrar_egresos(cuenta); break;
 					}
				  if(found!=true) cout<<"\n\t\t______No se hallaron registros que para mostrar aqui, por favor rellenelo :)"<<endl;
			  } getch();
		  }while(op3!=3);
			  break;
		case 5:	
		do{ system("cls"); salir=false;
		  cout<<"\t\t\t __________________________________________________"<<endl
		  	  <<"\t\t\t|...............   ELIMINAR DATOS       ...........|"<<endl
			  <<"\t\t\t|__________________________________________________|"<<endl;	
			  salir=Eliminar_datos(cuenta);
		}while(salir);
			break;
		case 6:
			system("cls");
		  cout<<"\t\t\t __________________________________________________"<<endl
		  	  <<"\t\t\t|...............  ESTADISTICAS          ...........|"<<endl
			  <<"\t\t\t|__________________________________________________|"<<endl
			  <<endl;
			  Mostrar_estadisticas(cuenta);
           break;
		 default: break;
		}
		fwrite(cuenta, sizeof(struct Anual), MAX,data);
		system("pause>nul");
   }while(op!=7);
   fclose(data);
        return 0;
}


