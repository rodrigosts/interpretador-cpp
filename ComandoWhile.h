#ifndef COMANDOWHILE_H
#define COMANDOWHILE_H

#include "Comando.h"
#include <string>
#include "TabelaHash.h"
#include "Variavel.h"
#include "VariavelInteira.h"
#include "VariavelString.h"
#include <cstdlib>
#include <vector>

class ComandoWhile : public Comando{
   private:
      string valor;
      string valor2;
      string op;
      TabelaHash * mem;
      vector<Comando*>* vect;
      
   public:
      ComandoWhile(TabelaHash*, string, string, string);
      bool verificaCondicao();
      void adicionaComando(Comando*);
      void executa();
      ~ComandoWhile();
};

#endif
