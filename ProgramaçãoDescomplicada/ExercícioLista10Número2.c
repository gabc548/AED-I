#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vector;
    int vectorSize;

    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &vectorSize);

    vector = (int *)malloc(vectorSize * sizeof(int));

    for(int i = 0; i < vectorSize; i++){
        printf("Digite o numero na posicao %d: ", i);
        scanf("%d", &vector[i]);
    }

    printf("\n");

    for(int i = 0; i < vectorSize; i++){
        printf("%d ", vector[i]);
    }

    free(vector);

    return 0;

}