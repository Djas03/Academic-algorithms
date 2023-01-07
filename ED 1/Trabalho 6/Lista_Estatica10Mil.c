/*
* UFMT - Ciencia da Computacao
* Estrutura de Dados 1 - Trabalho 6 : lst - estatica x dinamica 
* Prof Ivairton
* Discentes: Djalma de Almeida Mendes, Lucas Barbosa Amaral 
*/

//Bibliotecas
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 

//Tamanho da lista 
#define TAM 10000

//Estrutura da lista
struct estrutura_lista
{
    int lista[TAM];
    int quant;

};
typedef struct estrutura_lista tipo_lista;

//Prototipo das funcoes

void inserir_inicio(tipo_lista *f, int vl);
void inserir_fim(tipo_lista *f, int vl);
void inserir_posi (tipo_lista *f, int posi, int vl);
int remove_ini (tipo_lista *f);
int remove_fim(tipo_lista *f);
int remove_posi(tipo_lista *f, int posi);
void imprimelista(tipo_lista *f);


//Funcao principal
int main (){
    tipo_lista minha_lista;
    minha_lista.quant = 0;

    int cont1,i,j;
    clock_t t;

    //Inicializa o gerador de números randomicos, a partir de uma semente
    srand(time (NULL)); 

        
    //INSERCAO NO INICIO
    //---------------------------------------------------------------------------------------------------------
    printf("\n\nINSERCAO NO INICIO\n");
    printf("-----------------------------------------------------------------------------------------\n");
    t = clock();
    for (cont1 = 0; cont1 <3333; cont1 ++){
        i = rand () %   1000000;
        inserir_inicio(&minha_lista, i);
    }
    t = clock() - t;
    printf("Tempo: %lf milissegundos\n\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("-----------------------------------------------------------------------------------------\n");
    //---------------------------------------------------------------------------------------------------------



    //INSERCAO NO FIM 
    //---------------------------------------------------------------------------------------------------------
    printf("\n\nINSERCAO NO FIM\n");
    printf("-----------------------------------------------------------------------------------------\n");
    t = clock();
    for (cont1 = 0; cont1 <3333; cont1 ++){
        i = rand () %   1000000;
        inserir_fim(&minha_lista, i);
    }
    t = clock() - t;
    printf("Tempo: %lf milissegundos\n\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("-----------------------------------------------------------------------------------------\n");
    //---------------------------------------------------------------------------------------------------------



    //INSERCAO EM POSICOES ALEATORIAS
    //---------------------------------------------------------------------------------------------------------
    printf("\n\nINSERCAO EM POSICOES ALEATORIAS\n");
    printf("-----------------------------------------------------------------------------------------\n");
    t = clock();
    for (cont1 = 0; cont1 <3334; cont1 ++){
        i = rand () %   1000000;
        j = rand () %   10000;
        inserir_posi (&minha_lista,j,i);
    }
    t = clock() - t;
    printf("Tempo: %lf milissegundos\n\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("-----------------------------------------------------------------------------------------\n");
    //--------------------------------------------------------------------------------------------------------- 
    printf("\n\n\n");
    //imprimelista(&minha_lista);

    return 0;
}

void inserir_inicio(tipo_lista *f, int vl){
    if (f -> quant < TAM){
        
        int quant2 = f -> quant;
        while (quant2 >= 1){
            f -> lista [quant2] = f -> lista [quant2 - 1];
            quant2--; 
        }

        f -> lista [0] = vl;
        f -> quant++;



    }else{
        printf("ERRO a lista estah cheia!\n");
    }
}


void inserir_fim(tipo_lista *f, int vl){
    if (f-> quant < TAM){
        f -> lista [f -> quant++] = vl;
    }else{
        printf("ERRO a lista estah cheia!\n");
    }
}


void inserir_posi (tipo_lista *f,int posi, int vl){
    if (f-> quant < TAM){
        if (f -> quant > posi && f->quant != posi){
        
        int quant2 = f -> quant;
        while (quant2 > posi){
            f -> lista [quant2] = f -> lista [quant2 - 1];
            quant2--; 
        }
        f -> lista [posi] = vl;
        f -> quant++;
        }else{
            f-> lista[f->quant] = vl;
            f -> quant++;
        }
    }else{
        printf("ERRO a lista estah cheia!\n");
    }
}


int remove_ini (tipo_lista *f){
    if (f -> quant > 0 ){
        int cont = f -> lista [0];
        int quant2 = 1;
        while (quant2 < f -> quant){
            f -> lista [quant2 - 1] = f -> lista [quant2];
            quant2++; 
        }
        f -> quant--; 
        return cont;

    }else{
        printf("ERRO a lista estah vazia\n");
    }
    
}


int remove_fim(tipo_lista *f){
    if (f -> quant > 0){
        return f -> lista [--f -> quant];

    }else{
        printf("ERRO a lista estah vazia\n");
    }
}


int remove_posi(tipo_lista *f, int posi){
    if (f -> quant > 0){
        int cont = f -> lista [posi];
        if (f-> quant > posi && f->quant != posi){
        int quant2 = posi;
        while (quant2 < f -> quant){
            f -> lista [quant2] = f -> lista [quant2 + 1];
            quant2++; 
        }
        f -> quant--; 
        return cont;
        }else{
            f->quant--;
            return cont;
        } 

    }else{
        printf("ERRO a lista estah vazia\n");
    }
}



void imprimelista(tipo_lista *f){
    int i;
    i = 0;
    printf("Lista [");
    while (i < f -> quant){
        printf(" %d ", f -> lista [i]);
        i++;
    }
    printf("]\n");

}
