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

    if (n == 0){
        n = 1;
    }else if (n > 0){
        cont = n-1;
        while (cont > 1){
            n = n * cont;
            cont -=1;
        }
    }

    printf("%d! = %d\n",val,n);
 
    return 0;
}