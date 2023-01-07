/*
UFMT - Estrutura de dados 1
prof. Ivairton 
Aluno: Djalma de Almeida Mendes
*/

#include <stdio.h>
#include <stdlib.h>

struct crianca_t {
    char nome[30];
    int valor;
    int prev, next;
};

int main()
{
    while (1) {
        int N, i, j;
        struct crianca_t crianca[100];

        scanf("%d", &N);
        if (!N)
            break;

        for (i = 0; i < N; ++i) {
            scanf("%s%d", crianca[i].nome, &crianca[i].valor);

            crianca[i].prev = ((i - 1) % N + N) % N;
            crianca[i].next = (i + 1) % N;
        }

        i = 0;
        while (N > 1) {
            int valor = crianca[i].valor;

            if (valor % 2) {
                for (j = 0; j < valor; ++j)
                    i = crianca[i].next;
            } else {
                for (j = 0; j < valor; ++j)
                    i = crianca[i].prev;
            }

            crianca[crianca[i].prev].next = crianca[i].next;
            crianca[crianca[i].next].prev = crianca[i].prev;

            --N;
        }
        i = crianca[i].next;

        printf("Vencedor(a): %s\n", crianca[i].nome);
    }

    return 0;
}