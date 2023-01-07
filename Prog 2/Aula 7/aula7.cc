#include <iostream>

using namespace std;

class Data
{
private:
    int dia, mes, ano;

public:
    Data(){dia = 0; mes = 0; ano = 0;};
    Data(int d, int m, int a){ dia = d; mes = m; ano = a;};
    friend bool operator==(Data &date1, Data &date2);
    friend void operator++(Data &date);
    friend void operator+(Data &date, int n);
    friend void operator+=(Data &date, int n);
    friend std::istream &operator>>(std::istream &is, Data &date);
    friend std::ostream &operator<<(std::ostream &os, const Data &date);
    void setDia(int d){dia = d;};
    void setMes(int m){mes = m;};
    void setAno(int a){ano = a;};
    int getDia(){return dia;};
    int getMes(){return mes;};
    int getAno(){return ano;};
    int ultimoDiaMes(){
        if (getMes()== 1 || getMes()== 3 || getMes()== 5 || getMes()== 7 || getMes()== 8 || getMes()== 10 || getMes()== 12){
            int ultimoDia = 31;
            return ultimoDia;
        }else if (getMes()== 4 || getMes()== 6 || getMes()== 9 || getMes()== 11){
            int ultimoDia = 30;
            return ultimoDia;
        }else{
            
            if( (getAno() % 400 == 0) || ( (getAno() % 4 == 0) && (getAno() % 100 != 0) ) ){
                int ultimoDia = 29;
                return ultimoDia;
            }else{
               int ultimoDia = 28;
                return ultimoDia;
            }
        }
    };
    void imprime(){
        cout<<getDia()<<"/"<<getMes()<<"/"<<getAno()<<endl;
    };
};

bool operator==(Data &date1, Data &date2){
    if ((date1.getMes() == date2.getMes() && date1.getDia() == date2.getDia() && date1.getAno() == date2.getAno()) == true){
        cout<<"Sao iguais!"<<endl;
    }else{
        cout<<"Nao sao iguais!"<<endl;
    }
    return date1.getMes() == date2.getMes() && date1.getDia() == date2.getDia() && date1.getAno() == date2.getAno();
}

void operator++(Data &date){
    if (date.getDia() == date.ultimoDiaMes()){
        date.setDia(1);
        
        if (date.getMes()+1 > 12){
            date.setMes(1);
            date.setAno(date.getAno()+1);
        }else{
            date.setMes(date.getMes()+1);
        }
    }else{
        date.setDia(date.getDia()+1);
    }
}
void operator+(Data &date, int n){

    date.setDia(date.getDia()+n);
     while(date.getDia() > date.ultimoDiaMes()){
            date.setDia(date.getDia()-date.ultimoDiaMes());
            if (date.getMes() >= 12){
                date.setMes(1);
                date.setAno(date.getAno()+1);
            }else{
                date.setMes(date.getMes()+1);
            }
        
        }
}

void operator+=(Data &date, int n){
    operator+(date,n);
}

std::istream &operator>>(std::istream &is, Data &date){
    cout << "Digite uma data XX/XX/XXXX"<<endl;
    is >> date.dia >> date.mes >> date.ano;
    if(is){

    }
    return is;

} 
std::ostream &operator<<(std::ostream &os, const Data &date){
    os << date.dia<<"/" << date.mes<<"/" << date.ano;
    
    return os;
}

int main (){
    cout << "*************** testando Classe ***************"<<endl;
    Data date1(29,02,2024);
    Data date2(23,02,2004);

    date1.imprime();
    //testando operador ==
    cout << "************* testando operador ==*************"<<endl;
    date1==date2;

    //testando operador ++
    cout << "************* testando operador ++*************"<<endl;
    ++date1;
    date1.imprime();

    //testando operador +
    cout << "********** testando operador + (365) **********"<<endl;
    date1+365;
    date1.imprime();

    //testando operador +=
    cout << "************* testando operador +=*************"<<endl;
    for (int i = 0; i < 10; i++){
        date1+=1;
    }
    date1.imprime();

    //testando operador >>
    cout << "************* testando operador >>*************"<<endl;
    std::cin >> date1;
    //testando operador <<
    cout << "************* testando operador <<*************"<<endl;
    std::cout << date1;

    return 0;
}
