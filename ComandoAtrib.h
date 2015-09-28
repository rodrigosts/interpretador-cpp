#ifndef COMANDOATRIB_H
#define COMANDOATRIB_H

#include "Comando.h"
#include <string>
#include "TabelaHash.h"
#include "VariavelInteira.h"
#include "Expressao.h"
#include <cstdlib>
#include <vector>

class ComandoAtrib : public Comando{
   private:
      string nome;
      TabelaHash * mem;
      Expressao * exp;
      
   public:
      ComandoAtrib(TabelaHash*, string, Expressao*);
      void executa();
      ~ComandoAtrib();
};

#endif

