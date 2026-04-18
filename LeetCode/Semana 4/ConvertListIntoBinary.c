// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

typedef struct ListNode ListNode;

int getDecimalValue(struct ListNode* head) {
    ListNode *ptr = head;
    int decimal = 0;

    while(ptr != NULL){
        decimal = 2 * decimal + ptr->val;
        ptr = ptr->next;
    }

    return decimal;

}