#include <iostream>
#include <string>

using namespace std;
using std :: string;

int main (){
    string P;

    cout << "Digite uma palavra:";

    cin >> P;
    

    string reversed;

    int tam = P.size();

    for (int i = 0; i < tam; i++){
        reversed = P[i] + reversed;

    }

    cout << "Palavra invertida: "<< reversed << endl;



}