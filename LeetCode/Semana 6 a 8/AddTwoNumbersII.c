// https://leetcode.com/problems/add-two-numbers-ii/description/

typedef struct ListNode ListNode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int l1Size = 0, l2Size = 0, l1Stack[100], l2Stack[100], carry = 0, soma;
    ListNode *ptrAux, *head;

    while(l1 != NULL || l2 != NULL){
        if(l1 != NULL){
            l1Stack[l1Size] = l1->val;
            ptrAux = l1;
            l1 = l1->next;
            free(ptrAux);
            l1Size++;
        }
        if(l2 != NULL){
            l2Stack[l2Size] = l2->val;
            ptrAux = l2;
            l2 = l2->next;
            free(ptrAux);
            l2Size++;
        }
    }

    ptrAux = NULL;

    for(int i = l1Size - 1, j = l2Size - 1; i >= 0 || j >= 0 || carry == 1; i--, j--){
        if(i >= 0 && j >= 0){
            soma = (l1Stack[i] + l2Stack[j] + carry) % 10;
            carry = (l1Stack[i] + l2Stack[j] + carry) / 10;
        } else if(i >= 0){
            soma = (l1Stack[i] + carry) % 10;
            carry = (l1Stack[i] + carry) / 10;
        } else if(j >= 0){
            soma = (l2Stack[j] + carry) % 10;
            carry = (l2Stack[j] + carry) / 10;
        } else{
            soma = carry;
            carry = 0;
        }

        head = (ListNode*)malloc(sizeof(ListNode));
        head->val = soma;
        head->next = ptrAux;
        ptrAux = head;
    }

    return head;
}