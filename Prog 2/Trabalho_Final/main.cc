#include <iostream>
#include "prototipacao.h"

using namespace Trabalho;

int main (){
  
    Carro t3("Dodge Challenger SRT8",4,60);
    Aviao t5("Boeing 777",314,700,9000);
    Balao t6("Montgolfier",2,9,910);

    std::cout<<"-------------testes Aviao----------------"<<std::endl;
    t5.subir(10);
    t5.subir(1000);
    t5.descer(10);

    std::cout<<"-------------testes Balao----------------"<<std::endl;
    t6.subir(20);
    t6.subir(80);
    t6.descer(20);

    std::cout<<"-------------testes Carro----------------"<<std::endl;
    t3.frear();

    std::cout<<"-------------teste da Funcao amiga----------------"<<std::endl;
    t5>t6;


    return 0;
}