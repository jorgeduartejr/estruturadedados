#include <stdio.h>
#include <stdlib.h>

struct arv{
    int info;
    struct arv* esq;
    struct arv* dir;

};
typedef struct arv Arv;

Arv* abb_cria(void){
    return NULL; // cria arvore vazia representada que recebe null
}

void abb_imprime(Arv* a){ // imprime os valores da arvore em ordem crescente, percorrendo os nos em ordem simetrica (sae - raiz - sad)
    if(a != NULL){
        abb_imprime(a->esq);
        printf("%d\n",a->info);
        abb_imprime(a->dir);
    }
}

Arv* abb_busca(Arv* r, int v){
    if(r == NULL)
        return NULL; // arvore vazia
    else if(r->info > v)
        return abb_busca(r->esq,v); // busca o valor no no a esquerda
    else if(r->info < v)
        return abb_busca(r->dir,v); // busca o valor no nó a direita
    else 
        return r;
}

Arv* abb_insere(Arv* a, int v){
    if(a == NULL){
        a = (Arv*) malloc(sizeof(Arv));
        a->info =  v;
        a-> esq = a-> dir = NULL;
    }
    else if(v < a-> info)
        a -> esq = abb_insere(a-> esq,v); // se for menor que o nó insere na esquerda
    
    else // v >= a->info
        a -> dir = abb_insere(a-> dir,v); // se for maior que o nó insere na direita
    
    return a;
}

Arv* abb_retira(Arv* r, int v){
    if(r == NULL)
        return NULL;
    else if(r -> info > v)
        r ->esq = abb_retira(r->esq,v);
    else if(r-> info < v)
        r-> dir = abb_retira(r->dir,v);
    else{ // Achou o nó a ser removido
        // nó sem filhos
        if(r-> esq == NULL && r -> dir == NULL){
            free(r);
            r = NULL;
        }
        // nó só tem filho a direita
        else if (r-> esq == NULL){
            Arv* t = r;
            r = r-> dir;
            free(t);
        }
        // nó so tem filho a esquerda
        else if(r -> dir == NULL){
            Arv* t = r;
            r = r -> esq;
            free(t);
        }
        // nó tem os dois filhos
        else{
            Arv* f = r ->esq;
            while(f-> dir != NULL){
                f = f-> dir;
            }
            r -> info = f -> info; // troca as informações
            f -> info = v;
            r -> esq = abb_retira(r-> esq, v);

        }
    }
    return r;
}