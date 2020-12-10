/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */
#include "headers.h"
// using LeetCode::ListNode;
using namespace LeetCode;

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* l3 = NULL;
        ListNode **node = &l3;
        while(l1 != NULL | l2 != NULL | sum>0) {
            if (l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2=l2->next;
            }
            (*node) = new ListNode(sum % 10);
            sum/=10;
            node=&((*node)->next);
        }
        return l3;
    }
};
// @lc code=end


TEST(addTwoNumbers, addTwoNumbers)
{
    Solution s;

    List l1 = List({2,4,3});
    List l2 = List({5,6,4});
    List l3 = List({7,0,8});

    print_list(l1.head);
    print_list(l2.head);
    print_list(l3.head);

    ListNode *ans = s.addTwoNumbers(l1.head, l2.head);
    print_list(ans);

    EXPECT_EQ(is_same_list(s.addTwoNumbers(l1.head, l2.head), l3.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}