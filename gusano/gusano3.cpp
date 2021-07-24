#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
pausa(int x);
tecla(char &a,int &d);
direccion(int d, int&x, int&y);
dibujar(int ptos, int n[100][100]);
detener(int x, int y, char &a);
marco();
gusano(int cuerpo, int velocidad, int n[100][100]);
comida(int n[100][100], int &xc, int&yc);


main()
{
 randomize();
 char a,d;
 int v,b,c,m,n[100][100];

 clrscr();
 gotoxy(1,1);cout<<"Ingrese la velocidad entre 1 y 9 :";cin>>b;
 gotoxy(1,3);cout<<"Ingrese el cuerpo :";cin>>c;
 do{clrscr();
 v=10-b;
 gusano(c,10*v,n);

 getch();}while(1);
 getch();
}

gusano(int cuerpo, int velocidad, int n[100][100])
{  clrscr();
 char a;
 int d1=1,d2=1,i,j=0,m[1000], ptos=0, comio=0;
 int k1,k2,k3,xi,yi,xf,yf,xc,yc;

 for(k1=1;k1<=cuerpo+1;k1++)
 {m[k1]=1;}

 for(k2=1;k2<=26;k2++)
   for(k3=1;k3<=81;k3++)
    n[k2][k3]=0;

 xf=1; xi=xf+cuerpo+1; yi=12; yf=12; i=2+cuerpo;
 marco();
 comida(n,xc,yc);
 do
 {
   tecla(a,d1);

   if(xi==xc && yi==yc)
    {comida(n,xc,yc); ptos=ptos+5; comio=1;     }

   direccion(d1,xi,yi);
   if(n[xi][yi]==1)
    a=27;
   if(n[xi][yi]==0)
    n[xi][yi]=1;dibujar(ptos,n); pausa(velocidad);

   if(comio==0) {direccion(d2,xf,yf); n[xf][yf]=2;}
   m[i]=d1;
   if(comio==0) d2=m[i-cuerpo+j];
   if(comio==1) cuerpo++;
   detener(xi,yi,a);

  comio=0;
  i++;
  if(i==198) {i=2+cuerpo, j=196-cuerpo;}
  if(i==2+2*cuerpo) j=0;
  gotoxy(40,25); cout<<i*100;
  }while(a!=27);

}




pausa(int x)
{int y;
 for(int i=1;i<=x;i++)
  for(int j=1;j<=pow(10,4);j++)
  y=1;
}

tecla(char &a,int &d)
{
  if (kbhit())
 	 {a=getch();
     if(!a)
       {a=getch();
       switch (a)
        {case 77: d=1; break;
         case 72: d=2; break;
			case 75: d=3; break;
         case 80: d=4; break;
        }
       }
    }
}

direccion(int d,int &x,int &y)
{
  switch(d)
  {	case 1: x++;  break;
      case 2: y--;  break;
      case 3: x--;  break;
      case 4: y++;  break;
  }
}

dibujar(int ptos, int n[100][100])
{
  int i,j;
  for(i=2;i<=79;i++)
   for(j=2;j<=23;j++)
   {
     if(n[i][j]==0)  {continue;}
     if(n[i][j]==1)  {gotoxy(i,j); cout<<"*";}
     if(n[i][j]==2)  {gotoxy(i,j); cout<<" "; n[i][j]=0; }
     if(n[i][j]==3)  {gotoxy(i,j); cout<<"o"; n[i][j]=0;}
   }
  gotoxy(15,25); cout<<ptos;
}

marco()
{int i,j;
  for(i=2;i<=79;i++)
   {gotoxy(i,1); cout<<"Ä"; gotoxy(i,24); cout<<"Ä";}
  for(j=2;j<=23;j++)
   {gotoxy(1,j); cout<<"³"; gotoxy(80,j); cout<<"³";}
  gotoxy(1,1);   cout<<"Ú"; gotoxy(1,24); cout<<"À";
  gotoxy(80,1);  cout<<"¿"; gotoxy(80,24); cout<<"Ù";
  gotoxy(3,25);  cout<<"Puntaje:";
  gotoxy(70,25); cout<<"DGCP";
}


detener(int x,int y, char &a)
{
 if(x>=80){a=27; gotoxy(40,12); cout<<"FIN";}
 if(x<=1) {a=27; gotoxy(40,12); cout<<"FIN";}
 if(y<=1) {a=27; gotoxy(40,12); cout<<"FIN";}
 if(y>=24){a=27; gotoxy(40,12); cout<<"FIN";}
}

comida(int n[100][100], int &xc, int&yc)
{
 xc=random(77)+2; yc=random(22)+2;
 n[xc][yc]=3;
}


