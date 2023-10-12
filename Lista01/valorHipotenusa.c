//
// Created by felip on 08/09/2023.
//
#include <stdio.h>
#include <math.h>
int main()
{
    double b, c;
    printf("Informe o Cateto de b: ");
    scanf("%lf", &b);
    printf("Informe o Cateto de c: ");
    scanf("%lf", &c);

    
	
	double a = sqrt(pow (b,2) + pow (c,2));
	
	
	

    printf("o valor da hipotenusa e %.2f\n", a);

    return 0;
}
