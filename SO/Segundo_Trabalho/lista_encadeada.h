#ifndef lista_encadeada_h
#define lista_encadeada_h
#define L 0 //livre
#define O 1 //ocupado

typedef struct no{
    int valor;
    char nome[50];
    int status;
    int inicio, fim;
    struct no *proximo;
    struct no *anterior;
}No;

int Total(No *, int);
int MenorMelhor(int[] , int, int);

// procedimento para inserir no início
void inserir_no_inicio(No **memoria, int num, char nomee[]){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        strcpy(novo->nome, nomee);
        novo->status = L;
        novo->inicio = 0;
        novo->fim = num-1;
        novo->proximo = NULL;
        novo->anterior = NULL;
        if(*memoria)
            (*memoria)->anterior = novo;
        *memoria = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// insere no primeiro espaco disponivel alocavel
void First(No **memoria, int num,char nomee[], int memorymax){
    No *aux;/*
    aux = *memoria;
    int o=0;
    while(aux){
        if(aux->valor > num)
            break;
        else
            o++;
        aux = aux->proximo;
    }
    if(o == 0){*/
        int total = Total(*memoria, num);
        if (num > memorymax || total > memorymax){
            printf("\nValor execedeu a memoria: [%d]\n",total);
        }else{
            No *novo = malloc(sizeof(No));

            if(novo){
                aux = *memoria;
                while(aux->status == O || aux->valor < num ){
                    if(aux->proximo != NULL)
                        aux = aux->proximo;
                }
                novo->valor = aux->valor;
            
                if((aux->valor - num) ==0){ //se num tiver o mesmo tamanho de aux
                    strcpy(aux->nome, nomee);
                    aux->valor = num;
                    aux->status = O;
                } else{ //se nao vai criar um 'novo' alocamento
                    strcpy(aux->nome, nomee);
                    aux->status = O;
                    aux->valor = num;
                    if(aux->proximo){ //se aux tiver um proximo
                        aux->proximo->anterior = novo;
                        novo->proximo = aux->proximo;
                        aux->proximo = novo;
                        novo->anterior = aux;

                        aux->fim = aux->inicio+num;

                        novo->inicio = (novo->anterior->fim)+1;
                        if(novo->proximo){ //se aux tiver proximo
                            novo->fim = (novo->proximo->inicio)-1;
                            novo->valor = novo->valor - aux->valor;
                        }else {//se aux nao tiver proximo
                            novo->valor = novo->valor-num;
                            novo->fim = memorymax - 1;
                            novo->proximo = NULL;
                        }
                        novo->status = L;
                        strcpy(novo->nome, "nao utilizados");
                    }else { //se aux nao tiver proximo
                        aux->proximo = novo;
                        novo->anterior = aux;
                    
                        if(aux->anterior != NULL){ //Se aux tiver anterior 
                            aux->inicio = (aux->anterior->fim)+1;
                            aux->fim = (aux->inicio-1)+num;
                        }else //Se aux nao tiver anterior
                            aux->fim = num-1;

                        novo->inicio = (novo->anterior->fim)+1;
                        if(novo->proximo){ //se aux tiver proximo
                            novo->fim = (novo->proximo->inicio)-1;
                            novo->valor = novo->valor - aux->valor;
                        }else {//se aux nao tiver proximo
                            novo->valor = novo->valor-num;
                            novo->fim = memorymax - 1;
                            novo->proximo = NULL;
                        }
                        novo->status = L;
                        strcpy(novo->nome, "nao utilizados");
                    }
                }
            }else
                printf("Erro ao alocar memoria!\n");
        }/*
    }else
        printf("Valor excedeu o compartimento.\n");*/
}

void Best(No **memoria, int num,char nomee[], int memorymax){
    No *aux;/*
    aux = *memoria;
    int o=0;
    while(aux){
        if(aux->valor > num)
            break;
        else
            o++;
        aux = aux->proximo;
    }
    if(o == 0){*/
    //if(o == 0){
        int total = Total(*memoria, num);
        if (num > memorymax || total > memorymax){
            printf("\nValor execedeu a memoria: [%d]\n",total);
        }else{
            No *novo = malloc(sizeof(No));

            if(novo){
                aux = *memoria;
                int cont =0, p=0, result;
                int vet[p];
                
                while(aux){
                    if (aux->status == L && aux->valor > num)
                        cont++;
                    aux = aux->proximo;
                }
                aux = *memoria;
                //printf("cont: %d\n",cont);
                while(aux){
                    if (aux->status == O || aux->valor < num){
                        //printf("test2\n");
                        aux = aux->proximo;
                    }else if(cont == 1){
                        //printf("test3\n");
                        vet[p] = aux->valor;
                        break;
                        
                    }else{
                        vet[p] = aux->valor;
                        //printf("test3.1\n");
                        aux = aux->proximo;
                        p++;
                    }

                }
                //printf("p: [%d]\n",p);
                result = MenorMelhor(vet,p, num);
                //printf("o melhor: %d\n", result);
                aux = *memoria; // reinciar aux
                //printf("TST\n");
                while(aux->valor != result)
                    aux = aux->proximo;
                    
                //printf("VALOR: %d\n",aux->valor);
                novo->valor = aux->valor;
                printf("test4\n");

                if((aux->valor - num) ==0){ //se num tiver o mesmo tamanho de aux
                    //printf("entrou 1 :%s\n",aux->nome);
                    strcpy(aux->nome, nomee);
                    //printf("entrou u\n");
                    aux->valor = num;
                    //printf("entrou uu\n");
                    aux->status = O;
                    //printf("entrou uuu\n");
                } else{ //se nao vai criar um 'novo' alocamento
                    //printf("ENTROU nome: %s\n", aux->nome);
                    strncpy(aux->nome, nomee, sizeof(aux->nome)-1);
                    //printf("entrou 2.1\n");
                    aux->status = O;
                    //printf("entrou 2.2\n");
                    aux->valor = num;
                    //printf("entrou 2.3\n");
                    if(aux->proximo){ //se aux tiver um proximo
                        //printf("entrou 3\n");
                        aux->proximo->anterior = novo;
                        novo->proximo = aux->proximo;
                        aux->proximo = novo;
                        novo->anterior = aux;

                        aux->fim = aux->inicio+num;

                        novo->inicio = (novo->anterior->fim)+1;
                        if(novo->proximo){ //se aux tiver proximo
                            //printf("entrou 4\n");
                            novo->fim = (novo->proximo->inicio)-1;
                            novo->valor = novo->valor - aux->valor;
                        }else {//se aux nao tiver proximo
                            //printf("entrou 5\n");
                            novo->valor = novo->valor-num;
                            novo->fim = memorymax - 1;
                            novo->proximo = NULL;
                        }
                        novo->status = L;
                        strcpy(novo->nome, "nao utilizados");
                    }else { //se aux nao tiver proximo
                        //printf("entrou ELSE\n");
                        aux->proximo = novo;
                        novo->anterior = aux;
                    
                        if(aux->anterior != NULL){ //Se aux tiver anterior 
                            aux->inicio = (aux->anterior->fim)+1;
                            aux->fim = (aux->inicio-1)+num;
                        }else //Se aux nao tiver anterior
                            aux->fim = num-1;

                        novo->inicio = (novo->anterior->fim)+1;
                        if(novo->proximo){ //se aux tiver proximo
                            novo->fim = (novo->proximo->inicio)-1;
                            novo->valor = novo->valor - aux->valor;
                        }else {//se aux nao tiver proximo
                            novo->valor = novo->valor-num;
                            novo->fim = memorymax - 1;
                            novo->proximo = NULL;
                        }
                        novo->status = L;
                        strcpy(novo->nome, "nao utilizados");
                    }
                }
            }else
                printf("Erro ao alocar memoria!\n");
        }
    //}/*
    //}else
      //  printf("Valor excedeu o compartimento.\n");*/
}

void Liberar(No **memoria, int max){
    No *aux, *remove=NULL;
    aux = *memoria;
    aux->status = L;
    strcpy(aux->nome, "nao utilizados");
    
    if(aux->anterior !=NULL && aux->anterior->status == L){
        //printf("anterior 1\n");
        aux->valor = aux->valor + aux->anterior->valor;
        //printf("anterior 2\n");
        aux->inicio = aux->anterior->inicio;
        //printf("anterior 3\n");
        if(aux->anterior->anterior){
            //printf("anterior IF\n");
            aux->anterior->anterior->proximo = aux;
        }
        //printf("anterior 4\n");
        aux->anterior = aux->anterior->anterior = NULL;
        //printf("anterior final\n");
    }

    if(aux->proximo != NULL && aux->proximo->status == L){
        //printf("prixmo 1\n");
        aux->valor = aux->valor + aux->proximo->valor;
        //printf("prixmo 2\n");
        aux->fim = aux->proximo->fim;
        //printf("prixmo 3\n");
        if(aux->proximo->proximo){
            //printf("prixmo IF\n");
            aux->proximo->proximo->anterior = aux;
        }
        //printf("prixmo 4\n");
        aux->proximo = aux->proximo->proximo;
        //printf("prixmo final\n");
    }
    /*
    if(aux->anterior == NULL){
        printf("n tem anterior\n");
    }
    if(aux->proximo == NULL)
        printf("n tem proximo\n");
    */
}

/*
int RL(No **memoria, char *comando1,char *comando2){
    printf("opa1\n");
    printf("%s %s\n",comando1, comando2);
    //comando[]
    char *texto;
    strcpy(texto, comando1);
    
    printf("opa2\n");
    //comandomat[]
    char *texto2;
    strcpy(texto2, comando2);
    printf("opa3\n");   
}
*/

No* remover(No **memoria, int num){
    No *aux, *remover = NULL;

    if(*memoria){
        if((*memoria)->valor == num){
            remover = *memoria;
            *memoria = remover->proximo;
            if(*memoria)
                (*memoria)->anterior = NULL;
        }
        else{
            aux = *memoria;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
                if(aux->proximo)
                    aux->proximo->anterior = aux;
            }
        }
    }
    return remover;
}

void imprimir(No *no){
    printf("\n---------\n");
    while(no){
        printf("Enderecos [%d:%d] Processo %s\n", no->inicio, no->fim, no->nome);
        //printf("Enderecos [%d:%d] Processo [%s] status: [%i] valor: [%i]\n", no->inicio, no->fim, no->nome, no->status, no->valor); DEBUG
        no = no->proximo;
    }
}

int Total(No *no, int num){
    int total=0;
    while(no){
        if(no->status == O){
            total += no->valor;
        }
        no = no->proximo;
    }
    return total+num;
}

int MenorMelhor(int *vet, int p, int numaux){
    int aux, guard=0, indic;
        for(int kk=0; kk <= p; kk++)
            printf("vet[%d]\n",vet[kk]);
        guard = vet[0] - numaux;
        if(guard == 0)
            return vet[0];
        if(p == 0)
            return vet[0];
        for(int i=0; i <= p; i++){
            aux = vet[i]-numaux;
            if(aux == 0)
                return vet[i];
            if(aux < guard){
                guard = aux;
                indic = vet[i];
            }
        }
        return indic;
}

#endif