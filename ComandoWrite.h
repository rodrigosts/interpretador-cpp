#ifndef COMANDOWRITE_H
#define COMANDOWRITE_H

#include "Comando.h"
#include <string>
#include "TabelaHash.h"
#include "Variavel.h"
#include "VariavelInteira.h"
#include "VariavelString.h"


class ComandoWrite : public Comando{
   private:
      Variavel* conteudo;
      string nome;
      
   public:
      void setConteudo(Variavel*);
      Variavel* getConteudo();
      void setNome(string);
      string getNome();
      ComandoWrite(string);
      virtual void executa();
      ~ComandoWrite();
};

#endif
