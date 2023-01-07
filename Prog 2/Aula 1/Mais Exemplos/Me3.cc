#include <iostream>

using namespace std;

int main (){
    int v[10];

    cout << "Digite 10 valores: \n";
    for (int i = 0; i < 10; i++ ){
        cin >> v[i];
    }


    for (int i = 0; i < 10; i++ ){
        if (v[i]%2 == 0 && v[i] != 0){
            cout <<"numeros pares:" << v[i] << "\n";
        }
    }

}