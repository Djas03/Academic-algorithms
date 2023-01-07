#include <iostream>

using namespace std;

void troca (int a, int b);

int main (){

    int A,B;

    cout << "Digite dois valores:" << endl;

    cin >> A >> B;

    cout << "Valores iniciais:" << endl << "A = " << A << endl << "B = " << B << endl;

    troca (A,B);

}

void troca (int a, int b){
    int aux;

    aux = a;
    a = b;
    b = aux;

    cout << "Valores finais:" << endl << "A = " << a << endl << "B = " << b << endl;

}