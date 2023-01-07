/*eh isso msm meu patrao*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Tamanho da lista
#define TAM 10

// Estrutura da lista
struct estrutura_lista
{
    int lista[TAM];
    int quant;
};
typedef struct estrutura_lista tipo_lista;

// Prototipo das funcoes
void inserir_inicio(tipo_lista *f, int vl);
void inserir_fim(tipo_lista *f, int vl);
void inserir_posi(tipo_lista *f, int posi, int vl);
int remove_ini(tipo_lista *f);
int remove_fim(tipo_lista *f);
int remove_posi(tipo_lista *f, int posi);
void imprimelista(tipo_lista *f);
void bobble_sort(tipo_lista *f);
void ordena_shell(tipo_lista *f);

// Funcao principal
int main()
{
    tipo_lista minha_lista;
    minha_lista.quant = 0;

    inserir_inicio(&minha_lista, 30);
    imprimelista(&minha_lista);
    inserir_inicio(&minha_lista, 20);
    imprimelista(&minha_lista);
    inserir_inicio(&minha_lista, 10);
    imprimelista(&minha_lista);
    inserir_fim(&minha_lista, 40);
    imprimelista(&minha_lista);
    printf("Item removido: %d\n", remove_fim(&minha_lista));
    imprimelista(&minha_lista);
    printf("Item removido: %d\n", remove_ini(&minha_lista));
    imprimelista(&minha_lista);
    inserir_posi(&minha_lista, 1, 50);
    imprimelista(&minha_lista);
    printf("Item removido: %d\n", remove_posi(&minha_lista, 0));
    imprimelista(&minha_lista);
    inserir_inicio(&minha_lista, 20);
    inserir_inicio(&minha_lista, 400);
    imprimelista(&minha_lista);

    
    imprimelista(&minha_lista);

    //quicksort(&minha_lista, 0, 3);
    //imprimelista(&minha_lista);

    // ordena_shell (&minha_lista);
    // bobble_sort (&minha_lista);
    // imprimelista (&minha_lista);

    return 0;
}

void inserir_inicio(tipo_lista *f, int vl)
{
    if (f->quant < TAM)
    {

        int quant2 = f->quant;
        while (quant2 >= 1)
        {
            f->lista[quant2] = f->lista[quant2 - 1];
            quant2--;
        }

        f->lista[0] = vl;
        f->quant++;
    }
    else
    {
        printf("ERRO a lista estah cheia!\n");
    }
}

void inserir_fim(tipo_lista *f, int vl)
{
    if (f->quant < TAM)
    {
        f->lista[f->quant++] = vl;
    }
    else
    {
        printf("ERRO a lista estah cheia!\n");
    }
}

void inserir_posi(tipo_lista *f, int posi, int vl)
{
    if (f->quant < TAM)
    {
        int quant2 = f->quant;
        while (quant2 > posi)
        {
            f->lista[quant2] = f->lista[quant2 - 1];
            quant2--;
        }
        f->lista[posi] = vl;
        f->quant++;
    }
    else
    {
        printf("ERRO a lista estah cheia!\n");
    }
}

int remove_ini(tipo_lista *f)
{
    if (f->quant > 0)
    {
        int cont = f->lista[0];
        int quant2 = 1;
        while (quant2 < f->quant)
        {
            f->lista[quant2 - 1] = f->lista[quant2];
            quant2++;
        }
        f->quant--;
        return cont;
    }
    else
    {
        printf("ERRO a lista estah vazia\n");
    }
}

int remove_fim(tipo_lista *f)
{
    if (f->quant > 0)
    {
        return f->lista[--f->quant];
    }
    else
    {
        printf("ERRO a lista estah vazia\n");
    }
}

int remove_posi(tipo_lista *f, int posi)
{
    if (f->quant > 0)
    {

        int cont = f->lista[posi];
        int quant2 = posi;
        while (quant2 < f->quant)
        {
            f->lista[quant2] = f->lista[quant2 + 1];
            quant2++;
        }
        f->quant--;
        return cont;
    }
    else
    {
        printf("ERRO a lista estah vazia\n");
    }
}

void imprimelista(tipo_lista *f)
{
    int i;
    i = 0;
    printf("Lista [");
    while (i < f->quant)
    {
        printf(" %d ", f->lista[i]);
        i++;
    }
    printf("]\n");
}

void bobble_sort(tipo_lista *f)
{
    int troca, i, aux;

    troca = 1;

    while (troca)
    {
        troca = 0;
        for (i = 0; i < f->quant - 1; i++)
        {
            if (f->lista[i] > f->lista[i + 1])
            {
                aux = f->lista[i];
                f->lista[i] = f->lista[i + 1];
                f->lista[i + 1] = aux;
                troca++;
            }
        }
    }
}

void ordena_shell(tipo_lista *f)
{
    int i, aux, salto, troca;

    salto = f->quant / 2;

    while (salto > 1)
    {
        for (i = 0; (i + salto) < f->quant; i++)
        {
            if (f->lista[i] > f->lista[i + salto])
            {
                aux = f->lista[i];
                f->lista[i] = f->lista[i + salto];
                f->lista[i + salto] = aux;
            }
        }
    }
}

void insertsort(tipo_lista*);
void insereord(tipo_lista*, int valor);

void insertsort(tipo_lista *lst){
    int i;     
    tipo_lista liord;
    liord.quant = 0;
    for ( i = 0; i < lst->quant; i++){
        insereord(&liord, lst->lista[i]);
    }
    for ( i = 0; i < lst->quant; i++){
        lst->lista[i] = liord.lista[i];
    }   
}
void insereord(tipo_lista *lst, int valor){
    int i = 0;
    if(lst->quant == 0){
        insereposicao(lst, valor, i);
    }
    else{
        while (i < lst->quant && valor > lst->lista[i]){
            i++;
        }
        insereposicao(lst, valor, i);
        
    }
}




void quicksort (tipo_lista * f, int ini, int end){
    int meio, i, j, pivo, aux;
    meio = ((end - ini)/2) + ini;
    pivo = f->lista[meio];

    i = ini;
    j = end;
    while (i < j){
        while (f->lista[i] < pivo){
            i++;
        }
        while (f->lista[j] > pivo){
            j--;
        }
        if (i<j){
            aux = f->lista[i];
            f->lista[i] = f->lista[j];
            f->lista[j] = aux;
                    
        }
            
        
    
        if(f->lista[i] == f->lista[j]){
            i++;
        }
        if (j > ini){
            quicksort (f -> lista ,ini,j-1);
        }

        if (i < end){
            quicksort(f->lista ,i,end);
    
        }
    }
      
}