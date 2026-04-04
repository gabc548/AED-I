#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target); // This function is the solution to the problem

int main(){
    int nums[5] = {0, 1, 2, 5, 8};
    int numsSize = 5, target = 7, Output;

    Output = searchInsert(nums, numsSize, target);

    printf("%d", Output);

    return 0;

}

int searchInsert(int* nums, int numsSize, int target) {
    for(int i = 0; i < numsSize; i++){
        if(target <= nums[i]){
            return i;
        }
    }

    return numsSize;

}