//CURSO: COMPUTACION I
//TEMA: MANEJO DE ESTRUCTURAS CON CADENA
//FECHA: agosto del 2005
//Ejemplo de manejo de registros para base de datos
//Analice como se ordena por un campo numerico
//y por uncampo de cadena
//TAREA PARA PREPARARSE:
//1) Implemente la consideracion de que el examen sustitutorio es opcional
//   y modifique todas las funciones que esten involucradas
//2) Implemente la siguiente prototipo  de la funcion
//  void ordenar(Sdatos Lista[20], int campo);
// donde Lista[20] es lalista de los 20 alumnos como maximo, note que en
// la variable global n se almacena la cantidad de alumnos.
// y campo es el numero del campo por el que se va a ordenar, por ejemplo
// si campo es 1, entonces se ordena por codigo, si es 2 se ordena por
// nombre, si es 3 se ordena a paterno y asi sucesivamente por todos los campos.




#include <conio.h>
#include <iostream.h>
#include <string.h>
struct Sfecha
 {int dia,mes,year;
 };

struct Sdatos
{char codigo[10];
 char nombre[40];
 char apaterno[40];
 char amaterno[40];
 float peso;
 Sfecha fn;//fecha de nacimiento
 int p1,p2,p3,p4;//Notas de practica;
 int ep,ef,es;//parcial,final y sustitutorio
 int nf;//nota del curso
 //miembros que deben ser calculados a partir de las variables de arriba
 int mp;//la nota de practica que sera eliminado
 int pp;//promedio de practicas
 char condicion[20];//aprobado o desaprobado
 };


void leer(Sdatos &alumno);
void ver(Sdatos alumno);
void calcular(Sdatos &alu);
void vercalculo(Sdatos &alu);
void mejor_nota(Sdatos alumnos[20],Sdatos &alumno);
void ordenar_por_ef(Sdatos alu[20]);//de menor a mayor
void ordenar_por_apaterno(Sdatos alu[20]);//alfabeticamente

int n;//variable global
void main()
{
Sdatos Lista_alumnos[20],alu;
int i;
cout<<"Ingrese numero de alumnos:";cin>>n;
for (i=1;i<=n;i++)
 {cout<<"\nINGRESE DATOS DEL ALUMNO Nø "<<i<<endl;
  leer(Lista_alumnos[i]);
  calcular(Lista_alumnos[i]);
  cout<<"RESULTADO...."<<endl;
  vercalculo(Lista_alumnos[i]);
  cout<<"                        Presione cualquier tecla..."<<endl;
  getch();
 }
//ordenar_por_ef(Lista_alumnos);
ordenar_por_apaterno(Lista_alumnos);
clrscr();
cout<<"Los registros leidos son"<<endl;
for (i=1;i<=n;i++)
 {cout<<"\nALUMNO Nø "<<i<<endl;
  ver(Lista_alumnos[i]);
  cout<<"                        Presione cualquier tecla..."<<endl;
  getch();
 }


getch();
}


void leer(Sdatos &alumno)
 {cin.get();
  cout<<"Ingrese codigo:";cin.getline(alumno.codigo,10);
  cout<<"Ingrese nombre:";cin.getline(alumno.nombre,40);
  cout<<"Ingrese apellido paterno:";cin.getline(alumno.apaterno,40);
  cout<<"Ingrese apellido materno:";cin.getline(alumno.amaterno,40);
  cout<<"Ingrese peso:";cin>>alumno.peso;
  cout<<"Ingrese Fecha nacimiento(dd mm aa):";
  cin>>alumno.fn.dia>>alumno.fn.mes>>alumno.fn.year;
  cout<<"Ingrese primera practica:";cin>>alumno.p1;
  cout<<"Ingrese segunda practica:";cin>>alumno.p2;
  cout<<"Ingrese tercera practica:";cin>>alumno.p3;
  cout<<"Ingrese cuarta practica:";cin>>alumno.p4;
  cout<<"Ingrese examen parcial:";cin>>alumno.ep;
  cout<<"Ingrese examen final:";cin>>alumno.ef;
  cout<<"Ingrese examen sustitutorio:";cin>>alumno.es;
 }
void ver(Sdatos alumno)
 {cout<<"Codigo:"<<alumno.codigo<<endl;
  cout<<"Nombre:"<<alumno.nombre<<endl;
  cout<<"Apellido paterno:"<<alumno.apaterno<<endl;
  cout<<"Apellido materno:"<<alumno.amaterno<<endl;
  cout<<"Peso:"<<alumno.peso<<endl;
  cout<<"Fecha nacimiento(dd mm aa):";
  cout<<alumno.fn.dia<<"/"<<alumno.fn.mes<<"/"<<alumno.fn.year<<endl;
  cout<<"Primera practica:"<<alumno.p1<<endl;
  cout<<"Segunda practica:"<<alumno.p2<<endl;
  cout<<"Tercera practica:"<<alumno.p3<<endl;
  cout<<"Cuarta practica:"<<alumno.p4<<endl;
  cout<<"Parcial:"<<alumno.p4<<endl;
  cout<<"Examen final:"<<alumno.p4<<endl;
  cout<<"Examen sustitutorio:"<<alumno.p4<<endl;
  vercalculo(alumno);
 }

void calcular(Sdatos &alu)
{
int n1,n2,min=alu.p1;
if (alu.p2<min) min=alu.p2;
if (alu.p3<min) min=alu.p3;
if (alu.p4<min) min=alu.p4;
alu.mp=min;
alu.pp=(alu.p1+alu.p2+alu.p3+alu.p4-min)/3;
n1=(alu.pp+alu.es+2*alu.ef)/4;
n2=(alu.pp+alu.ep+2*alu.es)/4;
if (n1>n2) alu.nf=n1;
else alu.nf=n2;

if (alu.nf>=10) strcpy(alu.condicion,"APROBADO");
else strcpy(alu.condicion,"DESAPROBADO");
}

void vercalculo(Sdatos &alu)
 {
  cout<<"  La nota de practica que sera eliminada:"<<alu.mp<<endl;
  cout<<"  Promedio de practicas:"<<alu.pp<<endl;
  cout<<"  Nota final del curso:"<<alu.nf<<endl;
  cout<<"  Condicion:"<<alu.condicion<<endl;
}
void ordenar_por_ef(Sdatos alu[20])
{int i,j;
Sdatos tem;
for (i=1;i<=n-1;i++)
 for (j=i+1;j<=n;j++)
  if (alu[i].ef>alu[j].ef)
    {tem=alu[i];
     alu[i]=alu[j];
     alu[j]=tem;
     }
}

void ordenar_por_apaterno(Sdatos alu[20])//alfabeticamente
{int i,j;
Sdatos tem;
for (i=1;i<=n-1;i++)
 for (j=i+1;j<=n;j++)
  if (strcmp(alu[i].nombre,alu[j].nombre)>0)
    {tem=alu[i];
     alu[i]=alu[j];
     alu[j]=tem;
     }
}

