#include <stdio.h>
#include <stdlib.h>

void Lista ( void *pBuffer, int *sizeOfBuffer, int *count );
void* Adiciona ( void *pBuffer, int *sizeOfBuffer, char *currentChar, int *sizeOfSearch, int *flag );
void* Busca ( void *pBuffer, int *sizeOfBuffer, int* count, char *currentChar, int *sizeOfSearch, int *indexInicialRemove, int *flag, int* compareWordIndex );
void* Remove ( void *pBuffer, int *sizeOfBuffer, int* count, char *currentChar, int *sizeOfSearch, int *indexInicialRemove, int *flag, int* compareWordIndex );

int main ( ) {

    void *pBuffer;
    pBuffer = malloc ( 6 * sizeof ( int ) + sizeof ( char ) );

    if ( pBuffer == NULL ) {
        printf ( "ERRO NA ALOCACAO!" );
        exit ( 0 );
    }
    
    int *count, *sizeOfBuffer, *sizeOfSearch, *indexInicialRemove, *flag, *compareWordIndex;
    char *currentChar;

    sizeOfBuffer = &( ( int* ) pBuffer ) [0];
    count = &( ( int* ) pBuffer ) [1];
    sizeOfSearch = &( ( int* ) pBuffer )[2];
    indexInicialRemove = &( ( int* ) pBuffer )[3];
    flag = &( ( int* ) pBuffer )[4];
    compareWordIndex = &( ( int* ) pBuffer )[5];
    currentChar = &( ( char* ) pBuffer )[24];

    *sizeOfBuffer = 6 * sizeof ( int ) + sizeof ( char );
    *count = 0;
    *sizeOfSearch = 0;
    *indexInicialRemove = 0;
    *flag = 0;
    *compareWordIndex = 0;

    while( 1 ){
        printf ( "Escolha o que fazer: \n" );
        printf ( "1- Listar\n" );
        printf ( "2- Adicionar\n" );
        printf ( "3- Buscar\n" );
        printf ( "4- Remover\n" );
        printf ( "5- Sair\n" );
        scanf ( "%d", flag );
        getchar ( );

        switch ( *flag ) {
            case 1:
            Lista ( pBuffer, sizeOfBuffer, count );
            break;

            case 2:
            printf ( "\n" );
            *flag = 0; //Muda a flag pra 0
            pBuffer = Adiciona ( pBuffer, sizeOfBuffer, currentChar, sizeOfSearch, flag );
            sizeOfBuffer = &( ( int* ) pBuffer )[0]; //Redefine todos os ponteiros que apontam pro pBuffer na saída da função (necessário caso o pBuffer tenha sido mudado de local na memória)
            count = &( ( int* ) pBuffer )[1];
            sizeOfSearch = &( ( int* ) pBuffer )[2];
            *sizeOfSearch = 0;
            indexInicialRemove = &( ( int* ) pBuffer )[3];
            flag = &( ( int* ) pBuffer )[4];
            *flag = 0;
            compareWordIndex = &( ( int* ) pBuffer )[5];
            *compareWordIndex = 0;
            currentChar = &( ( char* ) pBuffer )[24];
            break;

            case 3:
            pBuffer = Busca ( pBuffer, sizeOfBuffer, count, currentChar, sizeOfSearch, indexInicialRemove, flag, compareWordIndex );
            sizeOfBuffer = &( ( int* ) pBuffer )[0];
            count = &( ( int* ) pBuffer )[1];
            *count = 0;
            sizeOfSearch = &( ( int* ) pBuffer )[2];
            *sizeOfSearch = 0;
            indexInicialRemove = &( ( int* ) pBuffer )[3];
            flag = &( ( int* ) pBuffer )[4];
            *flag = 0;
            compareWordIndex = &( ( int* ) pBuffer )[5];
            *compareWordIndex = 0;
            currentChar = &( ( char* ) pBuffer )[24];
            break;

            case 4:
            pBuffer = Remove ( pBuffer, sizeOfBuffer, count, currentChar, sizeOfSearch, indexInicialRemove, flag, compareWordIndex );
            sizeOfBuffer = &( ( int* ) pBuffer )[0];
            count = &( ( int* ) pBuffer )[1];
            *count = 0;
            sizeOfSearch = &( ( int* ) pBuffer )[2];
            *sizeOfSearch = 0;
            indexInicialRemove = &( ( int* ) pBuffer )[3];
            flag = &( ( int* ) pBuffer )[4];
            *flag = 0;
            compareWordIndex = &( ( int* ) pBuffer )[5];
            *compareWordIndex = 0;
            currentChar = &( ( char* ) pBuffer )[24];
            break;

            case 5:
            free ( pBuffer );
            return 0;

            default:
            printf ( "\nNao e uma opcao valida\n\n" );
            break;

        }
    }

    free ( pBuffer );

    return 0;
}





void Lista ( void *pBuffer, int *sizeOfBuffer, int *count ) {

    printf ( "\n\n" );

    for ( *count = 25; *count < *sizeOfBuffer; ( *count )++ ) { //Printa a partir do primeiro caractere

        if ( ( ( char* ) pBuffer )[*count] == ';') { //Se for um delimitador de ';' (final das informações de uma pessoa)
            printf ( "\n" );
        } else if ( ( ( char* ) pBuffer )[*count] == ',' ) { //Se for um delimitador de ',' (fina das informações do campo de uma pessoa)
            printf ( ", " );
        } else{
            printf ( "%c", ( ( char* ) pBuffer )[*count] );
        }
    }

    *count = 0;

    printf ( "\n\n" );

    return;
}




void* Adiciona ( void *pBuffer, int *sizeOfBuffer, char *currentChar, int *sizeOfSearch, int *flag ){

    printf( "Digite o nome: " );
    while( 1 ){

        *currentChar = getchar ( ); //Recebe um char pra cada letra digitada de uma só vez no terminal
        if( *currentChar == '\n' ){ //Se o char atual for um '\n'
            if ( *sizeOfSearch == 0 ) { //Se o único char lido for um '\n'
                printf( "O nome nao pode ser vazio\n\n" );
                continue;
            }
            break; //Sai do loop
        }

        void *tmp = realloc ( pBuffer, *sizeOfBuffer + 1 ); //Realoca um valor a mais pra cada caractere lido
        if( tmp != NULL ) {
            pBuffer = tmp;
        } else {
           printf ( "FALHA NA REALOCACAO!" );
        }

        sizeOfBuffer = &( ( int* ) pBuffer )[0]; //Redefine os ponteiros após o uso do realloc
        currentChar = &( ( char* ) pBuffer )[24];
        sizeOfSearch = &( ( int* ) pBuffer )[2];
        flag = &( ( int* ) pBuffer )[4];
        ( *sizeOfBuffer )++; //Aumenta o *sizeOfBuffer em 1
        ( ( char* ) pBuffer )[*sizeOfBuffer - 1] = *currentChar; //Coloca o char atual no final do pBuffer
        ( *sizeOfSearch )++; //Aumenta o tamanho do nome a ser buscado
    }

    if( *flag == 0 ){ //Se a flag não for 0 (veio da função Busca) pula os campos e-mail e idade

        void  *tmp = realloc ( pBuffer, *sizeOfBuffer + 1 );
        if( tmp != NULL ) {
            pBuffer = tmp;
        } else {
            printf( "FALHA NA REALOCACAO!" );
        }
        sizeOfBuffer = &( ( int* ) pBuffer )[0];
        sizeOfSearch = &( ( int* ) pBuffer )[2];
        flag = &( ( int* ) pBuffer )[4];
        currentChar = &( ( char* ) pBuffer )[24];
        ( *sizeOfBuffer )++;
        ( ( char* ) pBuffer )[*sizeOfBuffer - 1] = ','; //Adiciona uma vírgula no final do nome para delimitar nome e e-mail


        printf ( "Digite o e-mail: " );
        while( 1 ){

            *currentChar = getchar ( );
            if( *currentChar == '\n' ) {
                break;
            }

            void *tmp = realloc ( pBuffer, *sizeOfBuffer + 1 );
            if( tmp != NULL ) {
                pBuffer = tmp;
            } else {
            printf ( "FALHA NA REALOCACAO!" );
            }

            sizeOfBuffer = &( ( int* ) pBuffer )[0];
            sizeOfSearch = &( ( int* ) pBuffer )[2];
            flag = &( ( int* ) pBuffer )[4];
            currentChar = &( ( char* ) pBuffer )[24];
            ( *sizeOfBuffer )++;
            ( ( char* ) pBuffer )[*sizeOfBuffer - 1] = *currentChar;
        }

        tmp = realloc ( pBuffer, *sizeOfBuffer + 1 );
        if( tmp != NULL ){
            pBuffer = tmp;
        } else{
            printf( "FALHA NA REALOCACAO!" );
        }

        sizeOfBuffer = &( ( int* ) pBuffer )[0];
        sizeOfSearch = &( ( int* ) pBuffer )[2];
        flag = &( ( int* ) pBuffer )[4];
        currentChar = &( ( char* ) pBuffer )[24];
        ( *sizeOfBuffer )++;
        ( ( char* ) pBuffer )[*sizeOfBuffer - 1] = ','; //Adiciona uma vírgula no final do e-mail para delimitar e-mail e idade


        printf( "Digite a idade: " );
        while( 1 ){

            *currentChar = getchar ( );
            if ( *currentChar == '\n' ) {
                break;
            }

            void *tmp = realloc ( pBuffer, *sizeOfBuffer + 1 );
            if ( tmp != NULL ) {
                pBuffer = tmp;
            } else {
            printf ( "FALHA NA REALOCACAO!" );
            }

            sizeOfBuffer = &( ( int* ) pBuffer )[0];
            sizeOfSearch = &( ( int* ) pBuffer )[2];
            flag = &( ( int* ) pBuffer )[4];
            currentChar = &( ( char* ) pBuffer )[24];
            ( *sizeOfBuffer )++;
            ( ( char* ) pBuffer )[*sizeOfBuffer - 1] = *currentChar;
        }

        printf( "\n" );
    }

    void *tmp = realloc ( pBuffer, *sizeOfBuffer + 1 );
    if ( tmp != NULL ) {
        pBuffer = tmp;
    } else {
        printf ( "FALHA NA REALOCACAO!" );
    }

    sizeOfBuffer = &( ( int* ) pBuffer )[0];
    currentChar = &( ( char* ) pBuffer )[24];
    sizeOfSearch = &( ( int* ) pBuffer )[2];
    flag = &( ( int* ) pBuffer )[4];
    ( *sizeOfBuffer )++;
    ( ( char* ) pBuffer )[*sizeOfBuffer - 1] = ';'; //Adiciona um ponto e vírgula no final das informações de uma pessoa pra separar as pessoas e definir um delimitador pra busca e remoção
    ( *sizeOfSearch )++;

    return pBuffer;
}




void* Busca ( void *pBuffer, int *sizeOfBuffer, int* count, char *currentChar, int *sizeOfSearch, int *indexInicialRemove, int *flag, int *compareWordIndex ) {
    printf ( "\n" );
    if ( *flag != 2 ) { //Se não tiver vindo da função Remove
        *flag = 1; //Coloca a flag como 1
    }
    pBuffer = Adiciona ( pBuffer, sizeOfBuffer, currentChar, sizeOfSearch, flag ); //Adiciona o nome a ser buscado no final do pBuffer
    sizeOfBuffer = &( ( int* ) pBuffer )[0];
    count = &( ( int* ) pBuffer )[1];
    sizeOfSearch = &( ( int* ) pBuffer )[2];
    indexInicialRemove = &( ( int* ) pBuffer )[3];
    flag = &( ( int* ) pBuffer )[4];
    compareWordIndex = &( ( int* ) pBuffer )[5];
    currentChar = &( ( char* ) pBuffer )[24];
    *indexInicialRemove = 25;

    for ( *compareWordIndex = *sizeOfBuffer - *sizeOfSearch, *count = 25; *compareWordIndex < *sizeOfBuffer, *count < *compareWordIndex; ( *compareWordIndex )++, ( *count )++ ) {
        if ( ( ( char* ) pBuffer )[*count] == ( ( char* ) pBuffer )[*compareWordIndex] && ( ( char* ) pBuffer )[*count + 1] == ',' && ( ( char* ) pBuffer )[*compareWordIndex + 1] == ';' ) { //Se os nomes forem iguais e ambos estiverem nos seus delimitadores
            if ( *flag == 1 ) { //Se a flag for igual a 1
                printf ( "\n\n" );
                while ( ( ( char* ) pBuffer )[*indexInicialRemove] != ';' ) { //Recicla o ponteiro *indexInicialRemove para printar as informações da pessoa na tela
                    if ( ( ( char* ) pBuffer )[*indexInicialRemove] == ',' ){
                        printf ( ", " ) ;
                    } else {
                        printf ( "%c", ( ( char* ) pBuffer )[*indexInicialRemove] );
                    }
                    ( *indexInicialRemove )++;
                }
                printf ( "\n\n" );
            }
            break; //Sai do loop
        } else if ( ( ( char* ) pBuffer )[*count] != ( ( char* ) pBuffer)[*compareWordIndex] ) { //Se os caracteres forem diferentes
            *compareWordIndex = *sizeOfBuffer - *sizeOfSearch - 1; //Reseta o index da palavra a ser comparada
            while ( ( ( char* ) pBuffer )[*count] != ';' && *count != *compareWordIndex ) { //Enquanto o index da palavra com a qual se está comparando não chegar no final das informações da pessoa
                ( *count )++;
                *indexInicialRemove = *count + 1; //Index inicial da pessoa a ser removida segue o index da palavra
            }
            if ( *count == *compareWordIndex ) { //Se os ponteiros tiverem o mesmo valor
                break; //Sai do loop
            }
        }
    }

    if ( *count == *compareWordIndex ) { //Se os ponteiros tiverem o mesmo valor
        *indexInicialRemove = 0; //Index inicial da pessoa a ser removida (ou buscada no geral) é definida como 0, indicando que ela não existe na agenda
        printf ( "\n\nO usuario nao existe na agenda\n\n" );
    }
    
    void *tmp = realloc ( pBuffer, *sizeOfBuffer - *sizeOfSearch ); //Retira o campo auxiliar no final do pBuffer que continha o nome da pessoa a ser buscada
    if( tmp == NULL ) {
        printf("ERRO NA ALOCACAO");
    } else {
        pBuffer = tmp;
    }
    sizeOfBuffer = &( ( int* ) pBuffer )[0]; //Redefine os ponteiros após o uso do realloc
    sizeOfSearch = &( ( int* ) pBuffer )[2];
    indexInicialRemove = &( ( int* ) pBuffer )[3];
    *sizeOfBuffer = *sizeOfBuffer - *sizeOfSearch; //Diminui o valor do tamanho do buffer de acordo com o que foi tirado no realloc

    for( *indexInicialRemove; ( ( char* ) pBuffer ) [*indexInicialRemove + *sizeOfSearch] != ';' && *indexInicialRemove + *sizeOfSearch < *sizeOfBuffer - 1; ) { //Enquanto *indexInicialRemove e *sizeOfSearch não forem distantes o suficiente pra englobar o tamanho das informações da pessoa a ser removida
        ( *sizeOfSearch )++;
    }
    ( *sizeOfSearch )++; //Para incluir o delimitador

    printf( "\n" );

    return pBuffer;
}




void* Remove ( void* pBuffer, int *sizeOfBuffer, int *count, char *currentChar, int *sizeOfSearch, int *indexInicialRemove, int* flag, int* compareWordIndex ) {
    *flag = 2; //Define a flag como 2
    pBuffer = Busca ( pBuffer, sizeOfBuffer, count, currentChar, sizeOfSearch, indexInicialRemove, flag, compareWordIndex );
    sizeOfBuffer = &( ( int* ) pBuffer )[0]; //Redefine os ponteiros após a saida de uma função
    sizeOfSearch = &( ( int* ) pBuffer )[2];
    indexInicialRemove = &( ( int* ) pBuffer )[3];
    currentChar = &( ( char* ) pBuffer )[24];

    if ( *indexInicialRemove == 0 ) { //Se a pessoa não existe na agenda
        return pBuffer;
    }

    for ( *indexInicialRemove; *indexInicialRemove + *sizeOfSearch < *sizeOfBuffer; ( *indexInicialRemove )++ ) { //Enquanto *indexInicialRemove + *sizeOfSearch forem menores que *sizeOfBuffer
        ( ( char* ) pBuffer )[*indexInicialRemove] = ( ( char* ) pBuffer )[*indexInicialRemove + *sizeOfSearch]; //Puxa para trás todos os valores que estão *sizeOfSearch de distância de *indexInicialRemove e incrementa *indexInicialRemove em 1
    }
    
    pBuffer = realloc ( pBuffer, *sizeOfBuffer - *sizeOfSearch ); //Realoca de acordo com o excesso do tamanho das informações da pessoa que foi removida
    sizeOfBuffer = &( ( int* ) pBuffer )[0]; //Redefine os ponteiros após o uso do realloc
    sizeOfSearch = &( ( int* ) pBuffer )[2];
    *sizeOfBuffer = *sizeOfBuffer - *sizeOfSearch; //Diminui o tamanho do buffer de acordo com o que foi tirado no realloc

    return pBuffer;
}