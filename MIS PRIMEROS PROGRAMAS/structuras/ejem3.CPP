//Programa b sico de punteros con listas
//ejemplo de lista simplemente enlazada
//incluye funciones miembro para la estructura
//agosto 2005
#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
struct Snodo{
  //datos
  char nombre[20];
  float nota1,nota2;
  //funciones miembro
  float promedio();
  //puntero para enlazar
  Snodo *siguiente;
};

float Snodo::promedio()
{return (nota1+nota2)/2;}

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
  cout<<"Ingrese nombre:";
  cin.getline((*nuevo).nombre,50);
  cout<<"Ingrese nota1:";cin>>(*nuevo).nota1;
  cout<<"Ingrese nota2:";cin>>nuevo->nota2;
  (*nuevo).siguiente=cabeza;
  cabeza=nuevo;
  cout<<"Desea seguir ingresando mas datos S/N:";
  cin>>op;
  cin.get();
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
  cout<<"   NOTA1:"<<cabeza->nota1<<endl;
  cout<<"   NOTA2:"<<cabeza->nota2<<endl;
  cout<<"   PROMEDIO:"<<cabeza->promedio()<<endl;
  cabeza=(*cabeza).siguiente;
  getch();
}
}