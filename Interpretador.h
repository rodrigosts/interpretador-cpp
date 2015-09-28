#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H

#include "Comando.h"
#include "ComandoRead.h"
#include "ComandoWrite.h"
#include "ComandoWriteIndex.h"
#include "ComandoWriteIndexVar.h"
#include "ComandoWriteVar.h"
#include "ComandoWriteln.h"
#include "ComandoEndp.h"
#include "ComandoAtrib.h"
#include "ArquivoFonte.h"
#include "TabelaHash.h"
#include "Variavel.h"
#include "VariavelInteira.h"
#include "VariavelString.h"
#include "ComandoWhile.h"
#include "Expressao.h"
#include "ExpBinaria.h"
#include "ExpVariavel.h"
#include "ExpLiteral.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <stack>

using namespace std;
using namespace interpretadorTiny;

class Interpretador {
   private:
      bool mantem;
      string url;
      string palavraAtual;
      vector<Comando*>* vect;
      stack<Expressao*>* pilha;
      TabelaHash* escopo;
      ArquivoFonte *arquivo;
      Comando* comandowrite();
      Comando* comandoread();
      Comando* comandoatrib(string);
      Comando* comandowhile();
      Expressao* trataExpressao();
      void conferePalavraAtual();
      void expressao();
      void termo();
      void fator();
      bool variavel(string);
      
   public:
      Interpretador(string);
      void leArquivo();
      void executa();
      ~Interpretador();      
};

#endif
