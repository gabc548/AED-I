// https://leetcode.com/problems/jump-game-ii/description/

int jump(int* nums, int numsSize) {
    int i = 0, indexMax = 0, valueMax = -1, jumps = 0;

    while(i < numsSize - 1){
        if(numsSize - 1 <= nums[i] + i){
            i = numsSize - 1;
        }
        else{
            for(int j = 1; j <= nums[i]; j++){
                if(nums[i + j] + j > valueMax){
                    valueMax = nums[i + j] + j;
                    indexMax = i + j;
                }
            }
            i = indexMax;
            valueMax = -1;
            indexMax = 0;
        }

        jumps++;
    }

    return jumps;
}