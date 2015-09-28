#include "VariavelString.h"

VariavelString::VariavelString(string nome){
   defNome(nome);
   this->valor = "";
}

VariavelString::VariavelString(string nome, string valor){
   defNome(nome);
   this->valor = valor;
}

string VariavelString::leValor(){
   return this->valor;
}

int VariavelString::tamanho(){
    return this->valor.length();
}

int VariavelString::leValorInt(){
	return atoi (this->valor.c_str());
}
