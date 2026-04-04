/** Descrição:
    1. Crie um programa que:
    (a) Aloque dinamicamente um array de 5 números inteiros,
    (b) Peça para o usuário digitar os 5 números no espaço alocado,
    (c) Mostre na tela os 5 números,
    (d) Libere a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vector;
    vector = (int *)malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++){
        printf("Digite o numero na posicao %d: ", i);
        scanf("%d", &vector[i]);
    }

    printf("\n");

    for(int i = 0; i < 5; i++){
        printf("%d ", vector[i]);
    }

    free(vector);

    return 0;

}