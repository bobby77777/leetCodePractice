#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s){
    int *hashTable = (int*)malloc(128*sizeof(int));
    for (int i = 0; i < 127; i++) {
        hashTable[i] = -1;
    }
    int max = 0, substringStart = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (hashTable[s[i]] >= substringStart) { //already in substring
            substringStart = hashTable[s[i]] + 1;
            hashTable[s[i]] = i;
        } else { //not in substring
            hashTable[s[i]] = i;
            if (i - substringStart + 1 > max) {
                max = i - substringStart + 1;
            }
        }
    }
    return max;
}

int main() {
    char* s = "abcaa";
    lengthOfLongestSubstring(s);
    // printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}
