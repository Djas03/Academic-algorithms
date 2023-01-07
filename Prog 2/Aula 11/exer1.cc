#include <iostream>

template <typename T, typename U>

void troca (T &a, U &b){
    T aux;
    aux = a;
    a = b;
    b = aux;
} 


int main (){

    std::string a = "gato", b = "cachorro";
    std::cout << "a = "<< a << " b = "<< b << std::endl;
    troca(a,b);
    std:: cout << "Trocados: a = "<< a << " b = "<< b << std::endl;
}