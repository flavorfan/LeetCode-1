/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
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
            else
                l = mid + 1;
        }
        return nums[l];
    }
};
// @lc code=end


TEST(Test, case1)
{
    Solution s;
    vector<int> nums = {3,4,5,1,2};
    // int target = 3;
    EXPECT_EQ(s.findMin(nums), 1);
}

// TEST(Test, case2)
// {
//     Solution s;
//     vector<int> nums = {1};
//     int target = 0;
//     EXPECT_EQ(s.search(nums, target), false);
// }


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
/* 
element may be duplicate

*/