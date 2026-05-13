#include <iostream>
#include <string>
using namespace std;

void converte_8_2(int &a, int b){
    int contador=0;
    int vetor[100];
    while (a>0)
    {
        vetor[contador]=a%b;
        a=a/b;
        contador++;
    }

    if (b==2)
    {   
        cout<<"Conversao Decimal para Binario: ";
        for (int j = contador-1; j >=0; j--)
        {
            cout<<vetor[j];
        }
        cout<<endl;
        
    }else{
        
       cout<<"Conversao Decimal para Octal: ";
       for (int j = contador-1; j >=0; j--)
        {
            cout<<vetor[j];
        }
        cout<<endl;
    }
    
    
}

void converte_16(int &a){
    string base_hexa= "0123456789ABCDEF";  
    string hexadecimal="";
    while (a > 0)
    {
        int resto = a%16;
        hexadecimal = base_hexa[resto]+hexadecimal;
        a=a/16;
    }
    cout<<"Conversao Decimal para Hexadecimal: "<<hexadecimal<<endl;
    
}


int main(){
    char continuar='s';
    while (continuar=='s')
    {
        
        cout<<"-----------------------"<<endl;
        cout<<" Conversoes de Decimal "<<endl;
        cout<<"-----------------------"<<endl;
        cout<<" Base 2 - Binaria "<<endl;
        cout<<" Base 8 - Octal "<<endl;
        cout<<" Base 16 - Hexadecimal "<<endl;
        cout<<endl;

        int base,decimal;

        cout<<"Digite o Numero da base desejada : ";
        cin>>base;

        cout<<"Digite o numero Decimal para conversao : ";
        cin>>decimal;

        cout<<endl;

        if (base==2)
        {converte_8_2(decimal,base);}

        else if (base==8)
        {converte_8_2(decimal,base);}

        else if (base==16)
        {converte_16(decimal);}
        
        else{cout<<"Digite uma base correta!!";}
    
        cout<<endl;
        cout<<"Quer converter outro numero? (s/n): ";
        cin>>continuar;
        cout<<endl;

        if (continuar == 's')
        {
            system("cls");//limpa o restante do terminal para entrar um novo layot
        }   
    }

    cout<<"Programa encerrado, Muito Obrigado !!"<<endl;

    return 0;
}