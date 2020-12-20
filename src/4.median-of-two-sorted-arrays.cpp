/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

#include "headers.h"
#include <cmath>
# include<algorithm>

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();        
        if (len1 > len2) return findMedianSortedArrays(nums2, nums1);
        if (len1 == 0) return ( (double) nums2[(len2 - 1)/2] + (double) nums2[len2 / 2]) / 2 ;

        // int cutAB_cnt = (len1 + len2 + 1)/2;
        int total_len = len1 + len2;
        int A_startK = 0, A_endK = len1;
        int cutA,cutB;

        while(A_startK <= A_endK) {
            cutA = (A_endK + A_startK) / 2;
            cutB = (total_len + 1) / 2 - cutA;

            // cout << cutA << " " << cutB << endl;

            double L1 = (cutA ==0) ? INT_MIN : nums1[cutA -1];
            double L2 = (cutB ==0) ? INT_MIN : nums2[cutB -1];
            double R1 = (cutA == len1) ? INT_MAX : nums1[cutA];
            double R2 = (cutB == len2) ? INT_MAX : nums2[cutB];

            // cout << L1 << " " << L2 << " " << R1 << " " << R2 << endl;

            if (L1 > R2)  A_endK = cutA -1;
            else if (L2 > R1)  A_startK = cutA + 1;
            else {
                if (total_len % 2 == 0)
                    return (max(L1,L2) + min(R1, R2)) /2 ;
                else
                    return max(L1,L2);
            }
        }

        return -1;
    }
};
// @lc code=end
class Solution2 {
public:
    int kth(vector<int>& nums1, int nums1_left, int nums1_right, vector<int>& nums2, int nums2_left, int nums2_right, int k )
    {
        int m = nums1_right - nums1_left;
        int n = nums2_right - nums2_left;
        // 确保m为较短的数组
        if (m > n) return kth(nums2, nums2_left, nums2_right, nums1, nums1_left, nums1_right, k);
        // 极端情况
        else if (m == 0) return nums2[nums2_left + k -1];
        else if (k == 1) return min(nums1[nums1_left], nums2[nums2_left]);
        else {
            int s1LeftCount = min (k/2, m);
            int s2LeftCount = k - s1LeftCount;
		if (nums1[nums1_left + s1LeftCount - 1] == nums2[nums2_left + s2LeftCount - 1])
			return nums1[nums1_left + s1LeftCount - 1];
		else if (nums1[nums1_left + s1LeftCount - 1] < nums2[nums2_left + s2LeftCount - 1])
			return kth(nums1, nums1_left + s1LeftCount, nums1_right, nums2, nums2_left, nums2_right, k - s1LeftCount);
		else
		return kth(nums1, nums1_left, nums1_right, nums2, nums2_left + s2LeftCount, nums2_right, k - s2LeftCount);
        }
        
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int k = (m + n) / 2;
        int num1 = kth(nums1, 0, m, nums2, 0, n, k + 1);
        if ((n + m) % 2 == 0)
        {
            int num2 = kth(nums1, 0, m, nums2, 0, n, k);
            return (num1 + num2) / 2.0;
        }
        else return num1;       
    }
};

TEST(addTwoNumbers, addTwoNumbers)
{
    Solution s;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2, 4};


    EXPECT_EQ(s.findMedianSortedArrays(nums1, nums2), 2.5);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

/*----------------------------------------------------------------
binary search 选择较短
https://www.youtube.com/watch?v=ScCg9v921ns
*/