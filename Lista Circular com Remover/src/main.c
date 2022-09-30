#include <stdlib.h>
#include <stdio.h>
#include "../lib/No.h"

NO *inicio;
int tam = 0;

void add (int id, int sexo, int num_filhotes){
    NO *novo = malloc (sizeof(NO));
    novo->id = id;
    novo->sexo = sexo;
    novo->num_filhotes = num_filhotes;
    if(tam == 0){
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
    tam++;
}

void del(int id){
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
    tam--;
}

int soma (NO *no){
    if(no == NULL)
        return 0;
    if(no->prox == inicio)
        return no->num_filhotes;
    else
        return no->num_filhotes + soma(no->prox);
}

void imprimir(){
    NO *aux = inicio;
    for(int i=0; i<tam ;i++){
        printf("%d\n", aux->id);
        aux = aux->prox;
    }
}
int main(){
    add(1,1,2);
    add(2,1,1);
    add(3,0,0);
    add(4,1,2);
    add(5,0,0);
    //del(1);
    //del(3);
    //del(5);
    printf("Filhotes: %d\n", soma(inicio));
    imprimir();
    return 0;
}
