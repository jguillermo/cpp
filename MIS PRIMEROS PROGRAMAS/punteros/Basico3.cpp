//Programa basico de punteros con listas, ejemplo de lista simplemente enlazada
//este ejemplo esta desarrollado manualmente,
//piense ahora la forma de automatizar la lectura
//y escritura de la lista, agosto 2005
#include <iostream.h>
#include <conio.h>
#include <string.h>
struct Snodo{
	char nombre[20];
	int n1,n2; //notas
	int prom()
   	{return (n1+n2)/2;
      }
	int max()
   	{if (n1>n2) return n1;
      		else	return n2;
      }
	int min()
   	{if (n2>n1) return n1;
      		else	return n2;
      }
	Snodo *siguiente;
};

void main()
{
clrscr();
Snodo *cabeza,*nuevo;
cabeza=NULL;

nuevo=new Snodo;
strcpy((*nuevo).nombre,"LUCHO");
(*nuevo).n1=1;
(*nuevo).n2=5;
(*nuevo).siguiente=cabeza;
cabeza=nuevo;

nuevo=new Snodo;
strcpy((*nuevo).nombre,"MARCOS");
(*nuevo).n1=10;
(*nuevo).n1=9;
(*nuevo).siguiente=cabeza;
cabeza=nuevo;

nuevo=new Snodo;
strcpy((*nuevo).nombre,"JOSE");
(*nuevo).n1=19;
(*nuevo).n2=20;
(*nuevo).siguiente=cabeza;
cabeza=nuevo;

//RECUPERACION DE LA DATA
cout<<"Valores de los registros empezando por el ultimo\n";
cout<<" Registro 3"<<endl;
cout<<"  Nombre: "<<(*cabeza).nombre<<endl;
cout<<"  Nota 1: "<<(*cabeza).n1<<endl;
cout<<"  Nota 2: "<<(*cabeza).n2<<endl;
cout<<"  Promedio: "<<(*cabeza).prom()<<endl;
cout<<"  Maxima nota: "<<(*cabeza).max()<<endl;
cout<<"  Minima nota: "<<(*cabeza).min()<<endl;

cabeza=(*cabeza).siguiente;
cout<<" Registro 2"<<endl;
cout<<"  Nombre: "<<(*cabeza).nombre<<endl;
cout<<"  Nota 1: "<<(*cabeza).n1<<endl;
cout<<"  Nota 2: "<<(*cabeza).n2<<endl;
cout<<"  Promedio: "<<(*cabeza).prom()<<endl;
cout<<"  Maxima nota: "<<(*cabeza).max()<<endl;
cout<<"  Minima nota: "<<(*cabeza).min()<<endl;

cabeza=(*cabeza).siguiente;
cout<<" Registro 1"<<endl;
cout<<"  Nombre: "<<(*cabeza).nombre<<endl;
cout<<"  Nota 1: "<<(*cabeza).n1<<endl;
cout<<"  Nota 2: "<<(*cabeza).n2<<endl;
cout<<"  Promedio: "<<(*cabeza).prom()<<endl;
cout<<"  Maxima nota: "<<(*cabeza).max()<<endl;
cout<<"  Minima nota: "<<(*cabeza).min()<<endl;

getch();
}
