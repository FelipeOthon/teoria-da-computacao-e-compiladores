#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    printf ("\Informe a primeira nota: ");
    scanf("%d", &a);
    printf ("\Informe a segunda nota: ");
    scanf("%d", &b);
    printf ("\Informe a terceira nota: ");
    scanf("%d", &c);

    int media = (a + b + c) /3;

    printf("\A media foi: %d", media);

    return 0;


}
// Created by felip on 08/09/2023.
//
