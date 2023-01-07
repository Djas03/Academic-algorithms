#include <iostream>

using namespace std;



int main (){
    int N, n;
    int soma;
    soma  = 0;

    cout << "Insira a quantidade de numeros : ";
    cin >> N;
    int v[N];

    for (int i = 0; i < N; i++){
        cin >> v[i];
    }

    cout << "Quantos dos primeiros numeros pares devem ser somados ?\n";
    cin >> n;
    int cont = 0;
    for (int i = 0; i < N; i++){

        if (cont < n && v[i]%2 == 0){
        soma = soma + v[i];
        cont++;
        }
    }
    cout << "A somatoria eh = " << soma << "\n";
    


}