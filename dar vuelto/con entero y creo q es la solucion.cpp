#include<iostream.h>
#include<conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include<math.h>
   vuelto(int cant);
   double pruebadouble(char num[30]);

   main()
   {int intcant;   char num[30];
      double cant;
      for(int k=0;;k++){
      
         cout<<"Ingrese Cantidad  =  ";gets(num);
         double cant=pruebadouble(num);
      
         cout<<"num  "<<cant;
         int cant2=cant*100;
         cout<<" int num  "<<cant2;
         getch();
         if(cant<0)
            cout<<"\n\n\a  No es un numero valido\n\n";
         else
            vuelto(cant);
         getch();
         clrscr();
      }
   }


   vuelto(int cant){
   
      int dupli=0,dupli2;
      dupli2=cant;
      cout<<"num2  "<<cant<<"  dupli  "<<dupli;
      int  m[13]={20000,10000,5000,2000,1000,500,200,100,50,20,10,5,1};
      double m2[13]={200,100,50,20,10,5,2,1,0.5,0.2,0.1,0.05,0.01};
      int con[13];
      int i,j;
      for( i=0;i<=12;i++)con[i]=0;
   
   
      for(i=0;i<=12;i++)
      {
      
         for(int j=0;;j++)
         {
            if(cant>=m[i]){con[i]++;cant=cant-m[i];}
            else 
               break;
         }
      }
   
      for(int h=0;h<=12;h++){dupli=dupli+(con[h]*m[h]);}
      cout<<"\ndupli  "<<dupli<<"   dupli2   "<<dupli2<<"      con[12]  "<<con[12];
      for(int h=0;h<150;h++)
      {
         if(dupli!=dupli2)
         
         {
            if(dupli<dupli2)
            {dupli=dupli+0.01;con[12]++;}
            else
            {dupli=dupli-0.01;con[12]--;}
         }
         else 
            break;
      }
      cout<<"\ndupli  "<<dupli<<"   dupli2   "<<dupli2<<"      con[12]  "<<con[12];
      for(i=0,j=0;i<=4;i++){
         if(con[i]!=0){gotoxy(3,8+j);cout<<"Billetes de "<<m2[i]<<"  =  "<<con[i];j=j+2;}}
      for(i=5,j=0;i<=12;i++){
         if(con[i]!=0){gotoxy(40,j+8);cout<<"Monedas de "<<m2[i]<<"  =  "<<con[i];j=j+2;}}
   
   
   }

//*************
   double pruebadouble(char num[30]){
   
      int i,j,k,tam,tam2=0,emp=0,jo=0,punto=0; j=1;
   
      tam=strlen(num);
      for (i=0;i<tam;i++)
      {k=toupper(num[i]);
         if (k<46||k>57||k==47)j=0;
         if(k==45&&i==0){j=1;emp=1;}
         if(k==45&&tam==1)j=0;
         if(k==46){tam2=i; jo=1;punto++;}
         if(k!=46&&jo==0)tam2=tam;
      
      }
      double numero=0.0;
      if(punto>1)j=0;
      if(j==0)numero=-1;
      else {
      
      
         int cam=0,b,decimal=0;
      
      
         for (b=emp;b<tam;b++){
            int op=toupper(num[b]);  
            if(cam==1)decimal++;
         
            if(op==49){
               if(cam==0)numero=numero+1*pow(10,tam2-b-1);
               if(cam==1) numero=numero+1/pow(10,decimal);}
            if(op==50){
               if(cam==0)numero=numero+2*pow(10,tam2-b-1);
               if(cam==1) numero=numero+2/pow(10,decimal);}
            if(op==51){
               if(cam==0)numero=numero+3*pow(10,tam2-b-1);
               if(cam==1) numero=numero+3/pow(10,decimal);}
            if(op==52){
               if(cam==0)numero=numero+4*pow(10,tam2-b-1);
               if(cam==1) numero=numero+4/pow(10,decimal);}
            if(op==53){
               if(cam==0)numero=numero+5*pow(10,tam2-b-1);
               if(cam==1) numero=numero+5/pow(10,decimal);}
            if(op==54){
               if(cam==0)numero=numero+6*pow(10,tam2-b-1);
               if(cam==1) numero=numero+6/pow(10,decimal);}
            if(op==55){
               if(cam==0)numero=numero+7*pow(10,tam2-b-1);
               if(cam==1) numero=numero+7/pow(10,decimal);}
            if(op==56){
               if(cam==0)numero=numero+8*pow(10,tam2-b-1);
               if(cam==1) numero=numero+8/pow(10,decimal);}
            if(op==57){
               if(cam==0)numero=numero+9*pow(10,tam2-b-1);
               if(cam==1) numero=numero+9/pow(10,decimal);}
            if(op==46)cam=1;
         }
      
         if(emp==1)numero=-numero;
      }
      return numero;
   
   }
