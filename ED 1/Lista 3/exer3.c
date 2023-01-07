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

    printf ("Valores pares entre 1 e %d:\n",n);

    n = print (n);


 
    return 0;
}

int print (int N){


    if (N % 2 == 0 && N > 0){
        
        printf ("%d\n",N);
        print (N - 2);
        
    }else{
        print(N - 1);
    }
}