#ifndef VARIAVELSTRING_H
#define VARIAVELSTRING_H

#include "Variavel.h"
#include <string>
#include <cstdlib>

using namespace std;

class VariavelString : public Variavel{
   private:
      string valor;
      
   public:
      VariavelString(string);
      VariavelString(string,string);
      string leValor();
      int leValorInt();
      int tamanho();
};

#endif
