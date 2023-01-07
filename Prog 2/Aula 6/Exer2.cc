
/*Escreva a classe ObjetoGeometrico que represente um objeto
geométrico em duas dimensões. Esta classe deve ter métodos virtuais para
mostrar seus dados e calcular e retornar a sua área e perímetro.
Usando esta classe como base, escreva as classes herdeiras:
Circulo (contendo duas coordenadas para o centro e um raio);
Retangulo (contendo dois valores para os lados) e;
Triangulo (contendo três valores para os lados).
Todas as classes derivadas devem sobrepor os métodos descritos em
ObjetoGeometrico.
Dicas: a área de um círculo pode ser calculada com 𝜋𝑟2, onde 𝑟 é o raio do
círculo. O perímetro de um círculo é dado por 2𝜋𝑟. O perímetro do
retângulo é dado por 2𝑏 + 2ℎ. A área de um triângulo é dada por
√(𝑠(𝑠 − 𝑎)(𝑠 − 𝑏)(𝑠 − 𝑐) onde a, b e c são os lados do triângulo e s é a
metade do perímetro do triângulo (𝑎 + 𝑏 + 𝑐).
No programa principal, instancie um objeto de cada classe derivada,
utilizando do conceito de polimorfismo para mostrar na tela a área o
perímetro de cada um dos objetos a partir de um único objeto de referência.*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class ObjetoGeometrico {
    private:

    public:
        virtual double get_area() =  0;
        virtual double get_perimetro () = 0; 
        virtual void get_mostradados () = 0;
};

class Circulo : public ObjetoGeometrico {
    private:
        double Centro;
        double Raio;
    public:
        //construtor
        Circulo (double centro, double raio) : Centro (centro), Raio (raio) {};
        //
        double get_area() override {double Area = (3.14 * pow(Raio,2)); return Area;}
        double get_perimetro () override {double Perimetro = (2*3.14*Raio); return Perimetro;}
        void get_mostradados() override {
            cout <<"***********Circulo***********"<<endl;
            cout <<"Centro : " << Centro <<endl;
            cout <<"Raio : " << Raio <<endl;
            cout <<"Area : "<< get_area()<<endl;
            cout <<"Perimetro : "<<get_perimetro()<<endl;
            cout <<"*****************************"<<endl;
            }
        

};

class Retagulo : public ObjetoGeometrico{
    private:
        double B;
        double H;
    public:
        //construtor
        Retagulo (double b, double h) :B(b), H(h) {};
        //
        double get_area() override {double Area = (B*H); return Area;}
        double get_perimetro () override {double Perimetro = ((2*B)+(2*H)); return Perimetro;}
        void get_mostradados() override {
            cout <<"**********Retangulo**********"<<endl;
            cout <<"Base : " << B <<endl;
            cout <<"Altura : " << H <<endl;
            cout <<"Area : "<< get_area()<<endl;
            cout <<"Perimetro : "<<get_perimetro()<<endl;
            cout <<"*****************************"<<endl;
            }
        

};

class Triangulo : public ObjetoGeometrico{
    private:
        double A;
        double B;
        double C;
        double S;
    public:
        //construtor
        Triangulo (double a, double b,  double c) :  A(a), B (b), C(c){};
        //
        double get_perimetro () override {double Perimetro = (A+B+C); return Perimetro;}
        double calc_S () {S = (get_perimetro())/2; return S;}
        double get_area() override {calc_S(); double Area = (sqrt((S*(S-A)*(S-B)*(S-C)))); return Area;}
        void get_mostradados() override {
            cout <<"**********Triangulo**********"<<endl;
            cout <<"A : " << A <<endl;
            cout <<"B : " << B <<endl;
            cout <<"C : " << C <<endl;
            cout <<"S : " << calc_S() <<endl;
            cout <<"Perimetro : "<<get_perimetro()<<endl; 
            cout <<"Area : "<< get_area()<<endl;
            cout <<"*****************************"<<endl;
            }


};



int main (){

    Circulo c1(1.0, 3.0);
    Retagulo r1(2,2);
    Triangulo t1(3,5,7);

    vector<ObjetoGeometrico*> Objetos;

    Objetos.push_back(&c1);
    Objetos.push_back(&r1);
    Objetos.push_back(&t1);

    for (auto f : Objetos){
        f->get_mostradados();
    }

    return 0;
}