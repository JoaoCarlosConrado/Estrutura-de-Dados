#include<stdio.h>
#include<stdlib.h>

typedef struct No{
    int valor;
    struct No * prox;
}No;

No * inicio = NULL;
No * fim = NULL;
int tam = 0;

void adicionar(int valor, int pos){
    if(pos>= 0 && pos<= tam){
        No * novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = NULL;
    
        if(inicio == NULL){ //lista vazia!
            inicio = novo;
            fim = novo;
        }else if(pos == 0){ // posicao é 0 - inicio! :D
            novo->prox = inicio;
            inicio = novo;
        }else if(pos == tam){ //posicao é tam - fim! :D
            fim->prox = novo;
            fim = novo;
        }else{ //no meio! :'(
            //pedaco problematico!!!!!
            No * aux = inicio;
            for(int i = 0; i< pos - 1; i++){
                aux = aux->prox;
            }
            novo->prox = aux->prox;
            aux->prox = novo;
        }
        tam++;
    }
}


int remover(int pos){
    if(pos>=0 && pos<tam){
        if(inicio == NULL){//Verifica se a lista é vazia
            return 0;
        }
        if(pos == 0){//remover no inicio
            No *aux = inicio;
            inicio = inicio->prox;
            free(aux);
            if(tam == 1)
                fim = NULL;
        }else {//remover no meio ou fim
            No *aux = inicio;
            for(int i=0;i<pos-1;i++){
                aux = aux->prox;
            }
            if(aux->prox==fim)//verifica se o nó que quero excluir é o fim
                fim = aux;
            No *aux2 = aux->prox->prox;
            free(aux->prox);
            aux->prox = aux2;
            
        }
        tam--;
        return 1;
    }
    return 0;
}

//fiz um novo imprimir, pois o imprimir ensinado em aula, disfarçava um erro do código e graças a esse imprimir, pude corrigi-lo
void imprimir(No *no){
    if(tam == 0){
        return;
    }
    if(no != NULL)
        printf("VALOR = %d\n", no->valor);
    if(no->prox != NULL)
        imprimir(no->prox);
}

/*
void imprimir(){
    No * aux = inicio;
    for(int i = 0; i<tam; i++){
        printf("Valor = %d\n", aux->valor );
        aux = aux->prox;
    }
    
}
*/
int main(){
    adicionar(10,0);
    
    remover(0);
    /*if(remover(10)){
        printf("Número removido com sucesso\n");
    }
    */
    imprimir(inicio);
    return 0;
    
}
