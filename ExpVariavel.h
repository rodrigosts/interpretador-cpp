#ifndef EXPVARIAVEL_H
#define EXPVARIAVEL_H

#include "Expressao.h"
#include "TabelaHash.h"
#include <cstdlib>
#include <string>

using namespace std;

class ExpVariavel : public Expressao{
   private:
      string nome;
      TabelaHash* mem;
   public:
      ExpVariavel(TabelaHash*, string);
      ~ExpVariavel();
      int calcula();
};

#endif

