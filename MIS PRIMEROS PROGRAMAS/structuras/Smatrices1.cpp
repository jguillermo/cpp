//CURSO: COMPUTACION I
//EJEMPLO: MANEJO DE MATRICES USANDO ESTRUCTURAS
//PROF: Maximo Obregon Ramos
//Grupo: http://es.groups.yahoo.com/group/curso_computacion1
//Fecha: Sabado, 13 Agosto 2005
//Observe: En este caso el programa anterior en base solamente a
//        arreglos ha sido modificado y se han implementado nuevas
//        caracteristicas.
//         Fijese como cambia la notacion usando estructuras
//        y a su vez note como se reduce las definicion y el uso
//        de las funciones.
//Tarea:   Implemente todas las demas operaciones planteadas
//	   	  anteriormente

#include <iostream.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#define max 10
struct matriz
   {int f,c;
    float m[max][max];
    char nombre;
   };

leer_matriz(matriz &p);
mostrar_matriz(matriz p);
sumar(matriz p,matriz q,matriz &r);
restar(matriz p,matriz q,matriz &r);
genera_matriz(matriz &p);
limpiar_menu();
pintar_barras(matriz p);
char  menu();
int ancho=7;

main()
{
randomize();
int na,nb,nc;
char op;
matriz a,b,c;
a.nombre='A';b.nombre='B';c.nombre='C';
clrscr();
do
 {op=menu();
 switch (op)
  {
  case '1': leer_matriz(a);break;
  case '2': leer_matriz(b);break;
  case '3': sumar(a,b,c);break;
  case '4': restar(a,b,c);break;
  case '6': mostrar_matriz(a);break;
  case '7': mostrar_matriz(b);break;
  case '8': mostrar_matriz(c);break;
  case 'A':genera_matriz(a);break;
  case 'B':genera_matriz(b);break;
  }
 }while (op!='S');
}



char menu()
 {
  int op;
  gotoxy(30,1);cout<<"PROGRAMA DE MATRICES";
  limpiar_menu();
  gotoxy(1,23);
  cout<<"[1]Leer A  [2]Leer B  [3]C=A+B [4]C=A-B [5]C=A*B [6] Ver A  [7] Ver B [8] Ver C ";
  gotoxy(1,24);
  cout<<"[A]Genera A [B]Genera B [C]...  [D] .. [E] ... [F] .... ";
  gotoxy(1,25);
  cout<<"[H].... [I]... B [J]...  [K] .. [L] ... [S] Salir ";
  op=toupper(getch());
  return op;
 }


limpiar_menu()
{
  gotoxy(1,23);clreol();
  gotoxy(1,24);clreol();
  gotoxy(1,25);clreol();
}

pintar_barras(matriz p)
{int i,j;
 char si=218,sd=191,id=217,ii=192,cv=179,ch=196,nulo=155;
 if (p.f==0)
   {gotoxy(40-(ancho*p.c+1*(p.c+1))/2,12-(2*p.f-1)/2-1);
    cout<<p.nombre<<"=["<<nulo<<"]";
   }
  else
   {for (i=1;i<=(2*p.f-1);i++)
     {gotoxy(40-(ancho*p.c+1*(p.c+1))/2,12-(2*p.f-1)/2+(i-1));
      cout<<cv;
      gotoxy(40+(ancho*p.c+1*(p.c+1))/2,12-(2*p.f-1)/2+(i-1));
      cout<<cv;
     }
	 gotoxy(40-(ancho*p.c+1*(p.c+1))/2,12-(2*p.f-1)/2-1);cout<<si;
	 gotoxy(40-(ancho*p.c+1*(p.c+1))/2,12-(2*p.f-1)/2+(i-1));cout<<ii;
	 gotoxy(40+(ancho*p.c+1*(p.c+1))/2,12-(2*p.f-1)/2-1);cout<<sd;
	 gotoxy(40+(ancho*p.c+1*(p.c+1))/2,12-(2*p.f-1)/2+(i-1));cout<<id;
	 gotoxy(40-(ancho*p.c+1*(p.c+1))/2-2,12);cout<<p.nombre<<"=";
   }
}


leer_matriz(matriz &p)
{
int i,j;
clrscr();
gotoxy(30,1);cout<<"PROGRAMA DE MATRICES";
gotoxy(1,24);cout<<"Ingrese numero de filas:";cin>>p.f;
gotoxy(1,25);cout<<"Ingrese numero de columnas:";cin>>p.c;
pintar_barras(p);
   for (i=1;i<=p.f;i++)
     for(j=1;j<=p.c;j++)
     {limpiar_menu();
      gotoxy(1,25);cout<<"Ingrese Posicion ("<<i<<","<<j<<")=";
      cin>>p.m[i][j];
      gotoxy(40-(ancho*p.c+1*(p.c+1))/2+(j-1)*ancho+j,12-(2*p.f-1)/2+2*(i-1));
      cout.width(ancho);cout<<p.m[i][j];
     }
}

mostrar_matriz(matriz p)
{
int i,j;
clrscr();
pintar_barras(p);
   for (i=1;i<=p.f;i++)
     for(j=1;j<=p.c;j++)
     {
     gotoxy(40-(ancho*p.c+1*(p.c+1))/2+(j-1)*ancho+j,12-(2*p.f-1)/2+2*(i-1));
     cout.width(ancho);cout.precision(3);cout<<p.m[i][j];
     }
}

sumar(matriz p,matriz q,matriz &r)
{
int i,j;
if (((p.f)==(q.f))&&((p.c)==(q.c)))
  {
   for (i=1;i<=p.f;i++)
     for(j=1;j<=p.c;j++)
       r.m[i][j]=p.m[i][j]+q.m[i][j];
   r.f=p.f;
   r.c=p.c;
  }
  else
  {r.f=0;
   r.c=0;
  }

}

restar(matriz p,matriz q,matriz &r)
{
int i,j;
if (((p.f)==(q.f))&&((p.c)==(q.c)))
  {
   for (i=1;i<=p.f;i++)
     for(j=1;j<=p.c;j++)
       r.m[i][j]=p.m[i][j]-q.m[i][j];
   r.f=p.f;
   r.c=p.c;
  }
  else
  {r.f=0;
   r.c=0;
  }
}


genera_matriz(matriz &p)
{
int i,j;
clrscr();
gotoxy(30,1);cout<<"PROGRAMA DE MATRICES";
gotoxy(1,24);cout<<"Ingrese numero de filas:";cin>>p.f;
gotoxy(1,25);cout<<"Ingrese numero de columnas:";cin>>p.c;
for(i=1;i<=p.f;i++)
 for(j=1;j<=p.c;j++)
   p.m[i][j]=random(1000)+1.0*(random(100)+1)/100;
mostrar_matriz(p);
}
