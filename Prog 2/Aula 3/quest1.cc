/*1. Escreva uma fun¸c˜ao create que retorne um vetor de inteiros dinamicamente alocado (vocˆe pode usar
a classe vector para declarar conforme o slide 7 da Aula 3 ainda que n˜ao tenha sido apresentado,
desde que inclua a biblioteca vector).
Passe tal vetor para outra fun¸c˜ao cujo prot´otipo seja semelhante a void insert(vetor, valor)
que insira o parˆametro valor no vetor passado (a fun¸c˜ao push back(valor) adiciona valor no
final do vetor).
Passe o mesmo vetor para outra fun¸c˜ao que imprima na tela os valores lidos.
Teste as fun¸c˜oes criadas no programa principal. Lembre-se de utilizar o delete no momento
apropriado.
*/

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//Prototipação das funções
vector <int> *create ();
void insert (vector<int>*vet ,int val);
void imprime (vector<int> *vet);

//Função principal
int main (){

    auto vetor = create();
    insert (vetor, 50);
    insert (vetor, 70);
    insert (vetor, 80);
    imprime(vetor);
    delete (vetor);


}


vector <int> *create (){
    vector<int> *vet = new vector<int>;
    return vet;
}


void insert (vector<int>*vet ,int val){
    vet -> push_back(val);
}



void imprime (vector<int> *vet){
    for (auto c : *vet){
        cout << c << endl;
    } 
}