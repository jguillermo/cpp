#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define max 2001
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
genera(int f[max][8]);
mostrar(int n[41],int f[max][8],int aci[8]);
menu();
aciertos(int n[41],int f[max][8],int aci[8]);
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
//****************************
probabilidades(){ clrscr();
int n[41],f[max][8],aci[8];
numjuego(n);
genera(f);
aciertos(n,f,aci);
mostrar(n,f,aci);
getch();

}
//***********************************
aciertos(int n[41],int f[max][8],int aci[8]){
int k1=0,busca[max];
  for (int k=1;k<max;k++)
       {for (int i=1;i<=6;i++)
           {for (int j=1;j<=6;j++)
                {if (f[k][i]==n[j])k1=k1+1;}
           }
       busca[k]=k1;k1=0;

       }

for (int kt=0;kt<8;kt++)aci[kt]=0;
for(int hf=1;hf<max;hf++)
    {if(busca[hf]==0)aci[0]++;if(busca[hf]==3)aci[3]++;
     if(busca[hf]==1)aci[1]++;if(busca[hf]==4)aci[4]++;
     if(busca[hf]==2)aci[2]++;if(busca[hf]==5)aci[5]++;
     if(busca[hf]==6)aci[6]++;
    }
}
//*******************************
genera(int f[max][8]){
int x,y,uxi,n[41];
int por;gotoxy(36,12);cout<<"please wait";
for (int h=1;h<max;h++)
     {por=(h*100)/max; gotoxy(40,10);cout<<por<<" % ";
     numjuego(n);
         for(int j=1;j<=6;j++)
          {f[h][j]=n[j];
          }
     }

}
//************************************
mostrar(int n[41],int f[max][8],int aci[8]){
clrscr();int i,p=1,q=4,num=566;
gotoxy(1,15);cout<<"  ";
for(int i=1;i<=num;i++)
   {
        cout<<" "<<i<<") ";
        for (int j=1;j<=6;j++)
       {cout<<f[i][j]<<"   ";}
        cout<<"\t   ";
   }
gotoxy(6,2);cout<<"\n\t\t\t\tJugada ganadora";
for (int h=1;h<=6;h++)cout<<"  "<<n[h];
cout<<endl;
for(int hf=0;hf<=6;hf++)cout<<"  con "<<hf<<" aciertos   "<<aci[hf]<<endl;
cout<<"\n\tse jugaron con "<<(max-1)<<" numeros ";
cout<<"\n\taqui se muestran las primeras "<<num<<" jugadas";
}




