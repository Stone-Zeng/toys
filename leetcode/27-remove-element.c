// 27. Remove Element
// https://leetcode.com/problems/remove-element/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int i = 0, count = 0;
    while (i < numsSize - count) {
        if (nums[i] == val) {
            for (int j = i; j < numsSize - 1; j++)
                nums[j] = nums[j + 1];
            count++;
        }
        else
            i++;
    }
    return numsSize - count;
}

int main() {
    int test1[] = {1,2,3,4,2,2,5,6};
    int test2[] = {1,1,1};
    int test3[] = {};
    int test4[] = {1,2,3,4,2,2,5,6,1,2,3,4,2,2,5,6,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,3,4,2,2,5,6,1,2,3,4,2,2,5,6,1,2,3,4,2,2,5,6,1,2,3,5,6,1,2,3,4,2,2,5,6};
    printf("%d\n", removeElement(test1,  8, 2));
    printf("%d\n", removeElement(test2,  3, 1));
    printf("%d\n", removeElement(test3,  0, 2));
    printf("%d\n", removeElement(test4, 66, 1));
}
