#include <iostream>
#include <string>

using namespace std;

class Lampada{
    public:
    string marca;
    bool ligada;
    int tipo;
    int watt;
    int cor;

    void ligar(){
        ligada = true;
    }

    void desligar (){
        ligada = false;
    }

    void status (){
        if (ligada == true){
            cout << "Lampada " << marca << " está ligada"<<endl;
        }else{
            cout << "Lampada" << marca << " está desligada"<<endl;
        }
    }

    bool ehEconomica(){
        if (watt<40){
            return true;
        }else{
            return false;
        }

    }
};


int main (){
    Lampada l1,l2;
    int dado;

    cout << "Digite nome da marca da primeira Lampada:";
    cin >> l1.marca;
    cout << "Digite a potência da primeira lampada:";
    cin >> l1.watt;
    cout << "Digite 1 para ligar e 0 para desligar a primeira lampada:";
    cin >> dado;
    if (dado == 1){
        l1.ligar();
    }else{
        l1.desligar();
    }

    cout << "Digite nome da marca da segunda Lampada:";
    cin >> l2.marca;
    cout << "Digite a potência da segunda lampada:";
    cin >> l2.watt;
    cout << "Digite 1 para ligar e 0 para desligar a segunda lampada:";
    cin >> dado;
    if (dado == 1){
        l2.ligar();
    }else{
        l2.desligar();
    }

    l1.status();

    if (l1.ehEconomica() == true){
        cout << "Primeira Lampada eh economica"<<endl;
    }else{
        cout << "Primeira lampada nao eh economica" << endl;
    }

    l2.status();

    if (l2.ehEconomica() == true){
        cout << "Segunda Lampada eh economica"<<endl;
    }else{
        cout << "Segunda lampada nao eh economica" << endl;
    }


}