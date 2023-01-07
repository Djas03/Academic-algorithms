#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TT 10000

struct lista_estrutura{
    int lista[TT];
    int cont;
};

typedef struct lista_estrutura lista_tipo;

void inserirINICIO(lista_tipo *f, int valor);
void inserirP(lista_tipo *f, int valor, int esc);
void inserirFIM(lista_tipo *f, int valor);

void show(lista_tipo *f);

int main(){
    lista_tipo lista;
    time_t t;
    lista.cont = 0;
    int num, i, j,same, vet[TT], add1, add2, add3,ESC;
    num =0, i =0,same =0, add1 =0, add2 =0, add3 =0,ESC =0;

    clock_t begin = clock();

    srand((unsigned) time(&t));
    //WHILE pra impedir repetição no vet[].
    do{
        vet[i] = rand() % TT;
        same =0;
        for(j = 0; j < i; j++){
            if(vet[j] == vet[i])
                same++;
        }
        if(same == 0){
            if(add1 < (TT/3)){
                add1++;
                inserirINICIO(&lista, vet[i]);
                i++;
            } else if (add1 == (TT/3) && add2 < (TT/3)) {
                add2++;
                inserirFIM(&lista, vet[i]);
                i++;
            } else {
                inserirP(&lista, vet[i], ESC = rand() % (add1 + add2 + add3));
                add3++;
                i++;
            }
        }
    }while(i < TT);

    show(&lista);
    clock_t end = clock();

    printf("ADD inicio: [%d]\nADD final: [%d]\nADD rand: [%d]",add1,add2,add3);
    printf("\nTempo: %f",(double)(end - begin) / 100);


    return 0;
}

//--------------------------------------
//-------------------inserir no inicio-------------------
//--------------------------------------
void inserirINICIO(lista_tipo *f, int valor){
    for(int i = f->cont; i > 0; i--)
        f->lista[i] = f->lista[i-1];
    f->lista[0] = valor;
    f->cont++;
}
//-------------------inserir no Ponto random-------------------
void inserirP(lista_tipo *f, int valor, int esc){
    int i;
    for(i = f->cont; i > esc; i--)
        f->lista[i] = f->lista[i-1];
    f->lista[esc] = valor;
    f->cont++;
}
//-------------------inserir no fim-------------------
void inserirFIM(lista_tipo *f, int valor){
    f->lista[f->cont++] = valor;
}

//--------------------------------------
//-------------------SHOW lista-------------------
//--------------------------------------
void show(lista_tipo *f){
    printf("\n\n[");
    for(int i =0; i < f->cont; i++)
        printf(" %d ",f->lista[i]);
    printf("]\n\n");
}