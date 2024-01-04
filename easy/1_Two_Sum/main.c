#include <stdlib.h>

/* Way 1: Brute Forced, O(n^2) */
int* twoSum1(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* result = (int*)malloc(2 * sizeof(int));

                if (result != NULL) {
                    result[0] = i;
                    result[1] = j;
                    *returnSize = 2;
                    return result;

                } else {
                    *returnSize = 0;
                    return NULL;
                }
            }
        }
    }

    *returnSize = 0;
    return NULL;
}