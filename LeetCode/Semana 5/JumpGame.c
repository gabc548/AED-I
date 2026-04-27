// https://leetcode.com/problems/jump-game/description/

bool canJump(int* nums, int numsSize) {
    int valueMax = 0, indexMax = -1;
    for(int i = 0; i < numsSize;){
        if(nums[i] + i >= numsSize - 1){
            return true;
        }
        if(nums[i] == 0){
            return false;
        }
        for(int j = 1; j <= nums[i]; j++){
            if(nums[i + j] + j >= valueMax){
                valueMax = nums[i + j] + j;
                indexMax = i + j;
            }
        }
        i = indexMax;
        valueMax = 0;
        indexMax = 0;
    }

    return false;
}