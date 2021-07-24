#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<stdio.h>
#include <ctype.h>
#include <math.h>

main(){
char a1=196,a2=179,a3=193,a4=194,a5=191,a6=180,a7=195,a8=217;
char a9=218,a10=192,a11=197;
int y;

for(int h=1;h<=79;h++){gotoxy(h,5);cout<<a1;gotoxy(h,9);cout<<a1;gotoxy(h,7);cout<<a1;}
y=5;
gotoxy(1,y);cout<<a9;gotoxy(13,y);cout<<a4;gotoxy(40,y);cout<<a4;gotoxy(50,y);cout<<a4;gotoxy(63,y);cout<<a4;gotoxy(79,y);cout<<a5;
y++;
gotoxy(1,y);cout<<a2;gotoxy(13,y);cout<<a2;gotoxy(40,y);cout<<a2;gotoxy(50,y);cout<<a2;gotoxy(63,y);cout<<a2;gotoxy(79,y);cout<<a2;
y++;
gotoxy(1,y);cout<<a7;gotoxy(13,y);cout<<a3;gotoxy(40,y);cout<<a11;gotoxy(50,y);cout<<a3;gotoxy(63,y);cout<<a3;gotoxy(79,y);cout<<a6;
y++;
gotoxy(1,y);cout<<a2;gotoxy(40,y);cout<<a2;gotoxy(79,y);cout<<a2;
y++;
gotoxy(1,y);cout<<a10;gotoxy(40,y);cout<<a3;gotoxy(79,y);cout<<a8;

y=6;
gotoxy(4,y);cout<<" CODIGO";
gotoxy(16,y);cout<<"TIPO Y NUM DE DOCUMENTO";
gotoxy(44,y);cout<<"CIF";
gotoxy(54,y);cout<<"UNIDAD";
gotoxy(65,y);cout<<"CAN COMPRADA";
y=y+2;
gotoxy(3,y);cout<<"\tGRUPO PRODUCTO";
gotoxy(42,y);cout<<"\tPRODUCTO ESPECIFICO";
getch();
}