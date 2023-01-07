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

    int n;

    scanf("%d",&n);

    printf("Fib(%d)[ ",n);

    n = fibo(n);
    printf ("%d ]\n",n);


    return 0;
}

int fibo (int N ){
    if (N == 0){
        return 0;
    }else if(N == 1){
        return 1;
    }else{
        
        return fibo(N-1)+fibo(N-2);
    
    }
}