/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        bitset<32> bit(abs(n));
        double result = 1;
        for(int i = bit.size()-1; i >= 0; i--)
        {
            result*=result;
            if(bit[i] == 1)
                result *=x;
        }
        return (n >= 0)?result : 1/result;
    }
};
// @lc code=end
TEST(Test, case1)
{
    Solution s;

    List l1 = List({1,2,4});
    List l2 = List({1,3,4});
    List l3 = List({1,1,2,3,4,4});

    // EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(s.myPow(2.00000, -2),0.25000 );
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

/*
bitset存储二进制数位。
bitset就像一个bool类型的数组一样，但是有空间优化——bitset中的一个元素一般只占1 bit，
相当于一个char元素所占空间的八分之一。
  std::bitset<16> foo;
  std::bitset<16> bar (0xfa2);
  std::bitset<16> baz (std::string("0101111001"));

  std::cout << "foo: " << foo << '\n';
  std::cout << "bar: " << bar << '\n';
  std::cout << "baz: " << baz << '\n';

foo: 0000000000000000
bar: 0000111110100010
baz: 0000000101111001


*/