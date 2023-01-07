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
    double n,raio, raioe2, area;
    scanf ("%lf",&raio);
    

    n = 3.14159;
    raioe2 = raio*raio;
    area = n * raioe2;

    printf ("A=%0.4lf\n", area);

    return 0;
}