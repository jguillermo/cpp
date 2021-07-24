#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
#include <ctype.h>
#include <mbstring.h>


pintar(int j,int h,int r);
int computadora(int j,int r) ;
char endgame(int q);
pause();
int fichas();
int retiros(int jj);



main(){
int jj,rr,j,r,y=5,h=0;
char op,opf;
randomize();
do{
      jj=fichas();
      rr=retiros(jj);
      do{   clrscr();
           j=jj;r=rr;
           pintar(j,h,r);
                   do{        //int ff;cin>>ff;
                              op=toupper(getch());
                                 switch(op)
                                 {
                                  case '1':{j=j-1;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  case '2':{if(2>r ||j==1 )break;j=j-2;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  case '3':{if(3>r ||j==1 )break;j=j-3;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  case '4':{if(4>r ||j==1 )break;j=j-4;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  case '5':{if(5>r ||j==1 )break;j=j-5;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  case '6':{if(6>r ||j==1 )break;j=j-6;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  case '7':{if(7>r ||j==1 )break;j=j-7;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  case '8':{if(8>r ||j==1 )break;j=j-8;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  case '9':{if(9>r ||j==1 )break;j=j-9;h=1;pintar(j,h,r);j=computadora(j,r);break;}
                                  //case 'c':{opf='c';break;}
                                  //case 'r':{opf='r';break;}
                                }
                                if(j==-15){j=1;opf=endgame(j);break;}
                                if(j==0){opf=endgame(j);break;}
                                 //if(opf='c'){opf='c';break;}
                                 //if(opf='r'){opf='r';break;}

               }while(y==5);
                 if(opf='r')break;
          }while(opf='c');
}while(opf='r');


}


//funciones
pintar(int j,int h,int r){

clrscr();
 if(h==1){gotoxy(35,5);cout<<"COMPUTADORA";}
   if(h==0){gotoxy(35,5);cout<<"TU TURNO";}
 gotoxy(5,3);cout<<j<<"  "<<r<<"   ";


  cout<<"\n\n\n\n\n\n\n\n" ;
 int k=1;
for (int i=1;i<=j;i++)
     {cout<<" * ";
      if(i==25*k)
      {cout<<"\n\n";k++;}
      }
     if(h==1 && j>=1)pause(); }




int computadora(int j,int r)
{
  int t[100];
  int x,i,l,h,c,m;
  m=j/r;
  x=random(r)+1;
  for(i=1;i<=m;i++)
      {t[i]=1+(r+1)*i;}
  if (j==0){return c=0;}

  for( l=1;l<=m;l++){
      if(j==t[l])
      {c=j-x;h=0;pintar(c,h,r);
      return c=j-x;}}

  for(int l=1;l<=m;l++){
      if(j>=t[l]+1 && j<=t[l+1]-1)
      {c=t[l];h=0;pintar(c,h,r);
      return c=t[l];}}
if(j>1 && j<t[1])
{h=0;c=1;pintar(c,h,r);return c=1;}
if(j==1){return c=-15;}


}


char endgame(int q){
char tt;

 clrscr();
if(q==1)
{gotoxy(35,9);cout<<"GANASTE "<<endl;}
if(q==0)
{gotoxy(35,9);cout<<"PERDISTE "<<endl;}
cout<<"\n\n\n\tpara continuar c  "<<endl;
cout<<"\tpara reiciciar r";
tt=toupper(getch());
return tt;
}

pause(){
gotoxy(70,1);cout<<"pensando";
for (int g=1;g<=3;g++)
{ int gg;
  gg=5;//gg=1975;
 for (int i=72;i<=75;i++)
           {for (int j=0;j<gg;j++)
                {gotoxy(i,3);cout<<" *";}}
       for (int s=3;s<=6;s++)
           {for (int j=0;j<gg;j++)
                {gotoxy(75,s);cout<<"  ";
                 gotoxy(75,s+1);cout<<"*";}}
       for (int k=75;k>=72;k--)
           {for (int h=0;h<gg;h++)
                {gotoxy(k,7);cout<<"* ";}}
       for (int x=7;x>=4;x--)
           {for (int j=0;j<gg;j++)
                {gotoxy(72,x);cout<<" ";
                 gotoxy(72,x-1);cout<<"*";}}}}






 int fichas(){
 int jj;
 clrscr();
 do{
      gotoxy(1,10);clreol();
     gotoxy(10,10);cout<<"NUMERO DE FICHAS = ";cin>>jj;
     if(jj>=200){gotoxy(10,18);cout<<"Maximo 200 "; }
     if(jj<5){gotoxy(10,20);cout<<"El numero debe ser mayor igual a 5 "; }
     }while(jj<5 ||  jj>=201);
    return jj;}

 int retiros(int jj){
     int ll=0;
     int rr;
     clrscr();
     do{
     gotoxy(1,10);clreol();
     gotoxy(10,10);cout<<"NUMERO DE FICHAS A RETIRAR = ";cin>>rr;
     if(rr<10 && rr+1>=jj){gotoxy(10,18);cout<<"Maximo  "<<(jj-2);ll=1;}

     if(rr>9){gotoxy(10,20);cout<<"Maximo  9"; }
       if(rr>9 && ll==1){gotoxy(1,20);clreol();}
     if(rr<3){gotoxy(10,22);cout<<"El numero debe ser mayor igual a 3";}

     }while(rr<3 ||   (rr+1>=jj)  || rr>9) ;
     return rr;}




