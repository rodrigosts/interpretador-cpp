#include "ComandoWriteIndex.h"
#include <iostream>
using namespace std;

ComandoWriteIndex::ComandoWriteIndex(TabelaHash* mem, string nome, int index) : ComandoWriteVar (mem, nome){
   setConteudo (NULL);
   this->index = index;
}

void ComandoWriteIndex::executa(){
   setConteudo (getMem()->valorDe(getNome()));
   string saida;
   saida = getConteudo()->leValor();
   if(index >=0 ) saida = saida[index];
   cout << saida;  
}

void ComandoWriteIndex::setIndex(int index){
	this->index = index;
}

int ComandoWriteIndex::getIndex(){
	return this->index;
}
