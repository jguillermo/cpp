#include<conio.h>
#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iomanip.h>

main()
{randomize();
 char alu[40],tem[80];
 int i,j,n,tem1,tem2,a[40],b[40];
 cout<<"/n ingrese el numero de alumnos:"<<endl<<endl;
 cin>>n;
 //generar nota de los alumnos
 for(i=0;i<n;i++)
 {cout<<"/n ingrese codigo del alumno "<<(i+1)<<":";
  cin>>a[i];
  cout<<"/n ingrese apellidos y nombre del alumno "<<(i+1)<<":";
  gets(alu[i]);
  b[i]=random(20)+1;
  cout<<"/n el promedio del alumno "<<(i+1)<<":"<<b[i];
 }
 //ordenarlos alfabeticamente
 for(i=0;i<n-1;i++)
 	{for(j=(i+1);j<n;j++)
   	{if(strcmp(alu[i],alu[j])<0)
      	{//ordeno mobres
          strcpy(tem,alu[i]);
       	 strcpy(alu[i],alu[j]);
       	 strcpy(alu[j],tem);
          //ordeno loos codigos = q los nombres
          tem1=a[i];
          a[i]=a[j];
          a[j]=tem1;
          //ordeno las notas = q los nombres
          tem2=b[i];
          b[i]=b[j];
          b[j]=tem2;
      	}
      }
   }
 for(i=0;i<n;i++)
 {clrscr();
  cout<<"/n/n ordenando los nombres alfabeticamente"<<endl;
  cout<<"CODIGO       NOMBRE             NOTA"<<endl;
  cout<<setw(5)<<a[i]<<" "<<setw(5)<<alu[i]<<" "<<setw(5)<<b[i];
 }
 getch();
}

//ordenarlos x merito de notas

