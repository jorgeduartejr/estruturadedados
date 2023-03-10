#include <stdio.h>
#include <stdlib.h>

struct arvvar{
    char info;
    struct arvar *prim; // ponteiro para o eventual primeiro filho
    struct arvvar *prox; // ponteiro para o eventual irmão

};
typedef struct arvvar ArvVar;

ArvVar* arvv_cria(char c);
void arvv_insere(ArvVar* a, ArvVar* sa);
void arvv_imprime(ArvVar* a);
int arvv_pertence(ArvVar* a, char c);
void arvv_libera(ArvVar* a);
int arvv_altura(ArvVar* a);

ArvVar* arvv_cria(char c){
    ArvVar *a = (ArvVar*)malloc(sizeof(ArvVar)); // aloca o nó
    a->info = c; // info do campo é o char que foi recebido como parametro
    a-> prim = NULL; // inicializa os campos e atribui NULL
    a-> prox = NULL;
    return a;
}

void arvv_insere(ArvVar* a, ArvVar* sa){
    sa-> prox = a->prim; // insere uma nova subarvore como filha de um dado no inicio da lista
    a-> prim = sa;
}

void arvv_imprime(ArvVar* a){
    ArvVar* p;
    printf("<%c /n", a->info);
    for(p=a->prim; p!= NULL; p = p-> prox){
        arvv_imprime(p); // imprime filhas
    }
    printf(">");
}   

int arvv_pertence(ArvVar* a, char c){ // verifica a ocorrencia da informação na arvore
    ArvVar* p;
    if (a-> info == c)
    {
        return 1;
    } else{
        for (p=a->prim; p!= NULL; p = p-> prox)
        {
            if (arvv_pertence(p,c))
            {
                return 1;
            }
        }
    }
    return 0;
}

void arvv_libera(ArvVar* a){ // libera as subarvores antes de liberar o espaço associado a um nó
    // ou seja, libera em pós ordem
    ArvVar* p = a->prim;
    while(p!= NULL){
        ArvVar* t = p-> prox;
        arvv_libera(p);
        p = t;
    }
    free(a);
}

static int max2(int a, int b){
    return(a>b) ? a : b; // if a > b return a, else return b
}

int arvv_altura(ArvVar* a){ // altura da subarvore filha acrescido de uma unidade
// altura da sub arvore irma
    if(a == NULL)
        return -1;
    else
        return max2(1+arvv_altura(a->prim),arvv_altura(a->prox));
}

