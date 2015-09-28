#include "ExpBinaria.h"


ExpBinaria::ExpBinaria(string op, Expressao* expr1, Expressao* expr2){
	this->expr1 = expr1;
	this->expr2 = expr2;
	this->op = op;
}

ExpBinaria::~ExpBinaria(){
	if (expr1 != NULL) delete expr1;
	if (expr2 != NULL) delete expr2;
}

int ExpBinaria::calcula(){
	int xp1, xp2, resultado;
	xp1 = expr1->calcula();
	xp2 = expr2->calcula();
	if ( op == "+"){
		resultado = xp1 + xp2;
	}else if (op == "-"){
		resultado = xp2 - xp1;
	}else if (op == "/"){
		resultado = xp2 / xp1;
	}else if (op == "*"){
		resultado = xp2 * xp1;
	}
	return resultado;
}
