/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r])
                r = mid;
            else if (nums[mid] > nums[r])
                l = mid + 1;
            else
                r--;
        }
        return nums[l];        
    }
};
// @lc code=end

TEST(Test, case1)
{
    Solution s;
    vector<int> nums = {2,2,2,0,1};
    // int target = 3;
    EXPECT_EQ(s.findMin(nums), 0);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}