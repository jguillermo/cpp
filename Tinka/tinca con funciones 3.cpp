#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ordenar(int r[8]);
mensaje(int k);
llenado(int k[8]);
numjuego(int n[41]);
resultado(int n[41],int k[8],int r[8]);
mayormenor(int k[8],int i);
repite(int k[8],int i);
ejecuta();
double contrasena();
titulo();
presentacion();
main(){randomize(); ejecuta();}
//***************************************************************
mensaje(int k){
gotoxy(6,19);
if(k==6)cout<<"ganaste la tinka";
 if(k<6&&k>1)cout<<"obtubiste "<<k<<" haciertos que son :";
 if(k==1)cout<<"obtubiste 1 hacierto que es :" ;
 if(k<1)cout<<"obtubiste 0 haciertos  ";

 }
 //**************************************
llenado(int k[8]){ clrscr(); titulo();
for(int i=1;i<=6;i++){mayormenor(k,i);repite(k,i);}


}
//******************************************************
numjuego(int n[41]){  int x,y,uxi;
//for(int f=1;f<=40;f++)n[f]=f;
for(int f=1;f<=40;f++)n[f]=f;
for(int ca=1;ca<=3000;ca++){ x=random(39)+1;y=random(39)+1;
uxi=n[x];n[x]=n[y];n[y]=uxi;}
}
//******************************************************
resultado(int n[41],int k[8],int r[8]){ int k1=0;
clrscr();    titulo();
for(int ju=1;ju<=6;ju++)r[ju]=0;
cout<<"\n\n\tTu jugada es : \n\n\n";
for(int f=1;f<=6;f++)cout<<"        "<<k[f];
cout<<"\n\n\n\n\tLa jugada ganadora es : \n\n\n";
for(int f=1;f<=6;f++)cout<<"        "<<n[f];
for (int i=1;i<=6;i++)
{for (int j=1;j<=6;j++)
      {if (k[i]==n[j]){k1=k1+1;r[i]=k[i];}}
      }
     
 mensaje(k1);
if(k1>=1&&k1<6){ordenar(r);for (int hu=1;hu<=k1;hu++){cout<<"      "<<r[hu];}}

}
//***********************************
mayormenor(int k[8],int i){ do{
       gotoxy(8,i+5);cout<<"ingrese el numero ( "<<i<<" ) =  ";cin>>k[i];
       gotoxy(1,22);clreol();
       if(k[i]>40||k[i]<1){gotoxy(34,i+5);clreol();}
       gotoxy(10,22);
       if(k[i]<1)cout<<"\a El numero debe ser mayor o igual a 1";
       if(k[i]>40)cout<<"\a El numero debe der menor o igual a 40";
       }while(k[i]>40||k[i]<1);
}
//***********************
repite(int k[8],int i){
  int a;
  do{ a=0;
      for(int j=1;j<i;j++){if(k[i]==k[j]){a=1;} }
      if(a==1)
      {gotoxy(10,22);cout<<"\aYa ingreso el numero "<<k[i]<<" por favor ingrese otro numero ";
       gotoxy(34,i+5);clreol();
       mayormenor(k,i);
      }
     }while(a==1);
}
//**************************
ejecuta(){

 double cont;
 char op;

    do{cont=contrasena();}while(cont!=0);
    presentacion();
    do{   int n[41],k[8],r[8];
    llenado(k);
    numjuego(n);
    resultado(n,k,r);
    cout<<"\n\n\n   Para salir presione S, para continuar presione cualquier tecla "; op=getch();
    }while(op!='s');

}
//**************************
double contrasena(){clrscr(); titulo();
char mi[10]={"guillermo"},co[30];
gotoxy(8,11);cout<<"ingrese contrasena =  ";gets(co);
return strcmp(co,mi);
}
//**************************
titulo(){
gotoxy(25,2);cout<<"SIMULACRO DEL JUEGO LA TINKA";
gotoxy(25,3);cout<<"----------------------------";
}
//****************************
presentacion(){
clrscr();
    titulo();
gotoxy(33,11);cout<<"UNI - PERU  2007 ";

gotoxy(20,21);cout<<"Presione cualquier tecla para continuar";
gotoxy(1,24);cout<<"programa creado por   jg_antony  ";
getch();
}
//*********************************
ordenar(int r[8]){
int j,i,aux;
for (i=1;i<6;i++)
    {for(j=i+1;j<=6;j++)
    {if(r[i]<r[j])
     {aux=r[i];
     r[i]=r[j];
     r[j]=aux;}
}
}
}















