//
// Created by felip on 08/09/2023.
//
#include <stdio.h>

int main()
{
    double cotacao, dolares, reais;

    printf("Informe cotacao do dolar em reais: ");
    scanf("%lf", &cotacao);
    printf("Informe o valor atual do dolar: ");
    scanf("%lf", &dolares);

    reais = dolares * cotacao;

    printf("O valor em reais e: %.2lf\n", reais);

    return 0;
}
