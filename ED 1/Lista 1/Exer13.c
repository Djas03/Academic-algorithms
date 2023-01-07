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

    int N1,N2, cont1,cont2;

    scanf("%d %d",&N1,&N2);

    cont1 = 1;
    cont2 = 1;

    while (cont2 <= N2){
        
        if (cont1 < N1){
            printf("%d ",cont2);
            cont1++;
        }else{
            printf("%d\n",cont2);
            cont1 = 1;
        }
        

        cont2++;
    }
 
    return 0;
}