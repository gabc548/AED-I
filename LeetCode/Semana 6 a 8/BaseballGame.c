// https://leetcode.com/problems/baseball-game/description/

int Pop(int* stack, int* topo);

void Push(int* stack, int* topo, int* i, char** operations);

void Dobro(int* stack, int* topo);

void Soma(int* stack, int* topo);

int calPoints(char** operations, int operationsSize) {
    int *stack;
    stack = (int*)malloc(1000 * sizeof(int));
    int topo = 0, returnValue = 0, valor;

    for(int i = 0; i < operationsSize; i++){
        if(operations[i][0] == 'C'){
            valor = Pop(stack, &topo);
        } else{
            Push(stack, &topo, &i, operations);
        }
    }

    for(topo; topo > 0;){
        valor = Pop(stack, &topo);
        returnValue = returnValue + valor;
    }

    return returnValue;
}

int Pop(int* stack, int* topo){
    if(*topo == 0){
        exit(0);
    }
    (*topo)--;
    int valor = stack[*topo];
    return valor;
}

void Push(int* stack, int* topo, int* i, char** operations){
    if(*topo == 1000){
        return;
    }
    
    if(operations[*i][0] == 'D'){
        Dobro(stack, topo);
    } else if(operations[*i][0] == '+'){
        Soma(stack, topo);
    } else {
        stack[*topo] = atoi(operations[*i]);
        (*topo)++;
    }

    return;
}

void Dobro(int* stack, int* topo){
    (*topo)--;
    int valor = stack[*topo];
    (*topo)++;
    stack[*topo] = valor * 2;
    (*topo)++;

    return;
}

void Soma(int* stack, int* topo){
    (*topo)--;
    int valor1 = stack[*topo];
    (*topo)--;
    int valor2 = stack[*topo];

    (*topo)++;
    stack[*topo] = valor1;
    (*topo)++;
    stack[*topo] = valor1 + valor2;
    (*topo)++;

    return;
}