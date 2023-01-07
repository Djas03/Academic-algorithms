/*2. Refa¸ca o exerc´ıcio anterior, desta vez utilizando shared ptr no lugar dos ponteiros tradicionais na
fun¸c˜ao create e weak ptr nas fun¸c˜oes de inser¸c˜ao e impress˜ao para inserir e imprimir, onde as
opera¸c˜oes de inser¸c˜ao e impress˜ao s´o ser˜ao realizadas ap´os o uso da fun¸c˜ao lock() de weak ptr.
Crie tamb´em uma fun¸c˜ao create unique, semelhante `a create, mas que retorne um unique ptr
no lugar. No programa principal, al´em de testar as demais fun¸c˜oes convertidas, crie tamb´em dois
unique ptr’s e atribua um ao outro da maneira correta.*/

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

//prototipção das funções
shared_ptr<vector<int>> create ();
unique_ptr<int> create_unique();
void insert (weak_ptr<vector<int>> vet ,int val);
void imprime (weak_ptr<vector<int>> vet);

//Função principal
int main (){

    auto vetor = create();
    insert (vetor, 40);
    imprime(vetor);

    auto a = create_unique();

    

    
    unique_ptr<int> A(new int (48));
    unique_ptr<int> B(A.release());
    unique_ptr<int> C;
    C.reset(B.release());
    auto D = C.release();
    delete D;
    
    

}

shared_ptr<vector<int>> create (){
    auto vet = make_shared<vector<int>>();
    return vet;
}

unique_ptr<int> create_unique(){
    auto v = unique_ptr<int>();
    return v;
}


void insert (weak_ptr<vector<int>> vet ,int val){
    if (auto v = vet.lock()){
        v -> push_back(val);
    }
}



void imprime (weak_ptr<vector<int>> vet){
    if(auto v = vet.lock()){
        for (auto c : *v){
            cout << c << endl;
        }
    }    
}
