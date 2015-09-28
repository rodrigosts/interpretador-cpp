#include "TabelaHash.h"

TabelaHash::TabelaHash(){
}

void TabelaHash::inserir(string nome, Variavel* var){
   dados[nome] = var;
}

Variavel* TabelaHash::valorDe(string nome){
   if(dados.end() == dados.find(nome)){
      dados[nome] = new VariavelString (nome);
   }
   return dados[nome];
}
