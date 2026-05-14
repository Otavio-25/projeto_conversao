#include "validacao.hpp"
#include <string>
#include <iostream>
using namespace std;

bool validarEntrada(string valor, int base) {
    if(valor.empty()){
        return false;
    }

    string hex1 = "0123456789ABCDEF", hex2 = "0123456789abcdef";
    string octal = "01234567", decimal = "0123456789";
    int contador = 0, tamanho = valor.size();

    for(int i = 0; i < tamanho; i++) {
        char digito = valor[i];

        if(base == 2){
            if(digito == '0' || digito == '1'){
                contador++;
            }
        } 
        else if(base == 8){
            for(int j = 0; j < base; j++){
                if(digito == octal[j]){
                    contador++;
                }
            }
        }else if(base == 10){
            for(int j = 0; j < base; j++){
                if(digito == decimal[j]){
                    contador++;
                }
            }
        }else if(base == 16){
            for(int j = 0; j < base; j++){
                if(digito == hex1[j] || digito == hex2[j]){
                    contador++;
                }
            }
        }
    }

    if(contador == tamanho){
        return true;
    }else{
        return false;
    }
}