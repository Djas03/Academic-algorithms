#ifndef prototipacao_h
#define prototipacao_h
#include <iostream>

namespace Trabalho{

//---------------Transporte---------------
class Transporte{
    private:
        std::string Nome;
        int numPassageiros;
        int velocidadeAtual;
    public:
        //construtores
        Transporte();
        Transporte(std::string nome,int numpassageiros,int velocidadeatual);
        //modificadores
        void setNome(std::string nome);
        void setNumPassageiros(int numpassageiros);
        void setVelocidadAtual(int velocidadeatual);
        //seletores 
        std::string getNome();
        int getNumPassageiros();
        int getVelocidadAtual();
        //Métodos
        virtual bool estaParado() = 0;
        friend void operator>(Transporte &obj1,Transporte &obj2);
        virtual void mostraDados();
};

    //---------------Terrestre---------------
    class Terrestre: public Transporte{
        public:
            //construtores
            Terrestre();
            Terrestre(std::string nome,int numpassageiros,int velocidadeatual);
            //Métodos
            virtual void frear() = 0;
            bool estaParado() override;
            void mostraDados() override;

    };

        //---------------Carro---------------
        class Carro: public Terrestre{
            public:
                //construtor
                Carro();
                Carro(std::string nome,int numpassageiros,int velocidadeatual) ;
                //Métodos
                void frear() override;
            

        };




    //---------------Aereo---------------
    class Aereo: public Transporte{
        private:
            int Altura;
        public:
            //construtores
            Aereo();
            Aereo(std::string nome,int numpassageiros,int velocidadeatual, int altura);
            //Modificadores
            void setAltura(int altura);
            //Seletores
            int getAltura();
            //Métodos
            virtual void subir(int metros) = 0;
            virtual void descer(int metros) = 0;
            bool estaParado() override;
            void mostraDados() override;
    };

        //---------------Aviao---------------
        class Aviao: public Aereo{
            public:
                //Construtores
                Aviao();
                Aviao(std::string nome,int numpassageiros,int velocidadeatual, int altura);
                //Métodos
                void subir (int metros) override;
                void descer (int metros) override;
            
        };
        
        //---------------Balao---------------
        class Balao: public Aereo{
            public:
                //Construtores
                Balao();
                Balao(std::string nome,int numpassageiros,int velocidadeatual, int altura);
                //Métodos
                void subir (int metros) override;
                void descer (int metros) override;
        
        };

    }

#endif