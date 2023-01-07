#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

#define MAX_SIZE 256

int leAnaliseComando(char****cmds, int* n, int* pipe); //usada para pegar o comando e separar os tokens que o compoe.
int FuncDup(int in, int out, char** cmds, int j);
int Pipes (char** cmds,int* pipee );


int main(){
    char ***cmd = NULL;
    int n, pipee[1];
    while(leAnaliseComando(&cmd, &n, pipee) == 1)//le e analisa o comando
        Pipes(**cmd, pipee); 

    return 0;
}

int leAnaliseComando(char**** cmds, int* n, int* pipe){
    size_t size = 256;
    char *comando = (char*)malloc(size * sizeof(char));
    printf("Shell> ");
    getline(&comando, &size, stdin);
    comando[strlen(comando)-1] = '\0';

    int pipee =0, comercial=0;
    //conta a quantidade de pipes
    for(int i =0; i < strlen(comando); i++){    
        if(comando[i]== '|')pipee++;
        if(comando[i]== '&')comercial =1;
    }printf("\ncont de barras: %d\n",pipee);

    //aloca na matrix a quantidade de pipes.
    (*cmds) = (char**)malloc((pipee+1) * sizeof(char**)); 
    pipe[0] = pipee+1;
    pipe[1] = comercial;

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

int FuncDup(int entrada, int saida, char** cmds, int j){
    pid_t pid;
    if ((pid = fork()) == 0){
        if (entrada != 0){
            dup2(entrada, 0);
            close(entrada);
        }
        if (saida != 1){
            dup2(saida, 1);
            close(saida);
        }
        return execvp(cmds[j], &cmds[j]);
    }
    return pid;
}

int Pipes (char** cmds,int* pipee){
    int fd[2], entrada =0, j=0;
    pid_t pid = fork();

    if(pid < 0){
        perror("\nErro no fork!");
        exit(-1);

    } else if (pid == 0){
        for (int i = 0; i < pipee - 1; i++){
            pipe(fd);
            FuncDup(entrada, fd[1], cmds, j);
            close(fd[1]);
            entrada = fd[0];
            while (cmds[j] != NULL)
                j++;

            j++;
        }
        if (entrada != 0)
            dup2(entrada, 0);
        execvp(cmds[j], &cmds[j]);
        exit(0);
    }else{

        if (pipee[1] == 0){
            int stats;
            int t_wait;
            t_wait = wait(&stats);
            printf("\n-&");
        }else
            printf(">>>PID: %d\n", pid);
    }

}
