// https://leetcode.com/problems/longest-common-prefix/

char* longestCommonPrefix(char** strs, int strsSize) {
    int currentSizePrefix;
    char *strAux;
    strAux = (char*)malloc(201 * sizeof(char));
    strcpy(strAux, strs[0]);
    currentSizePrefix = strlen(strs[0]);

    for(int i = 1; i < strsSize; i++){
        for(int j = 0; j < currentSizePrefix && j < strlen(strs[i]); j++){
            if(strs[i][j] != strAux[j]){
                strAux[j] = '\0';
                currentSizePrefix = j;
                break;
            }
            if(j == strlen(strs[i]) - 1){
                strAux[j + 1] = '\0';
            }
        }
        if(strlen(strs[i]) == 0){
            return "";
        }
    }

    if(currentSizePrefix == 0){
        return "";
    }

    return strAux;

}