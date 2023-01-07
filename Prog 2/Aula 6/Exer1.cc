/*Escreva uma classe VeiculoAVenda que represente informações básicas
sobre um veículo genérico que esteja à venda, como: marca, modelo, ano e
preçoDeVenda. Defina o construtor que inicialize todos os atributos, além
dos métodos seletores e modificadores para cada um dos atributos. Defina
um método virtual chamado mostraDados() que imprima na tela os
dados dos atributos do veículo.

*Escreva uma classe AutomovelAVenda que seja derivado da classe acima.
Acrescente os atributos para motor (1.0, 1.4, 1.6, p.ex), um booleano para
câmbio automático ou manual e um inteiro para número de portas . Defina
o método construtor e os métodos seletores e modificadores para os novos
atributos.

*Sobrescreva o método mostraDados() da classe base para mostrar
também os dados dos atributos que foram acrescentados na classe derivada.
Escreva uma classe MotocicletaAVenda que também seja derivado da
classe VeiculoAVenda. Acrescente um atributo para o valor da
cilindrada do motor. Defina o método construtor e o método seletor e
modificador para o novo atributo.
Sobrescreva o método mostraDados() da classe base para mostrar
também o atributo que foi acrescentado.

*No programa principal, crie uma aplicação que instancie dois objetos de
cada classe derivada. Por fim, seu programa deve mostrar os dados de cada
um dos objetos instanciados e a somatória dos preços de venda de todos,
utilizando para isso uma única estrutura de dados.*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class VeiculoAVenda {
    private:
        string Marca, Modelo;
        int Ano;
        double precoDeVenda;
    public:
        //Construtor
        VeiculoAVenda (string marca, string modelo, int ano, double precodevenda): 
            Marca (marca), Modelo (modelo), Ano(ano), precoDeVenda(precodevenda){}

        //seletores
        string get_marca(){return Marca;}
        string get_modelo(){return Modelo;}
        int get_ano(){return Ano;}
        double get_precoDeVenda(){return precoDeVenda;}

        //metodos
        virtual double mostraDados(){
            cout<<"**************Veiculo************"<<endl;
            cout <<"Marca : "<<Marca<<endl;
            cout <<"Modelo : "<<Modelo<<endl;
            cout <<"Ano : "<<Ano<<endl;
            cout <<"Preco de Venda : "<<precoDeVenda<<endl;
            cout<<"*******************************"<<endl;
        }

        //modificadores
        void set_marca(string marca){Marca = marca;}
        void set_modelo(string modelo){Modelo = modelo;}
        void set_ano(int ano){Ano = ano;}
        void set_precoDeVenda(double precodevenda){precoDeVenda = precodevenda;}

};

class  AutomovelAVenda : public VeiculoAVenda {
    private:
        double Motor;
        bool Cambioauto;
        int NumPortas;

    public:
        //construtor
        AutomovelAVenda(string marca, string modelo, int ano, double precodevenda,double motor, bool cambio, int numportas):
            VeiculoAVenda (marca, modelo, ano, precodevenda), Motor(motor), Cambioauto(cambio), NumPortas(numportas){}
        
        //seletores
        double get_motor(){return Motor;}
        bool get_cambio(){return Cambioauto;}
        int get_numPortas(){return NumPortas;}
        //modificadores
        void set_motor(double motor){Motor = motor;}
        void set_cambio(bool cambio){Cambioauto = cambio;}
        void set_numportas(int numportas){NumPortas = numportas;}
        //metodos
        double mostraDados() override {
            cout<<"**************Automovel**************"<<endl;
            cout <<"Marca : "<<get_marca()<<endl;
            cout <<"Modelo : "<<get_modelo()<<endl;
            cout <<"Ano : "<<get_ano()<<endl;
            cout <<"Preco de Venda : "<<get_precoDeVenda()<<endl;
            cout <<"Motor : "<<get_motor()<<endl;
            if(get_cambio() == true){
                cout<<"Cambio Automatico : Sim"<<endl;
            }else{
                cout<<"Cambio Automatico : Nao"<<endl;
            }
            cout <<"Numero de Portas : "<<get_numPortas()<<endl;
            cout<<"*************************************"<<endl;
        }
};

class MotocicletaAVenda : public VeiculoAVenda {
    private:
        int CilindradaMt;
    
    public:
        MotocicletaAVenda(string marca, string modelo, int ano, double precodevenda, int cilindradamt):
            VeiculoAVenda(marca,modelo,ano,precodevenda), CilindradaMt(cilindradamt){}

        //seletor
        int get_cilindradaMt(){return CilindradaMt;}
        //modificador
        void set_cilindradaMt(int cilindradamt){CilindradaMt = cilindradamt;}

        //metodo
        double mostraDados() override {
            cout<<"**************Motocicleta************"<<endl;
            cout <<"Marca : "<<get_marca()<<endl;
            cout <<"Modelo : "<<get_modelo()<<endl;
            cout <<"Ano : "<<get_ano()<<endl;
            cout <<"Preco de Venda : "<<get_precoDeVenda()<<endl;
            cout <<"Cilindrada do Motor : "<<get_cilindradaMt()<<endl;
            cout<<"*************************************"<<endl;

        }

};

typedef struct Struct_Veiculos{
    vector<VeiculoAVenda*> Vet;
    double Total;
}Veiculos; 



int main (){
    VeiculoAVenda v0("Ford", "m1",1999,40000.50);
    
    AutomovelAVenda v1("Chevrolet","m1",1999,40000.90,1.5,false,4);
    MotocicletaAVenda v2("Honda", "m2", 2010, 10000.90,250);

    v1.mostraDados();
    v2.mostraDados();
    
    Veiculos veiculos;
    veiculos.Vet.push_back(&v1);
    veiculos.Vet.push_back(&v2);
    veiculos.Total = 0;

    for (auto f : veiculos.Vet){
        veiculos.Total += f->get_precoDeVenda();
    }
    cout << "====================================="<<endl;
    cout << "Preco total = " << veiculos.Total << endl;
    cout << "====================================="<<endl;
    

    return 0;
}