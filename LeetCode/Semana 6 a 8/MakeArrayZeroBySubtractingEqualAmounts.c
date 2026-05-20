// https://leetcode.com/problems/make-array-zero-by-subtracting-equal-amounts/description/

int minimumOperations(int* nums, int numsSize) {
    int *arrayUniques, repetitions = numsSize;
    arrayUniques = (int*)calloc(numsSize, sizeof(int));

    for(int i = 0; i < numsSize; i++){
        for(int j = 0; j < numsSize; j++){
            if(nums[i] == arrayUniques[j]){
                repetitions--;
                break;
            } else if(arrayUniques[j] == 0){
                arrayUniques[j] = nums[i];
                break;
            }
        }
    }

    return repetitions;
}