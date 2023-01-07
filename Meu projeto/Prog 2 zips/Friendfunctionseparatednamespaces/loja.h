#ifndef loja_h
#define loja_h

#include "mercado.h"

namespace loja {
  class Compra {
    private:
      int value = 10;
    public:
      friend void mercado::fatura(Compra &c, mercado::Compra &d);
      int getValue(){return value;};
};
} // namespace mercado

#endif