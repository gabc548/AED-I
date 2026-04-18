// https://leetcode.com/problems/linked-list-cycle/

typedef struct ListNode ListNode;

bool hasCycle(struct ListNode *head) {

    if(head == NULL){
        return false;
    }

    ListNode *fast;
    fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        head = head->next;

        if(fast == head || fast == head->next){
            return true;
        }
    }

    return false;

}