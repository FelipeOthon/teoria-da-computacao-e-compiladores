//
// Created by felip on 08/09/2023.
//
#include <stdio.h>

int main()
{
    double celsius, fahrenheit;
    printf("Informe a temperatura em Celsius: ");
    scanf("%lf", &celsius);
    
	
	fahrenheit = (celsius * 1,8 ) + 32;

    printf("A temperatura em fahrenheit e: %.2lf\n", fahrenheit);

    return 0;
}
