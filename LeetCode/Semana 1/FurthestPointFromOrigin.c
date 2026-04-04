#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int furthestDistanceFromOrigin(char* moves); // This function is the solution to the problem 

int main(){
    char moves[10] = {'L', '_', 'R', '_', 'L', 'R', '_', 'R', 'R', 'R'};
    int target = 6; // I don't really know how the main from the program may check it

    int Output = furthestDistanceFromOrigin(moves);

    if(Output == target){
        printf("It's right");
    }
    else{
        printf("It's wrong");
    }

    return 0;

}

int furthestDistanceFromOrigin(char* moves) {
    int L = 0, R = 0;
    int strlenght = strlen(moves);

    for(int i = 0; i < strlenght; i++){
        if(moves[i] == 'L'){
            L++;
        }
        if(moves[i] == 'R'){
            R++;
        }
    }

    if(R > L){
        R = strlenght - L;
    }
    else{
        L = strlenght - R;
    }

    return abs(L - R);

}