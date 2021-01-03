/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;        
        while(left <= right){  
            int mid = left + (right - left) / 2;            
            if(nums[mid] == target) 
                return true;
            if(nums[mid] > nums[right]){
                if(target > nums[mid] || target <= nums[right]) 
                    left = mid + 1;    
                else 
                    right = mid - 1;                                                           
            }
            else if(nums[mid] == nums[right])
                right--;   
            else{
                if(target <= nums[right] && target > nums[mid]) 
                    left = mid + 1; 
                else 
                    right = mid - 1;
            }
        }
    return false;
    }
};
// @lc code=end

TEST(Test, case1)
{
    Solution s;
    vector<int> nums = {1,3,1,1,1};
    int target = 3;
    EXPECT_EQ(s.search(nums, target), true);
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