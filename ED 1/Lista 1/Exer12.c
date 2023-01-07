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

    int N,n1,n2,n3;

    scanf("%d",&N);
    n1 = 1;
    n2 = 2;
    n3 = 3;

    while(N > 0){
        printf("%d %d %d PUM\n",n1 ,n2 ,n3);

        n1 += 4;
        n2 += 4;
        n3 += 4;

        N --;

    }
 
    return 0;
}