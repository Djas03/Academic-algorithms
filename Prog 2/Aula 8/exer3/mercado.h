#ifndef mercado_h
#define mercado_h

namespace loja {
    class Compra;
}

namespace mercado{
    class Compra{
        private:
        int qtdItens;
        double valorCompra;

        public:
        Compra(){qtdItens = 0; valorCompra = 0.0;}
        Compra(int qtditens, double valorcompra){qtdItens = qtditens; valorCompra = valorcompra;}
        double getValorCompra(){return valorCompra;}
        int getqtdItens(){return qtdItens;}

        friend void faturar(loja::Compra &obj1, Compra &obj2);

    };
}

#endif