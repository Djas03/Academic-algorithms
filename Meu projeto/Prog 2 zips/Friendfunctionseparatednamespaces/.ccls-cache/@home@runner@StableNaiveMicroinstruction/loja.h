#ifndef loja_h
#define loja_h
namespace mercado{
  class Compra;
}

namespace loja {
  class Compra {
    private:
      int value = 10;
    public:
      friend void fatura(Compra &c, mercado::Compra &d);
      int getValue(){return value;};
};
} // namespace mercado

#endif