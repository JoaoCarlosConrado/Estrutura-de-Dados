#include <stdlib.h>
#include <stdio.h>
#include "../lib/No.h"

NO *inicio = NULL;

int main(){
    inicio = add(1,1,2,inicio);
    inicio = add(2,1,1,inicio);
    inicio = add(3,0,0,inicio);
    inicio = add(4,1,2,inicio);
    inicio = add(5,0,0,inicio);
    //inicio = del(1, inicio, tam(inicio));
    //inicio = del(2, inicio, tam(inicio));
    //inicio = del(5, inicio, tam(inicio));
    printf("Filhotes: %d\n", soma(inicio, inicio));
    imprimir_no(inicio, inicio);
    return 0;
}