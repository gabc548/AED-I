// https://leetcode.com/problems/rotated-digits/description/

int rotatedDigits(int n) {
    int goodNumbers = 0, currentNumber = 0;
    bool candidate;

    for(int i = 1; i <= n; i++){
        currentNumber = i;
        while(currentNumber > 0){
            if(currentNumber % 10 == 3 || currentNumber % 10 == 4 || currentNumber % 10 == 7){
                candidate = false;
                break;
            }
            if(currentNumber % 10 == 2 || currentNumber % 10 == 5 || currentNumber % 10 == 6 || currentNumber % 10 == 9){
                candidate = true;
            }

            currentNumber = currentNumber / 10;
        }

        if(candidate){
            goodNumbers++;
        }

        candidate = false;
    }

    return goodNumbers;
    
}