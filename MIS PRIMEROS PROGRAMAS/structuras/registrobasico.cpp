#include<iostream.h>
 #include<conio.h>
 #include<string.h>
 struct sfecha
 {int dia, mes,year;
 };
 struct salumno
 {char codigo[9],apellido[50],nombre[50];
 int p1,p2,p3,p4,ef,ep;
 sfecha fn;
 };
 void leerdatos(salumno &alu);
 void mostrardatos(salumno alu);
void maxfinal(salumno lista[4],salumno &alu);
void maxnota(salumno lista[4],salumno &alu);
int notafinal(salumno alu);

 void main()
 {
 salumno listaalumnos[4],alumno;
 cout<<"ingrese datos de los 4 alumnos";
 for(int i=1;i<=4;i++)
 leerdatos(listaalumnos[i]);
 cout<<"los datoas del alumno con el mejor promedio son =>";
 cout<<endl;
 maxnota(listaalumnos,alumno);
 mostrardatos(alumno);
 cout<<endl;
 cout<<"los datos del alumno con el mejor examen final son =>";
 cout<<endl;
 maxfinal(listaalumnos,alumno);
 mostrardatos(alumno);
 getch();

 }

 void leerdatos(salumno &alu)
 {
 cin.get();
 cout<<"ingrese codigo =>";cin.getline(alu.codigo,9);
 cout<<"ingrese apellido =>";cin.getline(alu.apellido,50);
cout<<"ingrese nombre =>";cin.getline(alu.nombre,50);
cout<<"ingrese primera practica =>";cin>>alu.p1;
cout<<"ingrese segunda practica =>";cin>>alu.p2;
cout<<"ingrese tercera practica =>";cin>>alu.p3;
cout<<"ingrese cuarta practica =>";cin>>alu.p4;
cout<<"ingrese parcial =>";cin>>alu.ep;
cout<<"ingrese final =>";cin>>alu.ef;
cout<<"ingrese fecha de nacimiento =>";cin>>alu.fn.dia>>alu.fn.mes>>alu.fn.year;
}
void mostrardatos(salumno alu)
{
cout<<"codigo :"<<alu.codigo<<endl;
cout<<"apellido :"<<alu.codigo<<endl;
cout<<"nombre  :"<<alu.codigo<<endl;
cout<<"primera practica :"<<alu.codigo<<endl;
cout<<"segunda practica :"<<alu.codigo<<endl;
cout<<"tercera practica :"<<alu.codigo<<endl;
cout<<"cuarta practica :"<<alu.codigo<<endl;
cout<<"examen parcial :"<<alu.codigo<<endl;
cout<<"examen final :"<<alu.codigo<<endl;
cout<<"fecha de nacimiento"<<alu.fn.dia<<"/"<<alu.fn.mes<<"/"<<alu.fn.year<<endl;
}
int notafinal(salumno alu)
{float pp,nf;
pp=(alu.p1+alu.p2+alu.p3+alu.p4)/4.0;
nf=(alu.ep+pp+2*alu.ef)/4.0;
return(nf);
}
void maxnota(salumno lista[4],salumno &alu)
{
alu=lista[1];
for(int i=2;i<=4;i++)
if(notafinal(alu)<notafinal(lista[i]))
	alu=lista[i];
}
void maxfinal(salumno lista[4],salumno &alu)
{alu=lista[1];
for(int i=2;i<=4;i++)
if(alu.ef<lista[i].ef)
	alu=lista[i];

}




