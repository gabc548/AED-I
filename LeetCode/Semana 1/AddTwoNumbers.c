#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode; // Included in the solution to the problem

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2); // This function is the solution to the problem
void FreeList(struct ListNode* LFree);

int main(){
    ListNode *l1, *l2, *auxl1, *auxl2, *header1, *header2;
    auxl1 = (ListNode *)malloc(sizeof(ListNode));
    auxl2 = (ListNode *)malloc(sizeof(ListNode));
    auxl1->next = NULL;
    auxl2->next = NULL;

    for(int i = 0; i < 3; i++){
        l1 = (ListNode *)malloc(sizeof(ListNode));
        if(header1 == NULL){
            header1 = auxl1;
        }
        l1->val = i;
        auxl1->next = l1;
        l1->next = NULL;
        auxl1 = l1;
    }

    for(int i = 3; i < 6; i++){
        l2 = (ListNode *)malloc(sizeof(ListNode));
        if(header2 == NULL){
            header2 = auxl2;
        }
        l2->val = i;
        auxl2->next = l2;
        l2->next = NULL;
        auxl2 = l2;
    }

    ListNode *Output = addTwoNumbers(header1->next, header2->next);

    auxl1 = Output;

    while(auxl1 != NULL){
        printf("%d ", auxl1->val);
        auxl1 = auxl1->next;
    }

    FreeList(Output);
    FreeList(header1);
    FreeList(header2);

    return 0;

}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNode *ptr, *header, *Retorno;
    int m, n, carry = 0;
    header = NULL;

    while(l1 != NULL || l2 != NULL){

        if(l1 != NULL){
            m = l1->val;
            l1 = l1->next;
        }
        else{
            m = 0;
        }
        if(l2 != NULL){
            n = l2->val;
            l2 = l2->next;
        }
        else{
            n = 0;
        }

        ptr = (ListNode*)malloc(sizeof(ListNode));
        if(ptr == NULL){
            printf("Erro!");
        }

        if(m + n + carry >= 10){

            ptr->val = m + n + carry - 10;
            carry = 1;

        }

        else{
            
            ptr->val = m + n + carry;
            carry = 0;

        }

        ptr->next = NULL;
        if(header == NULL){
            header = ptr;
            Retorno = ptr;
        }
        else{
            header->next = ptr;
            header = header->next;
        }

    }

    if(carry == 1){
        ListNode *carry1;
        carry1 = (ListNode*)malloc(sizeof(ListNode));
        carry1->next = NULL;
        carry1->val = 1;
        ptr->next = carry1;
    }

    return Retorno;

}

void FreeList(struct ListNode* Lfree){
    ListNode *temp;

    while(Lfree != NULL){
        temp = Lfree;
        Lfree = Lfree->next;
        free(temp);
    }

    return;

}