#include <iostream>

using namespace std;

void par (int num, int i){
    if (num % 2 == 0 && num != 0){
        cout << "vet["<< i << "] = " << num << ": Verdadeiro!\n";
    }
}

int main (){
    int v[10];

    cout << "Digite 10 valores:\n";

    for (int i = 0; i < 10; i++ ){
        cin >> v[i];
    }


    for (int i = 0; i < 10; i++ ){
       
        par (v[i],i);
    }

}
