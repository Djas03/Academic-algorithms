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

    int N,total;
    double media,cont;

    total = 0;
    cont = 0;

    while (1){
        scanf("%d",&N);
        if (N < 0){
            break;
        }else{
            total += N;
            cont++;
        }
    }

    media = total / cont;

    printf("%.2lf\n",media);
 
    return 0;
}