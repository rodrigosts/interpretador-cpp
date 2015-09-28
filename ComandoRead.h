#ifndef COMANDOREAD_H
#define COMANDOREAD_H

#include "Comando.h"
#include <string>
#include "TabelaHash.h"
#include "Variavel.h"
#include "VariavelInteira.h"
#include "VariavelString.h"
#include <cstdlib>

class ComandoRead : public Comando{
   private:
      string nome;
      TabelaHash * mem;
      bool eString(string);
      
   public:
      ComandoRead(TabelaHash*, string);
      void executa();
      ~ComandoRead();
};

#endif
