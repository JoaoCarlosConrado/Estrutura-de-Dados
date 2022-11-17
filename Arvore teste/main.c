#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *right;
    struct no *left;
}NO;

typedef struct arvb_no{
    NO *raiz_no;
    int tam_no;
}arv_no;

void adicionar_right(NO* no, int valor);

void adicionar_left(NO *no, int valor){
     if(no->left == NULL){
        NO *novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->left = NULL;
        novo->right = NULL;
        no->left = novo;
    }else{
        if(valor < no->valor){
            adicionar_left(no->left, valor);
        } else if(valor > no->valor){
            adicionar_right(no->left, valor);
        }
    }
}

void adicionar_right(NO *no, int valor){
    if(no->right == NULL){
        NO *novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->left = NULL;
        novo->right = NULL;
        no->right = novo;
    }else{
        if(valor < no->valor){
            adicionar_left(no->right, valor);
        } else if(valor > no->valor){
            adicionar_right(no->right, valor);
        }
    }
}

void adicionar_no(arv_no *arv ,int valor){
    if (arv->raiz_no==NULL){
        NO *novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->left = NULL;
        novo->right = NULL;
        arv->raiz_no = novo;
    }else{
        if(valor < arv->raiz_no->valor){
            adicionar_left(arv->raiz_no, valor);
        } else if(valor > arv->raiz_no->valor){
            adicionar_right(arv->raiz_no, valor);
        }
    }
}

NO *inserir_no(NO *raiz, int valor){
    if(raiz == NULL){
        NO *novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->left = NULL;
        novo->right = NULL;
        return novo;
    }else{
        if(valor < raiz->valor){
            raiz->left = inserir_no(raiz->left, valor);
        }else if(valor > raiz->valor){
            raiz->right = inserir_no(raiz->right, valor);
        }
        return raiz;
    }
}

void imprimir_no(NO *raiz){
    if(raiz != NULL){
        imprimir_no(raiz->left);
        printf("%d ", raiz->valor);
        imprimir_no(raiz->right);
    }
}

int tamanho_no(NO *raiz){
    if(raiz==NULL)
        return 0;
    else
        return 1 + tamanho_no(raiz->left) + tamanho_no(raiz->right);
}

int buscar(NO *raiz, int chave){
    if(raiz == NULL){
        return 0;
    }
    else{
        if(raiz->valor == chave){
            return raiz->valor;
        }
        else{
            if(chave < raiz->valor){
                return buscar(raiz->left, chave);
            }else{
                return buscar(raiz->right, chave);
            }
        }
    }
}

NO *buscar_no(NO *raiz, int chave){
    if(raiz == NULL){
        return NULL;
    }
    else{
        if(raiz->valor == chave){
            return raiz;
        }
        else{
            if(chave < raiz->valor){
                return buscar_no(raiz->left, chave);
            }else{
                return buscar_no(raiz->right, chave);
            }
        }
    }
}

int altura_no(NO *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int left = altura_no(raiz->left);
        int right = altura_no(raiz->right);
        if(left > right)
            return left + 1;
        else
            return right + 1;
    }
}

NO *remover(NO *raiz, int chave){

    if(raiz == NULL){
        printf("Valor nao encontrado");
        return NULL;
    }else{
        if(raiz->valor == chave){
            if(raiz->left == NULL && raiz->right == NULL){
                free(raiz);
                return NULL;
            }else{
                if(raiz->left == NULL || raiz->right == NULL){
                    NO *aux;
                    if(raiz->left != NULL){
                        aux = raiz->left;
                    }else{
                        aux = raiz->right;
                    }
                    free(raiz);
                    return aux;
                }else{
                    NO *aux = raiz->left;
                    while(aux->right != NULL){
                        aux = aux->right;
                    }
                    raiz->valor = aux->valor;
                    aux->valor = chave;
                    raiz->left = remover(raiz->left, chave);
                    return raiz;
                }
            }
        }else{
            if(chave < raiz->valor){
                raiz->left = remover(raiz->left, chave);
            }else{
                raiz->right = remover(raiz->right, chave);
            }
            return raiz;
        }

    }

}

int main(){
    int op, valor, chave;
    arv_no arv;
    arv.raiz_no = NULL;

    do{
        printf("\n0 - SAIR\n1 - ADICIONAR\n2 - IMPRIMIR\n3 - BUSCAR\n4 - REMOVER\n");
        scanf("%d", &op);
        switch(op){
            case 0:
                printf("\nSaindo...\n");
                break;
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                //adicionar_no(&arv, valor);
                arv.raiz_no = inserir_no(arv.raiz_no, valor);
                printf("\nRaiz: %d\n", arv.raiz_no->valor);
                break;
            case 2:
                printf("Resultado:\n");
                imprimir_no(arv.raiz_no);
                printf("\nTamanho da Arvore: %d", tamanho_no(arv.raiz_no));
                printf("\nAltura da Arvore: %d", altura_no(arv.raiz_no));
                break;
            case 3:
                printf("Valor para busca: ");
                scanf("%d", &chave);
                printf("Resultado da Busca: %d", buscar(arv.raiz_no, chave));
                printf("\nAltura do No: %d", altura_no(buscar_no(arv.raiz_no, chave)));
                break;
            case 4:
                printf("Valor para remover: ");
                scanf("%d", &chave);
                arv.raiz_no = remover(arv.raiz_no, chave);
                break;
            default:
                printf("\nOpcao Invalida.\n");
                break;
        }
    }while(op!=0);

    return 0;
}
