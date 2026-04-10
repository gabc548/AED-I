// https://leetcode.com/problems/remove-linked-list-elements/

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;
struct ListNode* removeElements(struct ListNode* head, int val) {

    ListNode *ptrBack, *ptrFront;

    if(head == NULL){
        return head;
    }

    ptrBack = head;
    ptrFront = head->next;

    while(ptrFront != NULL){
        if(ptrFront->val == val){
            ptrBack->next = ptrFront->next;
            free(ptrFront);
            ptrFront = ptrBack->next;
        }
        else{
            ptrFront = ptrFront->next;
            ptrBack = ptrBack->next;
        }
    }

    if(head->val == val){
        ptrBack = head;
        head = head->next;
        free(ptrBack);
    }

    return head;

}