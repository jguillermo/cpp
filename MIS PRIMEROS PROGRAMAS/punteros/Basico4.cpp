//Programa basico de punteros con listas
//ejemplo de lista simplemente enlazada
//NOTE COMO SE IMPLEMENTAN LAS FUNCIONES
//agosto 2005
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
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


void crear(Snodo* &p);
void ver(Snodo *p);


void main()
{
Snodo *lista;
crear(lista);
cout<<"LOS VALORES LEIDOS ...\n";
ver(lista);
getch();
}


void crear(Snodo * &p)
{
Snodo *cabeza,*nuevo;
char op;
cabeza=NULL;
do
{ nuevo=new Snodo;
  cout<<"Ingrese nombre:";gets((*nuevo).nombre);
  cout<<"Ingrese nota 1:";cin>>(*nuevo).n1;
  cout<<"Ingrese nota 2:";cin>>(*nuevo).n2;
  (*nuevo).siguiente=cabeza;
  cabeza=nuevo;
  cout<<"Desea seguir ingresando mas datos S/N:";
  cin>>op;
  op=toupper(op);
} while (op!='N');
p=cabeza;
}

void ver(Snodo *p)
{
Snodo *cabeza;
cabeza=p;
int i=0;
while (cabeza!=NULL)
{ i++;
  cout<<" Registro "<<i<<endl;
  cout<<"   NOMBRE:"<<(*cabeza).nombre<<endl;
  cout<<"   NOTA 1:"<<(*cabeza).n1<<endl;
  cout<<"   NOTA 2:"<<cabeza->n2<<endl;
  cout<<"   PROMEDIO:"<<(*cabeza).prom()<<endl;
  cout<<"   MAXIMA NOTA:"<<(*cabeza).max()<<endl;
  cout<<"   MINIMA NOTA:"<<(*cabeza).min()<<endl;
  cabeza=(*cabeza).siguiente;
  getch();
}
}