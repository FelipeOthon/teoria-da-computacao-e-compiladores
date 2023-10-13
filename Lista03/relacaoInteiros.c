#include <stdio.h>
void relacao_nao_recusiva (int limite){
    for (int i = 0; i <= limite; ++i) {
        if(i%2==0)
            printf("[%d, %d]", i, (-1)*(i/2));
        else
            printf("[%d, %d]", i, (i/2)+1);
    }
}

void relacao_recursiva(int limite){

    if (limite < 0){
        return;
    }

    relacao_recursiva(limite-1);

    if(limite%2==0)
        printf("[%d, %d]", limite, (-1)*(limite/2));
    else
        printf("[%d, %d]", limite, (limite/2)+1);

}

int main() {
    relacao_nao_recusiva(5);
    printf("\n");
    relacao_recursiva(5);
}