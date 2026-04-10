// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    ListNode *ptrFront = head, *ptrBack = head, *remove_aux = head;
    
    for(int i = 0; i < n; i++){
        ptrFront = ptrFront->next;
    }

    while(ptrFront != NULL){
        remove_aux = ptrBack;
        ptrFront = ptrFront->next;
        ptrBack = ptrBack->next;
    }

    if(head == ptrBack){
        head = head->next;
        free(ptrBack);
        return head;
    }

    if(ptrBack->next != NULL){
        remove_aux->next = ptrBack->next;
        free(ptrBack);
    }
    else{
        remove_aux->next = NULL;
        free(ptrBack);
    }

    return head;
}