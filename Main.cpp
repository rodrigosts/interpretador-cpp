#include "Interpretador.h"
#include <string> 
#include <iostream>

using namespace std;

int main(int argc, char** argv){
   Interpretador *interpretador = new Interpretador(argv[1]);
   interpretador->leArquivo();
   interpretador->executa();
   delete interpretador;
   return 0; 
}

