#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vector;
    int sizeVector, even = 0, odd = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &sizeVector);

    vector = (int*)malloc(sizeVector * sizeof(int));

    for(int i = 0; i < sizeVector; i++){
        printf("Digite o valor na posicao %d: ", i);
        scanf("%d", &vector[i]);

        if(vector[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }

    printf("Quantidade de numeros pares: %d. Quantidade de numeros impares: %d.", even, odd);

    free(vector);

    return 0;
}