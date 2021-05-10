/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
 */

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return head;
        ListNode *head2 = head->next, *p1 = head, *p2 = head2;
        while (p2 && p2->next)
        {
            p1->next = p2->next;
            p1 = p2->next;
            p2->next = p1->next;
            p2 = p1->next;
        }
        p1->next = head2;
        return head;
    }
};
// @lc code=end

