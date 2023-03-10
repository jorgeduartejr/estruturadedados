#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista *prox;
};
typedef struct lista Lista;

void cria_lista(void){
    return NULL;
}

Lista* insere_lista(Lista* lst, int val){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    novo->info = val;
    novo->prox = lst;
    return novo;

}

Lista* busca(Lista* lst, int val){
    
}




int main(){
    return 0;
}