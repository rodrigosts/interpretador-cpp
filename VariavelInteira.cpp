#include "VariavelInteira.h"

VariavelInteira::VariavelInteira(string nome){
   defNome(nome);
   this->valor = 0;
}

VariavelInteira::VariavelInteira(string nome, int valor){
   defNome(nome);
   this->valor = valor;
}
      
string VariavelInteira::leValor(){
   stringstream ss;
   ss << this-> valor;
   return ss.str();
}

int VariavelInteira::leValorInt(){
	return this->valor;
}

int VariavelInteira::tamanho(){
   stringstream ss;
   ss << this-> valor;
   return ss.str().size();
}

