/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto first = nums.begin(), last = nums.end();
        while (first < last) {
            auto mid = first + ((last - first) >> 1);
            if (*mid < target) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }
        return first - nums.begin();
    }
};
// @lc code=end

TEST(Test, case1)
{
    Solution s;
    vector<int> nums = {1,3,5,7};
    int target = 2;
    EXPECT_EQ(s.searchInsert(nums, target), 1);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

//Actually, what we need here is std::lower_bound in C++ STL, 
// which returns an iterator pointing to the first element that does not less than target. 
// And then, things are quite simple:

