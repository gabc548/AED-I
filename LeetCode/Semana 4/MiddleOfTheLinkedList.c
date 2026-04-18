// https://leetcode.com/problems/middle-of-the-linked-list/

typedef struct ListNode ListNode;

struct ListNode* middleNode(struct ListNode* head) {
    ListNode *ptr = head;
    int listSize = 0;

    while(ptr->next != NULL){
        listSize++;
        ptr = ptr->next;
    }

    ptr = head;

    for(int i = 0; i < ceil(listSize) / 2; i++){
        ptr = ptr->next;
    }

    return ptr;

}