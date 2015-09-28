#ifndef COMANDOWRITEVAR_H
#define COMANDOWRITEVAR_H

#include "Comando.h"
#include "ComandoWrite.h"
#include <string>
#include "TabelaHash.h"
#include "Variavel.h"
#include "VariavelInteira.h"
#include "VariavelString.h"


class ComandoWriteVar : public ComandoWrite{
   private:
      TabelaHash * mem;
      
   public:
      void setMem (TabelaHash*);
      TabelaHash* getMem();
      ComandoWriteVar(TabelaHash*, string);
      void executa();
      ~ComandoWriteVar();
};

#endif
