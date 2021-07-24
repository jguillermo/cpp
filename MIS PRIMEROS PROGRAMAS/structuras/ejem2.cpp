#include<iostream.h>
#include<conio.h>
class notas
{
	private:
	float nota1,nota2;
	public:
	float prom;
	void leer();
	float cal_prom();
	};
float notas::cal_prom() {
	return((nota1+nota2)/2.0);};

void notas::leer(){
	cout<<"Nota 1: ";cin>>nota1;
	cout<<"Nota 2: ";cin>>nota2;}

void main()
{
	int n; float acum=0;
	notas alumno[50];
	cout<<"Ingrese el numero de alumnos (max 50): ";cin>>n;
	cout<<endl;
	for(int i=0;i<n;i++)
		{cout<<"Datos del alumno "<<(i+1)<<" :"<<endl;
		alumno[i].leer();
		alumno[i].prom=alumno[i].cal_prom();
		acum=acum+alumno[i].prom;}
   clrscr();
	cout<<"Alumno"<<"\t\t"<<"Promedio"<<endl;
	for(int j=0;j<n;j++)
		{cout<<"Alumno "<<(j+1)<<"\t\t"<<alumno[j].prom;
       cout<<endl;}
	cout<<"promedio total: "<<(acum/n);
	getch();
}
