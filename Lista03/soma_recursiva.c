#include <stdio.h>

// Função sucessor
int sucessor(int n) {
    return n + 1;
}


int soma(int m, int n) {

    if (n == 0) {
        return m;
    }

    return soma(sucessor(m), n - 1);
}

int main() {
    int resultado = soma(3, 2);
    printf("3 + 2 = %d\n", resultado);

    return 0;
}