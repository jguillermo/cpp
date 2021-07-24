#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>

void main(){
double a[20][21];
int n,i,np,j,m;
double fc,bg,te,sm;

cout<<"numero de ecuaciones  =  ";cin>>n;
cout<<"\n\ncoeficientes de X \n\n";
for (i=1;i<=n;i++)
    { for(j=1;j<=n;j++)
          {cout<<"X("<<i<<","<<j<<")= ";cin>>a[i][j];}
     }
cout<<"\n\n B coeficientes \n";
 for (i=1;i<=n;i++)
      {cout<<" B("<<i<<")= ";cin>>a[i][n+1];}

for (m=1;m<=n;m++)
    {np=m;
     bg=abs(a[m][m]);
     for(i=m;i<=n;i++)
         {if(abs(a[i][m])>bg)
                {bg=abs(a[i][m]);np=i;}
         }
    if(np!=m)
          {for (i=m;i<=n+1;i++)
               {te=a[m][i];
                a[m][i]=a[np][i];
                a[np][i]=te;}
          }
      for (i=m+1;i<=n;i++)
           {fc=a[i][m]/a[m][m];
            for( j=m+1;j<=n+1;j++)
                {a[i][j]=a[i][j]-(fc*a[m][j]);}
           }
     }

     a[n][n+1]=a[n][n+1]/a[n][n];
     for (i=n-1;i>=1;i--)
          {sm=0;
           for(j=i+1;j<=n;j++)
              {sm=sm+a[i][j]*a[j][n+1];}
           a[i][n+1]=(a[i][n+1]-sm)/a[i][i];
          }
          cout<<"\n\n respuestas \n\n";
          for( i=1;i<=n;i++)
              {cout<<"X("<<i<<")= "<<a[i][n+1]<<endl; }

              getch();
              }




        /*for (i=1;i<=n;i++)
              { for(j=1;j<=n+1;j++)
                   {cout<<a[i][j]<<"   ";}
                   cout<<endl; }
                   cout<<"\n\n";*/




















