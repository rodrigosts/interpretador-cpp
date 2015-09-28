#ifndef COMANDOWRITEINDEXVAR_H
#define COMANDOWRITEINDEXVAR_H

#include "Comando.h"
#include "ComandoWriteIndex.h"
#include <string>
#include "TabelaHash.h"
#include "Variavel.h"
#include "VariavelInteira.h"
#include "VariavelString.h"


class ComandoWriteIndexVar : public ComandoWriteIndex{
   private:
      Variavel* index;
      string indice;
      
   public:
      ComandoWriteIndexVar(TabelaHash*, string, string);
      ~ComandoWriteIndexVar();
      void executa();
};

#endif
