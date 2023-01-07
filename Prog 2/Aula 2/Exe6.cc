#include <iostream>

using namespace std;

struct retangulo {
    float altura;
    float largura;
};
typedef struct retangulo RT;

float area (RT var){
    return var.altura*var.largura;
    
}

int main (){
    RT retangulo;
    retangulo.altura = 0.0;
    retangulo.largura = 0.0;

    cout << "Digite a altura do retangulo:";
    cin >> retangulo.altura;

    cout << "Digite a largura do retangulo:";
    cin >> retangulo.largura;

    cout << "A area do retangulo eh: " << area(retangulo);


}

