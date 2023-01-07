#include <iostream>

using namespace std;

double media (double soma){
    return soma / 2.0;

}

int main (){
    int N;
    double soma;
    soma  = 0;

    cout << "Insira a quantidade de numeros : ";
    cin >> N;
    double v[N];

    for (int i = 0; i < N; i++){
        cin >> v[i];
    }
    for (int i = 0; i < N; i++){
        soma = soma + v[i];
    }
    cout << "A somatoria eh = " << soma << "\n";
    cout << "A media aritmehtica eh = " << media (soma) << "\n";



}