#include "ComandoAtrib.h"
#include <iostream>
using namespace std;

ComandoAtrib::ComandoAtrib(TabelaHash* mem, string nome, Expressao* exp){
	this->mem = mem;
	this->nome = nome;
	this->exp = exp;
}

void ComandoAtrib::executa(){
	int valor = exp->calcula();
	VariavelInteira * var = new VariavelInteira (nome, valor);
	mem->inserir(nome, var);
}

ComandoAtrib::~ComandoAtrib(){
	if (mem != NULL) delete mem;
	if (exp != NULL) delete exp;
}
