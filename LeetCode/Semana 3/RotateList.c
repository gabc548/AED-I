// https://leetcode.com/problems/rotate-list/

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

int contaTamanho(struct ListNode* head){

    ListNode *percorre;
    int cont = 0;
    
    percorre = head;

    while(percorre != NULL){
        percorre = percorre->next;
        cont++;
    }

    return cont;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {

    ListNode *ptrFront, *ptrBack;
    int cont;

    cont = contaTamanho(head);

    if(head == NULL){
        return head;
    }
    else if(head->next == NULL){
        return head;
    }

    k = k % cont;

    ptrFront = head->next;
    ptrBack = head;

    for(int i = 0; i < k; i++){

        while(ptrFront->next != NULL){
            ptrFront = ptrFront->next;
            ptrBack = ptrBack->next;
        }

        ptrFront->next = head;
        ptrBack->next = NULL;
        head = ptrFront;
        ptrFront = head->next;
        ptrBack = head;
    }

    return head;

}