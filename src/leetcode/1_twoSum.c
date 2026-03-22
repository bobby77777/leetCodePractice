#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 0;

    int* ret = (int*)malloc(2 * sizeof(int));
    if (ret == NULL) {
        return NULL;
    }

    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                *returnSize = 2;
                return ret;
            }
        }
    }

    free(ret);
    return NULL;
}

int main() {
    int nums[4] = {2, 7, 11, 15};
    int size = 0;
    int* result = twoSum(nums, 4, 9, &size);

    if (result != NULL && size == 2) {
        printf("[%d, %d]\n", result[0], result[1]);
    }

    free(result);
    return 0;
}
