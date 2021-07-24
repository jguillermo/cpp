// definicion de la clase
class Alumno{
private: // datos
	int codigo;
	char nombre[31];
	int n1, n2, n3, n4;

public:
	// constructores
	Alumno(){}
	Alumno(int codigo, char * nombre, int n1, int n2, int n3, int n4){
		this->codigo=codigo;
		strcpy(this->nombre,nombre);
		this->n1 = n1; 
		this->n2 = n2; 
		this->n3 = n3; 
		this->n4 = n4;

	}
	// funciones get/set
	void setCodigo(int codigo){this->codigo=codigo; }
	void setNombre(char * nombre){strcpy(this->nombre,nombre);}
	void setNotas(int n1, int n2, int n3, int n4){
		this->n1 = n1; 
		this->n2 = n2; 
		this->n3 = n3; 
		this->n4 = n4;
	}
	int getCodigo(){return codigo;}
	char * getNombre(){ return nombre;}
	void getNotas(int &a, int &b, int &c, int &d){
		a=n1; b=n2; c=n3; d=n4;}

	// funciones adicionales
	double promedio(){
		int m=n1;
		if (n2<m) m=n2;
		if (n3<m) m=n3;
		if (n4<m) m=n4;
		return (n1+n2+n3+n4-m)/3.0;
	}
	char * estado(){
		if (promedio()>=12.5)
			return "aprobado";
		else
			return "desaprobado";
	}
};
