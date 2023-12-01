#include <stdio.h>

int main() {
    char *q0 = "q0";
    char *q1 = "q1";
    char *q2 = "q2";
    char *q3 = "q3";
    char *q4 = "q4";
    char *q5 = "q5";

    char *atual = q0;
    char *final[] = {q1, q3};
    char cod[] = "bba";

    int i;
    for (i = 0; i < sizeof(cod) - 1; i++) {
        if (atual == q0) {
            if (cod[i] == 'a') {
                atual = q1;
            } else if (cod[i] == 'b') {
                atual = q2;
            }
        } else if (atual == q1) {
            if (cod[i] == 'a' || cod[i] == 'b') {
                atual = q1;
            }
        } else if (atual == q2) {
            if (cod[i] == 'a') {
                atual = q3;
            } else if (cod[i] == 'b') {
                atual = q4;
            }
        } else if (atual == q3) {
            if (cod[i] == 'a') {
                atual = q1;
            } else if (cod[i] == 'b') {
                atual = q3;
            }
        } else if (atual == q4) {
            if (cod[i] == 'a') {
                atual = q3;
            } else if (cod[i] == 'b') {
                atual = q5;
            }
        } else if (atual == q5) {
            if (cod[i] == 'b') {
                atual = q5;
            } else if (cod[i] == 'a') {
                atual = q5;
            }
        }
    }

    bool found = 0;
    for (i = 0; i < sizeof(final) / sizeof(final[0]); i++) {
        if (atual == final[i]) {
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Str Aceita\n");
    } else {
        printf("Str nÃ£o aceita\n");
    }

    return 0;
}