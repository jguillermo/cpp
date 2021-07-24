//Programa basico de punteros
//Ahora analice este ejemplo, note la forma como es tratado
//los arreglos
//agosto 2005
#include <iostream.h>
#include <conio.h>
void main()
{
int i,max=10;
clrscr();
float a,c[20],*x;
a=3.5;
x=&a;
cout<<"El valor donde apunta x:"<<*x<<endl;
*x=5.8;
cout<<"El valor de a que ha sido modificada desde x:"<<a<<endl;


for (i=0;i<=max;i++)
  c[i]=i+10;
//note que en lenguaje c, la variable de tipo arreglo es un
//puntero que apunta a la primera direccion
x=c;
cout<<"El valor donde apunta c:"<<*c<<endl;
cout<<"El valor donde apunta x:"<<*x<<endl;

cout<<"Los valores donde apunta x+i:"<<endl;
for (i=0;i<=max;i++)
  cout<<*(x+i)<<" ,";

cout<<"\nLos valores valor donde apunta *(x+i) es igual a x[i]:"<<endl;
for (i=0;i<=max;i++)
  cout<<x[i]<<" ,";

for (i=0;i<=max;i++)
   *(x+i)=*(x+i)*2;

cout<<"\nLos valores de c[i] luego de ser modificado desde el puntero x:"<<endl;
for (i=0;i<=max;i++)
  cout<<c[i]<<" ,";


getch();
}
