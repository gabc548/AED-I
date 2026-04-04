/** Descrição:
    1. Crie um programa que:
    (a) Aloque dinamicamente um array de 5 n ´umeros inteiros,
    (b) Pec¸a para o usu ´ario digitar os 5 n ´umeros no espac¸o alocado,
    (c) Mostre na tela os 5 n ´umeros,
    (d) Libere a mem ´oria alocada.
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