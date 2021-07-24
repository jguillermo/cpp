//Ejemplo de manejo de registros para base de datos
//Implementar las funciones calcular y mejor nota


#include <conio.h>
#include <iostream.h>
#include <cstring.h>
struct Sfecha
 {int dia,mes,year;
 };

struct Sdatos
{char codigo[10];
 char nombre[40];
 char apaterno[40];
 char amaterno[40];
 float peso;
 Sfecha fnacimiento;
 int p1,p2,p3,p4;//Notas de practica;
 int pp;//promedio de practicas
 int ep,ef,es;//parcial,final y sustitutorio
 int notafinal;//nota total
 char condicio[20];//aprobado o desaprobado
 };


void leer(Sdatos &alumno);
void ver(Sdatos alumno);
void calcular(Sdatos &alumno);
void mejor_nota(Sdatos alumnos[20],Sdatos &alumno);

void main()
{
Sdatos Lista_alumnos[20],alu;
int n,i;
cout<<"Ingrese numero de alumnos:";cin>>n;
for (i=1;i<=n;i++)
 {cout<<"\nAlumno N° "<<i<<endl;
  leer(Lista_alumnos[i]);
 }
clrscr();
cout<<"Los registros leidos son"<<endl;
for (i=1;i<=n;i++)
 {cout<<"\nAlumno N° "<<i<<endl;
  ver(Lista_alumnos[i]);
  cout<<"                        Presione cualquier tecla..."<<endl;
  getch()
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
  cin>>alumno.fnacimiento.dia>>alumno.fnacimiento.mes>>alumno.fnacimiento.year;
  cout<<"Ingrese primera practica:";cin>>alumno.p1;
  cout<<"Ingrese segunda practica:";cin>>alumno.p2;
  cout<<"Ingrese tercera practica:";cin>>alumno.p3;
  cout<<"Ingrese cuarta practica:";cin>>alumno.p4;
  cout<<"Ingrese examen parcial:";cin>>alumno.p4;
  cout<<"Ingrese examen final:";cin>>alumno.p4;
  cout<<"Ingrese examen sustitutorio:";cin>>alumno.p4;
 }
void ver(Sdatos alumno)
 {cout<<"Codigo:"<<alumno.codigo<<endl;
  cout<<"Nombre:"<<alumno.nombre<<endl;
  cout<<"Apellido paterno:"<<alumno.apaterno<<endl;
  cout<<"Apellido materno:"<<alumno.amaterno<<endl;
  cout<<"Peso:"<<alumno.peso<<endl;
  cout<<"Fecha nacimiento(dd mm aa):";
  cout<<alumno.fnacimiento.dia<<"/"<<alumno.fnacimiento.mes<<"/"<<alumno.fnacimiento.year<<endl;
  cout<<"Primera practica:"<<alumno.p1<<endl;
  cout<<"Segunda practica:"<<alumno.p2<<endl;
  cout<<"Tercera practica:"<<alumno.p3<<endl;
  cout<<"Cuarta practica:"<<alumno.p4<<endl;
  cout<<"Parcial:"<<alumno.p4<<endl;
  cout<<"Examen final:"<<alumno.p4<<endl;
  cout<<"Examen sustitutorio:"<<alumno.p4<<endl;
 }






