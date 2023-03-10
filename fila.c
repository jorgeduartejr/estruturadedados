#include <stdio.h>
#include <stdlib.h>

// nó da lista para armazenar valores reais
struct lista{
    float info;
    struct lista *prox;
};
typedef struct lista Lista;

// estrutura da fila
struct fila{
    Lista* ini;
    Lista* fim;
};
typedef struct fila Fila;

Fila* fila_cria(void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}
// função insere: insere um novo elemento na lista

void fila_insere(Fila* f, float v){
    Lista* n = (Lista*) malloc(sizeof(Lista));
    n-> info = v; // armazena a info
    n ->prox = NULL; //  novo nó passa ser o último
    if (f-> fim != NULL) // verifica se a fila nao está vazia
    {
        f-> fim -> prox = n;
    }
    else{ // fila estava vazia
        f -> ini = n;
    }
    f ->fim = n; // filha aponta para novo elemento
    
}
//verifica se a fila esta vazia
int fila_vazia(Fila* f){
    return(f-> ini == NULL);
}
float fila_retira(Fila* f){
    Lista *t;
    float v;
    if (fila_vazia(f)){printf("Fila vazia. \n");
        exit(1);} // aborta programa
    t = f-> ini;
    v = t-> info;
    f -> ini = t -> prox;
    if(f-> ini ==  NULL) // verifica se fila ficou vazia
        f-> fim = NULL;
    free(t);
    return v;
    
}