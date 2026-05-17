#include <stdio.h>
#include <stdlib.h>

/*
    
    A função main foi adicionada em casa
    
*/

struct ListNode {
    int val;
    struct ListNode *next;
};


int PopInd ( int *stackIndexes, int *topo );
int* nextLargerNodes ( struct ListNode* head, int* returnSize );



int main ( ) {
    int a = 10, b = 5, c = 20;

    struct ListNode *head;

    head = ( struct ListNode* ) malloc ( sizeof( struct ListNode ) );
    head->val = a;
    head->next = ( struct ListNode* ) malloc ( sizeof ( struct ListNode ) );
    head->next->val = b;
    head->next->next = ( struct ListNode* ) malloc ( sizeof ( struct ListNode ) );
    head->next->next->val = c;
    head->next->next->next = NULL;



    int *returnArray, returnSize;
    returnArray = nextLargerNodes ( head, &returnSize );

    int resultArray[3] = {20, 20, 0};



    for ( int i = 0; i < returnSize; i++ ) {
        if ( returnArray[i] != resultArray[i] ) {
            printf ( "Errado" );
            return 0;
        }
    }

    printf ( "Certo" );

    struct ListNode *aux;
    aux = head;

    while ( head != NULL ) {
        aux = head;
        head = head->next;
        free ( aux );
    }

    free ( returnArray ) ;

    return 0;
}



int PopInd ( int *stackIndexes, int *topo ) {
    int index = stackIndexes[*topo - 1];
    return index;
}

int* nextLargerNodes ( struct ListNode* head, int* returnSize ) {
    struct ListNode *ptrListAux;
    ptrListAux = head;
    int listSize = 0;
    for ( ; ptrListAux != NULL; ptrListAux = ptrListAux->next, listSize++ );

    int *returnArray, *stackValues, *stackIndexes, topo = 0;
    returnArray = ( int* ) calloc ( listSize, sizeof ( int ) );
    *returnSize = listSize;
    stackValues = ( int* ) malloc ( listSize * sizeof ( int ) );
    stackIndexes = ( int* ) malloc ( listSize * sizeof ( int ) );

    ptrListAux = head;

    for ( int i = 0; ptrListAux != NULL; ptrListAux = ptrListAux->next, i++ ) {

        if ( topo != 0 ) {

            if ( ptrListAux->val > stackValues[topo - 1] ) {

                while ( topo - 1 >= 0 && ptrListAux->val > stackValues[topo - 1] ) { //Peek()
                    int index = PopInd ( stackIndexes, &topo ) ;
                    returnArray[index] = ptrListAux->val;
                    topo--; //Já é um Pop() pra stackValues
                }

            }

        }

        stackValues[topo] = ptrListAux->val;
        stackIndexes[topo] = i;
        topo++;

    }

    for ( int i = 0; i < topo; i++ ) {
        returnArray[stackIndexes[i]] = 0;
    }

    free ( stackValues );
    free ( stackIndexes );

    return returnArray;
}