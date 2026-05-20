// https://leetcode.com/problems/fizz-buzz/description/

char** fizzBuzz(int n, int* returnSize) {
    char **output;
    output = (char**)malloc(n * sizeof(char*));
    *returnSize = n;

    for(int i = 0; i < n; i++){
        if((i + 1) % 5 == 0 && (i + 1) % 3 == 0){
            output[i] = (char*)malloc(9 * sizeof(char));
            strcpy(output[i], "FizzBuzz");
        } else if((i + 1) % 5 == 0){
            output[i] = (char*)malloc(5 * sizeof(char));
            strcpy(output[i], "Buzz");
        } else if((i + 1) % 3 == 0){
            output[i] = (char*)malloc(5 * sizeof(char));
            strcpy(output[i], "Fizz");
        } else{
            output[i] = (char*)malloc((log10(i + 1) + 1) * sizeof(char) + 1 * sizeof(char));
            sprintf(output[i], "%d", i + 1);
        }
    }

    return output;

}