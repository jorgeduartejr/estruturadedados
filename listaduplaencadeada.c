#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista* prox;
    struct lista* ant;

};
typedef struct lista Lista;

Lista* cria_lista(void){
    return NULL;
}

Lista* lista_insere(Lista* lst, int val){
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo -> info = val;
    novo -> prox = lst;
    novo -> ant = NULL;

    if (lst != NULL){
        lst -> ant = novo;
    }
    return novo;

}
Lista* lista_busca(Lista* lst, int val){
    Lista* p;
    for(p=lst;p != NULL;p = p->prox){
        
        if (p -> info == val)
        {
            return p;
        }
        
    }
    return NULL;
}
Lista* lista_retira(Lista* lst, int val){
    Lista* p = lista_busca(lst,val);
    if (p == NULL)
    {
        return lst;
    }
    if (lst == p)
    {
        lst = p -> prox;
    } else{
        p-> ant->prox = p-> prox;
    }
    if (p-> prox != NULL)
    {
        p-> prox -> ant = p-> ant;
    }
    free(p);
    
    return lst;
    
}



int main(void){

    return 0;
}