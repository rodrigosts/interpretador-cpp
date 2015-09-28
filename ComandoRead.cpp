#include "ComandoRead.h"
#include <iostream>
using namespace std;

ComandoRead::ComandoRead(TabelaHash* mem, string nome){
   this->nome = nome;
   this->mem = mem;
}
ComandoRead::~ComandoRead(){
	delete mem;
}
void ComandoRead::executa(){
   string valor;
   Variavel *var;
   cin >> valor;
   if(!eString(valor)){
      var = new VariavelInteira(nome, atoi(valor.c_str()));
   }else{
      var = new VariavelString(nome, valor);
   }    
   mem->inserir(nome, var);
}

bool ComandoRead::eString(string entrada){
	bool var = true;
	int i;
	int asc;
	for (i=0; i < entrada.length(); i++){
	    asc = (entrada.c_str())[i];
		if (!((asc >= 95 && asc <= 90 ) || (asc >= 97 && asc <= 122 ))){
			var = false;
		}
	}
	return var;
}
