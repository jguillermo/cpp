
#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include <stdio.h>
#define ESC 27
struct Curso
{
	char	cod_curso[30];
	char	nom_curso[30];
	char	costo[30];
};
// variables de CURSO
fstream 	datos_Curso;	// Crea un flujo de salida 
Curso	inst_curso;	// Instancia de la estructura Curso
int	indice_Curso;
long	nCursos;
long	t_RegCurso = sizeof(inst_curso);
// funciones de CURSO
void 	apertura_Curso();
void 	ingreso_Curso();
int 	ingCod_Curso();
void 	listado_Curso();
void 	buscar_Curso();
void 	recupera_Curso(int indice);
void 	modifica_Curso(int indice, Curso new_curso);
// Función apertura archivo curso
void apertura_Curso()
{
	datos_Curso.open("TiendaArchivo1.txt",ios::in|ios::out|ios::binary);
	if (datos_Curso.bad())
	{
		cout << "\tError no se puede abrir el archivo";
		getch();
		exit(1);
	}
	datos_Curso.seekg(0L,ios::end); //Desplaza el puntero al final de archivo
	nCursos = datos_Curso.tellg()/t_RegCurso; 
}



//******************************************************************************
int main ()
{char op;
   do{ clrscr();
    gotoxy(35,8);cout<<"1.- crear Item";
    gotoxy(35,10);cout<<"2.- Listado";
    gotoxy(35,12);cout<<"3.- Modificar";
    gotoxy(35,14);cout<<"4.- Salir";
    gotoxy(35,16);cout<<"ingrese opcion   ";op=getch();
    switch(op)
    {
    case '1': ingreso_Curso();break;
    case '2': listado_Curso();break;
    case '3': buscar_Curso();break;
    }
 }while(op!='4');


	return 0;
}
void listado_Curso()
{
	clrscr(); apertura_Curso();
	datos_Curso.seekg(0L,ios::beg);
	cout << "\nREPORTE DE GENERAL DE TIENDA";
	cout << "\n----------------------------\n\n";
	cout << setiosflags(ios::left);
	cout << setw(10) << "CODIGO";
	cout << setw(25) << "NOMBRE";
	cout << setw(30) << "COSTO";
	cout << "\n------    -----------------------  --------\n";
	for(int i = 0; i<nCursos; i++)
	{
		datos_Curso.read((char*)& inst_curso,t_RegCurso);
		cout << setw(10) << inst_curso.cod_curso;
		cout << setw(25) << inst_curso.nom_curso;
		cout << setw(30) << inst_curso.costo << endl;
	}
	datos_Curso.close();  getch();
}
//***********************************************************************************
void ingreso_Curso()
{
	int OP;
	int cuenta = 0;
	do	{
		cuenta++;
		clrscr();
		apertura_Curso();
		cout << "\n\tINGRESO DE PRODUCTOS";
		cout << "\n\t--------------------\n\n";
		cout << "\tCodigo.... : ";gets(inst_curso.cod_curso);
      //cin >> inst_curso.cod_curso;
		//cin.ignore();
		cout << "\tNombre.... : ";gets(inst_curso.nom_curso);
		//cin.getline(inst_curso.nom_curso, sizeof(inst_curso.nom_curso));
		cout << "\tCosto..... : ";gets(inst_curso.costo);
	//	cin.getline(inst_curso.costo, sizeof(inst_curso.costo));
		cout << "\n\t" << "(" << cuenta << ") Ingreso";
		// Graba los datos en el archivo
		datos_Curso.write((char *)& inst_curso,t_RegCurso);
		nCursos ++;
		cout << "\n\n\tENTER para ingresar mas registros ESC para salir";
      	OP = getch();
		datos_Curso.close();
	} while(OP != ESC);
}
//************************************************************************
 int ingCod_Curso()
{
	clrscr();
	apertura_Curso();
	char cod_busqueda[3];
	cout << "\n\tMODIFICACION DE PRODUCTOS\n";
	  cout << "\t-------------------------";
	cout << "\n\n\tIngrese codigo a buscar : "; cin >> cod_busqueda;
	datos_Curso.seekg(0L,ios::beg);
	for (int i = 0; i < nCursos; i++)
	{
		datos_Curso.read((char*)&inst_curso,t_RegCurso);
		if (!strcmp(inst_curso.cod_curso,cod_busqueda)) return i;
	}
	return -1;
	datos_Curso.close();
}
//***********************************************************************
void buscar_Curso()
{
	indice_Curso = ingCod_Curso();
	if (indice_Curso!=-1)
   	recupera_Curso(indice_Curso);
	else
	{
		cout << "\n\tRegistro no existente";
		datos_Curso.close(); getch();
	}
}
//***************************************************************************
void recupera_Curso(int indice)
{
	datos_Curso.seekg (indice*t_RegCurso,ios::beg);
	datos_Curso.read  ((char*)&inst_curso,t_RegCurso);
	cout << "\n\t(*) Datos del producto recuperados\n\n";
	cout << "\tCodigo.... : " << inst_curso.cod_curso << endl;
	cout << "\tNombre.... : " << inst_curso.nom_curso << endl;
	cout << "\tCosto..... : " << inst_curso.costo	  << endl;;
	// Funcion recupera campos a modificar
	modifica_Curso(indice, inst_curso);
}
// *************************************************************************
void modifica_Curso(int indice, Curso new_curso)
{
	char campo,Ccodigo[3], Cnombre[30], Ccosto[30];
	cout << "\n\n\t[1]Nombre, [2]Costo";
	cout << "\n\n\tIngrese su opcion (campo a modificar) : ";
 	campo = getch();
	strcpy(Ccodigo, new_curso.cod_curso);
	switch(campo)
	{
   	case '1':
			cin.ignore();
			cout << "\n\n\tNombre.... : ";
			cin.getline(Cnombre, sizeof(Cnombre));
			strcpy(new_curso.nom_curso, Cnombre);
			break;
      case '2':
			cin.ignore();
			cout << "\n\n\tCosto..... : ";
			cin.getline(Ccosto, sizeof(Ccosto));
			strcpy(new_curso.costo, Ccosto);
			break;
	}
	datos_Curso.seekp(indice*t_RegCurso,ios::beg);
	datos_Curso.write((char *)& new_curso,t_RegCurso);
	datos_Curso.close();
}






