#include <stdlib.h>
#include <stdio.h>

struct no{
    int id;
    int sexo;
    int num_filhotes;
    struct no *prox;
    struct no *ant;
}typedef NO;


NO *add (int id, int sexo, int num_filhotes,NO *inicio);

NO *del(int id,NO *inicio, int tam);

int soma (NO *no,NO *inicio);

void imprimir(NO *inicio, int tam);

int tam(NO *inicio);