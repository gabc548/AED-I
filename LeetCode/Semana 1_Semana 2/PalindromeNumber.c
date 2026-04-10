#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(int x); // This function is the solution to the problem

int main(){

    int num = 125;

    if(isPalindrome(num) == 1){
        printf("true");
    }
    else{
        printf("false");
    }

    return 0;
    
}

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