// https://leetcode.com/problems/first-missing-positive/

int firstMissingPositive(int* nums, int numsSize) {
    int *arrayaux = (int*)calloc(numsSize, sizeof(int));

    for(int i = 0; i < numsSize; i++){
        if(nums[i] - 1 < numsSize && nums[i] - 1 >= 0){
            arrayaux[nums[i] - 1] = nums[i];
        }
    }

    for(int i = 0; i < numsSize; i++){
        if(i == numsSize - 1 && arrayaux[i] == numsSize){
            return numsSize + 1;
        }
        else if(arrayaux[i] == 0){
            return i + 1;
        }
    }

    return 0;

}