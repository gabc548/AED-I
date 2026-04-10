// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// This one is made in a generalist manner, in a way that it should work even with a non-sorted list (hopefully)

#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode ListNode;

struct ListNode* reposiciona(int valor, struct ListNode* atual){

    while(atual != NULL){
        if(atual->val == valor){
            atual = atual->next;
        }
        else{
            break;
        }
    }
    
    return atual;

}

void removeValor(int valor, struct ListNode* dummy){
    ListNode *remove;
    remove = dummy;

    while(remove->next != NULL){
        if(remove->next->val == valor){
            remove->next = remove->next->next;
        }
        else{
            remove = remove->next;
        }
    }

    return;

}

struct ListNode* deleteDuplicates(struct ListNode* head) {

    ListNode *atual, *percorre, *dummy;
    int valor;

    dummy = (ListNode*)malloc(sizeof(ListNode));
    dummy->next = head;

    percorre = dummy;
    atual = dummy->next;

    while(atual != NULL){
        if(percorre->next == atual){
            percorre = dummy;
            atual = atual->next;
        }
        else if(percorre->next->val == atual->val){
            valor = atual->val;
            atual = reposiciona(valor, atual);
            removeValor(valor, dummy);
            percorre = dummy;
        }
        else{
            percorre = percorre->next;
        }

    }

    return dummy->next;

}