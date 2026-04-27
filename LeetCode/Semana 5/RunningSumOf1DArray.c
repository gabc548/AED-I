// https://leetcode.com/problems/running-sum-of-1d-array/description/

int* runningSum(int* nums, int numsSize, int* returnSize) {
    int currentSum = 0;
    int *arrayReturn;
    *returnSize = numsSize;
    arrayReturn = ( int* )malloc( *returnSize * sizeof( int ) );

    for(int i = 0; i < numsSize; i++){
        currentSum = nums[i] + currentSum;
        arrayReturn[i] = currentSum;
    }

    return arrayReturn;
}