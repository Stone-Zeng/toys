// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return numsSize;
    int count = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] < nums[i + 1])
            nums[++count] = nums[i + 1];
    }
    return count + 1;
}

#define TEST(nums, numsSize) \
    printf("%d\t", removeDuplicates((nums), (numsSize))); \
    for (int i = 0; i < (numsSize); i++) printf("%d,", (nums)[i]); \
    printf("\n");

int main() {
    int test1[] = {1,1,2};
    int test2[] = {0,0,1,1,1,2,2,3,3,4};
    int test3[] = {};
    int test4[] = {1,1,1,1,1,1,1,1,1};
    TEST(test1,  3);
    TEST(test2, 10);
    TEST(test3,  0);
    TEST(test4,  9);
}
