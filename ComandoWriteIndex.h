#ifndef COMANDOWRITEINDEX_H
#define COMANDOWRITEINDEX_H

#include "Comando.h"
#include "ComandoWriteVar.h"
#include <string>
#include "TabelaHash.h"
#include "Variavel.h"
#include "VariavelInteira.h"
#include "VariavelString.h"


class ComandoWriteIndex : public ComandoWriteVar{
   private:
      int index;
      
   public:
      void setIndex(int);
      int getIndex();
      ComandoWriteIndex(TabelaHash*, string, int);
      void executa();
};

#endif
