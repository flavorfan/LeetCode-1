/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int beg=0, end=nums.size()-1, mid;

        while(beg<=end)
        {
            mid = (beg+end)/2;
            if (nums[mid]==target){
                return mid;
            }
            if (nums[beg] <= nums[mid]){
                if (target <= nums[mid] && target >= nums[beg])
                    end = mid - 1;
                else 
                    beg = mid + 1;    
            }

            else {
                if (target >= nums[mid] && target <= nums[end])
                    beg=mid + 1;
                else
                    end= mid -1 ;
            }
        }
        return -1;
    }
};
// @lc code=end


TEST(Test, case1)
{
    Solution s;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    EXPECT_EQ(s.search(nums, target), 4);
}




int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}