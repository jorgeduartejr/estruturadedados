// Faça um programa que recebe como entrada a nota de 3 alunos e calcula a média

#include <stdio.h>

float media(float G1, float G2, float G3);

int main(){
    
    int nota1,nota2,nota3, notaFinal;
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    // verificando se notas são maiores que 3
    if ((nota1 && nota2 && nota3) > 3){
        printf("Tudo certo, verificando outros requisitos...\n");
        // verificando se está aprovado ou não...
        if (notaFinal < 5)
        {
            printf("Reprovado por média!\n");
        } 
        else
        {
            printf("Aprovado!\n");
        }
    } else{
        printf("Reprovado!\n");
    }

    // chamando a função

    notaFinal = media(nota1,nota2,nota3);
    
    
    return 0;
}

float media(float G1, float G2, float G3){
    int notaFinal;
    notaFinal = (G1 + G2 + G3)/3;
    return notaFinal; // retorna pra main o valor da média
}
