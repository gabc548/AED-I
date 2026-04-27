// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/

int numberOfSteps(int num) {
    int steps = 0;

    while ( num != 0 ) {
        if ( num % 2 == 0 ) {
            num = num / 2;
            steps++;
        } else {
            num = num - 1;
            steps++;
        }
    }

    return steps;
    
}