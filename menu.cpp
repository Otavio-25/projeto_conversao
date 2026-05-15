//menu com as opcoes de operacao

#include <iostream>
 #include "validacao.hpp" 
 #include "conversor.hpp" //das funcoes de validacao de valores em outro arquivo
using namespace std;

void menuPrincipal(){
    cout << "===========================" << endl;
    cout << "   CONVERSOR DE VALORES   " << endl;
    cout << "===========================" << endl;
    cout << "1 - Conversao Simples" << endl;
    cout << "2 - Conversao com Fracionarios" << endl;
    cout << "3 - Conversao Passo a Passo" << endl;
    cout << "4 - Modo Batch" << endl;
    cout << "5 - Modo Quiz" << endl;
    cout << "6 - Calculadora de Maximos" << endl;
    cout << "0 - Sair do Programa" << endl;
    cout << "===========================" << endl;
    cout << "Escolha uma opcao : ";
}

int main(){
    int opcao, baseOrigem, baseDestino;
    string valorEntrada, resultado; //string para o valor de entrada, pois pode ser um hexadecimal que utiliza letras

    do{
        cout<<endl;
        menuPrincipal();
        cin >> opcao;

        if(opcao == 1){
            cout << endl << "Base Origem (2, 8, 10, 16) : ";
            cin >> baseOrigem;
            cout << "Digite o valor : ";
            cin >> valorEntrada;
            cout << "Base Destino (2, 8, 10, 16) : ";
            cin >> baseDestino;

            //funcao para ver se o valor pertence à base
            if(validarEntrada(valorEntrada, baseOrigem)){
                resultado = conversorBases(valorEntrada, baseOrigem, baseDestino);
                cout << "Resultado : " << resultado << endl;
            }else{
                cout << "Erro! O numero digitado nao pertende a base" << endl;
            }
        }else if(opcao == 2){

        }else if(opcao == 3){

        }else if(opcao == 4){

        }else if(opcao == 5){

        }else if(opcao == 6){

        }else if(opcao == 0){
            cout << "Programa encerrado, Muito Obrigado !" << endl;
        }else{
            cout << "Opcao Invalida, digite um valor válido !" << endl;
        }



    } while(opcao != 0);

    return 0;
}
