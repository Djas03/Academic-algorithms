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

    int n,cont,val;

    scanf("%d", &n);

    val = n;

    n = fatorial(n);

    printf("%d! = %d\n",val,n);
 
    return 0;
}

//funcao que calcula o fatorial
int fatorial (int N){
    if (N == 0 ){
        return 1;
    }else{
        return N * fatorial (N - 1);
    }
}