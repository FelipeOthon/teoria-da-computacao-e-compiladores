//
// Created by felip on 08/09/2023.
//
#include <stdio.h>

int main()
{
    double salario;
    printf("Informe seu salario: ");
    scanf("%lf", &salario);
	
	double aumento = (salario / 100) * 25;
	double salarioNovo = salario + aumento;

    printf("O valor em reais foi de R$%.2lf\n e teu novo salario e R$%.2lf\n", aumento, salarioNovo);

    return 0;
}
