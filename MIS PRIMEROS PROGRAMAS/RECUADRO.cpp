#include<iostream.h>
#include<conio.h>



void main(){
int y=5;
   do{ for (int i=5;i<=75;i++)
           {for (int j=0;j<975;j++)
                {gotoxy(i,10);cout<<" *";}}
       for (int s=10;s<=25;s++)
           {for (int j=0;j<975;j++)
                {gotoxy(75,s);cout<<"  ";
                 gotoxy(75,s+1);cout<<"*";}}
       for (int k=75;k>=5;k--)
           {for (int h=0;h<945;h++)
                {gotoxy(k,26);cout<<"* ";}}
       for (int x=26;x>=11;x--)
           {for (int j=0;j<975;j++)
                {gotoxy(5,x);cout<<" ";
                 gotoxy(5,x-1);cout<<"*";}}


  }while(y=5);
    getch();
    }
