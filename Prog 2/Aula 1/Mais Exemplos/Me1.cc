#include <iostream>

using namespace std;

int main (){
    int a,b;
    cout << "insira dois valores:\n";

    cin >> a;
    cin >> b;
    if ( a > b){
        cout << "o maior eh A = " << a << "\n";
    }
    if (b > a){
        cout << "o maior eh B = " << b <<"\n";
    }
}