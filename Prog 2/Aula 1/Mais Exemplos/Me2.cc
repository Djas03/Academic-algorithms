#include <iostream>

using namespace std;

int main (){
    int F,C;
    cout << "Insira a temperatura em Fahrenheit:\n";
    cin >> F;
    C = (F - 32) * 5/9;

    cout << "Em Celsius eh = " << C << "\n";


}