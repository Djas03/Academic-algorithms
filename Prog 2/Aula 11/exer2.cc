#include <iostream>

template <typename T> T maximum (const T &a, const T &b){
    if (a < b){
        return b;
    
    }else if (a == b){
        std::cout<< "Sao iguais!"<<std::endl;
    }else{
        return a;
    }
    
} 


int main (){

    std::string a = "gato", b = "cachorro";
    std::cout << "a = "<< a << " b = "<< b << std::endl;
    auto res = maximum(a,b);
    std:: cout << "Maior Valor: " << res << std::endl;
}