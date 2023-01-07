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

    double M[12][12], soma, media;
    int linha, coluna, cl;
    char O[2];

    scanf("%S",&O);
    

    for (linha = 0; linha <= 11; linha++){
        for (coluna = 0; coluna <= 11; coluna++){
            scanf("%lf", &M[linha][coluna]);
        }
    }


    if (O[0] == "S"){

        linha = 0;
        soma = 0;
        coluna = 0;

        while (linha <= 10){

            cl = coluna;

            while (cl <= 11){

                soma = soma + M [linha][coluna];

            }

            coluna++;
            linha++;

            


        }
        
        printf("%.1lf\n",soma);
    }

    if (O[0] == "M"){
        linha = 0;
        soma = 0;
        coluna = 0;

        while (linha <= 10){

            cl = coluna;

            while (cl <= 11){

                soma = soma + M [linha][coluna];

            }

            coluna++;
            linha++;

            


        }
        
        media = soma / 66;
        printf("%.1lf\n", media);

    }
    
    return 0;
}