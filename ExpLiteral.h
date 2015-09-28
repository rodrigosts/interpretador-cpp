#ifndef EXPLITERAL_H
#define EXPLITERAL_H

#include "Expressao.h"

class ExpLiteral : public Expressao{
   private:
      int valor;
   public:
      ExpLiteral(int);
      int calcula();
};

#endif
