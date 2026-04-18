// https://leetcode.com/problems/merge-two-sorted-lists/

typedef struct ListNode ListNode;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL){
        return list2;
    }
    else if(list2 == NULL){
        return list1;
    }

    ListNode *percorre1, *percorre2, *dummy, *merge;
    dummy = (ListNode*)malloc(sizeof(ListNode));
    merge = dummy;
    percorre1 = list1;
    percorre2 = list2;

    while(1){
        if(percorre1 == NULL){
            merge->next = percorre2;
            break;
        }
        if(percorre2 == NULL){
            merge->next = percorre1;
            break;
        }
        if(percorre1->val <= percorre2->val){
            merge->next = percorre1;
            merge = merge->next;
            percorre1 = percorre1->next;
        }
        else{
            merge->next = percorre2;
            merge = merge->next;
            percorre2 = percorre2->next;
        }
    }

    return dummy->next;
    
}