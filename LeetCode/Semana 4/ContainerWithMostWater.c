// https://leetcode.com/problems/container-with-most-water/

int maxArea(int* height, int heightSize) {
    int mult = -1, currentHeight = 0;
    for(int i = 0; i < heightSize; i++){
        if(height[i] * (heightSize - i) < mult || height[i] < currentHeight){
            continue;
        }
        else{
            for(int j = i + 1; j < heightSize; j++){
                if(height[j] <= height[i] && height[j] * (j - i) > mult){
                    currentHeight = height[i];
                    mult = height[j] * (j - i);
                }
                else if(height[i] < height[j] && height[i] * (j - i) > mult){
                    currentHeight = height[i];
                    mult = height[i] * (j - i);
                }
            }
        }
    }

    return mult;

}