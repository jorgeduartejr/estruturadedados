#include <stdlib.h>
#include <stdio.h>



struct arv{
    char info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

Arv* arv_criavazia(void){ // cria uma arvore vazia que retorna NULL
    return NULL;
}

Arv* arv_cria (char c, Arv* sae,Arv* sad){ // cria uma nó raiz dadas as informações
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p-> info = c;
    p-> esq = sae;
    p-> dir = sad;
    return p; // retorna o endereço do no raiz criado
}

int arv_vazia(Arv* a){
    return a == NULL;
}

Arv* arv_libera(Arv* a){
    if (!arv_vazia(a))
    {
        arv_libera(a->esq); // libera sae
        arv_libera(a->dir); // libera sad
        free(a); // libera raiz
    }
    return NULL;
}

int arv_pertence(Arv* a, char c){
    if(arv_vazia(a))
        return 0;   // arvore vazia: não encontrada
    else{
        return a->info == c ||
        arv_pertence(a->esq,c) ||
        arv_pertence(a-> dir,c);
    }
}

void arv_imprime(Arv* a){
    printf("<");
    if(!arv_vazia(a)){ // se for diferente da arv_vazia(a) imprime
        printf("%c ", a-> info); // mostra raiz
        arv_imprime(a->esq);    // mostra sae
        arv_imprime(a->dir);    // mostra sad
    }
    printf(">");
}
  

int main(void){
    
    
    return 0;
}

