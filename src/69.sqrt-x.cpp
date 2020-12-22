/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        long long s=0, e=x, ans, mid;   //long long due to some of test cases overflows integer limit.
        while(s<=e){             
            mid=(s+e)/2;
            if(mid*mid==x) return mid;     //if the 'mid' value ever gives the result, we simply return it.
            else if(mid*mid<x){             
                s=mid+1;        //if 'mid' value encounterted gives lower result, we simply discard all the values lower than mid.
                ans=mid;        //an extra pointer 'ans' is maintained to keep track of only lowest 'mid' value. 
            }
            else e=mid-1;       //if 'mid' value encountered gives greater result, we simply discard all the values greater than mid. 
            // cout << s << " " << e <<" mid: " << mid << "mid^2 "<< mid * mid  << " ans: " << ans << endl;
        }
        return ans; 
    }
};
// @lc code=end

TEST(Test, case1)
{
    Solution s;


    // EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.mySqrt(8),2);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

/*

*/