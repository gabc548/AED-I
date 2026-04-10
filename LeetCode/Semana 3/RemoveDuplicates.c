// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* deleteDuplicates(struct ListNode* head) {

    ListNode *percorre, *atual, *dummy, *libera;
    dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;

    percorre = dummy;
    atual = dummy->next;

    while(atual != NULL){
        if(percorre->next == atual || percorre == atual){
            percorre = dummy;
            atual = atual->next;
        }
        else if(percorre->next->val == atual->val){
            libera = percorre->next;
            percorre->next = percorre->next->next;
            free(libera);
        }
        else{
            percorre = percorre->next;
        }
    }

    return dummy->next;
}