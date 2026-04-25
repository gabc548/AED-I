#include <stdbool.h>

bool lemonadeChange(int* bills, int billsSize) {
    int qtd5 = 0, qtd10 = 0;

    for(int i = 0; i < billsSize; i++){
        if(bills[i] == 5){
            qtd5++;
        }
        else if(bills[i] == 10){
            qtd10++;
            qtd5--;
        }
        else if(bills[i] == 20){
            if(qtd10 > 0){
                qtd10--;
                qtd5--;
            }
            else{
                qtd5 = qtd5 - 3;
            }
        }

        if(qtd5 < 0 || qtd10 < 0){
            return false;
        }
    }

    return true;

}