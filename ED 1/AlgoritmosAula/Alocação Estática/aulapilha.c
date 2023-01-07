/* é isso aí */

#include <stdio.h>
#include <stdlib.h>


#define N 10


struct estrutura_pilha
{
    int pilha[N];
    int quant;

};
typedef struct estrutura_pilha tipo_pilha;


void insere_pilha(tipo_pilha *pl, int vl);
int retira_pilha(tipo_pilha *pl);
int topo(tipo_pilha *pl);
void imprime_pilha(tipo_pilha *pl);


int main (){

    tipo_pilha minha_pilha;
    minha_pilha.quant = 0;

    insere_pilha(&minha_pilha, 100);
    insere_pilha(&minha_pilha, 200);
    insere_pilha(&minha_pilha, 300);


    imprime_pilha(&minha_pilha);

    printf("Elemento desempilhado = %d\n",retira_pilha(&minha_pilha));
    printf("Elemento desempilhado = %d\n",retira_pilha(&minha_pilha));

    printf("Valor no topo da pilha = %d\n\n", topo(&minha_pilha));


    return 0;
}


void insere_pilha(tipo_pilha *pl, int vl){
    if (pl -> quant < N){
        pl -> pilha [pl -> quant++] = vl;

    }else{
        printf ("[ERRO] pilha estah cheia!");
    }
}


int retira_pilha(tipo_pilha *pl){

    if (pl -> quant > 0){
        return pl -> pilha[--pl -> quant];

    }else{
        printf("ERRO Pilha estah vazia.");
    }
}


int topo(tipo_pilha *pl){
    return pl -> pilha [pl -> quant - 1];
}

void imprime_pilha(tipo_pilha *pl){

    int i;
    i = pl->quant;
    while (i > 0){
        i --;
        printf("%d\n", pl -> pilha [i]);
    }


}