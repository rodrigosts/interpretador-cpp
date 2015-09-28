#ifndef TABELAHASH_H
#define TABELAHASH_H

#include "Variavel.h"
#include "VariavelInteira.h"
#include "VariavelString.h"
#include <map>
#include <string>
#include <iostream>

using namespace std;

class TabelaHash{
   private:
      map<string,Variavel*> dados;   
   public:
      TabelaHash();
      void inserir(string, Variavel*);
      Variavel* valorDe(string);   
};

#endif
