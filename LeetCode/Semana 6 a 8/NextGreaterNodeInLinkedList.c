// https://leetcode.com/problems/next-greater-node-in-linked-list/description/

int PopInd(int *stackIndexes, int *topo){
    int index = stackIndexes[*topo - 1];
    return index;
}

int* nextLargerNodes(struct ListNode* head, int* returnSize) {
    struct ListNode *ptrListAux;
    ptrListAux = head;
    int listSize = 0;
    for(; ptrListAux != NULL; ptrListAux = ptrListAux->next, listSize++);

    int *returnArray, *stackValues, *stackIndexes, topo = 0;
    returnArray = (int*)malloc(listSize * sizeof(int));
    *returnSize = listSize;
    stackValues = (int*)malloc(listSize * sizeof(int));
    stackIndexes = (int*)malloc(listSize * sizeof(int));

    ptrListAux = head;

    for(int i = 0; ptrListAux != NULL; ptrListAux = ptrListAux->next, i++){
        if(topo != 0){
            if(ptrListAux->val > stackValues[topo - 1]){
                while(topo - 1 >= 0 && ptrListAux->val > stackValues[topo - 1]){ //Peek()
                    int index = PopInd(stackIndexes, &topo);
                    returnArray[index] = ptrListAux->val;
                    topo--; //Já é um Pop() pra stackValues
                }
            }
        }

        stackValues[topo] = ptrListAux->val;
        stackIndexes[topo] = i;
        topo++;

    }

    for(int i = 0; i < topo; i++){
        returnArray[stackIndexes[i]] = 0;
    }

    return returnArray;
}