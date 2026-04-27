// https://leetcode.com/problems/richest-customer-wealth/description/

int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
    int maxAmount = 0, currentAmount = 0;
    int *ptrMax = &maxAmount, *ptrCurrent = &currentAmount;

    for(int i = 0; i < accountsSize; i++){
        for(int j = 0; j < *accountsColSize; j++){
            *ptrCurrent = accounts[i][j] + *ptrCurrent;
        }
        if(currentAmount > maxAmount){
            *ptrMax = *ptrCurrent;
        }
        *ptrCurrent = 0;
    }

    return maxAmount;
}