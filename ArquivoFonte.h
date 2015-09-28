#ifndef ARQUIVOFONTE_H
#define ARQUIVOFONTE_H

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

namespace interpretadorTiny
{
	class ArquivoFonte
	{
	private:
		ifstream arq;
		string linha;
		size_t pos;
		string delim;
		bool em_string;
	public:

		ArquivoFonte(string name)
		{
			delim = "+-*/()=<> ':[]";
			arq.open(name.c_str());
			if (arq.is_open()) {
				getline(arq, linha);
				pos = 0;
				em_string = false;
			} else {
				cerr << "Nao eh possivel abrir o arquivo especificado." <<endl;
				exit(0);
			}
		}

		string proximaPalavra()
		{
			string s;
			size_t posFinal = 0;
			if (delim.find_first_of(linha.at(pos)) != string::npos) {
				posFinal = pos+1;
			} else {
				posFinal = linha.find_first_of(delim, pos+1);
			}
			if (posFinal == string::npos)
				posFinal = linha.size();
			s = linha.substr(pos, posFinal - pos);
			pos = posFinal;
			if (posFinal == linha.size()) {
				do {
					if (arq.eof()) {
						linha = "EOF";
					} else {
							getline(arq, linha);
					}
				} while (linha.size() == 0);
				pos = 0;
			}
			if (s == "'")
				em_string = !em_string;
			if ((s == " ") && (!em_string))
				return proximaPalavra();
			return s;
		}
		
		bool eof(){
		   return arq.eof();
		}

		void saltaPalavra()
		{
			string s = proximaPalavra();
		}

		~ArquivoFonte(void)
		{
			arq.close();
		}

	};

}

#endif
