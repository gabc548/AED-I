// https://leetcode.com/problems/watering-plants-ii/

int minimumRefill(int* plants, int plantsSize, int capacityA, int capacityB) {
    int currentA = capacityA, currentB = capacityB, refills = 0;

    for(int i = 0, j = plantsSize - 1; i <= j; i++, j--){
        if(i == j){
            if(currentA < plants[i] && currentB < plants[j]){
                refills++;            
            }
            break;
        }

        if(currentA < plants[i]){
            currentA = capacityA;
            refills++;
        }
        if(currentB < plants[j]){
            currentB = capacityB;
            refills++;
        }
        currentA = currentA - plants[i];
        currentB = currentB - plants[j];

    }

    return refills;

}