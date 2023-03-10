#include <stdlib.h>
#include <stdio.h>

typedef struct inLista{
    int info;
    struct inLista *prox;
} Elemento;

Elemento* criarNovo(int Caractere);
Elemento* Push(Elemento *Topo, int Caractere);
Elemento* Pop(Elemento *Topo);
Elemento* Top(Elemento *Topo);

int main(){
    int Dados, i, op;
    Elemento *PilhaA = NULL, *aux, *PilhaB = NULL;

    do
    {
        printf("1 - Adicionar elemento\n");
        printf("2 - Remover elemento\n");
        printf("0 - Encerrar\n\n");

        printf("Opção: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                printf("Digite um inteiro: ");
                scanf("%d", &Dados);

                PilhaA = Push(PilhaA,Dados);
                printf("Elemento adicionado\n\n");
                break;

            case 2:
                if (Top(PilhaB) == NULL)
                {
                    while (Top(PilhaA) != NULL)
                    {
                        int removido = Top(PilhaA) -> info;
                        PilhaA = Pop(PilhaA);
                        PilhaB = Push(PilhaB, removido);
                    }
                    
                }
                if (Top(PilhaB) == NULL)
                {
                    while (Top(PilhaA) != NULL)
                    {
                        int removido = Top(PilhaA) -> info;
                        PilhaA = Pop(PilhaA);
                        PilhaB = Push(PilhaB, removido);
                    }
                }
                if(Top(PilhaB) != NULL) {
                    int removido = Top(PilhaB)->info;
                    PilhaB = Pop(PilhaB);
                    printf("Elemento %d removido\n\n", removido);
                }   
                if(Top(PilhaB) != NULL) {
                    int removido = Top(PilhaB)->info;
                    PilhaB = Pop(PilhaB);
                    printf("Elemento %d removido\n\n", removido);
                } else {
                    printf("A pilha esta vazia\n\n");
                }
            break;

            case 3:
 
                break;

        }
    } while(op!=0);
    return 0;
}

Elemento* criarNovo(int Caractere) {
    Elemento *novo;
 
    novo = (Elemento*) malloc(sizeof(Elemento));
    novo->info = Caractere;
    novo->prox = NULL;
 
    return novo;
}
 
Elemento* Push(Elemento *Topo, int Caractere) {
    Elemento *novo;
 
    novo = criarNovo(Caractere);
 
    novo->prox = Topo;
    Topo = novo;
    return Topo;
}
 
Elemento* Pop(Elemento *Topo) {
    Elemento *aux;
 
    aux = Topo;
    if(Topo != NULL) {
        Topo = Topo->prox;
        free(aux);
    }
    return Topo;
}
 
Elemento* Top(Elemento *Topo) {
    return Topo;
}


