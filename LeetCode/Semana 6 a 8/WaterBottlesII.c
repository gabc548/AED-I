// https://leetcode.com/problems/water-bottles-ii/description/

int maxBottlesDrunk(int numBottles, int numExchange) {
    int bottlesDrunk = numBottles;

    while(numBottles >= numExchange){
        numBottles = numBottles - numExchange + 1;
        bottlesDrunk++;
        numExchange++;
    }

    return bottlesDrunk;
}