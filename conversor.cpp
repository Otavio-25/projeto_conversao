#include "conversor.hpp"
#include <string>
#include <cmath>
#include <iostream>
using namespace std;


string decimalParaOutras(int valor, int base){

    string resultado="";
    if (base==2)
    {
        
        while (valor>0)
        {
            if (valor%base==1)
            { resultado = '1' + resultado;
            }else{resultado = '0' + resultado;}
            
            valor=valor/base;
        }    
    } else if(base==8){//decimal -> octal

        resultado="";
        while (valor>0)
        {
            resultado=to_string(valor%base)+resultado;//isso aqui transforma os valores inteiros em carcteres , pq somados um int+string da erro 
            valor=valor/base;
        } 

    } else if (base==16){//decimal-> hexadecimal

        string base_hexa = "0123456789ABCDEF";
        resultado="";
        while(valor>0){

           int resto=valor%base;
           
           resultado=base_hexa[resto]+resultado;

           valor/=base;
        }
    }
    return resultado;
}



//outras bases para decimal
int outrasParaDecimal(string valor, int base){

    int tamanho=valor.size();
    int resultado=0;
    if(base == 2){

        for(int i = 0; i < tamanho ; i++){
            resultado+=(valor[i]-'0')* pow(2,tamanho-1-i);// esse valor[i]-'0' ,transforma o caracter numero em um numero de verdade 
        }
    }
    else if(base == 8){

        for(int i = 0; i < tamanho ; i++){
            resultado+=(valor[i]-'0')* pow(8,tamanho-1-i);
        }
    }
    else if(base == 16){

        for(int i = 0; i < tamanho ; i++){

            int digito;

            if(valor[i]>='0' and valor[i]<='9'){

                digito= valor[i]-'0';//com essa operçao coneguimos converter o valor de char para um numero real

            } else{
                digito= valor[i]-'A' +10;//esse aqui faz a subtraçao das letras , tipo A-C=2 eles tbm tem valores , fazendo assim eles transformao em numeros e soma com o 10 
            }
            resultado+=digito*pow(16,tamanho-1 - i);
        }

    }
    
    
    return resultado;
}

//Binario->Octal


string binarioOctal(string valor){
    int tamanho=valor.size();
    int resultado;
    if(tamanho%3==1){

        valor="00"+valor;//aqui eu acrescento caso esteja faltando , aqui tem um numero a mais que o agrupamento de 3 ent precisa de mais 2 zeros pra ajudar a completar o agrupamento de 3 

    }else if(tamanho%3==2){

        valor="0"+valor;

    }

    tamanho=valor.size();
    string octal="";

    for(int i = 0; i < tamanho ; i+=3){//separa por 3 em 3 
        int b1=valor[i]-'0';
        int b2=valor[i+1]-'0';
        int b3=valor[i+2]-'0';

        resultado=b1*4 + b2*2 + b3*1;//aqui pega por posiçao e faz a multiplicaçao , acha um unico valor fazendo a soma desses 3 

        octal+=(resultado+'0');// diferente de outros que vimos esse é o contrario , ele faz o numero -> caractere
    }
    return octal;
}

//binario->hexadecimal
string binarioHex(string valor){

    int tamanho=valor.size();
    int resultado;

    int resto=tamanho%4;
    int zeros = (4 - resto)%4;
    for(int i = 0; i < zeros ; i++){//aqui vou acrescentar zeros para fazer o agrupamento de 4 a 4 
        valor="0"+valor;
    }


    tamanho=valor.size();
    string hex="";

    for(int i = 0; i < tamanho ; i+=4){//separa por 4 por 4 
        int b1=valor[i]-'0';
        int b2=valor[i+1]-'0';
        int b3=valor[i+2]-'0';
        int b4=valor[i+3]-'0';

        resultado=b1*8 + b2*4 + b3*2 + b4*1;//aqui pega por posiçao e faz a multiplicaçao , acha um unico valor fazendo a soma desses 3 
        if(resultado<=9){
            hex+= (resultado+ '0');
        }else{
            hex+=(resultado-10 +'A');//aqui faz uma tranformaçao de A=0, ent se o 12-10=2 nesse caso vamos somar com o A , A+2=C
        }
        
    }
    return hex;
}

//octal->hexadecimal



string octalhex(string valor){
    int tamanho=valor.size();
    string bin="";
    for(int i = 0; i < tamanho ; i++){
        int digito=valor[i]-'0';
        if(digito == 0){bin+= "000";}
        if(digito == 1){bin+= "001";}
        if(digito == 2){bin+= "010";}
        if(digito == 3){bin+= "011";}
        if(digito == 4){bin+= "100";}
        if(digito == 5){bin+= "101";}
        if(digito == 6){bin+= "110";}
        if(digito == 7){bin+= "111";}

    }

    return binarioHex(bin);
}






string conversorBases(string valor, int baseOrigem, int baseDestino){

    if(baseOrigem == baseDestino){// se forem iguais 
        return valor;
    }

    if(baseOrigem == 10){//decimal-> outras bases
            int valorInt= stoi(valor);//passa o valor string , para um inteiro , pois se for base 10 , so vai entrar numeros

            string resposta = decimalParaOutras(valorInt, baseDestino);
            return resposta;
    }
   
    else if(baseDestino == 10){//Outras bases -> decimal

        int respostaInt = outrasParaDecimal(valor, baseOrigem);

        return to_string(respostaInt);
    } 

    else if(baseOrigem==2 ){//binario -> octal ou hexadecimal

        if(baseDestino==8){

            string resultado = binarioOctal(valor);
            return resultado;
        }
        if(baseDestino==16){

            string resultado = binarioHex(valor);
            return resultado;
        }
        
    }

    else if(baseOrigem=8){
        string resultado = octalhex(valor);
        return resultado;
    }
    return valor;
}

