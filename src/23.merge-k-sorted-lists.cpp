/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        for (ListNode * head: lists){
            while (head != NULL){
                minheap.push(head->val);
                head = head->next;
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode * head = dummy;
        while( !minheap.empty()){
            dummy->next = new ListNode(minheap.top());
            minheap.pop();
            dummy=dummy->next;
        }
        return head-> next;
    }
};
// @lc code=end

TEST(addTwoNumbers, addTwoNumbers)
{
    Solution s;

    List l1 = List({1,4,5});
    List l2 = List({1,3,4});
    List l3 = List({2,6});

    vector<ListNode*>  lists;
    lists.push_back(l1.head);
    lists.push_back(l2.head);
    lists.push_back(l3.head);

    List expected = List({1,1,2,3,4,4,5,6});

    print_list(l1.head);
    print_list(l2.head);
    print_list(l3.head);

    print_list(expected.head);

    // EXPECT_EQ(s.removeNthFromEnd(l1,2), 3);
    EXPECT_EQ(is_same_list(s.mergeKLists(lists), expected.head), true);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

/* priority_queue<Type, Container, Functional>
Type 就是数据类型，
Container 就是容器类型（Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。
STL里面默认用的是vector），
Functional 就是比较的方式

priority_queue<int, vector<int>, greater<int>> minheap; 

//升序队列
priority_queue <int,vector<int>,greater<int> > q;

//降序队列
priority_queue <int,vector<int>,less<int> >q;

*/