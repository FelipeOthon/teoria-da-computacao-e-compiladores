#include <stdio.h> //FILE, fopen (), getchar (), putc (),
//fclose ().
#include <stdlib.h> //system ().

void ler_escrever_printar(FILE *arq) {

    int ch;

    arq = fopen("arquivoC.txt", "w");

    if (arq == NULL) {
        printf("\n Erro ao abrir o arquivo arquivoC.txt.");
        system("pause");
        exit(1);
    }

    for (int i = 0; i < 2; ++i) {
        printf("\nInforme uma sequencia de numeros naturais para o arquivo:  ");

        while ((ch = getchar()) != '\n') {
            putc(ch, arq);
        }

        putc('\n', arq);
    }
    printf("\nArquivo salvo!\n");
    fclose(arq);
}

void ler(FILE *arq) {
    arq = fopen("arquivoC.txt", "r");
    int ch;
    printf("\nConteudo do arquivo:\n");
    while ((ch = getc(arq)) != EOF) {
        putchar(ch); // Imprime no console
    }
    fclose(arq);
}

int main() {
    FILE *arq;
    ler_escrever_printar(arq);
    ler(arq);
    system("pause");
}

