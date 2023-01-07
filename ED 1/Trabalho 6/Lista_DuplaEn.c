/*
* UFMT - Ciencia da Computacao
* Estrutura de Dados 1 - Trabalho 6 : lst - estatica x dinamica 
* Prof Ivairton
* Discentes: Djalma de Almeida Mendes, Lucas Barbosa Amaral 
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Definicao do tipo do noh da lista
struct est_No {
    int valor;
    struct est_No *prox;
    struct est_No *ant;
};
typedef struct est_No tipoNo;

//prototipacao das funcoes
void insereFim(tipoNo **lst, int vlr);
void insereInicio (tipoNo **lst, int vlr);
void inserePosi (tipoNo **lst, int pos, int vlr);
void imprimeLista (tipoNo **lst);

//Funcao principal
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
    for (cont1 = 0; cont1 < 3333; cont1 ++){
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
        inserePosi(&minha_lista,j,i);
    }
    t = clock() - t;
    printf("Tempo: %lf milissegundos\n\n",((double)t)/((CLOCKS_PER_SEC/1000)));
    printf("-----------------------------------------------------------------------------------------\n");
    //--------------------------------------------------------------------------------------------------------- 
    printf("\n\n\n");

    //imprimeLista(&minha_lista);
    

    return 0;
}

//Funcao que insere no fim da lista
void insereFim(tipoNo **lst, int vlr){
    tipoNo *novoNo, *aux;
    novoNo = (tipoNo*) malloc (sizeof(tipoNo));

    //Inicializa valores do novo noh
    novoNo->valor = vlr;
    novoNo->prox = NULL;
    novoNo->ant = NULL;

    //Acopla novo noh na lista
    if (*lst == NULL){  //trata o caso especial que é a lista vazia 
        *lst = novoNo;
    }else{
        //percorre a lista ate o ultimo noh
        aux = *lst;
        while (aux->prox != NULL){
            aux = aux->prox;

        }
        //anexa o novo noh ao ultimo noh
        aux->prox = novoNo;
        novoNo->ant = aux;
    }
}

//funcao que insere no inicio da lista encadeada
void insereInicio (tipoNo **lst, int vlr){
    tipoNo *novoNo;
    novoNo = (tipoNo*) malloc (sizeof(tipoNo));
    if (novoNo != NULL){
        novoNo->valor = vlr;
        novoNo->prox = *lst;
        novoNo -> ant = novoNo;
        (*lst) = novoNo;
    }
}

//insere um valor em uma posicao especifica
void inserePosi (tipoNo **lst, int pos, int vlr){
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

//Funcao que imprime a lista
void imprimeLista (tipoNo **lst){
    tipoNo *aux;
    aux = *lst;
    printf("Lista->");
    while (aux != NULL) {
        printf("[%d]->", aux->valor);
        aux = aux->prox;
    }
    printf("NULO\n");
}

