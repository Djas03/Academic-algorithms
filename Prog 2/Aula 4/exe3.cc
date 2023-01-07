#include <iostream>

using namespace std;

class Empregado {
    public:
    string nome;
    float salario;

    void aumento(float porcentagem){
        float salario1;
        porcentagem = porcentagem / 100;
        salario1 = salario * porcentagem;
        salario = salario + salario1;
    }

    void mostraDados(){
        cout << "Nome: "<< nome << endl;
        cout << "Salario: "<<salario<<endl;
    }
};

int main (){
    float porcent;

    Empregado e1;

    cout << "Digite o nome do Empregado:";
    cin >> e1.nome;

    cout << "Digite o Salario do empregado:";
    cin >> e1.salario;

    cout << "Digite a porcentagem do aumento:";
    cin >> porcent;

    e1.mostraDados();
    e1.aumento(porcent);
    e1.mostraDados();


}