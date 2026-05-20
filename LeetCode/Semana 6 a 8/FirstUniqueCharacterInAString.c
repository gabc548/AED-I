// https://leetcode.com/problems/first-unique-character-in-a-string/description/

int firstUniqChar(char* s) {
    int *auxArr;
    auxArr = (int*)calloc(26, sizeof(int));

    for(int i = 0; i < strlen(s); i++){
        auxArr[s[i] - 'a']++;
    }

    for(int i = 0; i < strlen(s); i++){
        if(auxArr[s[i] - 'a'] == 1){
            return i;
        }
    }

    return -1;
}