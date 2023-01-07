#include <iostream>

namespace fun1 {
    int soma (int a,int b){
        return a + b;
    }
}

namespace fun2 {
    int soma (int a,int b){
        return a + b;
    }
}

int main (){

    std::cout<<"Funcao soma 1: "<<fun1::soma(6,8)<<std::endl;
    std::cout<<"Funcao soma 2: "<<fun2::soma(9,2)<<std::endl;
}