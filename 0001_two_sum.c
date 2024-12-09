#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate memory for the result
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    // Nested loops to check all pairs
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            // Check if the pair adds up to the target
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result; // Return indices when the solution is found
            }
        }
    }

    *returnSize = 0; // If no solution is found
    return NULL;
}

int main() {
    int nums[] = {3,2,5};
    int target = 6;
    int returnSize;

    // Call the function
    int* result = twoSum(nums, 4, target, &returnSize);
    if (result != NULL) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
       // free(result); // Free allocated memory
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
