#include "../include/advanced_array_function.h"
#include "stdlib.h"

int max_subarray_sum(int* nums, int size) {
    if (size == 0) return 0;

    int maxSum = nums[0];
    int currentSum = nums[0];

    for (int i = 1; i < size; i++) {
        if (nums[i] > currentSum + nums[i]) {
            currentSum = nums[i];
        } else {
            currentSum += nums[i];
        }
        //~Тернар() ? nums[i] : current_sum + nums[i]
        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    return maxSum;
}

int length_of_lis(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int maxLen = 1;
    int currentLen = 1;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > nums[i - 1]) {
            currentLen++;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            currentLen = 1;
        }
    }

    return maxLen;
}

int* merge(int* intervals, int intervalsSize, int* returnSize) {
    //1, 3, 2, 6, 8, 10, 15, 18, 16, 20, 0, 25 expected 0,25
    //1, 3, 2, 6, 10, 15 expected 1,6,10,15
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    //Гибрид пузерька с шустрым алго
    for (int i = 0; i < intervalsSize - 1; i++) {
        for (int j = 0; j < intervalsSize - i - 1; j++) {
            if (intervals[2 * j] > intervals[2 * (j + 1)]) {
                int temp1 = intervals[2 * j];
                int temp2 = intervals[2 * j + 1];
                intervals[2 * j] = intervals[2 * (j + 1)];
                intervals[2 * j + 1] = intervals[2 * (j + 1) + 1];
                intervals[2 * (j + 1)] = temp1;
                intervals[2 * (j + 1) + 1] = temp2;
            }
        }
    }
    int* result = (int*)malloc(2 * intervalsSize * sizeof(int));
    int count = 0;
    int currentStart = intervals[0];
    int currentEnd = intervals[1];
    for (int i = 1; i < intervalsSize; i++) {
        int nextStart = intervals[2 * i];
        int nextEnd = intervals[2 * i + 1];
        if (nextStart <= currentEnd) {
            if (nextEnd > currentEnd) {
                currentEnd = nextEnd;
            }
        } else {
            result[2 * count] = currentStart;
            result[2 * count + 1] = currentEnd;
            count++;
            currentStart = nextStart;
            currentEnd = nextEnd;
        }
    }
    result[2 * count] = currentStart;
    result[2 * count + 1] = currentEnd;
    count++;

    *returnSize = count;
    return result;
}

