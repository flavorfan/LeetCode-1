/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor) return INT_MAX;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT_MIN ? INT_MAX : -dividend;

        bool flag =  ((divisor < 0) ^ (dividend < 0)) ;

        unsigned int nom = fabs(dividend),  den = fabs(divisor);
        // cout << nom << "" << " " << den <<  endl;

        unsigned int rem = 0, quot = 0;

        for (int i =31; i>=0; --i){
            rem <<= 1;
            rem |= (nom >> i) & 1;
            if (rem >= den){
                rem -= den;
                quot |= (1<<i);
            }
            // cout << rem << "" << " " << den <<  " " << quot << endl;
        }
        // cout << dividend << "" << " " << divisor <<  " " << quot << endl;
        return flag ? -quot: quot;

    }
};
// @lc code=end
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor==0 ) return INT_MAX;
        long long res = double(exp(log(fabs(dividend)) - log(fabs(divisor))));
        cout << dividend << "" << " " << divisor <<  " " << res << endl;
        if ((divisor < 0) ^ (dividend < 0)) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        return res;
    }
};

// TEST(Test, case1)
// {
//     Solution s;
//     EXPECT_EQ(s.divide(-2147483648, -1), 2147483647);
// }


TEST(Test, case2)
{
    Solution s;
    EXPECT_EQ(s.divide(7, -3), -2);
}


// TEST(Test, case3)
// {
//     Solution s;
//     EXPECT_EQ(s.divide(0, 1), 0);
// }

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

/* 
关键点 
1 符号的处理，转换为都是正数的情况；
2 被除数减去除数，如何更高效，用移位，还有多移位的处理


*/