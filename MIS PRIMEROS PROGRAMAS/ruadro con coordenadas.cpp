#include<iostream.h>
#include<conio.h>



void main(){
int i,j,s,k,h,x,ix,iy,dx,dy,y=5;
cout<<"                ingrese coordenadas\n";
cout<<"                --------------------\n ";
cout<<"Esquina superior izquierda  X   ";cin>>ix;
cout<<"Esquina superior izquierda  Y   ";cin>>iy;
cout<<"Esquina inferior derecha    X   ";cin>>dx;
cout<<"Esquina inferior derecha    Y   ";cin>>dy;
clrscr();
   do{ for (i=ix;i<=dx;i++)
           {for ( j=0;j<975;j++)
                {gotoxy(i,ix);cout<<" *";}}
       for (s=ix;s<=dy;s++)
           {for (j=0;j<975;j++)
                {gotoxy(dy,s);cout<<"  ";
                 gotoxy(dy,s+1);cout<<"*";}}
       for (k=dy;k>=ix;k--)
           {for (h=0;h<945;h++)
                {gotoxy(k,dx);cout<<"* ";}}
       for (x=dx;x>=ix;x--)
           {for (j=0;j<975;j++)
                {gotoxy(ix,x);cout<<" ";
                 gotoxy(ix,x-1);cout<<"*";}}


  }while(y=5);
    getch();
    }