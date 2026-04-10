// https://leetcode.com/problems/plus-one/

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int carry = 1;
    int *array;
    *returnSize = 0;

    for(int i = digitsSize - 1; i >= 0; i--){
        if(i == 0 && digits[0] + carry >= 10){
            *returnSize = digitsSize + 1;
        }
        else if(i == digitsSize - 1){
            *returnSize = digitsSize;
        }
        if(digits[i] + carry >= 10){
            carry = 1;
        }
        else{
            carry = 0;
        }
    }

    array = (int *)malloc(*returnSize * sizeof(int));

    carry = 1;
    int n = 0;
    if(*returnSize > digitsSize){
        n = 1;
        array[0] = 1;
    }

    for(int i = digitsSize - 1; i >= 0; i--){
        if(digits[i] + carry >= 10){
            array[i + n] = (digits[i] + carry) % 10;
        }
        else{
            array[i + n] = digits[i] + carry;
            carry = 0;
        }
    }

    return array;

}