/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * 快慢指针遍历
 * 
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;
		//判断是否存在环路
		do {
			if (!fast || !fast->next)
				return nullptr;
			fast = fast->next->next;
			slow = slow->next;
		} while (fast != slow);

		//查找环路起始节点
		fast = head;
		while (fast != slow) {
			slow = slow->next;
			fast = fast->next;
		}
		return fast;
	}
};
// @lc code=end
