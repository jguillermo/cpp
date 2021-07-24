/*CURSO: COMPUTACION I
EJEMPLO: MANEJO DE MATRICES
PROF: Maximo Obregon Ramos
Grupo: http://es.groups.yahoo.com/group/curso_computacion1
Fecha: 16 de Mayo 2006
Tarea: Se sugiere implementar todas las demas funciones relacionadas a las matrices
Puede empezar con lo siguiente:
0) Revisar este Programa
1) Corregir las variables adecuadamente para que funcione correctamente la opcion '1' y 'A'
2) Implementar opcion [S]: Para salir
3) Implementar opcion [B]: Generar automaticamente la matriz B aleatoria
4) Implementar opcion [5]: Multiplicar matrices
5) Implementar opcion [C]: Ordenar Matriz A en C de menor a mayor siguiendo las filas izquierda a derecha
6) Implementar opcion [D]: Ordenar Matriz A en C de menor a mayor siguiendo las columnas de arriba abajo
7) Implementar opcion [E]: Invertir la matriz A en C con un espejo vertical en el centro de A.
8) Implementar opcion [F]: copiar matriz A en C y ordenar solo la diagonal principal
9) Implementar opcion [G]: Ordenar Matriz A en C de mayor a menor siguiendo
								   todas las diagonales paralela a la principal de arriba abajo
10) Implementar opcion [H]: Hallar la inversa de Matriz A en C, use el algoritmo dado en clase
11) Implementar opcion [I]: Hallar la determinante de A, use el algoritmo dado en clase
12) Implementar opcion [J]: Hallar el producto A*B en C, use el algoritmo dado en clase
13) Implementar opcion [K]: Pasar C en A
14) Implementar opcion [L]: Pasar A en B
15) Implementar opcion [M]: Generar una matriz identidad en A
*/

#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#define max 10

leer_matriz(int &n,float m[max][max]);
mostrar_matriz(int n,float m[max][max]);
sumar(int oa,float a[max][max],int ob,float b[max][max],int &oc,float c[max][max]);
restar(int oa,float a[max][max],int ob,float b[max][max],int &oc,float c[max][max]);
multiplicar(int oa,float a[max][max],int ob,float b[max][max],int oc,float c[max][max]);
genera_matriz(int &n,float m[max][max]);
lineas(int n);

int  menu();

int ancho=7;
main()
{
randomize();
int na,nb,nc,op;
float a[max][max],b[max][max],c[max][max];
clrscr();
do
 {op=menu();
 switch (op)
  {
  case '1': leer_matriz(na,a);break;
  case '2': leer_matriz(nb,b);break;
  case '3': sumar(na,a,nb,b,nc,c);break;
  case '4': restar(na,a,nb,b,nc,c);break;
  case '5': multiplicar(na,a,nb,b,nc,c);break;
  case '6': mostrar_matriz(na,a);break;
  case '7': mostrar_matriz(nb,b);break;
  case '8': mostrar_matriz(nc,c);break;
  case 'A':genera_matriz(na,a);break;
  case 'B':genera_matriz(nb,b);break;
  }
 }while (op!='S');

}


int menu()
 {
  int op;
  gotoxy(1,24);clreol();
  cout<<"[1]Leer A  [2]Leer B  [3]C=A+B [4]C=A-B [5]C=A*B [6] Ver A  [7] Ver B [8] Ver C ";
  gotoxy(1,25);clreol();
  cout<<"[A]Generar A [B]Generar B [C]...  [D] .. [E] ... [S] Salir ";
  do
  {op=toupper(getch());
   } while (!(((op>='1')&&(op<='9'))||((op>='A')&&(op<='Z'))));
  gotoxy(1,24);clreol();
  return op;
 }


lineas(int n)
{int i;
 char si=218,sd=191,id=217,ii=192,cv=179,ch=196;
   for (i=1;i<=(2*n-1);i++)
    {gotoxy(40-(ancho*n+1*(n+1))/2,12-(2*n-1)/2+(i-1));
     cout<<cv;
     gotoxy(40+(ancho*n+1*(n+1))/2,12-(2*n-1)/2+(i-1));
     cout<<cv;
    }
gotoxy(40-(ancho*n+1*(n+1))/2,12-(2*n-1)/2-1);cout<<si;
gotoxy(40-(ancho*n+1*(n+1))/2,12-(2*n-1)/2+(i-1));cout<<ii;
gotoxy(40+(ancho*n+1*(n+1))/2,12-(2*n-1)/2-1);cout<<sd;
gotoxy(40+(ancho*n+1*(n+1))/2,12-(2*n-1)/2+(i-1));cout<<id;
}

leer_matriz(int &n,float m[max][max])
{
int i,j;
clrscr();
gotoxy(1,25);cout<<"Ingrese orden Matriz:";cin>>n;
lineas(n);
   for (i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     {
     gotoxy(1,25);clreol();
     gotoxy(1,25);cout<<"Ingrese Posicion ("<<i<<","<<j<<")=";
     cin>>m[i][j];
     gotoxy(40-(ancho*n+1*(n+1))/2+(j-1)*ancho+j,12-(2*n-1)/2+2*(i-1));
     cout.width(ancho);cout<<m[i][j];
     }

}

mostrar_matriz(int n,float m[max][max])
{
int i,j;
clrscr();
lineas(n);
   for (i=1;i<=n;i++)
     for(j=1;j<=n;j++)
     {
     gotoxy(40-(ancho*n+1*(n+1))/2+(j-1)*ancho+j,12-(2*n-1)/2+2*(i-1));
     cout.width(ancho);cout.precision(2);cout<<m[i][j];

     }


}

sumar(int oa,float a[max][max],int ob,float b[max][max],int &oc,float c[max][max])
{

 int i,j;
 if(oa==ob)
 {  for (i=1;i<=oa;i++)
     for(j=1;j<=oa;j++)
       c[i][j]=a[i][j]+b[i][j];
   oc=oa;
 }
 else
 {  cout<<"No se pueden sumar.";getch();
 }
}

restar(int oa,float a[max][max],int ob,float b[max][max],int &oc,float c[max][max])
{

 int i,j;
 if(oa==ob)
 {  for (i=1;i<=oa;i++)
     for(j=1;j<=oa;j++)
       c[i][j]=a[i][j]-b[i][j];
   oc=oa;
 }
 else
 {	 cout<<"No se pueden restar.";getch();
 }
}

genera_matriz(int &n,float m[max][max])
{
int i,j;
clrscr();
gotoxy(1,25);cout<<"Ingrese orden Matriz:";cin>>n;
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
   m[i][j]=random(100)+1.0*(random(10)+1)/100;
mostrar_matriz(n,m);
}
multiplicar(int oa,float a[max][max],int ob,float b[max][max],int oc,float c[max][max])
{
  if(oa==ob)
  {for(int i=1;i<=oa;i++)
    for(int j=1;j<=oa;j++)
    	{ c[i][j]=0;
        for(int k=1;k<=oa;k++)
           c[i][j]+=a[i][k]*b[k][i];
      }
   oc=oa;
  }
  else
  {  cout<<"No se pueden multiplicar"; getch();
  }
}
