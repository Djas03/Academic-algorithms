#include <iostream>

using namespace std;

int main (){

    int n,cont,val;

    cout << "Deseja fazer fatorial de qual numero?\n";
    cin >> n;

    val = n;

    if (n == 0){
        n = 1;
    }else if (n > 0){
        cont = n-1;
        while (cont > 1){
            n = n * cont;
            cont -=1;
        }
    }

    cout << "\n" << val << "! = " << n << "\n";

    
}