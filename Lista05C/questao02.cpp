#include <stdio.h>

int main() {
    char cod[] = "ababa";
    char atual = 'q0';
    char final[] = {'q0', 'q1', 'q3'};
    int i;

    for (i = 0; i < sizeof(cod) - 1; i++) {
        if (atual == 'q0') {
            if (cod[i] == 'a') {
                atual = 'q1';
            } else if (cod[i] == 'b') {
                atual = 'q0';
            }
        } else if (atual == 'q1') {
            if (cod[i] == 'a') {
                atual = 'q2';
            } else if (cod[i] == 'b') {
                atual = 'q3';
            }
        } else if (atual == 'q3') {
            if (cod[i] == 'b') {
                atual = 'q3';
            } else if (cod[i] == 'a') {
                atual = 'q1';
            }
        } else if (atual == 'q2') {
            if (cod[i] == 'a') {
                atual = 'q2';
            } else if (cod[i] == 'b') {
                atual = 'q2';
            }
        }
    }

    int accepted = 0;
    for (i = 0; i < sizeof(final) / sizeof(final[0]); i++) {
        if (atual == final[i]) {
            accepted = 1;
            break;
        }
    }

    if (accepted) {
        printf("Aceita\n");
    } else {
        printf("NÃ£o aceita\n");
    }

    return 0;
}