/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
#include "headers.h"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 || l2 && l1->val > l2->val) 
            swap(l1, l2);
        if (l1) 
            l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
};
// @lc code=end

// 递归算法实现
// 编绳子
TEST(addTwoNumbers, addTwoNumbers)
{
    Solution s;

    List l1 = List({1,2,4});
    List l2 = List({1,3,4});
    List l3 = List({1,1,2,3,4,4});

    // EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(is_same_list(s.mergeTwoLists(l1.head, l2.head), l3.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}