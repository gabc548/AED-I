// https://leetcode.com/problems/valid-parentheses/description/

bool isValid(char* s) {

    if(strlen(s) % 2 == 1){
        return false;
    }

    char *pilha;
    int base = 0, topo = 0;
    pilha = (char*)malloc(strlen(s) * sizeof(char));

    for(int i = 0; i < strlen(s); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            printf("%d\n", topo);
            pilha[topo] = s[i];
            topo++;
        } else if(topo == 0){
            free(pilha);
            return false;
        } else if((s[i] == ')' && pilha[topo - 1] != '(') || (s[i] == ']' && pilha[topo - 1] != '[') || (s[i] == '}' && pilha[topo - 1] != '{')){
            free(pilha);
            return false;
        } else{
            topo--;
        }
    }

    free(pilha);

    if(base != topo){
        return false;
    }

    return true;
}