/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode pHead = ListNode(0, head);
        ListNode *pre, *cur, *next, *tail, *front, *p_new;
        pre = &pHead;
        for (size_t i = 0; i < left - 1; i++)
        {
            pre = pre->next;
        }
        cur = pre->next;
        tail = cur;
        p_new = nullptr;
        for (size_t i = left; i <= right; i++)
        {
            next = cur->next;
            cur->next = p_new;
            p_new = cur;
            cur = next;
        }
        pre->next = p_new;
        tail->next = cur;
        return pHead.next;
    }
};
// @lc code=end

