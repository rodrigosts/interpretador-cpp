#ifndef VARIAVEL_H
#define VARIAVEL_H

#include <string>
using namespace std;

class Variavel{
   private:
      string nom;
      
   public:
      string nome(){return nom;}
      void defNome (string nome){nom = nome;}
      virtual string leValor() = 0;
      virtual int leValorInt() = 0;
      virtual int tamanho() = 0;
};

#endif
