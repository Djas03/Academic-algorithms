#include <iostream>

using namespace std;

int main(){

    int N;

    cout << "Insira a quantidade de numeros:";
    cin >> N;

    int vet [N];

    for (int i = 0; i < N; i++){
        vet[i] = i+1;
    }

    for (int i = 0; i < N; i++){
        vet[i] = vet[i]*vet[i];
    }

    cout << "\nQuadrado dos numeros:\n";
    for (int i = 0; i < N; i++){
        cout << vet[i] << "\n";
    }
}