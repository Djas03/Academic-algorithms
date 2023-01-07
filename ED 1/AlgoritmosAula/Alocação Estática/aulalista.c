/*eh isso msm meu patrao*/

//Bibliotecas
#include <stdlib.h>
#include <stdio.h>

//Tamanho da lista 
#define TAM 10

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

    inserir_inicio(&minha_lista, 30);
    imprimelista(&minha_lista);
    inserir_inicio(&minha_lista, 20);
    imprimelista(&minha_lista);
    inserir_inicio(&minha_lista, 10);
    imprimelista(&minha_lista);
    inserir_fim(&minha_lista, 40);
    imprimelista(&minha_lista);
    printf("Item removido: %d\n",remove_fim(&minha_lista));
    imprimelista(&minha_lista);
    printf("Item removido: %d\n", remove_ini(&minha_lista));
    imprimelista(&minha_lista);
    inserir_posi(&minha_lista, 1, 50);
    imprimelista(&minha_lista);
    printf("Item removido: %d\n",remove_posi(&minha_lista, 0));
    imprimelista(&minha_lista);
    inserir_posi (&minha_lista, 2,100);
    imprimelista(&minha_lista);
    inserir_posi(&minha_lista, 6, 32);
    imprimelista(&minha_lista);
    remove_posi(&minha_lista, 6);
    imprimelista(&minha_lista);
    remove_posi(&minha_lista, 0);
    imprimelista(&minha_lista);



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
        if (f -> quant > posi && f-> quant != posi){
        int quant2 = f -> quant;
        while (quant2 > posi){
            f -> lista [quant2] = f -> lista [quant2 - 1];
            quant2--; 
        }
        f -> lista [posi] = vl;
        f -> quant++;
        } else {
            f-> lista [f-> quant] = vl;
            f->quant++;
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
