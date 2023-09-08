//
// Created by felip on 08/09/2023.
//
#include <stdio.h>

int main()
{
    double salarioMin = 1400.00, salario;
    printf("Informe o seu salario: ");
    scanf("%lf", &salario);
    
	
	double qtdSalaMin = salario / salarioMin;

    printf("A quantidade de salario minos que você recebe e: %.2lf\n", qtdSalaMin);

    return 0;
}
