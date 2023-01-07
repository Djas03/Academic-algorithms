#include "prototipacao.h"

namespace Trabalho{
//---------------Transporte---------------

//Contrutores
Transporte::Transporte() = default;
Transporte::Transporte(std::string nome,int numpassageiros,int velocidadeatual){
    Nome = nome; numPassageiros = numpassageiros; velocidadeAtual = velocidadeatual;
};
//Modificadores
void Transporte:: setNome(std::string nome){Nome = nome;}
void Transporte:: setNumPassageiros(int numpassageiros){numPassageiros = numpassageiros;}
void Transporte:: setVelocidadAtual(int velocidadeatual){velocidadeAtual = velocidadeatual;}
//Seletores
std::string Transporte:: getNome(){return Nome;}
int Transporte:: getNumPassageiros(){return numPassageiros;}
int Transporte:: getVelocidadAtual(){return velocidadeAtual;}

void Transporte::mostraDados(){
    std::cout<<"---------------Dados---------------"<<std::endl;
    std::cout<<"Nome: "<<getNome()<<std::endl;
    std::cout<<"Numero de Passageiros: "<<getNumPassageiros()<<std::endl;
    std::cout<<"Velocidade atual: "<<getVelocidadAtual()<<std::endl;
}




//---------------Operador---------------
void operator>(Transporte &obj1, Transporte &obj2){
    if (obj1.getNumPassageiros() > obj2.getNumPassageiros()){
        std::cout<< "O objeto: " << obj1.getNome() << " possui o maior numero de passageiros!"<<std::endl;
        obj1.mostraDados();
    } else if (obj2.getNumPassageiros() > obj1.getNumPassageiros()){
        std::cout<< "O objeto: " << obj2.getNome() << " possui o maior numero de passageiros!"<<std::endl;
        obj2.mostraDados();
        
    } else {
        std::cout<<"O numero de passageiros do objeto: "<< obj1.getNome() << " eh igual ao do objeto: "<< obj2.getNome()<<"!"<<std::endl;
    }
}

//---------------Terrestre---------------

//Contrutores
Terrestre::Terrestre() = default;
Terrestre::Terrestre(std::string nome,int numpassageiros,int velocidadeatual) :
    Transporte(nome,numpassageiros,velocidadeatual){}
//Metodo

bool Terrestre:: estaParado(){
    if(getVelocidadAtual() == 0){
        std::cout << "Estah parado!"<<std::endl;
        return true;
    } else {
        std::cout<<"Nao estah parado!"<<std::endl;
        return false;
    }
}

void Terrestre::mostraDados(){
    std::cout<<"---------------Dados---------------"<<std::endl;
    std::cout<<"Nome: "<<getNome()<<std::endl;
    std::cout<<"Numero de Passageiros: "<<getNumPassageiros()<<std::endl;
    std::cout<<"Velocidade atual: "<<getVelocidadAtual()<<std::endl;
}
 
//---------------Carro---------------

//Contrutores
Carro::Carro() = default;
Carro::Carro(std::string nome,int numpassageiros,int velocidadeatual) :
    Terrestre(nome,numpassageiros,velocidadeatual){}
//Metodo
void Carro::frear(){
    if(getVelocidadAtual() == 0){
        std::cout<<"O carro ja estah parado!"<<std::endl;
    } else{
        int aux = getVelocidadAtual()*0.25;
        setVelocidadAtual(getVelocidadAtual() - aux);
        std::cout<<"Velocidade atual: "<<getVelocidadAtual()<<std::endl; 
    }
}


//---------------Aereo---------------

//Contrutores
Aereo::Aereo() = default;
Aereo::Aereo(std::string nome,int numpassageiros,int velocidadeatual, int altura) :
    Transporte(nome,numpassageiros,velocidadeatual){Altura = altura;}
//Modificadores
void Aereo::setAltura(int altura){Altura = altura;}
//Seletor
int Aereo::getAltura(){return Altura;}

bool Aereo:: estaParado(){
    if(getVelocidadAtual() == 0){
        std::cout << "Estah parado!"<<std::endl;
        return true;
    } else {
        std::cout<<"Nao estah parado!"<<std::endl;
        return false;
    }
}

void Aereo::mostraDados(){
    std::cout<<"---------------Dados---------------"<<std::endl;
    std::cout<<"Nome: "<<getNome()<<std::endl;
    std::cout<<"Numero de Passageiros: "<<getNumPassageiros()<<std::endl;
    std::cout<<"Velocidade atual: "<<getVelocidadAtual()<<std::endl;
    std::cout<<"Altura atual: "<<getAltura()<<std::endl;
}

//---------------Aviao---------------

//Contrutores
Aviao::Aviao() = default;
Aviao::Aviao(std::string nome,int numpassageiros,int velocidadeatual, int altura) :
    Aereo(nome,numpassageiros,velocidadeatual, altura){}
//Metodos
void Aviao::subir(int metros){
    if (metros + getAltura() > 10000){
        std::cout<<"Erro! Limite de altura do Aviao ultrapassado!"<<std::endl;
    } else {
        setAltura(getAltura() + metros);
        std::cout<<"Altura atual: "<<getAltura()<<std::endl;
    }
}
void Aviao::descer(int metros){
    if(getAltura() == 0){
        std::cout<<"Aviao ja estah no chao!";
    }else if((getAltura() - metros) < 0){
        std::cout <<"Erro! Limite do chao ultrapassado!"<<std::endl ;
    } else{
        setAltura(getAltura() - metros);
        std::cout<<"Altura atual: "<<getAltura()<<std::endl;
    }
}


//---------------Balao---------------

//Contrutores
Balao::Balao() = default;
Balao::Balao(std::string nome,int numpassageiros,int velocidadeatual, int altura) :
    Aereo(nome,numpassageiros,velocidadeatual, altura){}
//Metodos
void Balao::subir(int metros){
    if (metros + getAltura() > 1000){
        std::cout<<"Erro! Limite de altura do Balao ultrapassado!"<<std::endl;
    } else {
        setAltura(getAltura() + metros);
        std::cout<<"Altura atual: "<<getAltura()<<std::endl;
    }
}
void Balao::descer(int metros){
    if(getAltura() - metros == 0){
        std::cout<<"O Balao ja estah no chao" << std::endl;
   }else if((getAltura() - metros) < 0){
        std::cout <<"Erro! Limite do chao ultrapassado!"<<std::endl ;

    } else{
        setAltura(getAltura() - metros);
        std::cout<<"Altura atual: "<<getAltura()<<std::endl;
    }
}



}