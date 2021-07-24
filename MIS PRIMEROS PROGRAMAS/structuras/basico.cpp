//ejemplo basico sobre estructuras
//Realice un seguimiento a cada una de las lineas
//Y calcule mentalmente cuales seran los nuevos valores que van tomando
//las variables

#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#define max 10

struct Spunto
{float x,y,z;
};


struct Smatriz
{int nf,nc;
 float m[max][max];
};

void main()
{
 randomize();
 Spunto p1,p2,p3[20];
 int m[10],n[10],i;
 p1.x=5; p1.y=7; p1.z=8; p2=p1;
 cout<<"La componente x de p2 es "<<p2.x<<endl;

 Smatriz a,b,c,d[5];
 a.nf=3;a.nc=1;a.m[1][1]=10;a.m[2][1]=5;
 b=a; b.m[2][1]=10;
 cout<<"el elemento a(2,1) es "<<a.m[2][1]<<endl;
 cout<<"el elemento b(2,1) es "<<b.m[2][1]<<endl;
 m[1]=6;m[6]=6;

// n=m;Esto no funciona
 n[1]=5;
 cout<<"el elemento m(1) es "<<m[1]<<endl;
 cout<<"el elemento n(1) es "<<n[1]<<endl;
 for (i=1;i<=10;i++)
	{p3[i].x=i;
    p3[i].y=-i;
    p3[i].z=random(i);
   }
cout<<"Presione una tecla para ver los valores cargados a las variables"<<endl;
getch();
cout<<"Elemento:       x   y   z"<<endl;
 for (i=1;i<=10;i++)
   cout<<"       "<<i<<"        "<<p3[i].x<<"  "<<p3[i].y<<"  "<<p3[i].z<<endl;
getch();
 }


