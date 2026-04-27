// https://leetcode.com/problems/watering-plants/

int wateringPlants(int* plants, int plantsSize, int capacity) {
    int steps = 1, currentWater = capacity;
    currentWater = currentWater - plants[0];

    for(int i = 0; i < plantsSize - 1; i++){
        if(currentWater < plants[i + 1]){
            currentWater = capacity;
            steps = i + 1 + i + 2 + steps;
        }
        else{
            steps++;
        }
        currentWater = currentWater - plants[i + 1];
    }

    return steps;
}