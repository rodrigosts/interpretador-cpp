#include "ExpLiteral.h"


ExpLiteral::ExpLiteral(int valor){
	this->valor = valor;
}

int ExpLiteral::calcula(){
   return this->valor;
}
