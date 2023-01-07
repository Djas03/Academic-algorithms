/**
 * UFMT - Bacharelado em Ciencia da Computacao
 * Prof. Ivairton
 *
 * Exercicio com manipulacao de registros.
 */
#include<stdio.h>
#include<stdlib.h>

//Definicao de tipos
struct est_ponto {
    int x;
    int y;
};
typedef struct est_ponto tipo_ponto;

struct est_linha {
    tipo_ponto p1;
    tipo_ponto p2;
};
typedef struct est_linha tipo_linha;