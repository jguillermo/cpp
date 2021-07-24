// herencia con archivos
// clase base

#include <iostream.h>
#include <conio.h>
#include <string.h>	// para manejo de cadenas
#include "alumno.h"	// clase individual
#include "alumnosa.h"	// clase administradora

// clase de aplicacion
class GestorAlumnosA{
protected:
	// objeto que administra el archivo
	AlumnosA objAlumnos;
public:
	// funcion que gestiona la ejecución
	void ejecuta();
protected:
// funciones disponibles en la ejecución
	void ingresa();
	void lista();
	int menu();
	void mensaje(char * m){cout<<m<<endl;}
};

// desarrollo de las funciones:
void GestorAlumnosA::ingresa(){
	int    codigo;
	char   nombres[31];
	int   n1,n2,n3,n4;

		// ingresa datos de un alumno
		cout << "Codigo   : "; cin>>codigo; cin.ignore();
		// verifica que no se duplique
		int p=objAlumnos.busca(codigo);
		if (p!=-1)
			mensaje("Codigo ya existe");
		else{
			cout << "Nombres  : "; cin.getline(nombres,30);
			cout << "4 notas enteras: ";cin>>n1>>n2>>n3>>n4;

			// crea un objeto
			Alumno unAlumno(codigo,nombres,n1,n2,n3,n4);
		
			// guarda el objeto creado
			objAlumnos.agrega(unAlumno);

			// mensaje de exito
			mensaje("Ingreso realizado satisfactoriamente");
		}
}

//desarrollo de la función lista:


void GestorAlumnosA::lista(){
	// titulos
cprintf("%-7s%-31s%10s\n\r","CODIGO","NOMBRES","PROMEDIO");
	
	// detalle
	for (int i = 0; i < objAlumnos.getN(); i++){
		Alumno unAlumno = objAlumnos.getAlumno(i);
		cprintf("%-7d%-31s%10.1f\n\r",
				unAlumno.getCodigo(), 
				unAlumno.getNombre(),
				unAlumno.promedio()
			  );
	}
}
//------------------------------------------------------------
void GestorAlumnosA::ejecuta(){
	int op;
	do{
		op = menu();
		switch(op){
		case 1: ingresa();	break;
		case 2: lista();	break;
		}
	}while (op!=0);

}
int GestorAlumnosA::menu(){
	int op;
	cout<<"[1]Ingresa"<<endl;
	cout<<"[2]Lista"<<endl;
	cout<<"[0]Fin"<<endl;
	cout<<"OPCION:"; cin>>op;
	return op;
}
