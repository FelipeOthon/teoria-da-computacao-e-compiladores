#include <stdio.h>

int main() {
    char *q0 = "q0";
    char *q1 = "q1";
    char *atual = q0;
    char *final[] = {"q0"};
    char cod[] = "010";

    int i;
    for (i = 0; i < sizeof(cod) - 1; i++) {
        if (atual == q0) {
            if (cod[i] == '1') {
                atual = q0;
            } else if (cod[i] == '0') {
                atual = q1;
            }
        } else if (atual == q1) {
            if (cod[i] == '1') {
                atual = q1;
            } else if (cod[i] == '0') {
                atual = q0;
            }
        }
    }

    int found = 0;
    for (i = 0; i < sizeof(final) / sizeof(final[0]); i++) {
        if (atual == final[i]) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Aceita\n");
    } else {
        printf("NÃ£o aceita\n");
    }

    return 0;
}