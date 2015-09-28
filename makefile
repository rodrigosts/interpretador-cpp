all:
	g++ Main.cpp TabelaHash.cpp ComandoRead.cpp ComandoWrite.cpp ComandoWriteVar.cpp ComandoWriteIndex.cpp ComandoWriteIndexVar.cpp ComandoWriteln.cpp ComandoEndp.cpp ComandoWhile.cpp ComandoAtrib.cpp Interpretador.cpp VariavelInteira.cpp VariavelString.cpp ExpLiteral.cpp ExpVariavel.cpp ExpBinaria.cpp -o tp2

clean:
	rm tp1
