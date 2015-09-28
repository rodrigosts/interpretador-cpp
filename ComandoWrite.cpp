#include "ComandoWrite.h"
#include <iostream>
using namespace std;

ComandoWrite::ComandoWrite(string conteudo){
   this->nome = "";
   this->conteudo = new VariavelString("",conteudo);
}

ComandoWrite::~ComandoWrite(){
   if(conteudo != NULL) delete conteudo;
}

void ComandoWrite::executa(){
   cout << conteudo->leValor();
}

void ComandoWrite::setConteudo(Variavel* conteudo){
	this->conteudo = conteudo;
}

Variavel* ComandoWrite::getConteudo(){
	return this->conteudo;
}

void ComandoWrite::setNome(string nome){
	this->nome = nome;
}

string ComandoWrite::getNome(){
	return this->nome;
}
