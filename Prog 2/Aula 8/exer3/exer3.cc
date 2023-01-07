#include <iostream>
#include "loja.h"
#include "mercado.h"

void mercado::faturar(loja::Compra &obj1, mercado::Compra &obj2){
    std::cout<<"Fatura : R$ " << (obj1.getValorCompra()*obj1.getqtdItens()) + (obj2.getValorCompra()*obj2.getqtdItens()) <<std::endl;
}


int main (){

    loja::Compra l1(4,10.0);
    mercado::Compra m1(2,5.0);
    
    mercado::faturar(l1, m1);
}
