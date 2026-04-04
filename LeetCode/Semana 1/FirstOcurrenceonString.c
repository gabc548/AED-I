#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr(char* haystack, char* needle); // This function is the solution to the problem

int main(){
    char *haystack, *needle;

    haystack = (char *)malloc(sizeof(char) * 8);
    needle = (char *)malloc(sizeof(char) * 5);

    strcpy(haystack, "Testing");
    strcpy(needle, "esti");

    int n = strStr(haystack, needle);

    printf("%d", n);

    free(haystack);
    free(needle);

    return 0;
    
}

int strStr(char* haystack, char* needle) {
    for(int j = 0; j < strlen(haystack); j++){
        if(needle[0] == haystack[j]){
            for(int i = 0; i < strlen(needle); i++){
                if(needle[i] != haystack[j+i]){
                    break;
                }
                if(i == strlen(needle) - 1){
                    return j;
                }
            }
        }
    }

    return -1;

}