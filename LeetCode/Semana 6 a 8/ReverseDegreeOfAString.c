// https://leetcode.com/problems/reverse-degree-of-a-string/description/

int reverseDegree(char* s) {
    int currentMult = 1, sum = 0;
    for(int i = 0; i < strlen(s); i++){
        currentMult = (123 - s[i]) * (i + 1);
        sum = currentMult + sum;
    }

    return sum;
}