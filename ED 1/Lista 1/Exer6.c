/*
UFMT - Estrutura de dados 1
prof. Ivairton 
Aluno: Djalma de Almeida Mendes
*/

//Bibliotecas 
#include <stdio.h>
#include <stdlib.h>


//Funcao principal
int main (){

    int cod, quant;
    double CQ,Xs,Xb,Ts,Refri, vp;

    CQ = 4.00;
    Xs = 4.50;
    Xb = 5.00;
    Ts = 2.00;
    Refri = 1.50;

    scanf("%d",&cod);
    scanf("%d",&quant);

    vp = 0;

    if (cod == 1){
        while (quant > 0){
            vp = vp + CQ;
            quant--;
        }
    }
    if (cod == 2){
        while (quant > 0){
            vp = vp + Xs;
            quant--;
        }
    }
    if (cod == 3){
        while (quant > 0){
            vp = vp + Xb;
            quant--;
        }

    }
    if (cod == 4){
        while (quant > 0){
            vp = vp + Ts;
            quant--;
        }

    }
    if (cod == 5){
        while (quant > 0){
            vp = vp + Refri;
            quant--;
        }

    }

    printf("Total: R$ %.2f\n", vp);

    return 0;
}