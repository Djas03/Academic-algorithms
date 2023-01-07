#include <iostream>
#include "loja.h"
#include "mercado.h"
using std::string;
using std::cout;


void loja::fatura(loja::Compra &c, mercado::Compra &d){
  cout << c.value<<std::endl;
  cout << d.value<<std::endl;
}

int main() {
  string str1 = "Example";
  using std::cout, std::endl;
  loja::Compra c;
  mercado::Compra d;
  loja::fatura(c,d);
  //cout << str1 <<endl;
  
}
