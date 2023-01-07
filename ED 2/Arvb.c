#include <stdlib.h>
#include <stdio.h>

struct ArvoreBin {

    //char info;
    int chave;
    struct ArvoreBin *dir;
    struct ArvoreBin *esq;
    
};
typedef struct ArvoreBin avb;

avb *criaNo (char ch);
avb *busca (avb *no, int chave);
avb *buscarecursiva (avb *no, int chave);
avb *insere (avb *no, int chave);
void profundidade (avb *a);
void simetria (avb *a);
void posOrdem (avb *a);
avb* criaArvoreBalanceada (avb*raiz, int v[], int inicio, int fim);



//==================Função Principal========================
int main (){
    int tam = 7;
    int v[] = {150, 300, 400, 500, 600, 800, 900};
    avb*raiz;
    raiz = NULL;
    raiz = criaArvoreBalanceada(raiz,v,0,tam-1);
    simetria (raiz);
    


    return 0;
}
//==========================================================

avb *criaNo (char ch){
    avb *novo;
    novo = (avb *) malloc (sizeof (avb));
    //novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;

}


void profundidade (avb *a){
    if (a!= NULL){
        printf ("%d\n",a->chave);
        profundidade(a->esq);
        profundidade(a->dir);
    }

}

void simetria (avb *a){
    if (a!= NULL){
        simetria (a->esq);
        printf("%d\n",a->chave);
        simetria(a->dir);
    }

}

void posOrdem (avb *a){
    if (a!= NULL){
        posOrdem(a->esq);
        posOrdem(a->dir);
        printf("%d\n",a->chave);
        
    }

}


avb *busca (avb *no, int chave){
    while (no != NULL){
        if (no->chave == chave){
            return no;
        }else{
            if (no->chave > chave){
                no = no->esq;
            }else{
                no = no->dir;
            }
        }
    }
    return NULL;
}

avb *buscarecursiva (avb *no, int chave){
    if (no == NULL){
        return NULL;
    }
    else if (no->chave == chave){
        return no;

    }
    else if (no->chave > chave){
        return buscarecursiva (no->esq, chave);

    }else{
        return buscarecursiva (no->dir, chave);
    }
}


avb *insere (avb *no, int chave){
    if (no == NULL){
        no = (avb *) malloc(sizeof(avb));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;

    }else if(chave < (no->chave)){
        no->esq = insere(no->esq, chave);
    }else if(chave > (no->chave)){
        no->dir = insere(no->dir, chave);
    }else{
        printf ("\nInserção inválida!\n\n\n");
        exit(1);
    }
    return no;
}   


avb *criaArvoreBalanceada (avb*raiz, int v[], int inicio, int fim){
    if (inicio <= fim){
        int meio =  (inicio + fim)/2;
        raiz  = insere (raiz, v[meio]);

        raiz->esq = criaArvoreBalanceada (raiz->esq, v, inicio, meio-1);
        raiz->dir = criaArvoreBalanceada (raiz->dir, v, meio + 1, fim);

        return raiz;
    }
    return NULL;
}
