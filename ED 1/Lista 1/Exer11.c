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

    int N,num;

    scanf("%d",&N);

    while (N > 0){
        scanf("%d",&num);

       if (num > 0){
           if (num % 2 == 0){
               printf("EVEN POSITIVE\n");
           }else{
               printf("ODD POSITIVE\n");
           }
       }

       if (num < 0){
           if (num % 2 == 0){
               printf("EVEN NEGATIVE\n");
           }else{
               printf("ODD NEGATIVE\n");
           }
       }

       if (num == 0){
            printf("NULL\n");
        }

        N--;
    }

    return 0;
}