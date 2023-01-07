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

    int h1,h2,cont;

    scanf("%d %d",&h1,&h2);

    if (h1==h2){
        cont = 24 - h1 + h2;
        printf("O JOGO DUROU %d HORA(S)\n",cont);

    } else if (h1<=h2){
        cont = h2 - h1;
        printf("O JOGO DUROU %d HORA(S)\n",cont);

    }else {
        cont = 24 - h1 + h2;
        printf("O JOGO DUROU %d HORA(S)\n",cont);
    }
 
    return 0;
}