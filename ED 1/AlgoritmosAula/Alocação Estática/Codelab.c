/*Finge que tem algo aqui, pq tem*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define TAM 10

//Estrutura Fila
struct Fila{
   int fila[TAM];
   int quant;

};
typedef struct Fila tipo_fila;

//funcoes 
void add_fila (tipo_fila *f, int vl);
int remove_fila(tipo_fila *f);
void imprimeFila(tipo_fila *f);


//funcao principal
int main (){
    tipo_fila f_prioridade;
    f_prioridade.quant = 0;
    tipo_fila f_comum;
    f_comum.quant = 0;

    time_t t;
    srand( (unsigned) time(&t) );

    
    while (1){
        int op;
        printf("------------------------------------------------------------\n");
        printf("Digite 1 para Solicitar nova Senha ou Digite 2 para Atender Senha:");
        scanf ("%d",&op);
        printf("\n");

        if (op == 1){
            int op2;
            printf("Digite 1 para senha de prioridade ou digite 2 para senha comum:");
            scanf ("%d",&op2);
            printf("\n");

            if (op2 == 1){
                add_fila(&f_prioridade, rand()%10);
                imprimeFila(&f_prioridade);
                imprimeFila(&f_comum);

            }
            else if (op2 == 2){
                add_fila(&f_comum, rand()%10);
                imprimeFila(&f_prioridade);
                imprimeFila(&f_comum);

            }else{
                printf("Opcao invalida\n\n");
            }




        }
        else if (op == 2){
            if (f_prioridade.quant != 0){
                printf ("senha removida %d\n",remove_fila(&f_prioridade));
                imprimeFila(&f_prioridade);
                imprimeFila(&f_comum);
            }else{
                printf ("senha removida %d\n", remove_fila(&f_comum));
                imprimeFila(&f_prioridade);
                imprimeFila(&f_comum);
            }


        }else{
            printf ("Opcao Invalida\n");
            printf ("Fim do programa\n");
            printf ("------------------------------------------------------------\n");
            break;
        }
    }

    
    return 0;
}

void add_fila (tipo_fila *f, int vl){
        if (f -> quant < TAM){
        
        int quant2 = f -> quant;
        while (quant2 >= 1){
            f -> fila [quant2] = f -> fila [quant2 - 1];
            quant2--; 
        }

        f -> fila [0] = vl;
        f -> quant++;



    }else{
        printf("ERRO a fila estah cheia!\n");
    }
}

int remove_fila(tipo_fila *f){
        if (f -> quant > 0 ){
        int cont = f -> fila [0];
        int quant2 = 1;
        while (quant2 < f -> quant){
            f -> fila [quant2 - 1] = f -> fila [quant2];
            quant2++; 
        }
        f -> quant--; 
        return cont;

    }else{
        printf("ERRO a fila estah vazia\n");
    }
}

void imprimeFila(tipo_fila *f){
    int i;
    i = 0;
    printf("Fila [");
    while (i < f -> quant){
        printf(" %d ", f -> fila [i]);
        i++;
    }
    printf("]\n");

}
