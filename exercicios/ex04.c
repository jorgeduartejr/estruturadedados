// Implemente uma função que receba como paramentos dois numeros inteiros, n e k, e calcule o coeficiente binomial

#include <stdio.h>

int coeficiente(int n, int k);
int main(){
    int n, k;
    int coef;

    printf("Digite os numeros n e k: ");
    scanf("%d %d", &n, &k);
    if (n < k || n < 0)
    {
        printf("Erro! n deve ser maior ou igual a k e maiores ou igual a zero\n");
    }
    else{
        coef = coeficiente(n,k);
        printf("coeficiente = %d\n", coef);
    }

    return 0;
}
int coeficiente(int n, int k){
    int coef;
    if (n == k || k == 0)
    {
        return 1;
    }
    else{
        return coeficiente(n-1,k) + coeficiente(n-1,k-1);
    }
    
}