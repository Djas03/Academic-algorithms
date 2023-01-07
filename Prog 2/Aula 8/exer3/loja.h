#ifndef loja_h
#define loja_h

#include "mercado.h"

namespace loja {
    class Compra{
        private:
        int qtdItens;
        double valorCompra;

        public:
        Compra(){qtdItens = 0; valorCompra = 0.0;}
        Compra(int qtditens, double valorcompra){qtdItens = qtditens; valorCompra = valorcompra;}
        double getValorCompra(){return valorCompra;}
        int getqtdItens(){return qtdItens;}

        friend void mercado::faturar(Compra &obj1, mercado::Compra &obj2);

    };
}

#endif