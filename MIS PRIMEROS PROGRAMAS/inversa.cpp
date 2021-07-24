#include<iostream.h>
#include<conio.h>
void main()
{ float A[50][50],B[50][50],I[50][50];
 int n,i,j,j1,i1,i2,j2,i3,j3,i4,j4,i5,j5,i6,j6,t=1,t1;
 cout<<"ingrese en orden de la m ";cin>>n;
 t1=n;

//GENERANDO MATRIZ IDENTIDAD EN I
 for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
  {if(i==j)I[i][j]=1;
   else I[i][j]=0;
  }

//CARGANDO VALORES PARA MATRIZ A
 for(i=1;i<=n;i++)
  for(j=1;j<=n;j++)
   { gotoxy(4+4*j,4+4*i);
     cin>>A[i][j];
   }

//PASANDO VALORES DE A a B
 for(i1=1;i1<=n;i1++)
  for(j1=1;j1<=n;j1++)
   B[i1][j1]=A[i1][j1];

 while(t<=n)
  {for(i2=t;i2<=n;i2++)
     for(j2=1;j2<=n;j2++)
       if(B[i2][t]!=0)
          A[i2][j2]=A[i2][j2]/B[i2][t];
       else break;
  }


   for(i2=t;i2<=n;i2++)
   { for(j2=1;j2<=n;j2++)

     if(B[i2][t]!=0)
       {
        I[i2][j2]=I[i2][j2]/B[i2][t];
       }

    else break;
   }

    for(i3=t+1;i3<=n;i3++)
   { for(j3=1;j3<=n;j3++)

    A[i3][j3]=A[i3][j3]-A[t][j3];
  }

     for(i3=t+1;i3<=n;i3++)
   { for(j3=1;j3<=n;j3++)

     I[i3][j3]=I[i3][j3]-I[t][j3];
   }
    

 for(i4=1;i4<=n;i4++)
 for(j4=1;j4<=n;j4++)
 {
  B[i4][j4]=A[i4][j4];

 }
 t=t+1;
}





while(t1>=1)
{

   for(i5=t1;i5>=1;i5--)
  { for(j5=n;j5>=1;j5--)

      if(B[i5][t1]!=0)
   {
     A[i5][j5]=A[i5][j5]/B[i5][t1];
   }
    else break;
  }

   for(i5=t1;i5>=1;i5--)
  { for(j5=n;j5>=1;j5--)

      if(B[i5][t1]!=0)
   {
      I[i5][j5]=A[i5][j5]/B[i5][t1];
   }
    else break;
  }

    for(i6=t1-1;i6>=1;i6--)
  { for(j6=n;j6>=1;j6--)
   {
   A[i6][j6]=A[i6][j6]-A[t1][j6];
   }
  }

    for(i6=t1-1;i6>=1;i6--)
  { for(j6=n;j6>=1;j6--)
   {
     I[i6][j6]=I[i6][j6]-I[t1][j6];
   }
  }



  for(i6=1;i6<=n;i6++)
  for(j6=1;j6<=n;j6++)
  {
   B[i6][j6]=A[i6][j6];

  }
 t1=t1-1;
}
getch();
clrscr();


    for(i2=1;i2<=n;i2++)
    for(j2=1;j2<=n;j2++)
    {
     gotoxy(4+4*j2,4+4*i2);
     cout<<A[i2][j2];
    }
    for(i2=1;i2<=n;i2++)
    for(j2=1;j2<=n;j2++)
    {
     gotoxy(15+4*j2,4+4*i2);
     cout<<I[i2][j2];
    }
 getch();
}
