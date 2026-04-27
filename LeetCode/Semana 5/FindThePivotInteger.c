// https://leetcode.com/problems/find-the-pivot-integer/description/

int pivotInteger(int n) {
    int leftIndex = 1, rightIndex = n, leftSum = 0, rightSum = 0;

    while(leftIndex < rightIndex){
        if(leftSum <= rightSum){
            leftSum = leftSum + leftIndex;
            leftIndex++;
        }
        else if(rightSum < leftSum){
            rightSum = rightSum + rightIndex;
            rightIndex--;
        }
    }

    if(leftSum == rightSum){
        return leftIndex;
    }

    return -1;
}