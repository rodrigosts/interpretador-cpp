#include "ComandoWriteVar.h"
#include <iostream>
using namespace std;

ComandoWriteVar::~ComandoWriteVar(){
   if(mem!= NULL) delete mem;
}

ComandoWriteVar::ComandoWriteVar(TabelaHash* mem, string nome) : ComandoWrite(""){
   this->mem = mem;
   setConteudo (NULL);
   setNome(nome);
}

void ComandoWriteVar::executa(){
   if(getNome().rfind(".length") == string::npos){
	  setConteudo ( this->mem->valorDe(getNome()));
      cout << getConteudo()->leValor();  
   }else{
      string aux = getNome().substr(0, getNome().size()-7);
      setConteudo (this->mem->valorDe(aux));
      cout << getConteudo()->tamanho();
   }
}

void ComandoWriteVar::setMem (TabelaHash* mem){
	this->mem = mem;
}

TabelaHash* ComandoWriteVar::getMem(){
	return this->mem;
}
