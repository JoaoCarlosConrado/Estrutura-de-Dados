#include<stdlib.h>
#include<stdio.h>
#include "../lib/No.h"

NO *add (int id, int sexo, int num_filhotes,NO *inicio){
    NO *novo = malloc (sizeof(NO));
    novo->id = id;
    novo->sexo = sexo;
    novo->num_filhotes = num_filhotes;
    if(inicio == NULL){
        novo->prox = novo;
        novo->ant = novo;
        inicio = novo;
    }else{
        NO *fim = inicio->ant;
        novo->prox = inicio;
        novo->ant = fim;
        inicio->ant = novo;
        fim->prox = novo;
        if(inicio->prox == inicio)
            inicio->prox = novo;
    }
    return inicio;
}

NO *del(int id,NO *inicio, int tam){
    NO *aux = inicio;
    for(int i=0; i<tam ;i++){
        if(id == aux->id)
            break;
        if(aux->prox == inicio){
            printf("id invalido!\n");
            return;
        }
        aux = aux->prox;
    }
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    if(aux == inicio){
        if(aux->prox == inicio)
            inicio = NULL;
        else
            inicio = aux->prox;
    }
    free(aux);
    return inicio;
}

int soma (NO *no, NO *inicio){
    if(no == NULL)
        return 0;
    if(no->prox == inicio)
        return no->num_filhotes;
    else
        return no->num_filhotes + soma(no->prox, inicio);
}

void imprimir(NO *inicio, int tam){
    NO *aux = inicio;
    for(int i=0; i<tam ;i++){
        printf("%d\n", aux->id);
        aux = aux->prox;
    }
}

int tam(NO *inicio){
    int tamanho = 0;
    NO *aux = inicio->prox;
    if(inicio != NULL)
        tamanho = 1;
    while(aux != inicio){
        tamanho++;
        aux = aux->prox;
    }
    return tamanho;
}