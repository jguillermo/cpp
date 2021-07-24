struct fecha{
char dia[3], mes[8], year[5];
};
//******************************************************************************
class producto{
private:
char codigo[12];
char nombre[30];
char grupo[12];
char especifico[20];
char unidad[8];
char lugar[10];
double almacen;
double precio;
fecha fechacompra;

public:
producto(){}
producto(char *cod,char *nomb,char *grup,char *espes,char *unin,
char *lug,double alm,double pre,char *di,char *me,char *yea){
strcpy(codigo,cod);
strcpy(nombre,nomb);
strcpy(grupo,grup);
strcpy(especifico,espes);
strcpy(unidad,unin);
strcpy(lugar,lug);
almacen=alm;
precio=pre;
strcpy(fechacompra.dia,di);
strcpy(fechacompra.mes,me);
strcpy(fechacompra.year,yea);
}
void setcodigo(char *cod){strcpy(codigo,cod);}
void setnombre(char *nomb){strcpy(nombre,nomb);}
void setgrupo(char *grup){strcpy(grupo,grup);}
void setespecifico(char *espes){strcpy(especifico,espes);}
void setunidad(char *unin){strcpy(unidad,unin);}
void setlugar(char *lug){strcpy(lugar,lug);}
void setalmacen(double alm){almacen=alm;}
void setprecio(double pre){precio=pre;}
void setfecha(char *di,char *me,char *yea){strcpy(fechacompra.dia,di);
                                        strcpy(fechacompra.mes,me);
                                        strcpy(fechacompra.year,yea);}
char *getcodigo(){return codigo;}
char *getnombre(){return nombre;}
char *getgrupo(){return grupo;}
char *getespecifico(){return especifico;}
char *getunidad(){return unidad;}
char *getlugar(){return lugar;}
double getalmacen(){return almacen;}
double getprecio(){return precio;}
fecha getfecha(){return fechacompra;}
void change();
void lista();

};
void producto::change(){char op;
 clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista ();

cout<<"\n\nIngrese Opcion   :";
    op=getch();
     switch(op)
     {case'1': do{cout<<"\tCodigo............:";gets(codigo);
                if(strlen(codigo)>12){cout<<"\t\aMaximo 12 cifras\n";}
               }while( strlen(codigo)>12); break;
      case'2': do{cout<<"\tNombre............:";gets(nombre);
               if(strlen(nombre)>30){cout<<"\t\t\aMaximo 30 cifras\n";}
               }while( strlen(nombre)>30); break;
      case'3':  do{cout<<"\tGrupo.............:";gets(grupo);
                if(strlen(grupo)>12){cout<<"\t\t\aMaximo 12 cifras\n";}
                 }while( strlen(grupo)>12); break;
      case'4':  do{cout<<"\tEspecifico........:";gets(especifico);
                 if(strlen(especifico)>20){cout<<"\t\t\aMaximo 20 cifras\n";}
                }while( strlen(especifico)>20); break;
      case'5':  do{cout<<"\tUnidad............:";gets(unidad);
                if(strlen(unidad)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
                  }while( strlen(unidad)>8);break;
      case'6': do{cout<<"\tLugar de almacen..:";gets(lugar);
               if(strlen(lugar)>10){cout<<"\t\t\aMaximo 10 cifras\n";}
                }while( strlen(lugar)>10);break;
      case'7': cout<<"\tFecha de compra........:";
                do{cout<<"\n\t\tDia....: ";gets(fechacompra.dia);
              	 if(strlen(fechacompra.dia)>3){cout<<"\t\t\aMaximo 3 cifras\n";}
              	 }while( strlen(fechacompra.dia)>3);
                do{cout<<"\t\tMes....: ";gets(fechacompra.mes);
      	  			if(strlen(fechacompra.mes)>8){cout<<"\t\t\aMaximo 8 cifras\n";}
      				}while( strlen(fechacompra.mes)>8);
     					 do{cout<<"\t\tYear....: ";gets(fechacompra.year);
      			 if(strlen(fechacompra.year)>5){cout<<"\t\t\aMaximo 5 cifras\n";}
      			 }while( strlen(fechacompra.year)>5);
     					cout<<"\n\t\t"<<fechacompra.dia<<" / "<<fechacompra.mes;
            	 cout<<" / "<<fechacompra.year<<"\n\n";  break;
                  case'8': cout<<"\tAlmacen ........:";cin>>almacen; break;
      case'9': cout<<"\tPrecio ........:";cin>>precio; break;
      }
     clrscr();cout<<"\n\t\tCORREGIR PRODUCTO\n";
cout<<"\t\t-----------------\n\n";
lista ();

}


//*************************************************************************
void producto::lista(){
  cout<<"\n     1.- Codigo.............:   "<<codigo<<endl;
cout<<"\n     2.- Nombre.............:   "<<nombre<<endl;
cout<<"\n     3.- Grupo..............:   "<<grupo<<endl;
cout<<"\n     4.- Especifico.........:   "<<especifico<<endl;
cout<<"\n     5.- Unidad.............:   "<<unidad<<endl;
cout<<"\n     6.- Lugar de Almacen...:   "<<lugar<<endl;
cout<<"\n     7.- Fecha de compra....:   ";
cout<<fechacompra.dia<<" / "<<fechacompra.mes;
cout<<" / "<<fechacompra.year<<"\n";
cout<<"\n     8.- Almacen............:   "<<almacen<<endl;
cout<<"\n     9.- Precio Unitario....:   "<<precio<<endl;
cout<<"\n\tPresio Unitario.....:"<<(almacen/precio);
cout<<"\n\n";
}
//*************************************************************************