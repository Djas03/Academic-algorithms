/*
* UFMT - Ciencia da Computacao
* Estrutura de Dados 1 - Trabalho 5 : Metodos de ordenacao
* Prof Ivairton
* Discentes: Djalma de Almeida Mendes, Lucas Barbosa Amaral 
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 100000


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


//funcao principal
int main (){

    tipo_lista minha_lista;
    minha_lista.quant = 0;

    int cont1;
    int i,cont;
    clock_t t;

    //Inicializa o gerador de números randomicos, a partir de uma semente
    srand(time (NULL)); 
        
    printf("\n\nNUMEROS GERADOS E ARMAZENADOS\n");
    printf("-----------------------------------------------------------------------------------------\n");

    //gera 1000 numeros pseudo randomicos de 0 a 999.999

    for (cont1 = 0; cont1 <100000; cont1 ++){
        i = rand () %   1000000;
        while (Existe(&minha_lista, i, cont1) == 0){
            i = rand () %   1000000;
    
        }
        inserir_fim(&minha_lista, i);
        printf("%d\n", i);
    }

    printf("-----------------------------------------------------------------------------------------\n");
    printf("\n\nLISTA COM VALORES DESORGANIZADOS\n");
    printf("-----------------------------------------------------------------------------------------\n");
    imprimelista(&minha_lista);
    printf("-----------------------------------------------------------------------------------------\n\n\n");
    t = clock();
    insertsort(&minha_lista);//metodo de ordenacao utilizado
    t = clock() - t;
    printf("Tempo: %lf milissegundos\n\n",((double)t)/((CLOCKS_PER_SEC/1000)));

    printf("LISTA ORGANIZADA ATRAVES DO BOBBLE SORT\n");
    printf("-----------------------------------------------------------------------------------------\n");
    imprimelista(&minha_lista);
    printf("-----------------------------------------------------------------------------------------\n\n");


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
        int quant2 = f -> quant;
        while (quant2 > posi){
            f -> lista [quant2] = f -> lista [quant2 - 1];
            quant2--; 
        }
        f -> lista [posi] = vl;
        f -> quant++;
        
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
        int quant2 = posi;
        while (quant2 < f -> quant){
            f -> lista [quant2] = f -> lista [quant2 + 1];
            quant2++; 
        }
        f -> quant--; 
        return cont; 

    }else{
        printf("ERRO a lista estah vazia\n");
    }
}


void imprimelista(tipo_lista *f){
    int i;
    i = 0;
    printf("Lista [\n");
    while (i < f -> quant){
        printf(" %d \n", f -> lista [i]);
        i++;
    }
    printf("]\n");

}

int Existe (tipo_lista *f, int i, int tamanho){
    int result, cont1;
    result = 1;
    cont1 = 0;
	for(cont1 = 0; cont1 < tamanho ; cont1 ++){
		if(f ->lista[cont1] == i){
            result = 0;
            return result;
        }
		
	}
	return result;
}

void insertsort(tipo_lista *f){
    int i;
    tipo_lista liord;
    liord.quant = 0;
    for ( i = 0; i < f ->quant; i++){
        insereord(&liord, f ->lista[i]);
    }
    for ( i = 0; i < f ->quant; i++){
        f -> lista[i] = liord.lista[i];
    }   
}



void insereord(tipo_lista * f, int valor){
    int i, troca;
    i = 0;
    troca = 0;
    if(f -> quant == 0){
        inserir_posi(f , i, valor);
    }
    else{
        while (i < f ->quant && valor > f ->lista[i]){
            i++;
        }
        inserir_posi(f , i, valor);
        
    }
}

