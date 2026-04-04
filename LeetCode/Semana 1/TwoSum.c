#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize); // This function is the solution to the problem

int main(){
    int nums[5] = {2, 7, 0, 11, 20};
    int numsSize = 5, Size_return = 0, target = 2;
    int *returnSize = &Size_return;

    int *Output = twoSum(nums, numsSize, target, returnSize);

    for(int i = 0; i < Size_return; i++){
        printf("%d ", Output[i]);
    }

    free(Output);

    return 0;

}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *Output = (int *)(malloc(2 * sizeof(int)));

    *returnSize = 2;

    for(int i = 0; i < numsSize - 1; i++){

        for(int j = i + 1; j < numsSize; j++){

            if(nums[j] == target - nums[i]){
                Output[0] = i;
                Output[1] = j;
                return Output;
            }

        }

    }

    return Output;

}