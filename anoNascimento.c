//
// Created by felip on 08/09/2023.
//
#include <stdio.h>

int main()
{
    int anoNascimento, anoAtual;

    printf ("Informe seu ano de Nascimento ");
    scanf("%d", &anoNascimento);
    printf ("Informe o ano atual: ");
    scanf("%d", &anoAtual);
    int idade = anoAtual - anoNascimento;
    int idade2050 = 2050 - anoNascimento;

    printf("A Sua idade atual e: %d anos, e em 2050 voce tera: %d anos ", idade, idade2050);

    return 0;


}
