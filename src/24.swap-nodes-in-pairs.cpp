/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL)
            return NULL;
        
        if (head->next == NULL)
        {
            return head;
        }

        ListNode* p = head;
        while(p!=NULL && p->next != NULL)
        {
            swap(p->val, p->next->val);
            p=p->next->next;
        }

        return head;
    }
};
// @lc code=end

TEST(swapPairs, swapPairs)
{
    Solution s;

    List l1 = List({1,2,3,4});
    List l2 = List({2,1,4,3});

    // EXPECT_EQ(s.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(is_same_list(s.swapPairs(l1.head), l2.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
// 交换值