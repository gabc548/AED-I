// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

long long pickGifts(int* gifts, int giftsSize, int k) {
    int maxIndex = 0;
    long long finalAmount = 0;

    for(int i = 0; i < k; i++){
        for(int j = 0; j < giftsSize; j++){
            if(gifts[j] > gifts[maxIndex]){
                maxIndex = j;
            }
        }
        gifts[maxIndex] = floor(sqrt(gifts[maxIndex]));
    }

    for(int i = 0; i < giftsSize; i++){
        finalAmount = gifts[i] + finalAmount;
    }

    return finalAmount;

}