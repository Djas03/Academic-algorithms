/*   Trabalho feito por: Djalma de Almeida e Joao Pedro P. Burjack   */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "lista_encadeada.h"

#define L 0 //livre
#define O 1 //ocupado
    
int letoken(int); //le quanto parametros o comando vai precisar ler
    

int main(int argv, char *argc[ ]){
    
    int MAX_MEMORY;
    MAX_MEMORY = atoi(argc[1]);

    //int RL, RQ, C, STAT, W, F, B;
    No *process= NULL;
    inserir_no_inicio(&process, MAX_MEMORY,"nao utilizados");
    int x = 539;
    
    
    //printf("\n__________________________MAX_MEMORY: %d___________________m_______\n", MAX_MEMORY);
    
    int opcao =0;
    
    //INICIO DE DO PROMPT
    while(1){
        printf("alocator>");

        //----LE E SEPARA O COMANDO EM TOKENS----    
        char comando[100];
        char comandomat[4][50];
        
        fgets(comando,100,stdin);
        int alok =strlen(comando)-2;

        char *pt;
        pt = strtok(comando, " ");

        int i = 0;
        while(pt){
            strcpy(comandomat[i],pt);
            pt = strtok(NULL, " ");
            i++;
        }
        //---------------------------------------

        //DEBUG
        //printf("      %d %d %d %d\n",comando[3],comando[4],comando[5],comando[6]);
        //printf("\n      token: %d\n",i);
        //printf("\n      tamanho token 0: %ld\n",strlen(comandomat[0]));
        //printf("\n      tamanho token 4: %ld\n",strlen(comandomat[3]));
        //printf("\n      tamanho token: %s\n",comandomat[3]);

        switch (opcao = letoken(i)){
            //__________________________1 token
            case 1: 
                if(comando[0] == 67 && (strlen(comandomat[0]) == 2)){        //C = 67

                    printf("Compactar memoria!\n");
                }else if(comando[0] == 83 && comando[1] == 84 && comando[2] == 65 && comando[3] == 84 && (strlen(comandomat[0]) == 5)){ //STAT = 83 84 65 84
                    imprimir(process);
                } else if(comando[0] == 88 && (strlen(comandomat[0]) == 2)){ //X = 88
                    printf("Saindo...\n");
                    exit(0);
                } else{
                    printf("Comando desconhecido.\n");
                }
                break;

            //__________________________2 tokens 
            case 2:
                if(comando[0] == 82 && comando[1] == 76 && (strlen(comandomat[0]) == 2)){ //RL = 82 76
                    No *aux;
                    aux = process;
                    int temp = strlen(aux->nome);
                    int k = 0;
                    //printf("test: %d %ld\n",temp, strlen(comandomat[1])-1);
                    //printf("tamanho: %ld %ld\n",strlen(aux->nome), strlen(comandomat[1])-1);
                    while(1){
                        for(i=0; i < strlen(comandomat[1])-1; i++){
                           //printf("cont: %d %d\n",aux->nome[i], comandomat[1][i]);
                        }
                        //printf("tamanho final: %d %ld\n",i, strlen(aux->nome));
                        for(int j=0; j < i; j++){
                            if(aux->nome[j] == comandomat[1][j])
                                k++;
                        }
                        if(k == strlen(aux->nome)){
                            temp = strlen(aux->nome);
                            //printf("entrou: %s %ld\n",aux->nome, strlen(aux->nome));
                            Liberar(&aux, MAX_MEMORY);
                            break;
                        }
                        //printf("proximo!\n");
                        if(aux->proximo != NULL)
                            aux = aux->proximo;
                        else
                            break;
                    }
                    if(temp != strlen(comandomat[1])-1 || k != temp){
                        //printf("%d %ld\n",temp, strlen(comandomat[1])-1);
                        printf("Processo desconhecido.\n");
                    } 
                } else
                    printf("Comando desconhecido.\n");
                break;
            //__________________________4 tokens 
            case 3:
                if(comando[0] == 82 && comando[1] == 81 && (strlen(comandomat[0]) == 2)){ //RQ = 82 81
                    if(comando[alok] == 87){        //W = 87
                        printf("Novo processo, tipo W\n");
                    }else if(comando[alok] == 70){  //F = 70
                        if(atoi(comandomat[2]) != 0)
                            First(&process, atoi(comandomat[2]),comandomat[1] ,MAX_MEMORY);
                        else
                            printf("Argumentos invalidos!\n");
                    }else if(comando[alok] == 66){ //B = 66
                        if(atoi(comandomat[2]) != 0)
                            Best(&process, atoi(comandomat[2]),comandomat[1] ,MAX_MEMORY);
                        else
                            printf("Argumentos invalidos!\n");
                    }else
                        printf("Argumentos invalidos para RQ.\n");
                } else
                    printf("Comando desconhecido.\n");
                break;

            //__________________________invalidos 
            case 4:
                printf("Argumentos invalidos!\n");
                break;
        }
    }

    return 0;
    
}

//--------- funcoes ---------
int letoken(int token){
    if(token == 1)
        return 1;
    else if(token == 2)
        return 2;
    else if(token == 4)
        return 3;
    else
        return 4;
}
