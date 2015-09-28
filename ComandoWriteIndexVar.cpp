#include "ComandoWriteIndexVar.h"
#include <iostream>
#include <cstdlib>
using namespace std;

ComandoWriteIndexVar::ComandoWriteIndexVar(TabelaHash* mem, string nome, string indice) : ComandoWriteIndex (mem, nome, 0){
   setConteudo (NULL);
   this->indice= indice;
}

void ComandoWriteIndexVar::executa(){
   setConteudo (getMem()->valorDe(getNome()));
   string saida;
   index = getMem()->valorDe(indice);
   setIndex(atoi(index->leValor().c_str()));
   saida = getConteudo()->leValor();
   if(getIndex() >=0 ) saida = saida[getIndex()];  
   cout << saida;  
}

ComandoWriteIndexVar::~ComandoWriteIndexVar(){
	if(index != NULL) delete index;
}
