#include <stdio.h>
#include <stdlib.h>

struct lista {
    int info; // informação
    struct lista *prox; // cria ponteiro para o proximo
};
typedef struct lista Lista; // novo tipo de dado Lista


// criar uma lista que retorna vazio
Lista* cria_lista(void){
    return NULL;
}

// insere no inicio e retona a lista atualizada

Lista* insere_lista (Lista* lst, int val){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo-> info = val;
    novo ->prox = lst;
    return novo;
}

// imprimir lista
void imprime_lista (Lista* lst){
    Lista *p;
    for(p = lst; p != NULL; p = p-> prox)
        printf("Info = %d\n", p->info);
}
// testar se lista esta vazia
int lista_vazia (Lista* lst){
    return (lst == NULL);
}
// função buscar
Lista* busca(Lista* lst, int val){
    Lista *p;
    for(p=lst; p!= NULL; p ->prox){
        if (p-> info == val)
        {
            return p;
        }
    }
}
// função retira

Lista* retira_lista(Lista* lst, int val){
    Lista *ant = NULL; // ponteiro pro elemento anterior
    Lista *p = lst; // ponteiro que percorre a lista
    // percorre a lista e guarda o anterior
    while(p != NULL && p-> info != val){
        ant = p;
        p = p->prox;
    }
    //verifica se achou o elemento
    if(p == NULL)
        return lst;
    
    // retira elemento da lista
    if (ant == NULL)
    {
        lst = p-> prox;// retira do começo da lista
    }
    else{
        ant->prox = p ->prox; // retira no meio da lista
    }
    free(p); // desaloca p
    return lst;
    
}

void libera_lista(Lista* lst){
    Lista *p = lst;
    while (p != NULL)
    {
        Lista* t = p-> prox; // var temp recebe ref pro proximo elemento
        free(p);    // libera a memoria do p
        p = t;      // faz p apontar pro prox
    }
    
}

void inverte_lista(Lista* lst, int ){

}

int main(void){

    Lista* lst; // declarou lista mas ainda não inicializou
    lst = cria_lista(); // cria a lista vazia
    lst = insere_lista(lst, 23); // insere na lista criada o 23
    lst = insere_lista(lst, 45); //  insere na lista 45
    lst = insere_lista(lst, 56); // insere lista 56
    lst = insere_lista(lst, 78); //  insere lista 78
    imprime_lista(lst); // imprime a lista
    printf("---------------------------\n");
    lst = retira_lista(lst, 78); // remove da lista 78
    imprime_lista(lst);  // 23 45 56
    printf("---------------------------\n");
    lst = retira_lista(lst, 45);
    imprime_lista(lst); // 23 56
    printf("---------------------------\n");

    return 0;
}