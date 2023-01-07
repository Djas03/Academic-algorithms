#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class ItemFatura {
    private:
        int id;
        string nome;
        int qtd;
        float precoUnit; 

    public:
        //Construtores
        ItemFatura(): nome("None"), id(0), qtd(0),precoUnit(0) {};
        ItemFatura (int id, string nome, int qtd, float precoUnit): id(id), nome(nome), qtd(qtd), precoUnit(precoUnit){};
        //Modificadores
        void set_id (int i) {id = i ;}
        void set_nome (string name) {nome = name;}
        void set_qtd (int qtd1) {qtd = qtd1;}
        void set_precoUnit (float precoU) {precoUnit = precoU;}
        
        //Seletores
        
        int get_id(){return id;}
        string get_nome(){return nome;}
        int get_qtd(){return qtd;}
        float get_precoUnit(){return precoUnit;}
        
        float totalItem(){ return qtd * precoUnit;}


        void imprime(){
            cout << "******************************"<<endl;
            cout << "ID : " << id << endl;
            cout << "Nome : " << nome << endl;
            cout << "Quantidade : " << qtd << endl;
            cout << "Preco Unidade : " << precoUnit << endl;
            cout << "Total : " << totalItem() << endl;
        }

        void imprime(string obs){
            cout << "**************"<< obs <<"****************"<<endl;
            cout << "ID : " << id << endl;
            cout << "Nome : " << nome << endl;
            cout << "Quantidade : " << qtd << endl;
            cout << "Preco Unidade : " << precoUnit << endl;
            cout << "Total : " << totalItem() << endl;
        }

};

class Fatura {
    private:
        vector<ItemFatura> *vet;


    public:
    //construtor
        Fatura();
    
    //destrutor
        ~Fatura();

    //metodo
    void addItem(ItemFatura it){vet->push_back(it);}
    void totalFatura(){
        float soma;
        for (auto saida : *vet){
            saida.imprime();
            soma = soma + saida.totalItem();
            
        }

        cout << "TOTAL DAS FATURAS : "<<soma<<endl;

    }


};

Fatura::Fatura(){
    vet = new vector<ItemFatura>();
}

Fatura::~Fatura(){
    delete(vet); vet=nullptr;
}




int main (){
    ItemFatura item1;
    item1.imprime("Default");

    item1.set_id(546516510);
    item1.set_nome("Feijao");
    item1.set_qtd(2);
    item1.set_precoUnit(10.0);
    item1.imprime("Atributos com set");

    ItemFatura item2(6555656,"Batata", 30, 50.0);
    item2.imprime("Com Parametros");
    
    item2.set_precoUnit(100.0);
    item2.imprime("Atualizado");

    cout<<endl;
    cout<<endl;
    cout<<"EXER. 2"<<endl;
    ItemFatura item3(415415151,"Tomate",60,3);
    
    Fatura vetor;
    vetor.addItem(item1);
    vetor.addItem(item2);
    vetor.addItem(item3);

    vetor.totalFatura();



}