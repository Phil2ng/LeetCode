/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *pHead = new ListNode();
        pHead->next = head;
        ListNode *p = pHead;
        while (p->next)
        {
            if (p->next->val == val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return pHead->next;
    }
};
// @lc code=end
