#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h> //ler de um terminal
#include <readline/history.h>  //histórico dos comandos

#define NDEBUG
#include <assert.h>

#include <signal.h>

#define MAXCMD 128
#define MAXSTR 1024

#define clear() printf("\033[H\033[J")

char **str_split(char *a_str, const char a_delim);
void startShell();
int takeInput(char *inputStr);
int auxCmd(char **cmdStr);
int spawnProcess(int in, int out, char **cmdStr, int j);
int forkPipes(char **cmdStr, int numCmds);

static void sig_usr(int);
static int sig = 0;

char **str_split(char *a_str, const char a_delim)
{
    char **result = 0;
    size_t count = 0;
    char *tmp = a_str;
    char *last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }
    count += last_comma < (a_str + strlen(a_str) - 1);
    count++;
    result = malloc(sizeof(char *) * count);
    if (result)
    {
        size_t idx = 0;
        char *token = strtok(a_str, delim);
        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }
    return result;
}

void startShell()
{
    clear();
}

int takeInput(char *inputStr)
{
    char *str, dir[MAXSTR];
    char *username = getenv("USER");

    char hostname[32];
    gethostname(hostname, 32);

    getcwd(dir, sizeof(dir));

    fflush(stdin);

    printf("%s@%s:%s", username, hostname, dir);
    str = readline("$ ");
    if (strlen(str) != 0)
    {
        add_history(str);
        strcpy(inputStr, str);
        return 0;
    }
    else
    {
        return 1;
    }
}

int auxCmd(char **cmdStr)
{
    int cmdNum = 2, cmdS = 0;
    char *cmdList[cmdNum];

    cmdList[0] = "exit";
    cmdList[1] = "cd";

    for (int i = 0; i < cmdNum; i++)
    {
        if (strcmp(cmdStr[0], cmdList[i]) == 0)
        {
            cmdS = i + 1;
            break;
        }
    }

    switch (cmdS)
    {
    case 1:
        printf("Bye Bye...\n");
        sleep(0.5);
        exit(0);
    case 2:
        chdir(cmdStr[1]);
        return 1;
    default:
        break;
    }
    return 0;
}

int spawnProcess(int in, int out, char **cmdStr, int j)
{
    pid_t pid;
    if ((pid = fork()) == 0)
    {
        if (in != 0)
        {
            dup2(in, 0);
            close(in);
        }
        if (out != 1)
        {
            dup2(out, 1);
            close(out);
        }
        return execvp(cmdStr[j], &cmdStr[j]);
    }
    return pid;
}

int forkPipes(char **cmdStr, int numCmds)
{
    if (sig == 1)
    {
        signal(SIGCHLD, sig_usr);
    }

    if (numCmds == 1)
    {
        pid_t pid;
        if ((pid = fork()) == -1)
        {
            printf("Falha na criação do filho\n");
            exit(0);
        }
        else if (pid == 0)
        {
            if (execvp(cmdStr[0], cmdStr) < 0)
            {
                printf("Não foi possível executar o comando\n");
                exit(0);
            }
        }
        else
        {
            if (sig == 0)
            {
                int status;
                int ret_wait;
                ret_wait = wait(&status);
            }
            else
            {
                printf("- [PID: %d]\n", pid);
            }
        }
    }
    else
    {
        int i, in = 0, fd[2], j = 0;
        pid_t pid = fork();

        if (pid == 0)
        {
            for (i = 0; i < numCmds - 1; i++)
            {
                pipe(fd);
                spawnProcess(in, fd[1], cmdStr, j);
                close(fd[1]);
                in = fd[0];
                while (cmdStr[j] != NULL)
                {
                    j++;
                }
                j++;
            }
            if (in != 0)
            {
                dup2(in, 0);
            }
            execvp(cmdStr[j], &cmdStr[j]);
            exit(0);
        }
        else
        {
            if (sig == 0)
            {
                int status;
                int ret_wait;
                ret_wait = wait(&status);
            }
            else
            {
                printf("- [PID: %d]\n", pid);
            }
        }
    }
}
static void sig_usr(int funcSig)
{
    if (funcSig == SIGCHLD)
    {
        int status;
        int ret_wait;
        ret_wait = wait(&status);
        if (ret_wait > 0)
        {
            printf("- [DONE: %d]\n", ret_wait);
        }
    }
}

int main()
{
    char inputStr[MAXSTR];
    int auxExec, numCmds, cont;

    startShell();

    while (1)
    {
        numCmds = 1;
        cont = 0;

        for (int forr = 0; forr < MAXCMD; forr++)
        {
            inputStr[forr] = '\0';
        }

        if (takeInput(inputStr))
        {
            continue;
        }

        char **inp = str_split(inputStr, ' ');
        while (inp[cont] != NULL)
        {
            if ((strcmp(inp[cont], "&") == 0) && inp[cont + 1] == NULL)
            {
                sig = 1;
                inp[cont] = NULL;
            }
            cont++;
        }

        cont = 0;

        while (inp[cont] != NULL)
        {
            if (strcmp(inp[cont], "|") == 0)
            {
                inp[cont] = NULL;
                numCmds++;
            }
            cont++;
        }

        if (auxCmd(inp))
            auxExec = 0;
        else
            auxExec = 1;

        if (auxExec == 1)
        {
            forkPipes(inp, numCmds);
        }
        sig = 0;
    }
    return 0;
}