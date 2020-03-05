// 75. Sort Colors
// https://leetcode.com/problems/sort-colors/

#include "stdio.h"

void sortColors(int* nums, int numsSize) {
    int counts[3] = {0, 0, 0};
    for (int i = 0; i != numsSize; ++i)
        counts[nums[i]]++;
    for (int i = 0; i != counts[0]; ++i)
        nums[i] = 0;
    for (int i = 0; i != counts[1]; ++i)
        nums[counts[0] + i] = 1;
    for (int i = 0; i != counts[2]; ++i)
        nums[counts[0] + counts[1] + i] = 2;
}

void printVec(int* v, int n) {
    for (int i = 0; i != n; ++i)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int v1[] = {2,0,2,1,1,0};
    printVec(v1, 6);
    sortColors(v1, 6);
    printVec(v1, 6);

    int v2[] = {0,2,0,2,2,0,2,2,2,0,0,0,2,2,2,2,0,2,2,0};
    printVec(v2, 10);
    sortColors(v2, 10);
    printVec(v2, 10);
}
