#ifndef EXPBINARIA_H
#define EXPBINARIA_H

#include "Expressao.h"
#include <cstdlib>
#include <string>

using namespace std;

class ExpBinaria : public Expressao{
   private:
      Expressao* expr1;
      Expressao* expr2;
      string op;
      
   public:
      ExpBinaria(string, Expressao*, Expressao*);
      ~ExpBinaria();
      int calcula();
};

#endif

