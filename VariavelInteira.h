#ifndef VARIAVELINT_H
#define VARIAVELINT_H

#include "Variavel.h"
#include <string>
#include <sstream>

using namespace std;

class VariavelInteira : public Variavel{
   private:
      int valor;
      
   public:
      VariavelInteira(string);
      VariavelInteira(string,int);
      string leValor();
      int leValorInt();
      int tamanho();
    
};

#endif
