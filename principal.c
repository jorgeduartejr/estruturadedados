
// Função principal
#include <converte.c>

int main(void){

    float t1;
    float t2;
    // Mostra a mensagem para o usuário
    printf("Digite a temperatuda em Celsius: ");
    // Captura o valor entrado via teclado
    scanf("%f", &t1);
    // Converte o valor, chamando a função auxiliar
    t2 = converte(t1);
    // exibe resultado
    printf("Temperatura em Fahrenheit: %f\n", t2);
    return 0;
}