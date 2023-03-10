#include <iostream>

using namespace std;

//Vetor criado para armazenar os valores de fibonacci
long long int vetor[1000];

int fibona(int valor){
    if(vetor[valor] != -1)
        return vetor[valor];

    if(valor < 0)
        return 0;

    if(valor == 1 || valor ==  0)
        return valor;

    vetor[valor] = fibona(valor-1) + fibona(valor-2);
    return vetor[valor];
}


int main(){

    //preencher vetor inicialmente
    for (int i=0; i<1000; i++)
    {
        vetor[i] = -1;
    }

    //definindo primeira e segunda posição  
    vetor[0] = 0;
    vetor[1] = 1;
    
    int fibonacci;
    cout << "Digite um valor para calculo da funcao de fibonacci F(x): ";
    cin >> fibonacci;
  
    

    cout << "Fibonac: ";
    cout << fibona(fibonacci) << endl;
    +
    return 0;

}