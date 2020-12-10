/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
#include "headers.h"

// @lc code=start
class Solution {
public:
    int maxOfArray(int arr[]){
        for(int i='a';i<='z';i++)
            if(arr[i]>1)
                return 2;
        for(int i='A';i<='Z';i++)
            if(arr[i]>1)
                return 2;
        for(int i=0;i<'A';i++)
            if(arr[i]>1)
                return 2;
        for(int i='Z'+1;i<'a';i++)
            if(arr[i]>1)
                return 2;
        for(int i='z'+1;i<256;i++)
            if(arr[i]>1)
                return 2;
        return 1;
    }

    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, n=s.length(),m=0;
        int arr[256] = {0};

        while (end < n){
            while (end < n && arr[s[end]] == 0)
                arr[s[end++]] ++;
            m = max(m, end -start);
            arr[s[end++]] ++;
            while (start < end && maxOfArray(arr) > 1)
                arr[s[start++]] --;
            
        }
        return m;
    }
};
// @lc code=end


TEST(addTwoNumbers, addTwoNumbers)
{
    Solution s;



    EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}