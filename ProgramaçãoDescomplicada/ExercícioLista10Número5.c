#include <stdio.h>
#include <stdlib.h>

int main(){

    int *vector;
    int N, X, contador = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &N);

    vector = (int*)malloc(N * sizeof(int));

    for(int i = 0; i < N; i++){
        printf("Digite o numero na posicao %d: ", i);
        scanf("%d", &vector[i]);
    }

    printf("Digite o numero a ter seus multiplos buscados: ");
    scanf("%d", &X);

    for(int i = 0; i < N; i++){
        if(vector[i] <= 0){
            continue;
        }
        else if(vector[i] % X == 0){
            printf("%d ", vector[i]);
            contador++;
        }
    }

    printf("Quantidade de multiplos = %d", contador);

    free(vector);

    return 0;

}