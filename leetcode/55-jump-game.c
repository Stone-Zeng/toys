// 55. Jump Game
// https://leetcode.com/problems/jump-game/

#include <stdio.h>

#define bool int
#define true  1
#define false 0

bool canJump(int* nums, int numsSize) {
    int range = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        if (range >= numsSize - 1) return true;
        if (range < i) return false;
        if (range < i + nums[i]) range = i + nums[i];
    }
    return true;
}

int main() {
    int nums1[] = {2,3,1,1,4};
    printf("%d\n", canJump(nums1, 5));
    int nums2[] = {3,2,1,0,4};
    printf("%d\n", canJump(nums2, 5));
    int nums3[] = {1,2,3};
    printf("%d\n", canJump(nums3, 3));
}
