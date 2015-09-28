#include "Interpretador.h"

Interpretador::Interpretador(string nomeArquivo){
   this->url = nomeArquivo;
   vect = new vector<Comando*>();
   escopo = new TabelaHash();
   mantem = false;
}

Interpretador::~Interpretador(){
   if (vect != NULL) delete vect;
   if (escopo != NULL) delete escopo;
   if (pilha != NULL) delete pilha;
}

void Interpretador::leArquivo(){
   string leitura;
   arquivo = new ArquivoFonte(this->url);
   Comando * comando;
   while(!arquivo->eof()){
	  if (mantem){
		  leitura = palavraAtual;
		  mantem = false;
	  }else{
		  leitura = arquivo->proximaPalavra();
	  }
      if (leitura == "read"){
         comando = comandoread();
         this->vect->push_back (comando);
	  }else if (leitura == "write"){
	     comando = comandowrite();
	     this->vect->push_back (comando);
	  }else if (leitura == "writeln"){
		  comando = new ComandoWriteln();
		  this->vect->push_back (comando);
	  }else if (leitura == "endp"){
		  comando = new ComandoEndp();
		  this->vect->push_back (comando);
	  }else if (leitura == "while"){
		  comando = comandowhile();
		  this->vect->push_back (comando);
      }else if(variavel(leitura)){
		  comando = comandoatrib(leitura);
		  this->vect->push_back (comando);
      }
   }
}

Comando* Interpretador::comandowhile(){
   ComandoWhile * comandow;
   Comando * comando;
   string leitura;
   arquivo->saltaPalavra();
   string var1 = arquivo->proximaPalavra();
   string op = arquivo-> proximaPalavra();
   string var2 = arquivo->proximaPalavra();
   if (var2 == "="){
      op = op + var2;
      var2 = arquivo -> proximaPalavra();
   }
   comandow = new ComandoWhile(escopo, var1, var2, op);
   arquivo->saltaPalavra();
   leitura = arquivo->proximaPalavra();
   while (leitura != "endw" && !arquivo->eof()){
      if (leitura == "read"){
         comando = comandoread();
         comandow->adicionaComando(comando);
	  }else if (leitura == "write"){
	     comando = comandowrite();
	     comandow->adicionaComando(comando);
	  }else if (leitura == "writeln"){
		 comando = new ComandoWriteln();
		 comandow->adicionaComando(comando);
	  }else if (leitura == "endp"){
		 comando = new ComandoEndp();
		 comandow->adicionaComando(comando);
	  }else if (leitura == "while"){
		 comando = comandowhile();
		 comandow->adicionaComando(comando);
      }else if(variavel(leitura)){
	     comando = comandoatrib(leitura);
	     comandow->adicionaComando(comando);
      }
      if (mantem){
		 leitura = palavraAtual;
		 mantem = false;
	  }else {
         leitura = arquivo->proximaPalavra();
      }
   }
   return comandow;
}

Comando* Interpretador::comandoatrib(string nome){
   Comando * comando;
   arquivo->saltaPalavra();
   Expressao * xp = trataExpressao();
   comando = new ComandoAtrib(escopo, nome, xp);
   conferePalavraAtual();
   return comando;
}

Comando* Interpretador::comandowrite(){
   Comando * comando;
   string leitura;
   arquivo->saltaPalavra();
   leitura = arquivo->proximaPalavra();
   if(leitura == "'"){
      leitura = "";
      string aux = arquivo->proximaPalavra();
      while(aux != "'"){
         leitura = leitura + aux;
         aux = arquivo->proximaPalavra();
      }
      comando = new ComandoWrite(leitura);
      arquivo->saltaPalavra();
   }else{
      if(arquivo->proximaPalavra()=="["){
		 string indice = arquivo->proximaPalavra();
         if (variavel(indice)){
			 comando = new ComandoWriteIndexVar(escopo, leitura, indice);
		 }else{
			int index = atoi(indice.c_str());
	        comando = new ComandoWriteIndex(escopo, leitura, index);
		 }
         arquivo->saltaPalavra();
         arquivo->saltaPalavra();
      }else{
         comando = new ComandoWriteVar(escopo, leitura);
      }	   
   }
   return comando;
}

Comando* Interpretador::comandoread(){
   Comando* comando;
   string leitura;
   arquivo->saltaPalavra();
   leitura = arquivo->proximaPalavra();
   comando = new ComandoRead(escopo, leitura);
   arquivo->saltaPalavra();
   return comando;
}

void Interpretador::executa(){
   int i;
   for (i=0; i < vect->size(); i++){
      (vect->at(i))->executa();
   }
}

Expressao* Interpretador::trataExpressao() {
   palavraAtual= arquivo->proximaPalavra();
   if (pilha != NULL) delete pilha;
   pilha = new stack<Expressao*>();
   expressao();
   Expressao * raizArvoreExpressao = pilha->top();
   pilha->pop();
   return raizArvoreExpressao;
}

void Interpretador::conferePalavraAtual(){
	if ((palavraAtual == "read") || (palavraAtual == "write") || (palavraAtual == "writeln") ||
	(palavraAtual == "while") || (palavraAtual == "endw") || (palavraAtual == "endw") || variavel(palavraAtual)) mantem = true;
}
  
void Interpretador::expressao() {
   termo();
   string op;
   while (palavraAtual == "+" || palavraAtual == "-") {
     op = palavraAtual;
     palavraAtual= arquivo->proximaPalavra();
     termo();
     Expressao *exp1 = pilha->top();
     pilha->pop();
     Expressao *exp2 = pilha->top();
     pilha->pop();
     pilha->push(new ExpBinaria(op,exp1,exp2));
   }  
}

void Interpretador::termo() {
   fator();
   string op;
   while (palavraAtual == "*" || palavraAtual == "/") {
     op = palavraAtual;
     palavraAtual = arquivo->proximaPalavra();
     fator();
     Expressao *exp1 = pilha->top();
     pilha->pop();
     Expressao *exp2 = pilha->top();
     pilha->pop();
     pilha->push(new ExpBinaria(op,exp1,exp2));
   }  
}


void Interpretador::fator() {
  int teste = atoi (palavraAtual.c_str());
  if (variavel(palavraAtual)) {
     pilha->push(new ExpVariavel(escopo, palavraAtual));
     palavraAtual = arquivo->proximaPalavra();
  }   
  else if (teste != 0 || (teste == 0 && palavraAtual == "0")) {
     pilha->push(new ExpLiteral(teste));
     palavraAtual = arquivo->proximaPalavra();
  }   
  else if (palavraAtual == "("){
     palavraAtual = arquivo->proximaPalavra();
     expressao();
     if (palavraAtual == ")")
        palavraAtual = arquivo->proximaPalavra();
  }   
}

bool Interpretador::variavel(string entrada){
	bool var = true;
	int i;
	int asc;
	for (i=0; i < entrada.length(); i++){
	    asc = (entrada.c_str())[i];
		if (!((asc >= 65 && asc <= 90 ) || (asc >= 97 && asc <= 122 ))){
			var = false;
		}
	}
	return var;
}
