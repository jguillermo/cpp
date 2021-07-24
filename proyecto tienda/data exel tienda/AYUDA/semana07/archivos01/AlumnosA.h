// clase administradora
#include <fstream.h>

class AlumnosA{
	private:
		fstream 	archivo;
		Alumno	unAlumno;
		int 		n,tamreg, error;

	public:
		// constructor
	AlumnosA(){
	archivo.open("alumnos.dat", ios::in | ios::out | ios::binary);
		if ( !archivo ){
			error = 1;
		} else {
			error = 0;
			tamreg = sizeof(unAlumno);
			archivo.seekg(0, ios::end);
			n = archivo.tellg() / tamreg;
		}	
	}
	// destructor
	~AlumnosA(){
		if (!error)	archivo.close();
	}
	//------------------
	// metodos de administracion del archivo
	void agrega(Alumno obj){
			// graba el objeto al final del archivo
			archivo.seekp(0,ios::end);
			archivo.write((char *)&obj, tamreg);
			n++;
	}
	//------------------
	Alumno getAlumno(int i){ 
			archivo.seekg(i*tamreg,ios::beg);
			archivo.read((char *)&unAlumno,tamreg);
			return unAlumno;

	}
//-------------------
	void setAlumno(Alumno obj, int i){
			archivo.seekp(i*tamreg,ios::beg);
			archivo.write((char *)&obj,tamreg);
	}
	//------------------
	int getN(){return n;}
	//------------------
	int busca(int codigo){

			for (int i=0; i < n; i++){
				if (codigo==getAlumno(i).getCodigo())
				return i;
			}
			return -1;		
	}
};

