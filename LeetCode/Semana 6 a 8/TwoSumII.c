// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int *returnArray;
    *returnSize = 2;
    returnArray = (int*)malloc(*returnSize * sizeof(int));

    int i = 0, j = numbersSize - 1;

    while(1){
        if(numbers[i] + numbers[j] == target){
            returnArray[0] = i + 1;
            returnArray[1] = j + 1;
            break;
        } else if(numbers[i] + numbers[j] < target){
            i++;
        } else{
            j--;
        }
    }

    return returnArray;
}