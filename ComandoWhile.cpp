#include "ComandoWhile.h"
#include <iostream>
using namespace std;

ComandoWhile::ComandoWhile(TabelaHash* mem, string valor, string valor2, string op){
   this->valor = valor;
   this->valor2 = valor2;
   this->op = op;
   this->mem = mem;
   vect = new vector<Comando*>();
}

ComandoWhile::~ComandoWhile(){
	if(mem != NULL) delete mem;
	if(vect != NULL) delete vect;
}

void ComandoWhile::executa(){
	int i;
	while (verificaCondicao()){
	   for (i=0; i < vect->size(); i++){
          (vect->at(i))->executa();
       }
	}
}

void ComandoWhile::adicionaComando(Comando * comando){
	vect->push_back(comando);
}

bool ComandoWhile::verificaCondicao(){
	int val1, val2;
	string aux;
	bool condicao = false;
	val1 = atoi (valor.c_str());
	val2 = atoi (valor2.c_str());
	if(val1==0 && valor!="0"){
		if(valor.rfind(".length") == string::npos){
		   val1 = mem->valorDe(valor)->leValorInt();
	    }else{
		    aux = valor.substr(0, valor.size()-7);
			val1 = mem->valorDe(aux)->tamanho();
		}
    }
    if(val2==0 && valor2!="0"){
		if(valor2.rfind(".length") == string::npos){
		   val2 = mem->valorDe(valor2)->leValorInt();
	    }else{
			aux = valor2.substr(0, valor2.size()-7);
			val2 = mem->valorDe(aux)->tamanho();
		}
    }
    if ( op == "<"){
		condicao = (val1 < val2)? true: false;
	}else if ( op == "<="){
		condicao = (val1 <= val2)? true: false;
	}else if (op == ">"){
		condicao = (val1 > val2)? true: false;
	}else if (op == ">="){
		condicao = (val1 >= val2)? true: false;
	}else if (op == "=="){
		condicao = (val1 == val2)? true: false;
	}else if (op == "!="){
		condicao = (val1 != val2)? true: false;
	}
	return condicao;
}

