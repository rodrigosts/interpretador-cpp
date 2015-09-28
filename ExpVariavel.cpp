#include "ExpVariavel.h"


ExpVariavel::ExpVariavel(TabelaHash* mem, string nome){
	this->nome = nome;
	this->mem = mem;
}

int ExpVariavel::calcula(){
   return mem->valorDe(nome)->leValorInt();
}

ExpVariavel::~ExpVariavel(){
	if(mem != NULL) delete mem;
}
