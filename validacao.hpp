/*
Nessa parte, o ifndef serve para "perguntar" se alguém
já registrou o arquivo validacao_hpp, se ninguém registrou,
o define faz o registro. Isso possibilita que o arquivo
validacao.hpp seja lido apenas uma vez durante todo o seu
uso, e impede de dar erro.
*/
#ifndef validacao_hpp
#define validacao_hpp
#include <iostream>
using namespace std; 

bool validarEntrada(string valor, int base);

#endif
//endif apenas fecha o bloco que o ifndef abriu.