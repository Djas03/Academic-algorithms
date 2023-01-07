#include <iostream>

namespace A{
    namespace B{
        int mult (int a, int b);
    }
}

namespace AB = A::B;

int AB::mult(int a, int b){
    return a * b;
}

int main (){

    std::cout<<"AB : "<<AB::mult(3,3)<<std::endl;
}
