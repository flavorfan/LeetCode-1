/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int s = 0, e= nums.size()-1;
        vector<int> ans = {-1,-1};
        //first occurrence
        while (s <= e){
            int m = (s + e)/2;
            if (nums[m] < target) s = m+1;
            else if (nums[m] > target) e = m-1;
            else {
                if (m == s || nums[m] != nums[m-1]){
                    ans[0] = m;
                    break;
                }else{
                    e = m-1;
                    ans[0] = m -1;
                }
            }
        }

        //last occurrence
        s = 0, e= nums.size()-1;
        while (s <= e){
            int m = (s + e)/2;
            if (nums[m] < target) s = m+1;
            else if (nums[m] > target) e = m-1;
            else {
                if (m == e || nums[m] != nums[m+1]){
                    ans[1] = m;
                    break;
                }else{
                    s = m+1;
                    ans[1] = m +1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end


TEST(Test, case1)
{
    Solution s;
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    vector<int> expected = {3,4};
    EXPECT_EQ(s.searchRange(nums, target), expected);
}

TEST(Test, case2)
{
    Solution s;
    vector<int> nums = {2,2};
    int target = 2;
    vector<int> expected = {0,1};
    EXPECT_EQ(s.searchRange(nums, target), expected);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}