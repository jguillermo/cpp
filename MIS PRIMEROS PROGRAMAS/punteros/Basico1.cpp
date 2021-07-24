//Programa basico de punteros
//Concepto de direccion de memoria
//Analice cada una de las sentencias
//y compare con la informacion dada en clase teorica
//agosto 2005
#include <iostream.h>
#include <conio.h>
void main()
{
clrscr();
float A,*x;
int B,*y;
A=5.5;
B=2.75;
cout<<"==========VARIABLES ESTATICAS==========================="<<endl;
cout<<"La variable A contiene el valor de:"<<A<<endl;
cout<<"La variable B contiene el valor de:"<<B<<endl;
cout<<"La variable A esta ubicado en la siguiente direccion:"<<&A<<endl;
cout<<"La variable B esta ubicado en la siguiente direccion:"<<&B<<endl;
cout<<"La variable A ocupa "<<sizeof(A)<<" bytes en la memoria"<<endl;
cout<<"La variable B ocupa "<<sizeof(B)<<" bytes en la memoria"<<endl;
cout<<"==========VARIABLES TIPO PUNTERO========================="<<endl;
cout<<"La variable x contiene el valor de:"<<x<<endl;
cout<<"La variable x esta ubicado en la siguiente direccion:"<<&x<<endl;
cout<<"El valor de la direccion que apunta la variable x es:"<<*x<<endl;
cout<<"La variable x ocupa "<<sizeof(x)<<" bytes en la memoria"<<endl;
cout<<"La variable y contiene el valor de:"<<y<<endl;
cout<<"La variable y esta ubicado en la siguiente direccion:"<<&y<<endl;
cout<<"El valor de la direccion que apunta la variable y es:"<<*y<<endl;
cout<<"La variable y ocupa "<<sizeof(y)<<" bytes en la memoria"<<endl;
getch();
cout<<"=========================================================="<<endl;
cout<<"=======RESULTADO DE LAS OPERACIONES CON PUNTERO==========="<<endl;
x=&A;
y=&B;
A++;
B++;
(*x)++;
(*y)++;
*x=(*y+A);
cout<<"==========VARIABLES ESTATICAS==========================="<<endl;
cout<<"La variable A contiene el valor de:"<<A<<endl;
cout<<"La variable B contiene el valor de:"<<B<<endl;
cout<<"La variable A esta ubicado en la siguiente direccion:"<<&A<<endl;
cout<<"La variable B esta ubicado en la siguiente direccion:"<<&B<<endl;
cout<<"La variable A ocupa "<<sizeof(A)<<" bytes en la memoria"<<endl;
cout<<"La variable B ocupa "<<sizeof(B)<<" bytes en la memoria"<<endl;
cout<<"==========VARIABLES TIPO PUNTERO========================="<<endl;
cout<<"La variable x contiene el valor de:"<<x<<endl;
cout<<"La variable x esta ubicado en la siguiente direccion:"<<&x<<endl;
cout<<"El valor de la direccion que apunta la variable x es:"<<*x<<endl;
cout<<"La variable x ocupa "<<sizeof(x)<<" bytes en la memoria"<<endl;
cout<<"La variable y contiene el valor de:"<<y<<endl;
cout<<"La variable y esta ubicado en la siguiente direccion:"<<&y<<endl;
cout<<"El valor de la direccion que apunta la variable y es:"<<*y<<endl;
cout<<"La variable y ocupa "<<sizeof(y)<<" bytes en la memoria"<<endl;
getch();
}
