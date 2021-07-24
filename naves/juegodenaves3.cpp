#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
#include <ctype.h>
#include <stdio.h>
int a=1,b=1;
marco();
nave(int x,int y,int xe,int ye);
cnave(int x,int y);
naveenemiga(int x,int y);
cnaveenemiga(int x,int y);
disparo(int x,int y);
disparoe(int x,int y);
pausa(int t);
moveenemigo(int x,int y,int &xf,int &yf);
tecla(int &x,int &y,int &d,int &wh,char &f);
//******************************
//*****************************
main(){ randomize();
 marco();
 int i,z,xme=22,yme=22,sw=0;
 char fle=77,f=49;
 int dir,ye=2,xe=2,d=0;
 int x,y,xf=5,yf=7;
 x=random(60)+5;
 y=random(8)+5;
 for(;;) {
 z=random(6);
moveenemigo(x,y,xf,yf);
   x=xf;y=yf;
naveenemiga(xf,yf);
if(z==3)disparoe(x,y);
pausa(3);
cnaveenemiga(xf,yf);
     tecla(xme,yme,d,sw,f);
   if(xme<=4)xme=4;if(xme>=77)xme=77;
   if(yme<=3)yme=3;if(yme>=22)yme=22;
    if(f!=49){    xe=xme;ye=yme;
              switch(f)
             {case '8': ye++; break;
              case '5':  ye--;break;
              case '4':  xe++;break;
              case '6':   xe--;break;
             }  f=49;}
      gotoxy(4,4);cout<<xme<<yme<<d<<sw<<xe<<ye<<f;
    if(sw==1){nave(xme,yme,xe,ye);sw=0;}
     if(xme==xf&&d==1){cout<<"\a";}
     if(xme==xf-1&&d==1){cout<<"\a";}
     if(xme==xf+1&&d==1){cout<<"\a";}
    if(d==1){disparo(xme,yme);d=0;}
}
}
//**************************************
marco(){
 int i,j;
char h=177,v=177;
  for(i=2;i<=79;i++)
   {gotoxy(i,1); cout<<h; gotoxy(i,24); cout<<h;}
  for(j=1;j<=24;j++)
   {gotoxy(2,j); cout<<v; gotoxy(79,j); cout<<v;}
}
//*********************************************************
nave(int x,int y,int xe,int ye){
char c=202,du=188,dd=187,iu=200,id=201,cn=206,co=205;
 cnave(xe,ye);
                          gotoxy(x,y-1);cout<<c;
gotoxy(x-1,y);cout<<iu;    gotoxy(x,y);cout<<cn;     gotoxy(x+1,y);cout<<du;
gotoxy(x-1,y+1);cout<<id;                              gotoxy(x+1,y+1);cout<<dd;
                    gotoxy(x,y+1);cout<<co;
}
//*************************
cnave(int x,int y){
                            gotoxy(x,y-1);cout<<" ";
gotoxy(x-1,y);cout<<" ";    gotoxy(x,y);cout<<" ";     gotoxy(x+1,y);cout<<" ";
gotoxy(x-1,y+1);cout<<" ";                              gotoxy(x+1,y+1);cout<<" ";
                    gotoxy(x,y+1);cout<<" ";
}
//**************************
naveenemiga(int x,int y){
char du=188,iu=200,cn=219,co=205;
                          gotoxy(x,y-1);cout<<co;
gotoxy(x-1,y);cout<<iu;    gotoxy(x,y);cout<<cn;     gotoxy(x+1,y);cout<<du;
}
//*******************
cnaveenemiga(int x,int y){
                          gotoxy(x,y-1);cout<<" ";
gotoxy(x-1,y);cout<<" ";    gotoxy(x,y);cout<<" ";     gotoxy(x+1,y);cout<<" ";
}
 //*****************************
pausa(int t){
 for(int j=1;j<=t*1000;j++){gotoxy(80,24);cout<<"_";}
}
//*********************************************************
disparo(int x,int y){
char dis=179;
for(int rayo=y-2;rayo>=2;rayo--){gotoxy(x,rayo);cout<<dis;}
pausa(3);
for(int rayo=y-2;rayo>=2;rayo--){gotoxy(x,rayo);cout<<" ";}
}
//*********************************************************
disparoe(int x,int y){
char dis=179;
for(int rayo=y;rayo<=23;rayo++){gotoxy(x,rayo);cout<<dis;}
pausa(1);
for(int rayo=y;rayo<=23;rayo++){gotoxy(x,rayo);cout<<" ";}
}
//*******************************
moveenemigo(int x,int y,int &xf,int &yf){
int aa;
xf=x;yf=y;
aa=random(4);
if(x==75){a=-1;}
if(x==5){a=+1;}
if(y==4){b=1; }
if(y==15){b=-1; }
if(aa==1){yf=yf+b;}
xf=xf+a;
}
//*************************************************
tecla(int &x,int &y,int &d,int &wh,char &f)
{char ab;
wh=0;
  if (kbhit())
 	 {ab=getch();
     if(!ab)
       {wh=1;ab=getch();
       switch (ab)
        {case 77:f=54; x++; break;
         case 72:f=56; y--; break;
			case 75:f=52; x--; break;
         case 80:f=53; y++;d=1; break;
        }
       }
    }
}
//****************