// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

int removeDuplicates(int* nums, int numsSize) {
    int k = nums[0], cont;

    if(numsSize == 1 || numsSize == 0){
        return numsSize;
    }

    for(int i = 0; i < numsSize - 1; i++){
        for(int j = i + 1; j < numsSize; j++){
            if(k < nums[j]){
                nums[i+1] = nums[j];
                k = nums[j];
                break;
            }
            else if(j == numsSize - 1){
                return i + 1;
            }
        }
        cont = i;
    }

    return cont + 2;

}