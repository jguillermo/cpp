#include<conio.h>
#include<iostream.h>
#include <stdlib.h>
mensaje(int k);
main(){
randomize();
int n[41],k[8],a=0,x,y,uxi,k1=0;
for(int i=1;i<=6;i++){   gotoxy(15,2);cout<<i;
       do{
       gotoxy(8,i+5);cout<<"ingrese el numero ( "<<i<<" ) =  ";cin>>k[i];
       gotoxy(1,22);clreol();
       if(k[i]>40||k[i]<1){gotoxy(34,i+5);clreol();}
       gotoxy(10,22);
       if(k[i]<1)cout<<"\a El numero debe ser mayor o igual a 1";
       if(k[i]>40)cout<<"\a El numero debe der menor o igual a 40";
       }while(k[i]>40||k[i]<1);



     do{  a=0;
     for(int j=1;j<i;j++){if(k[i]==k[j]){a=1;} }
    if(a==1){
                 gotoxy(10,22);cout<<"\aYa ingreso el numero "<<k[i]<<" por favor ingrese otro numero ";
                 gotoxy(34,i+5);clreol();


                 do{
                   gotoxy(8,i+5);cout<<"ingrese el numero ( "<<i<<" ) =  ";cin>>k[i];
                   gotoxy(1,22);clreol();
                   if(k[i]>40||k[i]<1){gotoxy(34,i+5);clreol();}
                   gotoxy(10,22);
                   if(k[i]<1)cout<<"\a El numero debe ser mayor o igual a 1";
                   if(k[i]>40)cout<<"\a El numero debe der menor o igual a 40";
                   }while(k[i]>40||k[i]<1);

            }





    }while(a==1);


}

for(int f=1;f<=40;f++)n[f]=f;
for(int ca=1;ca<=1000;ca++){ x=random(39)+1;y=random(39)+1;

uxi=n[x];
n[x]=n[y];
n[y]=uxi;
}
//for(int f=1;f<=40;f++)cout<<k[f]<<"   ";
clrscr();
cout<<"\n\n\tTu jugada es : \n\n\n";
for(int f=1;f<=6;f++)cout<<"        "<<k[f];
cout<<"\n\n\n\n\tLa jugada ganadora es : \n\n\n";
for(int f=1;f<=6;f++)cout<<"        "<<n[f];
for (int ji=1;ji<=6;ji++)
{for (int jii=1;jii<=6;jii++)
      {if (k[ji]==n[jii])k1=k1+1;}
      }
 mensaje(k1);
  //cout<<k1;



getch();
}
mensaje(int k){
if(k==6)cout<<"\n\n\tganaste la tinka";
 if(k<6&&k>1)cout<<"\n\n\n\n\n\tobtubiste "<<k<<" haciertos  \n";
 if(k==1)cout<<"\n\n\n\n\n\tobtubiste 1 hacierto  \n";
 if(k<1)cout<<"\n\n\n\n\n\tobtubiste 0 haciertos  \n";

}


