/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * 哈希表
 * 
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_set<ListNode *> st;
        while (head)
        {
            if (st.count(head))
                return true;
            st.insert(head);
            head = head->next;
        }
        return false;
    }
};
// @lc code=end

