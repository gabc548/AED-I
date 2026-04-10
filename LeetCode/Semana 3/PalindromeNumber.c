// https://leetcode.com/problems/palindrome-number/

#include <stdbool.h>

bool isPalindrome(int x) {
    char str[100];
    if(x < 0){
        return false;
    }
    sprintf(str, "%d", x);

    for(int i = 0; i < strlen(str) / 2; i++){
        if(str[i] != str[strlen(str)-1-i]){
            return false;
        }
    }

    return true;

}