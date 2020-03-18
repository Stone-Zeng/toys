// 189. Rotate Array
// https://leetcode.com/problems/rotate-array/

#include <stdio.h>

void rotateSingle(int* nums, int numsSize) {
    int temp = nums[numsSize - 1];
    for (int i = 0; i < numsSize - 1; ++i)
        nums[numsSize - 1 - i] = nums[numsSize - 2 - i];
    nums[0] = temp;
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    for (int i = 0; i < k; ++i)
        rotateSingle(nums, numsSize);
}

int main() {
    int nums[] = {1,2,3,4,5,6,7};
    rotate(nums, 7, 3);
    for (int i = 0; i < 7; ++i) printf("%d,", nums[i]);
    printf("\n");
}
