//
// Created by felip on 08/09/2023.
//
#include <stdio.h>

int main()
{
    double peso;
    printf("informe seu peso atual: ");
    scanf("%lf", &peso);
    
	
	double peso15 = (peso / 100) *15, peso20 = (peso / 100) *20;
	double pesoEngordar = peso15 + peso, pesoEmagrecer = peso20 + peso;
	
	

    printf("Se voce engordar seu peso sera %.2f\n, caso emagrecer teu peso sera %.2f\n", pesoEngordar, pesoEmagrecer);

    return 0;
}
