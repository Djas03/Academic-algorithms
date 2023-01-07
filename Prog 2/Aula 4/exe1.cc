#include <iostream>


using namespace std;

class Triangulo {
    public:
    float base;
    float altura;

    void calculaArea(){
        float area;
        area = (base*altura)/2;
        cout << "A área do Triangulo é: "<< area << endl;
    }
};


int main(){
    Triangulo t1;
    Triangulo t2;

    cout << "Digite a medida da base do primeiro triangulo:";
    cin >> t1.base;

    cout << "Digite a medida da altura do primeiro triangulo:";
    cin >> t1.altura;
    
    t1.calculaArea();

    cout << "Digite a medida da base do segundo triangulo:";
    cin >> t2.base;

    cout << "Digite a medida da altura do segundo triangulo:";
    cin >> t2.altura;

    
    
    t2.calculaArea();

}