// https://leetcode.com/problems/harshad-number/

int sumOfTheDigitsOfHarshadNumber(int x) {
    int sumDigits = 0, tmpX = x;

    while(tmpX > 0){
        sumDigits = tmpX % 10 + sumDigits;
        tmpX = tmpX / 10;
    }

    if(x % sumDigits == 0){
        return sumDigits;
    }

    return -1;
}