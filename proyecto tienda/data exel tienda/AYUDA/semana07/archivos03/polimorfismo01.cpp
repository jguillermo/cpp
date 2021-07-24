#include "base.h"
#include <fstream.h>

// definicion de la clase gestor
class GestorAlumnosAP: public GestorAlumnosA{
// constructor
public:
	GestorAlumnosAP():GestorAlumnosA(){};

// funciones virtuales para una lista diferente
virtual void titulo();
virtual void muestraDetalle(int i);
	
};
void main(){
	GestorAlumnosAP objGestorAP;
	objGestorAP.ejecuta();
}

// desarrollo de las funciones virtules
void GestorAlumnosAP::titulo(){
     cprintf("%-7s%10s\n\r","CODIGO","PROMEDIO");
}

void GestorAlumnosAP::muestraDetalle(int i){
Alumno unAlumno = objAlumnos.getAlumno(i);
		cprintf("%-7d%10.1f\n\r",
				unAlumno.getCodigo(), 
				unAlumno.promedio()
			  );
}
