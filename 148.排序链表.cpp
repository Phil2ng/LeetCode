/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode *sortList(ListNode *head)
    {
        return sortList(head, nullptr);
    }
    ListNode *sortList(ListNode *head, ListNode *tail)
    {
        if (!head)
            return head;
        if (head->next == tail)
        {
            head->next = nullptr;
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast != tail)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail)
                fast = fast->next;
        }
        ListNode *mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummyHead = new ListNode();
        ListNode *p = dummyHead, *p1 = head1, *p2 = head2;
        while (p1 && p2)
        {
            if (p1->val <= p2->val)
            {
                p->next = p1;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = p1 ? p1 : p2;
        return dummyHead->next;
    }
};
// @lc code=end
