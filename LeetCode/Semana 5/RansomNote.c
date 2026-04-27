// https://leetcode.com/problems/ransom-note/description/

bool canConstruct(char* ransomNote, char* magazine) {
    for( int i = 0; i < strlen( ransomNote ); i++ ) {
        for( int j = 0; j < strlen( magazine ); j++ ) {
            if(ransomNote[i] == magazine[j]) {
                magazine[j] = '1';
                ransomNote[i] = '1';
                break;
            }
        }
    }

    for( int i = 0; i < strlen( ransomNote ); i++ ) {
        if( ransomNote[i] != '1' ){
            return false;
        }
    }

    return true;
}