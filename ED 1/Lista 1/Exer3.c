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
    int x;
    double y,CM;
    scanf("%d",&x);
    scanf("%lf",&y);

    CM = x / y; //calculo do consumo medio

    printf("%0.3lf km/l\n",CM);
 
    return 0;
}