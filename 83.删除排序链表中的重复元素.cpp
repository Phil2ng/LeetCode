/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *prev = head, *curr = head->next;
        while (curr)
        {
            if (prev->val == curr->val)
            {
                prev->next = curr->next;
                curr = curr->next;
            }
            else
            {
                prev = prev->next;
                curr = curr->next;
            }
        }
        return head;
    }
};
// @lc code=end

