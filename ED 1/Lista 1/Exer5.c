/*
UFMT - Estrutura de dados 1
prof. Ivairton 
Aluno: Djalma de Almeida Mendes
*/

//Bibliotecas 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Funcao principal
int main (){
    double A,B,C,delta,delta2,deltasolu, raiz, r1,r2;

    scanf("%lf %lf %lf",&A,&B,&C);

    delta = B*B;
    delta2 = 4*A*C;
    deltasolu = delta - delta2;

    if (delta2 > delta ||delta2 == 0){
        printf("Impossivel calcular\n");
    }else{
        raiz = sqrt(deltasolu);
        r1 = ((-B)+raiz)/(2*A);
        r2 = ((-B)-raiz)/(2*A);

        printf("R1 = %.5lf\n",r1);
        printf("R2 = %.5lf\n",r2);

    }
    return 0;
}