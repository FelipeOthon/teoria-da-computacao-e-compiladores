//
// Created by felip on 08/09/2023.
//
#include <stdio.h>
#include <math.h>
int main()
{
    double raio, pi = 3.1415;
    printf("Informe o raio: ");
    scanf("%lf", &raio);
    
	double c = 2 * pi * raio;
	double a =  pi * pow (raio,2);
	double v = (4.0 / 3.0) * pi * pow (raio,3);
	
	printf("O comprimento da esfera e %.2f\n ", c);
	printf("A área de uma esfera e %.2f\n", a);
	printf("O volume de uma esfera e %.2f\n", v);
	
    return 0;
}