// https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/description/

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    int tempBubble;

    for(int i = 0; i < arrSize - 1; i++){
        for(int j = i + 1; j < arrSize; j++){
            if(arr[j] < arr[i]){
                tempBubble = arr[j];
                arr[j] = arr[i];
                arr[i] = tempBubble;
            }
        }
    }

    int difference = arr[1] - arr[0];

    for(int i = 1; i < arrSize - 1; i++){
        if(arr[i+1] - arr[i] != difference){
            return false;
        }
    }

    return true;

}