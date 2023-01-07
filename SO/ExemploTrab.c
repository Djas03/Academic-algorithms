#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

#define MAX_SIZE 80

int leAnaliseComando(char****cmds, int* n, int* pipe); //usada para pegar o comando e separar os tokens que o compoe.



int main(){
    char ***cmd = NULL;
    int n, pipee;
    while(leAnaliseComando(&cmd, &n, &pipee) == 1){//le e analisa o comando
        pid_t pid = fork(); //cria o processo filho para criar o comando
        if(pid < 0){
            perror("\n(ﾉ｀□´)ﾉ⌒┻━┻ Error no fork!");
        } else if(pid == 0){ //processo filho
            execvp(cmd[0], cmd);
        } else { //processo pai - shell
            int status;
            wait(&status);
        }
    } 

    return 0;
}

int leAnaliseComando(char**** cmds, int* n, int* pipe){
    size_t size = 256;
    char *comando = (char*)malloc(size * sizeof(char));
    printf("(҂‾ ▵‾)︻デ═一 ");
    getline(&comando, &size, stdin);
    comando[strlen(comando)-1] = '\0';

    int pipee = 0;
    int ecomerce = 0;
    for(int i =0; i < strlen(comando); i++){//conta o numero de barras    
        if(comando[i]== '|')pipee++;
        if (comando[i]== '&')ecomerce = 1;
    }printf("\ncont de barras: %d\n",pipee);

    (*cmds) = (char**)malloc((pipee+1) * sizeof(char**)); //aloca na matrix a quantidade de pipes.
    *pipe = pipee+1;

    char* token = strtok(comando," ");
    int count =0;
    while(token != NULL){
        count++;
        *cmds = (char**)realloc(*cmds, count * sizeof(char*));
        (*cmds)[count-1]= token;
        token = strtok(NULL," ");
    }
    count++;
    *cmds = (char**)realloc(*cmds, count * sizeof(char*));
    (*cmds)[count-1]= NULL;
    *n =count;

    return 1;
}