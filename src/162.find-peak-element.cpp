/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */
#include "headers.h"

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
// edge case - only one item
        if (nums.size() == 1) return 0;
        // peak is first item
        if (nums[0] > nums[1]) return 0;
        // peak is last item
        if (nums.back() > nums[nums.size()-2]) return nums.size()-1;
        // iterate to find peak
        for (int i=0; i<nums.size(); i++) 
            if ((nums[i] > nums[max(0,i-1)]) && (nums[i] > nums[i+1])) return i;
        return -1;    
    }
};
// @lc code=end


TEST(Test, case1)
{
    Solution s;
    vector<int> nums = {1,2,1,3,5,6,4};
    EXPECT_EQ(s.findPeakElement(nums), 1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
/* 
element may be duplicate

*/