#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int* hashTable = (int*)malloc(128 * sizeof(int));
    if (hashTable == NULL) {
        return 0;
    }

    for (int i = 0; i < 128; i++) {
        hashTable[i] = -1;
    }

    int maxLength = 0;
    int substringStart = 0;
    int length = (int)strlen(s);

    for (int i = 0; i < length; i++) {
        unsigned char current = (unsigned char)s[i];
        if (hashTable[current] >= substringStart) {
            substringStart = hashTable[current] + 1;
        }

        hashTable[current] = i;
        if (i - substringStart + 1 > maxLength) {
            maxLength = i - substringStart + 1;
        }
    }

    free(hashTable);
    return maxLength;
}

int main() {
    char s[] = "abcaa";
    printf("%d\n", lengthOfLongestSubstring(s));
    return 0;
}
