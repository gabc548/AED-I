// https://leetcode.com/problems/water-bottles/description/

int numWaterBottles(int numBottles, int numExchange) {
    int bottlesDrunk = numBottles;

    while(numBottles >= numExchange){
        bottlesDrunk = numBottles / numExchange + bottlesDrunk;
        numBottles = numBottles / numExchange + numBottles % numExchange;
    }

    return bottlesDrunk;
}