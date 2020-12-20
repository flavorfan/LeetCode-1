/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        ListNode * l1 = head, * l2 = head;
        int distance = 0;
        // find the break point l2
        while(true){
            if ( l2 == NULL)
                break;
            else{
                l2 = l2->next;
                distance ++;
                if (distance > n-1){
                    l1 = l1->next;
                    distance --;
                }
            }
        }

        // reconstruct list
        l2->next = l2->next->next;
        return head;
        */

        if (head == NULL){
            return head;
        }

        // dummy head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i=0; i< n;i++)
            fast= fast->next;

        while (fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow -> next = slow-> next->next;

        return dummy->next;
    }
};
// @lc code=end


TEST(addTwoNumbers, addTwoNumbers)
{
    Solution s;

    List l1 = List({1,2,3,4,5});
    List l2 = List({1,2,3,5});

    print_list(l1.head);
    print_list(l2.head);

    // EXPECT_EQ(s.removeNthFromEnd(l1,2), 3);
    EXPECT_EQ(is_same_list(s.removeNthFromEnd(l1.head, 2), l2.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}