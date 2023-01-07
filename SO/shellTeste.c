#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

#define MAX_SIZE 256
static int sig = 0;

int leAnaliseComando(char****cmds, int* n, int* pipe); //usada para pegar o comando e separar os tokens que o compoe.
int FuncDup(int in, int out, char** cmds, int j);
int Pipes (char** cmds,int* pipee );


int main(){
    char ***cmd = NULL;
    int n, pipee;
    while(leAnaliseComando(&cmd, &n, &pipee) == 1){//le e analisa o comando
        pid_t pid = fork(); //cria o processo filho para criar o comando
        if(pid < 0){
            perror("\n Erro no fork!");
        } else if(pid == 0){ //processo filho
            execvp(cmd[0], cmd);
            Pipes(&cmd,&pipee);
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
    printf("shell>");
    getline(&comando, &size, stdin);
    comando[strlen(comando)-1] = '\0';

    int pipee =0;
    //conta a quantidade de pipes
    for(int i =0; i < strlen(comando); i++){    
        if(comando[i]== '|')pipee++;
    }printf("\ncont de barras: %d\n",pipee);

    //aloca na matrix a quantidade de pipes.
    (*cmds) = (char**)malloc((pipee+1) * sizeof(char**)); 
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

int FuncDup(int in, int out, char** cmds, int j){
    pid_t pid;
    if ((pid = fork()) == 0){
        if (in != 0){
            dup2(in, 0);
            close(in);
        }
        if (out != 1){
            dup2(out, 1);
            close(out);
        }
        return execvp(cmds[j], &cmds[j]);
    }
    return pid;
}

int Pipes (char** cmds,int* pipee ){

    int in = 0;
    int fd[2];
    int j = 0;
    int i = 0;
    pid_t pid = fork();

    if (pid == 0){
        for (i = 0; i < pipee - 1; i++){
            pipe(fd);
            FuncDup(in, fd[1], cmds, j);
            close(fd[1]);
            in = fd[0];
            while (cmds[j] != NULL){
                j++;
            }
            j++;
        }
        if (in != 0){
            dup2(in, 0);
        }
        execvp(cmds[j], &cmds[j]);
        exit(0);
    }else{
        if (sig == 0){
            int status;
            int ret_wait;
            ret_wait = wait(&status);
        }else{
            printf(">>>PID: %d\n", pid);
        }
    }


}
