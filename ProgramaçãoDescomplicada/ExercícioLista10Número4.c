#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    char *string;
    int sizeString;

    printf("Digite o tamanho da string: ");
    scanf("%d", &sizeString);
    getchar();

    string = (char*)malloc((sizeString + 1) * sizeof(char));

    printf("Digite o conteudo da string: ");
    fgets(string, sizeString, stdin);

    for(int i = 0; i < sizeString; i++){
        if(tolower(string[i]) == 'a' || tolower(string[i]) == 'e' || tolower(string[i]) == 'i' || tolower(string[i]) == 'o' || tolower(string[i]) == 'u'){
            continue;
        }
        else{
            printf("%c", string[i]);
        }
    }

    free(string);

    return 0;

}