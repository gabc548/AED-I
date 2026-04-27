// https://leetcode.com/problems/mirror-distance-of-an-integer/

int mirrorDistance(int n) {
    int m = 0, tmp = n;

    while(tmp > 0){
        m = tmp % 10 + m * 10;
        tmp = tmp / 10;
    }

    return abs(n - m);
}