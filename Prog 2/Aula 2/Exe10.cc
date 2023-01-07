#include <iostream>

using namespace std;

int incrementa (int n);

int main (){
    int N;

    cout << "Digite um valor:";

    cin >> N;

    cout << "Valor antes da funcao: " << N << endl;

    cout << "Valor apos a funcao : " << incrementa(N) << endl;

    
}

int incrementa (int n){
    return n += 1;
}
