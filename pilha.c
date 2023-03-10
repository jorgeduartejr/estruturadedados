#include <stdio.h>
#include <stdlib.h>


// nó da lista para armazenar valores reais
struct elemento{
    int info;
    struct elemento *prox;
};
typedef struct elemento Elemento;

// estrutura da pilha
struct pilha{
    Elemento* prim; // aponta para o topo da pilha
};
typedef struct pilha Pilha;


// cria e aloca a estrutura da pilha
// inicializa a lista sendo vazia
Pilha* pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->prim = NULL;
    return p;
}
// insere um novo elemento no inicio da lista
void pilha_push(Pilha* p, float v){
    Elemento*  n = (Elemento*) malloc(sizeof(Elemento));
    n -> info = v;
    n-> prox = p-> prim;
    p-> prim = n;
}

// retira o elemento do inicio da lista
float pilha_pop(Pilha* p){
    Elemento* t;
    float v;
    if (pilha_vazia(p)) exit(1); // aborta programa
    t = p->prim;
    v = t->info;
    p->prim = t->prox;
    free(t);
    return v;

}

// libera todos os elementos da lista e depois libera
void pilha_libera(Pilha* p){
    Elemento *t, *q = p->prim;
    while (q != NULL)
    {
        t = q-> prox;
        free(q);
        q = t;
    }
    free(p);
}

// retorna 1 se a pilha esta vazia, ou 0 caso contrário
int pilha_vazia(Pilha* p){
    if (p->prim == NULL)
    {
        return 1;
    }
    return 0;
    
}

int main(void){

    


    return 0;
}