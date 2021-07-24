#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
#include <ctype.h>
int vueltas();char  menu();pintar(int j,int h,int r,int v);
int computadora(int j,int r,int v);
char endgame(int q);pause(int v);int fichas();int retiros(int jj);presentacion();
instrucciones();double contrasena();juegoyou(int v,int h,int r,int &j,char &op);
juego();main(){juego();}pintar(int j,int h,int r,int v){clrscr();if(h==1)
{gotoxy(35,7);cout<<"COMPUTADORA";}if(h==0){gotoxy(35,7);cout<<"TU TURNO";}
gotoxy(2,2);cout<<"Puedes retirar maximo  "<<r<<" fichas   ";gotoxy(2,4);
cout<<"Hay "<<j<<" fichas";char imagen=15;cout<<"\n\n\n\n\n\n" ;int k=1;
for (int i=1;i<=j;i++){cout<<" "<<imagen<<" ";if(i==25*k){cout<<"\n\n";k++;}}
if(h==1&&j>=1)pause(v); }int computadora(int j,int r,int v){int h=0;int t[100];
int x,i,l,c,m;m=j/r+15;for(i=1;i<=m;i++){t[i]=1+(r+1)*i;}if(j>1 && j<t[1])
{c=1;h=0;pintar(c,h,r,v);return c=1;}for(int l=1;l<=m;l++){
if(j>=t[l]+1 && j<=t[l+1]-1){c=t[l]; h=0;pintar(c,h,r,v);return c=t[l];}}
x=random(r)+1;for( l=1;l<=m;l++){if(j==t[l]){c=j-x; h=0;pintar(c,h,r,v);
return c=j-x;}}if (j==0){return c=0;}if(j==1){return c=-15;}}
char endgame(int q){int tt;clrscr();if(q==1){gotoxy(35,9);
cout<<"GANASTE "<<endl;}if(q==0){gotoxy(35,9);cout<<"PERDISTE "<<endl;}
cout<<"\n\n\n\n\n\tpara continuar c"<<endl;cout<<"\n\tpara reiciciar r";
tt=toupper(getch());return tt;}pause(int v){gotoxy(70,1);cout<<"pensando";
for (int g=1;g<=v;g++){int gg;gg=500;for (int i=72;i<=75;i++)
{for (int j=0;j<gg;j++){gotoxy(i,3);cout<<" *";}}for (int s=3;s<=6;s++)
{for (int j=0;j<gg;j++){gotoxy(75,s);cout<<"  ";gotoxy(75,s+1);cout<<"*";}}
for (int k=75;k>=72;k--){for (int h=0;h<gg;h++){gotoxy(k,7);cout<<"* ";}}
for (int x=7;x>=4;x--){for (int j=0;j<gg;j++){gotoxy(72,x);cout<<" ";
gotoxy(72,x-1);cout<<"*";}}}}int fichas(){double jj;clrscr();do{gotoxy(1,10);
clreol();gotoxy(10,10);cout<<"NUMERO DE FICHAS = ";cin>>jj;if(jj>=200)
{gotoxy(10,18);cout<<"Maximo 200 ";}if(jj<5){gotoxy(10,20);
cout<<"El numero debe ser mayor igual a 5 "; }}while(jj<5 ||  jj>=201);
return jj;}int retiros(int jj){int ll=0;double rr;clrscr();do{gotoxy(1,10);
clreol();gotoxy(10,10);cout<<"NUMERO DE FICHAS A RETIRAR = ";cin>>rr;
if(rr<10 && rr+1>=jj){gotoxy(10,18);cout<<"Maximo  "<<(jj-2);ll=1;}
if(rr>9){gotoxy(10,20);cout<<"Maximo  9"; }if(rr>9 && ll==1){gotoxy(1,20);
clreol();}if(rr<3){gotoxy(10,22);cout<<"El numero debe ser mayor igual a 3";}}
while(rr<3 ||   (rr+1>=jj)  || rr>9);return rr;}char menu(){char op;
op=toupper(getch());return op;}presentacion(){clrscr();gotoxy(31,2);
cout<<"JUEGO DE RELAJO MENTAL";gotoxy(30,3);cout<<"------------------------";
gotoxy(30,11);cout<<"UNI - PERU  2007 ";gotoxy(20,21);
cout<<"Presione cualquier tecla para continuar";gotoxy(1,24);
cout<<"programa creado por   jg_antony  ";getch();}instrucciones()
{clrscr();gotoxy(35,2);cout<<"INSTRUCCCIONES";gotoxy(34,3);
cout<<"----------------";cout<<"\n\n\n Este juego trata de retirar fichas\n";
cout<<"\n\n gana el jugador que NO saque la ultima ficha\n";
cout<<"\n\n en cualquier momento del juego puedes pulsar ";
cout<<" C para reiniciar la jugada y\n";
cout<<"\n\n R para ingresar nuevos valores al juego\n";
gotoxy(20,21);cout<<"Presione cualquier tecla para continuar\n";getch();}
double contrasena(){clrscr();gotoxy(31,2);cout<<"JUEGO DE RELAJO MENTAL";
gotoxy(30,3);cout<<"------------------------";char busca[30],valor[30];
char con[30]={"guillermo"};gotoxy(10,10);cout<<"INGRESE CONTRASENA  =  ";
cin>>valor;strcpy(busca,valor);return strcmp(busca,con);}
juegoyou(int v,int h,int r,int &j,char &op){ op=menu();switch(op){
case '1':{if(j<=0)break;j=j-1;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
case '2':{if(2>r||j<=1)break;j=j-2;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
case '3':{if(3>r||j<=1)break;j=j-3;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
case '4':{if(4>r||j<=1)break;j=j-4;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
case '5':{if(5>r||j<=1)break;j=j-5;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
case '6':{if(6>r||j<=1)break;j=j-6;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
case '7':{if(7>r||j<=1)break;j=j-7;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
case '8':{if(8>r||j<=1)break;j=j-8;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
case '9':{if(9>r||j<=1)break;j=j-9;h=1;pintar(j,h,r,v);j=computadora(j,r,v);break;}
}if(j==-15){j=1;op=endgame(j);}if(j==0){op=endgame(j);}}juego(){double com
;char op;int v,jj,rr,j,r,h;randomize();do{com=contrasena();}while(com!=0);
presentacion();instrucciones();for(;;){h=0;jj=fichas();rr=retiros(jj);v=vueltas();
for (;;){h=0;clrscr();j=jj;r=rr;pintar(j,h,r,v);do{juegoyou(v,h,r,j,op);
if (op==67)break;}while(op!=82);if(op==82)break;}}}
int vueltas(){double jj;clrscr();do{gotoxy(1,10);clreol();gotoxy(5,10);
cout<<"TIEMPO DE ESPERA = ";cin>>jj;if(jj>=50){gotoxy(10,18);
cout<<"Maximo 50 "; }if(jj<1){gotoxy(10,20);
cout<<"El numero debe ser mayor igual a 1 ";}}while(jj<1||jj>=51);return jj;}





