/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> cache;
        vector<int> answer;

        for (size_t i =0; i< nums.size(); ++i){
            int needed_num = target -nums[i];

            if ( cache.find(needed_num) != cache.end()){
                answer.push_back(cache[needed_num]);
                answer.push_back(i);
                return answer;
            }
            else{
                cache.insert(make_pair(nums[i], i));
            }
        }
        return answer;
    }
};
// @lc code=end

TEST(twoSum, twoSum)
{
    Solution s;
    vector<int> nums = {2,7,11,15};
    int target = 9;
    vector<int>  ans = {0,1};
    EXPECT_EQ(s.twoSum(nums, target), ans);

    
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}