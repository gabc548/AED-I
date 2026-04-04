#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val); // This function is the solution to the problem

int main(){
    int nums[5] = {0, 1, 2, 2, 3};
    int numsSize = 5;
    int val = 1, Output;

    Output = removeElement(nums, numsSize, val);

    for(int i = 0; i < Output; i++){
        printf("%d ", nums[i]);
    }

    return 0;

}

int removeElement(int* nums, int numsSize, int val) {
    int count = 0;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] != val){
            nums[count] = nums[i];
            count++;
        }
    }

    return count;
}