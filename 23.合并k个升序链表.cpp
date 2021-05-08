/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    struct Comp
    {
        bool operator()(ListNode *l1, ListNode *l2)
        {
            return l1->val > l2->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, Comp> pq;
        for (ListNode *list : lists)
        {
            if (list)
                pq.push(list);
        }
        ListNode *head = new ListNode(), *tail = head;
        while (!pq.empty())
        {
            tail->next = pq.top();
            pq.pop();
            tail = tail->next;
            if (tail->next)
                pq.push(tail->next);
        }
        return head->next;
    }
};
// @lc code=end

