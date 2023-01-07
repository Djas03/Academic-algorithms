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

    int cont;
    double v1,v2,v3,v4,v5,v6,media;

    cont = 0;

    scanf("%lf",&v1);
    if (v1 > 0){
        cont++;
    }else{
        v1 = 0;
    }
    scanf("%lf",&v2);
    if (v2 > 0){
        cont++;
    }else{
        v2 = 0;
    }
    scanf("%lf",&v3);
    if (v3 > 0){
        cont++;
    }else{
        v3 = 0;
    }
    scanf("%lf",&v4);
    if (v4 > 0){
        cont++;
    }else{
        v4 = 0;
    }
    scanf("%lf",&v5);
    if (v5 > 0){
        cont++;
    }else{
        v5 = 0;
    }
    scanf("%lf",&v6);
    if (v6 > 0){
        cont++;
    }else{
        v6 = 0;
    }

    printf("%d valores positivos\n",cont);

    media = (v1 + v2 + v3 + v4 + v5 + v6) / cont;

    printf ("%.1lf\n", media);

    return 0;
}