#include <stdio.h> //FILE, fopen (), getchar (), putc (),
//fclose ().
#include <stdlib.h> //system ().
#include <math.h>

void ler_escrever_printar(FILE *arq) {

    int ch;

    arq = fopen("arquivoC.txt", "a");

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

void read_to_vector(FILE *arq, int vet[2]) {
    arq = fopen("arquivoC.txt", "r");

    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    for (int i = 0; i < 2; ++i) {
        if (fscanf(arq, "%d", &vet[i]) != 1) {
            printf("\nErro ao ler o arquivo.");
            fclose(arq);
            return;
        }
    }

    fclose(arq);
}

void exibirVetor(int vet[], int tamanho) {
    printf("Elementos do vetor:\n");
    for(int i = 0; i < tamanho; i++) {
        printf("%d, ", vet[i]);
    }
    printf("\b\b  \n"); // Apaga a vírgula extra e imprime uma nova linha
}

void dividir_em_digitos(int numero, int vetor[], int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        vetor[i] = numero % 10;
        numero /= 10;
    }
}

void dividir_vetor(int vetor[2], int **conj1, int **conj2, int *tamanho1, int *tamanho2) {
    *tamanho1 = snprintf(NULL, 0, "%d", vetor[0]);
    *tamanho2 = snprintf(NULL, 0, "%d", vetor[1]);

    *conj1 = (int*)malloc(*tamanho1 * sizeof(int));
    *conj2 = (int*)malloc(*tamanho2 * sizeof(int));

    dividir_em_digitos(vetor[0], *conj1, *tamanho1);
    dividir_em_digitos(vetor[1], *conj2, *tamanho2);
}

void gerar_conjunto_potencia(int conjunto[], int tamanho, FILE *arq) {

    arq = fopen("arquivoC.txt", "a"); // Abre o arquivo em modo "append"

    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    int total_conjuntos = pow(2, tamanho);
    printf("Conjunto Potencia\n");
    fprintf(arq, "Conjunto Potencia\n");
    for (int i = 0; i < total_conjuntos; i++) {
        printf("{");
        fprintf(arq, "{");
        //ESTUDAR!!
        for (int j = 0; j < tamanho; j++) {
            if ((i >> j) & 1) {
                printf("%d ", conjunto[j]);
                fprintf(arq, "%d ", conjunto[j]);
            }
        }
        fprintf(arq, "}\n");
        printf("}\n");
    }

    fclose(arq);
}

void gerar_conjunto_potencia_proper(int conjunto[], int tamanho, FILE *arq) {

    arq = fopen("arquivoC.txt", "a"); // Abre o arquivo em modo "append"

    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    int total_conjuntos = pow(2, tamanho);
    printf("Conjuntos proprios dos conjuntos potencia\n");
    fprintf(arq, "Conjuntos proprios dos conjuntos potencia\n");
    for (int i = 1; i < total_conjuntos - 1; i++) {
        printf("{");
        fprintf(arq, "{");
        for (int j = 0; j < tamanho; j++) {
            if (i & (1 << j)) {
                printf("%d ", conjunto[j]);
                fprintf(arq, "%d ", conjunto[j]);
            }
        }
        fprintf(arq, "}\n");
        printf("}\n");
    }

    fclose(arq);

}
void uniao_de_conjuntos(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, FILE *arq) {
    arq = fopen("arquivoC.txt", "a"); // Abre o arquivo em modo "append"
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    int conjunto_uniao[tamanho1 + tamanho2]; // Tamanho máximo da uniao
    int k = 0; // Próxima posicao vazia na uniao

    // Copiar elementos de A para a uniao
    for (int i = 0; i < tamanho1; i++) {
        conjunto_uniao[k++] = conjunto1[i];
    }

    // Adicionar elementos de B à uniao, evitando duplicatas
    for (int i = 0; i < tamanho2; i++) {
        int duplicata = 0;
        for (int j = 0; j < tamanho1; j++) {
            if (conjunto2[i] == conjunto1[j]) {
                duplicata = 1;
                break;
            }
        }
        if (!duplicata) {
            conjunto_uniao[k++] = conjunto2[i];
        }
    }

    // Exibir a uniao na tela
    printf("Uniao de A e B: {");
    for (int i = 0; i < k; i++) {
        printf("%d", conjunto_uniao[i]);
        if (i < k - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Armazenar a uniao no arquivo
    fprintf(arq, "Uniao de A e B: {");
    for (int i = 0; i < k; i++) {
        fprintf(arq, "%d", conjunto_uniao[i]);
        if (i < k - 1) {
            fprintf(arq, ", ");
        }
    }
    fprintf(arq, "}\n");
}
void intersecao_de_conjuntos(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, FILE *arq) {
    arq = fopen("arquivoC.txt", "a"); // Abre o arquivo em modo "append"
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    int tamanho_intersecao = tamanho1 < tamanho2 ? tamanho1 : tamanho2; // Tamanho máximo da intersecao
    int conjunto_intersecao[tamanho_intersecao];
    int k = 0; // Próxima posicao vazia na intersecao

    // Verificar elementos que estao presentes em ambos os conjuntos
    for (int i = 0; i < tamanho1; i++) {
        for (int j = 0; j < tamanho2; j++) {
            if (conjunto1[i] == conjunto2[j]) {
                conjunto_intersecao[k++] = conjunto1[i];
                break;
            }
        }
    }
        // Exibir a intersecao na tela
    printf("Intersecao de A e B: {");
    for (int i = 0; i < k; i++) {
        printf("%d", conjunto_intersecao[i]);
        if (i < k - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Armazenar a intersecao no arquivo
    fprintf(arq, "Intersecao de A e B: {");
    for (int i = 0; i < k; i++) {
        fprintf(arq, "%d", conjunto_intersecao[i]);
        if (i < k - 1) {
            fprintf(arq, ", ");
        }
    }
    fprintf(arq, "}\n");
}
void diferenca_de_conjuntos(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, FILE *arq) {
    arq = fopen("arquivoC.txt", "a"); // Abre o arquivo em modo "append"
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    int conjunto_diferenca[tamanho1]; // Tamanho máximo da diferenca
    int k = 0; // Próxima posicao vazia na diferenca

    // Verificar elementos que estao em A, mas nao em B
    for (int i = 0; i < tamanho1; i++) {
        int pertence_a_B = 0;
        for (int j = 0; j < tamanho2; j++) {
            if (conjunto1[i] == conjunto2[j]) {
                pertence_a_B = 1;
                break;
            }
        }
        if (!pertence_a_B) {
            conjunto_diferenca[k++] = conjunto1[i];
        }
    }

    // Exibir a diferenca na tela
    printf("Diferenca de A - B: {");
    for (int i = 0; i < k; i++) {
        printf("%d", conjunto_diferenca[i]);
        if (i < k - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Armazenar a diferenca no arquivo
    fprintf(arq, "Diferenca de A - B: {");
    for (int i = 0; i < k; i++) {
        fprintf(arq, "%d", conjunto_diferenca[i]);
        if (i < k - 1) {
            fprintf(arq, ", ");
        }
    }
    fprintf(arq, "}\n");
}
void diferenca_entre_conjuntos(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, FILE *arq) {
    arq = fopen("arquivoC.txt", "a"); // Abre o arquivo em modo "append"
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    int conjunto_diferenca[tamanho2]; // Tamanho máximo da diferenca
    int k = 0; // Próxima posicao vazia na diferenca

    // Verificar elementos que estao em B, mas nao em A
    for (int i = 0; i < tamanho2; i++) {
        int pertence_a_A = 0;
        for (int j = 0; j < tamanho1; j++) {
            if (conjunto2[i] == conjunto1[j]) {
                pertence_a_A = 1;
                break;
            }
        }
        if (!pertence_a_A) {
            conjunto_diferenca[k++] = conjunto2[i];
        }
    }

    // Exibir a diferenca na tela
    printf("Diferenca de B - A: {");
    for (int i = 0; i < k; i++) {
        printf("%d", conjunto_diferenca[i]);
        if (i < k - 1) {
            printf(", ");
        }
    }
    printf("}\n");

    // Armazenar a diferenca no arquivo
    fprintf(arq, "Diferenca de B - A: {");
    for (int i = 0; i < k; i++) {
        fprintf(arq, "%d", conjunto_diferenca[i]);
        if (i < k - 1) {
            fprintf(arq, ", ");
        }
    }
    fprintf(arq, "}\n");
}
void produto_cartesiano(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, FILE *arq) {
    arq = fopen("arquivoC.txt", "a"); // Abre o arquivo em modo "append"
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    // Exibir o produto cartesiano na tela
    printf("Produto Cartesiano de A e B:\n");
    fprintf(arq, "Produto Cartesiano de A e B:\n");

    for (int i = 0; i < tamanho1; i++) {
        for (int j = 0; j < tamanho2; j++) {
            printf("(%d, %d)\n", conjunto1[i], conjunto2[j]);
            fprintf(arq, "(%d, %d)\n", conjunto1[i], conjunto2[j]);
        }
    }
}
void produto_cartesiano_B_A(int conjunto1[], int tamanho1, int conjunto2[], int tamanho2, FILE *arq) {
    arq = fopen("arquivoC.txt", "a"); // Abre o arquivo em modo "append"
    if (arq == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return;
    }

    // Exibir o produto cartesiano B x A na tela
    printf("Produto Cartesiano de B e A:\n");
    fprintf(arq, "Produto Cartesiano de B e A:\n");

    for (int i = 0; i < tamanho2; i++) {
        for (int j = 0; j < tamanho1; j++) {
            printf("(%d, %d)\n", conjunto2[i], conjunto1[j]);
            fprintf(arq, "(%d, %d)\n", conjunto2[i], conjunto1[j]);
        }
    }
}
int main() {
    FILE *arq;
    ler_escrever_printar(arq);
    ler(arq);

    int vet [2];

    read_to_vector(arq, vet);
    exibirVetor(vet, 2);

    int *conj1;
    int *conj2;

    int tamanho_conj1, tamanho_conj2;
    dividir_vetor(vet, &conj1, &conj2, &tamanho_conj1, &tamanho_conj2);

    exibirVetor(conj1, tamanho_conj1);
    exibirVetor(conj2, tamanho_conj2);

    gerar_conjunto_potencia(conj1, tamanho_conj1, arq);
    gerar_conjunto_potencia(conj2, tamanho_conj2, arq);

    gerar_conjunto_potencia_proper(conj1, tamanho_conj1, arq);
    gerar_conjunto_potencia_proper(conj2, tamanho_conj2, arq);

    uniao_de_conjuntos(conj1, tamanho_conj1,conj2, tamanho_conj2, arq);

    intersecao_de_conjuntos (conj1, tamanho_conj1,conj2, tamanho_conj2, arq);

    diferenca_de_conjuntos (conj1, tamanho_conj1,conj2, tamanho_conj2, arq);

    diferenca_entre_conjuntos (conj1, tamanho_conj1,conj2, tamanho_conj2, arq);

    produto_cartesiano (conj1, tamanho_conj1,conj2, tamanho_conj2, arq);

    produto_cartesiano_B_A (conj1, tamanho_conj1,conj2, tamanho_conj2, arq);

    system("pause");
}