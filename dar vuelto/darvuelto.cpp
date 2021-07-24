#include<iostream.h>
#include<conio.h>
vuelto(float cant);
main(){
for(int k=0;;k++){
float cant;
cout<<"Ingrese Cantidad  =  ";cin>>cant;
//if(cant<1.0)cant=cant+0.01;
vuelto(cant);
getch();
clrscr();
}
}

vuelto(float cant){
float m[13]={200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.01};

int con[13];
int i,j;
for( i=0;i<=12;i++)con[i]=0;


for(i=0;i<=12;i++)
{

   for(int j=0;;j++)
   {
     if(cant>=m[i]){con[i]++;cant=cant-m[i];}
     else break;
     }


  }
//for(i=0;i<=12;i++){if(con[i]!=0)cout<<"\n\nBilletes de "<<m[i]<<"  =  "<<con[i];}
for(i=0,j=0;i<=4;i++){if(con[i]!=0){gotoxy(3,8+j);cout<<"Billetes de "<<m[i]<<"  =  "<<con[i];j=j+2;}}
for(i=5,j=0;i<=12;i++){if(con[i]!=0){gotoxy(40,j+8);cout<<"Monedas de "<<m[i]<<"  =  "<<con[i];j=j+2;}}


}