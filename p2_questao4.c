#include <stdlib.h>
#include <stdio.h>


struct lista{
    int info;
    struct lista* ant; // cria um ponteiro pra estrutura anterior
    struct lista* prox;// cria um ponteiro para a proxima estrutura
};
typedef struct lista Lista;

// Insere no inicio da lista
Lista* lst_insere(Lista* lst, int val){
    Lista* novo = (Lista*)malloc(sizeof(Lista)); // aloca memoria
    novo->info = val; 
    novo->prox = lst;
    novo->ant = NULL;

    if(lst != NULL){
        lst -> ant = novo;
    }
    return novo;
}
// busca um elemento
Lista* lst_busca (Lista* lst, int val){
    Lista* p;
    for(p=lst; p!= NULL; p=p->prox){
        if (p-> info == val)
        {
            return p;
        } 
    }
    return NULL; // quando não acha o elemento
}

// remove o elemento da lista
Lista* lst_retira(Lista* lst, int val){
    Lista* p = lst_busca(lst,val);
    if(p == NULL){
        return lst; // não achou o elemento
    }
    // retira elemento do encadeamento
    if(lst == p){ // testa se o elemento é o primeiro
        lst = p->prox;
    }else{
        p-> ant->prox = p-> prox;
    }
    if(p-> prox != NULL){// testa se é o ultimo elemento da lista
        p-> prox -> ant = p-> ant;
    } 
    free(p); // desaloca memoria do ponteiro p

    return lst;
}
// função imprime lista
void lst_imprime(Lista* lst){
    Lista* p;
    printf("\n----------------------------\n");
    for(p = lst;p!= NULL;p = p-> prox){
        printf("\t - %d\n", p->info);
    }
    printf("\n----------------------------\n");
}
// cria uma lista vazia
Lista* lst_cria(void){ // cria uma lista vazia rtornando o ponteior NULL
    return NULL; 
}


int main(void){
    Lista* lst; // declarei a lista
    lst = lst_cria(); // criei e inicializei a lista vazia

    int opcao,valor;
    do{
        printf("\n\tLista duplamente encadeada\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\tDigite uma opção: ");
        scanf("%d", &opcao);
        switch(opcao){
        case 1: 
            printf("Digite um valor: ");
            scanf("%d",&valor);
            lst = lst_insere(lst,valor);
            lst_imprime(lst);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d",&valor);
            lst = lst_retira(lst,valor);
            lst_imprime(lst);
            break;
        case 3:
            
            lst_imprime(lst);
            break;
        
        default:
            if (opcao != 0)
            {
                printf("Opção inválida!\n");
            }
           
        }
      
    }while (opcao != 0);
    

    return 0;
}