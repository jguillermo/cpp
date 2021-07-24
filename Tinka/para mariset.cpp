#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<math.h>
#include <ctype.h>
int pruebaintcodigo (char num[30]);
linea();
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
 pausa();
aciertos(int n[41],int f[8],int aci[8],int nums);
juganadora(int n[41],int nums);
mostrar(int mu[567][7],int must);
menu();
aviso();
estadisticas(int n[41],int f[8],int aci[8],int nums);
caso3();
main(){randomize(); menu();}
//***************************************************************
mensaje(int k){
gotoxy(3,19);
if(k==6)cout<<"ganaste la tinka\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
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
int pruebaintcodigo(char num[30]){
int i,j,k,tam; j=1;
tam=strlen(num);
for (i=0;i<tam;i++)
{k=toupper(num[i]);
 if (k<48||k>57)j=0;
}
int numero=0;

if(j==0)numero=-1;
else {
int b;
for (b=0;b<tam;b++){
int op=toupper(num[b]);
if(op==49)numero=numero+1*pow(10,tam-b-1);
if(op==50)numero=numero+2*pow(10,tam-b-1);
if(op==51)numero=numero+3*pow(10,tam-b-1);
if(op==52)numero=numero+4*pow(10,tam-b-1);
if(op==53)numero=numero+5*pow(10,tam-b-1);
if(op==54)numero=numero+6*pow(10,tam-b-1);
if(op==55)numero=numero+7*pow(10,tam-b-1);
if(op==56)numero=numero+8*pow(10,tam-b-1);
if(op==57)numero=numero+9*pow(10,tam-b-1);
} }
return numero;
}
//***********************************
mayormenor(int k[8],int i){
char num[30];
do{

       gotoxy(8,i+5);cout<<"ingrese el numero ( "<<i<<" ) =  ";gets(num);
       gotoxy(1,22);clreol();
       k[i]=pruebaintcodigo(num);
       if(k[i]>40||k[i]<1){gotoxy(34,i+5);clreol();}
       if(k[i]==-1){gotoxy(34,i+5);clreol();}
       gotoxy(10,22);
       if(k[i]<1&&k[i]!=-1)cout<<"\a El numero debe ser mayor o igual a 1";
       if(k[i]>40)cout<<"\a El numero debe der menor o igual a 40";
        if(k[i]==-1)cout<<"\a No es un numero valido ";
       }while(k[i]>40||k[i]<1);
}
//***********************
repite(int k[8],int i){
  int a;
  do{ a=0;
      for(int j=1;j<i;j++){if(k[i]==k[j]){a=1;} }
      if(a==1)
      {
gotoxy(10,22);
cout<<"\aYa ingreso el numero "<<k[i]<<" por favor ingreseotro numero ";
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
cout<<"\n\n\n";
cout<<"\tPara salir presione [ S ], para continuar presione cualquier tecla ";
 op=getch();
    }while(op!='s');
    }
//**************************
double contrasena(){clrscr(); titulo();
char mi[30]={"mariset"},co[100];
int k=random(7)+7;
textcolor(k);
gotoxy(8,11);cprintf("ingrese contrasena =  ");gets(co);
return strcmp(co,mi);
}
//**************************
titulo(){

textcolor(12);
gotoxy(25,2);cprintf("SIMULACRO DEL JUEGO LA TINKA");
gotoxy(25,3);cprintf("----------------------------");
}
//****************************
presentacion(){
clrscr();
    titulo();
textcolor(12);
gotoxy(33,11);cprintf("UNI - PERU  2008 ");

gotoxy(20,21);cprintf("Presione cualquier tecla para continuar");
textcolor(12);
gotoxy(1,24);cprintf("programa creado por   jg_antony  ");
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
//do{cont=contrasena();}while(cont!=0);
//aviso();
presentacion();
for(;;){
clrscr();
titulo();
textcolor(2);
gotoxy(25,12);cprintf("1.- Tinka");
gotoxy(25,14);cprintf("2.- Probabilidades");
gotoxy(25,16);cprintf("3.- ??????  (te recomiendo no usar esta opcion)");

op1=getch();
switch(op1)
{case '1':tinka();break;
 case '2':probabilidades();break;
 case '3':caso3();break;
}
clrscr();
}
}
//**************************
caso3(){clrscr(); int x,y,k=0,ju=0,i;
for(int h=0;h<=2;h++)
{
gotoxy(1,8);
textcolor(h+1);

cprintf("                    Mariset guerra avisada no mata gente");
cout<<"\n\n\n\n\n";
cprintf("                    Lo siento Mariset pero en este monento" );
cout<<"\n\n\n";
cprintf("                   todos tus archivos estan siendo borrados" );

 linea();
   }
cprintf("\a");

 textbackground(0);
for( k=1;k<=6;k++){
clrscr();  textcolor(12);

gotoxy(10,10);
if(k==1){cprintf("BORRANDO     C:/ Archivos de programa / Microsof Office");
        linea();linea();}
if(k==2){cprintf("BORRANDO     C:/ Archivos de programa / Archivos comunes");
        linea();linea();}
if(k==3){cprintf ("BORRANDO     C:/ Documentos and Setting / All Users");
        linea();linea();}
if(k==4){cprintf("BORRANDO     C:/ Documentos and Setting / Escritorio");
linea();linea();}
if(k==5){cprintf("BORRANDO     C:/ Documentos and Setting / Applicacion Data");
linea();linea();}
if(k==6){cprintf("BORRANDO     C:/ WINDOWS / system32 ");
linea();linea();}

cout<<"\n";

for(i=1;i<=12000;i++)
    {
      x=random(2);
      if(i%40==0)cout<<"\r";
      textcolor(2);
      if(x==0)cprintf("0 ");
      else
      cprintf("1 ");
       pausa();
    }

}
for(int b=0;b<=4;b++){textcolor(b+1);cprintf("\n\tGracias por dejarme borrar todos tus archivos que tenga un buen dia\n ");}
for(int b=0;b<=1;b++)cout<<"\n\n\t\tpresione cualkier tecla para continuar ";
getch();  clrscr();gotoxy(1,5);
 for(int b=0;b<=4;b++)cout<<"\n\n\t\tjajajajajajajajajajajajajajaja";
cout<<"\n\n\n\t\aNO TE PREOCUPES NO PASO NADA SOLO BROMITA NO MAS";getch();
}

//*************************
int numero(){
int nums; char num[30];
do{gotoxy(17,12);cout<<"ingrese numero de jugadas  ";gets(num);//cin>>nums;
nums=pruebaintcodigo(num);
if(nums<1&&nums!=-1){gotoxy(12,17);cout<<"Minimo    1   jugada";gotoxy(1,12);clreol();}
if(nums==-1){gotoxy(12,17);cout<<"\a No es un numero valido ";gotoxy(1,12);clreol(); }
}while(nums<1);
return nums;}
//****************************

probabilidades(){ clrscr();
int nums,i;char op;
int por;

nums=numero();
int n[41],f[8],aci[8],mu[567][7];
for(int h=0;h<8;h++)aci[h]=0;
numjuego(n); clrscr();


         gotoxy(36,12);cout<<"please wait";
         for(i=1;i<=nums;i++){
        por=(i*100)/nums; gotoxy(40,10);cout<<por<<" % ";
         genera(f,mu,i);
         aciertos(n,f,aci,nums);

          }
 cout<<"\a\a";
estadisticas(n,f,aci,nums);
do{op=getch();
    switch(op){ clrscr();
    case '1':juganadora(n,nums);mostrar(mu,nums);break;
    case '2':estadisticas(n,f,aci,nums);break;
     }

}while(op!='s');




}
//************************************
aviso(){clrscr();titulo();
cout<<"\n\n\n";
textcolor(9);
cprintf("   Hola Mariset ste es uno de mis programas k sta hecho en el lenguaje");
cout<<"\n\n";
cprintf("   llamado c++, no es un programa muy coplicado, y no lo cree como los ");
cout<<"\n\n";
cprintf("          programas windows solo xq es un poko mas trabajoso ");
cout<<"\n\n";
cprintf("            tambien te mando el programa sin conpilar talvez algun dia ");
cout<<"\n\n";
cprintf("                               lo uses  :)");
cout<<"\n\n";
cprintf("presiona cualkier tecla para continuar");
getch();cout<<"\n\n";
cprintf("\aOtra vez"); getch(); cout<<"\n\n";
cprintf("\a jajaja         buelbe a presionar cuarkier tecla ");
getch();
}
//************************************
mostrar(int mu[567][7],int nums){
int num=566;



gotoxy(1,10);cout<<"  ";
if (nums<=566)num=nums;
for(int i=1;i<=num;i++)
   {
        cout<<" "<<i<<") ";
        for (int j=1;j<=6;j++)
       {cout<<mu[i][j]<<"   ";}
        cout<<"\t   ";
   }

gotoxy(1,1);cout<<"";
}
//*******************************************************
juganadora(int n[41],int nums){
int num=566; clrscr();
if (nums<=566)num=nums;
gotoxy(20,2);cout<<"Jugada ganadora";
for (int h=1;h<=6;h++)cout<<"  "<<n[h];
 cout<<"\n\n\tse jugaron con "<<nums<<" numeros ";
cout<<"\n\n\taqui se muestran las primeras "<<num<<" jugadas";
cout<<"\n\n\tpresione [2] para ver estadisticas\n\n\n";


}

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
           if(i<=566)mu[i][j]=n[j];
          }

}
//************************************
estadisticas(int n[41],int f[8],int aci[8],int nums){
clrscr();


gotoxy(8,5);cout<<"Jugada ganadora";
for (int h=1;h<=6;h++)cout<<"  "<<n[h];
gotoxy(1,8);
 for(int hf=0;hf<=6;hf++)cout<<"  con "<<hf<<" aciertos   "<<aci[hf]<<endl;
cout<<"\n\tse jugaron con "<<nums<<" numeros ";
cout<<"\n\n\n\n\n\n\npara ver jugadas [1] para salir [S]";
}
//**************************
pausa(){
int ju=0;
for (int p2=0;p2<1543;p2++){

      for(int p=0;p<=888;p++)ju++;ju=0;
      }

}
linea(){

     for(int h1=10;h1<=60;h1++)
        { for(int h2=0;h2<=500;h2++)
              {gotoxy(h1,4);cout<<" *";}
        }
      for(int h1=60;h1>=10;h1--)
        { for(int h2=0;h2<=800;h2++)
              {gotoxy(h1,4);cout<<"* ";}
        }
 gotoxy(1,23);textcolor(12);cprintf("programa creado por jg_antony");
  cprintf("\a");
}