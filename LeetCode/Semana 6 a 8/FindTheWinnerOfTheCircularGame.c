// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

void RemovePlayer(int* jogadores, int* n, int num){
    for(int i = num; i < *n - 1; i++){
        jogadores[i] = jogadores[i + 1];
    }

    (*n)--;

    return;
}

int findTheWinner(int n, int k) {
    int *jogadores, num, startRound = 0;
    jogadores = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        jogadores[i] = i + 1;
    }

    while(n > 1){
        num = (k + startRound) % n;
        num--;
        if(num == -1){
            num = n - 1;
        }
        startRound = num;
        RemovePlayer(jogadores, &n, num);
    }

    return jogadores[0];
}