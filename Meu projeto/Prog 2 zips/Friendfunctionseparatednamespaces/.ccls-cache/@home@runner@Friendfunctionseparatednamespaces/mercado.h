#ifndef mercado_h
#define mercado_h

 namespace loja{
   class Compra;
 }

namespace mercado {
  class Compra {
    private:
      int value = 20;
    public:
      friend void fatura(loja::Compra &c, Compra &d);
      int getValue(){return value;};
};
} // namespace mercado

#endif