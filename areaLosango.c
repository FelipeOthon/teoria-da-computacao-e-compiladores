//
// Created by felip on 08/09/2023.
//
#include <stdio.h>

int main()
{
    double dmaior, Dmenor;
    printf("Informe a diagonal maior do losango: ");
    scanf("%lf", &dmaior);
    printf("Informe a diagonal menor do losango: ");
    scanf("%lf", &Dmenor);
	
	double area = (dmaior / Dmenor) / 2;

    printf("A area do losango e: %.2lf\n", area);

    return 0;
}
