#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    // int ans[2] = {0, 0};
    *returnSize = 2;
    int *ret = (int*)malloc(2*sizeof(int));
    for (int i = 0; i < numsSize-1; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                ret[0] = i;
                ret[1] = j;
                break;
            }
        }
        // break;
    }
    return ret;
}

int main() {
    int nums[4] = {2, 7, 11, 15};
    int size = 2;
    printf("[%d, %d]\n", *twoSum(nums, 4, 9, &size), *(twoSum(nums, 4, 9, &size)+1));
    return 0;
}