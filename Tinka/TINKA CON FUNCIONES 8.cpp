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
tinka();
double contrasena();
titulo();
presentacion();
probabilidades();
genera(int f[8],int mu[567][7],int i);

aciertos(int n[41],int f[8],int aci[8],int nums);
juganadora(int n[41],int nums);
mostrar(int mu[567][7]);
menu();

estadisticas(int n[41],int f[8],int aci[8],int nums);
main(){randomize(); menu();}
//***************************************************************
mensaje(int k){
gotoxy(6,19);
if(k==6)cout<<"ganaste la tinka";
 if(k<6&&k>1)cout<<"obtubiste "<<k<<" haciertos  ";
 if(k==1)cout<<"obtubiste 1 hacierto " ;
 if(k<1)cout<<"obtubiste 0 haciertos  ";

 }
 //**************************************
llenado(int k[8]){ clrscr(); titulo();
for(int i=1;i<=6;i++){mayormenor(k,i);repite(k,i);}


}
//******************************************************
numjuego(int n[41]){  int x,y,uxi;
//for(int f=1;f<=40;f++)n[f]=f+15;
for(int f=1;f<=40;f++)n[f]=f;
for(int ca=1;ca<=3000;ca++){ x=random(40)+1;y=random(40)+1;
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
     if(k1>=1)ordenar(r);

if(k1>=1){gotoxy(30,19);for (int hu=1;hu<=k1;hu++){cout<<"      "<<r[hu];}}
 mensaje(k1);
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
tinka(){
 char op;
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
     r[j]=aux;}}
     }
}

//*************************
menu(){
char op1;
double cont;
/*do{cont=contrasena();}while(cont!=0);
presentacion();*/
for(;;){
clrscr();
titulo();
gotoxy(30,12);cout<<"1.- Tinka";
gotoxy(30,14);cout<<"2.- Probabilidades";
op1=getch();
switch(op1)
{case '1':tinka();break;
 case '2':probabilidades();break;
}
clrscr();
}
}
//**************************
int numero(){
double nums;
do{gotoxy(17,12);cout<<"ingrese numero de jugadas  ";cin>>nums;
if(nums>20000){gotoxy(12,17);cout<<"Maximo 20000 jugadas";gotoxy(1,12);clreol();}
if(nums<1){gotoxy(12,17);cout<<"Minimo    1   jugada";gotoxy(1,12);clreol();}


}while(nums>40000||nums<1);
return nums;}
//****************************
/****************************************************/
//*****************************************************





probabilidades(){ clrscr();
int nums,i;char op;
nums=numero();
int n[41],f[8],aci[8],mu[267][7];
for(int h=0;h<8;h++)aci[h]=0;
numjuego(n);



         for(i=1;i<=nums;i++){
         genera(f,mu,i);
         aciertos(n,f,aci,nums,mu);

          }

estadisticas(n,f,aci,nums);
do{op=getch();
switch(op){ clrscr();

case '2':estadisticas(n,f,aci,nums);break;
case '1':juganadora(n,nums);mostrar(mu);

}while(op!='s');




}
//************************************
mostrar(int mu[567][7]){




gotoxy(1,10);cout<<"  ";
if (nums<=566)num=nums;
for(int i=1;i<=num;i++)
   {
        cout<<" "<<i<<") ";
        for (int j=1;j<=6;j++)
       {cout<<f[i][j]<<"   ";}
        cout<<"\t   ";
   }


}
//*******************************************************
juganadora(int n[41],int nums){
int num=566; clrscr();
if (nums<=566)num=nums;
gotoxy(20,2);cout<<"Jugada ganadora";
for (int h=1;h<=6;h++)cout<<"  "<<n[h];
 cout<<"\n\n\tse jugaron con "<<nums<<" numeros ";
cout<<"\n\n\taqui se muestran las primeras "<<num<<" jugadas";
cout<<"\n\n\tpresione cualquier tecla para ver estadisticas\n\n\n";


}
//////////////////////***************************
//*************************************
aciertos(int n[41],int f[8],int aci[8],int nums){
int busca=0;

       for (int i=1;i<=6;i++)
           {for (int j=1;j<=6;j++)
                {if (f[i]==n[j])busca++;} }




        if(busca==0)aci[0]++;if(busca==3)aci[3]++;
         if(busca==1)aci[1]++;if(busca==4)aci[4]++;
         if(busca==2)aci[2]++;if(busca==5)aci[5]++;
         if(busca==6)aci[6]++;

}
//*********************************

//*******************************
genera(int f[8],int mu[567][7],int i){
int x,y,uxi,n[41],c;

     numjuego(n);
         for(int j=1;j<=6;j++)
          {f[j]=n[j];
           if(i<=566)mu[i][j];
          }

}
//************************************
estadisticas(int n[41],int f[8],int aci[8],int nums){
clrscr();
int num=566;
if (nums<=566)num=nums;
gotoxy(8,5);cout<<"Jugada ganadora";
for (int h=1;h<=6;h++)cout<<"  "<<n[h];
gotoxy(1,8);
 for(int hf=0;hf<=6;hf++)cout<<"  con "<<hf<<" aciertos   "<<aci[hf]<<endl;
cout<<"\n\tse jugaron con "<<nums<<" numeros ";

}
















