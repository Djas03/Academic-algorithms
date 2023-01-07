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
    
    double rd;

    scanf("%lf",&rd);


    if (rd <= 2000.00){
        printf("Isento\n");
    }
    else if (rd > 2000.00 && rd <= 3000.00){
        rd = (rd - 2000.00) * 0.08;
        printf("R$ %.2lf\n",rd);
    }
    else if (rd > 3000.00 && rd <= 4500.00){
        rd = (rd - 3000.00) * 0.18 + 1000.00 * 0.08;
        printf("R$ %.2lf\n",rd);
    }else{
        rd = (rd - 4500.00) * 0.28 + 1500.00 * 0.18 + 1000.00 * 0.08;
        printf("R$ %.2lf\n",rd);
    }
    return 0;
}