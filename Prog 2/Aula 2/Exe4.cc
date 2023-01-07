#include <iostream>

using namespace std;

int main (){

    string P;

    cout << "Digite uma frase: ";
    getline (cin, P);
    

    for(auto c : P){
        if (!isspace(c)){
        cout << c;
        }
    }
}