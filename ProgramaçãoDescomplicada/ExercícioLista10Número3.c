/** Descrição:
    3. Faça um programa que leia do usuário o tamanho de um vetor a ser lido e faça a alocação
    dinâmica de memória. Em seguida, leia do usuário seus valores e mostre quantos dos
    números são pares e quantos são ímpares.
 */

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