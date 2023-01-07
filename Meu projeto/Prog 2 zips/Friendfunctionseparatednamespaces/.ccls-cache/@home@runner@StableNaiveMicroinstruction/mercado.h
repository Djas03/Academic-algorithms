#ifndef mercado_h
#define mercado_h

#include "loja.h"

namespace mercado {
  class Compra {
    private:
      int value = 20;
    public:
      friend void loja::fatura(loja::Compra &c, Compra &d);
      int getValue(){return value;};
};
} // namespace mercado

#endif