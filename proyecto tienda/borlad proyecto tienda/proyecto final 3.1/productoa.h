class productoA{
private:
fstream archivo;
producto unproducto;
int n,tamreg,error;

public:
productoA(){
archivo.open("producto.dat",ios::in|ios::out|ios::binary);
if (!archivo){error=1;}
else {
 error=0;
     tamreg=sizeof(unproducto);
     archivo.seekg(0,ios::end);
     n=archivo.tellg()/tamreg;
     }
}
~productoA(){ if(!error) archivo.close();}

void addproducto(producto obj){
archivo.seekp(0,ios::end);
archivo.write((char*)& obj,tamreg);
n++;
}

producto getproducto(int i){
archivo.seekg(i*tamreg,ios::beg);
archivo.read((char*)&unproducto,tamreg);
return unproducto;
}

void setproducto(producto obj,int i){
archivo.seekp(i*tamreg,ios::beg);
archivo.write((char*)&obj,tamreg);
}

int numproductos(){return n;}
void setN(int n){ this->n = n;}

int buscaproducto(char *busca){producto productoleido;



for (int p=0;p<n;p++){

archivo.seekg(p*tamreg,ios::beg);
archivo.read((char*)&productoleido,tamreg);
if(strcmp(productoleido.getcodigo(),busca)==0)return p;
if(strcmp(productoleido.getnombre(),busca)==0)return p;
if(strcmp(productoleido.getgrupo(),busca)==0)return p;
}
return -1;
}
};