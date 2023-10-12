//
// Created by felip on 08/09/2023.
//
#include <stdio.h>
#include <math.h>
int main()
{
    int a;
    printf("Informe um numero: ");
    scanf("%d", &a);

    
	
	for (int i = 0; i<= 10; i++){
		
		int resultado = a * i;
		printf("%d x %d = %d\n", a, i, resultado);
		
	}
	

    return 0;
}