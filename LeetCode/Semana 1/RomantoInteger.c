#include <stdio.h>
#include <string.h>

int SymboltoValue(char c); // Included in the solution to the problem
int romanToInt(char *s); // This function is the solution to the problem

int main(){
    char str[5] = "CLIX";

    int Output = romanToInt(str);

    printf("%d", Output);

    return 0;

}

int SymboltoValue(char c){
    if(c == 'I'){
        return 1;
    }
    else if(c == 'V'){
        return 5;
    }
    else if(c == 'X'){
        return 10;
    }
    else if(c == 'L'){
        return 50;
    }
    else if(c == 'C'){
        return 100;
    }
    else if(c == 'D'){
        return 500;
    }
    else if(c == 'M'){
        return 1000;
    }

    return 0;
}

int romanToInt(char* s) {
    int m, n, num = 0; // 1690
    for(int i = 0; i < strlen(s); i++){
        n = 0;
        m = SymboltoValue(s[i]); // 5
        if(i < strlen(s) - 1){
            n = SymboltoValue(s[i+1]); // 100
        }

        if(m < n){
            num = num + n - m;
            i++;
        }

        else{
            num = num + m;
        }

    }

    return num;

}