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


struct est_No {
    int valor;
    struct est_No *prox;
};
typedef struct est_No tipoNo;

//Prototipo das funcoes
void insereInicio(tipoNo **lst, int vlr);
void inserePos (tipoNo **lst, int pos, int vlr);
void insereFim(tipoNo **lst, int vlr);
tipoNo removeFim(tipoNo **lst);
void imprimeLista (tipoNo**lst);


int main (){
    tipoNo *minha_lista;
    minha_lista = NULL;

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
        insereInicio(&minha_lista, i);
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
        insereFim(&minha_lista, i);
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
        inserePos (&minha_lista,j,i);
    }
    t = clock() - t;
    printf("Tempo: %lf milissegundos\n\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("-----------------------------------------------------------------------------------------\n");
    //--------------------------------------------------------------------------------------------------------- 
    printf("\n\n\n");
    //imprimeLista(&minha_lista);
    

    return 0;
}

// funcao  que insere no fim da lista
void insereFim(tipoNo **lst, int vlr){
    tipoNo *novoNo, *aux;
    novoNo = (tipoNo*) malloc (sizeof(tipoNo));

    //inicializa valores do novoNo
    novoNo->valor = vlr;
    novoNo->prox = NULL;

    //Acopla novoNo na lista
    if ((*lst)==NULL){
        *lst = novoNo;
    }else{
        //percorre a lista ate o ultimo no
        aux = *lst;
        while (aux->prox != NULL){
            aux = aux->prox;

        }
        //anexa o novoNo ao  ultimo noh
        aux -> prox = novoNo;
    }


} 

//funcao que insere no incio da lista encadeada
void insereInicio(tipoNo **lst, int vlr){
    tipoNo *novoNo;
    novoNo = (tipoNo*) malloc(sizeof(tipoNo));
    novoNo -> valor = vlr;
    novoNo -> prox = *lst;
    *lst = novoNo;
}

//funcao que insere um valor em uma posicao especifica  da lst 
void inserePos (tipoNo **lst, int pos, int vlr){
    int cont;
    tipoNo *novoNo, *aux, *aux_ant;
    novoNo =  (tipoNo*)malloc(sizeof(tipoNo));
    novoNo -> valor = vlr;
    cont = 0;
    aux = (*lst);

    while ((cont < pos) && (aux != NULL)){
        cont = cont + 1;
        aux_ant = aux;
        aux = aux->prox;
    }

    //verifica o contexto da parda do enquanto
    if ((cont == pos)&&(pos > 0)){
        novoNo -> prox = aux;
        aux_ant-> prox = novoNo; 

    }else{

        novoNo->prox = *lst;
        *lst = novoNo;

    }
}

//funcao que remove o noh do fim da lista
tipoNo  removeFim(tipoNo **lst){
    tipoNo *aux, *noRemover, noCopia;

    //trata o caso especial de haver apenas  1 noh
    if ((*lst)->prox == NULL){
        noCopia = **lst;
        free(*lst);
        (*lst) = NULL;
        return noCopia;
    }else{
        noRemover = (*lst);
        while (noRemover->prox != NULL){
            aux = noRemover;
            noRemover = noRemover->prox;

        }
        noCopia = *noRemover;
        free(noRemover);
        aux->prox = NULL;
        return noCopia;
    }
}

void imprimeLista (tipoNo**lst){
    tipoNo *aux;
    aux = *lst;
    printf("Lista->");
    while (aux != NULL) {
        printf("[%d]->", aux->valor);
        aux = aux->prox;
    }
    printf("NULO\n");
}


