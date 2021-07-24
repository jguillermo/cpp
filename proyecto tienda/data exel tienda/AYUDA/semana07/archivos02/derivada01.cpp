#include "base.h"
#include <fstream.h>

// definicion de la clase gestor
class GestorAlumnosAD: public GestorAlumnosA{
// constructor
public:
	GestorAlumnosAD():GestorAlumnosA(){};

	// funcion que administra la ejecución
	void ejecuta();
protected:
// funciones adicionales a las existentes en la clase base
	void modifica();
	void elimina();
// funcion redefinida para ampliar la funcionalidad de la clase
	int menu();
	
};
void main(){
	GestorAlumnosAD objGestor;
	objGestor.ejecuta();
}

// desarrollo de las funciones adicionales
void GestorAlumnosAD::elimina(){
	int    codigo;
	// ingresa codigo de un alumno
	cout << "Codigo   : "; cin>>codigo; cin.ignore();
	// verifica que exista
	int p=objAlumnos.busca(codigo);
	if (p==-1)
		mensaje("Codigo no existe");
	else{
		// elimina físicamente el objeto
		fstream otro;
		otro.open("auxiliar.dat",ios::out|ios::binary);
		// pasamos al archivo auxiliar todo excepto el encontrado
		for (int i=0; i<objAlumnos.getN(); i++){
			if (i!=p){
				Alumno unAlumno=objAlumnos.getAlumno(i);
				otro.write((char *)&unAlumno,sizeof(unAlumno));
			}
		}
		otro.close();// cierra archivo
		//pasamos todo el auxiliar al archivo original
		fstream entrada, salida;
		entrada.open("auxiliar.dat", ios::in|ios::binary);// solo lectura
		salida.open("alumnos.dat",ios::out|ios::binary);// solo grabación
		
		// lee de entrada y graba en salida, uno por uno, secuencialmente
		Alumno uno;
		while(!entrada.eof()){
			entrada.read((char *)&uno, sizeof(uno));
			salida.write((char *)&uno, sizeof(uno));
		}
		entrada.close();
		salida.close();
		objAlumnos.setN(objAlumnos.getN()-1);// actualiza numero de objetos
		
		// mensaje de exito
		mensaje("Eliminacion realizada satisfactoriamente");
	}
}
//---------------------------------
void GestorAlumnosAD::modifica(){
	// complete
}

// desarrollo de las funciones redefinidas
void GestorAlumnosAD::ejecuta(){
	int op;
	do{
		op = menu();
		switch(op){
			case 1: ingresa();	break;
			case 2: lista();	break;
			case 3: elimina();	break;
			case 4: modifica();	break;
		}
	}while (op!=0);

}
int GestorAlumnosAD::menu(){
	int op;
	cout<<"[1]Ingresa"<<endl;
	cout<<"[2]Lista"<<endl;
	cout<<"[3]Elimina"<<endl;
	cout<<"[4]Modifica"<<endl;
	cout<<"[0]Fin"<<endl;
	cout<<"OPCION:"; cin>>op;
	return op;
}
