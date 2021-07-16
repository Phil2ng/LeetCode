/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return nullptr;
        Node *p = head, *q;
        while (p)
        {
            Node *node = new Node(p->val);
            node->next = p->next;
            p->next = node;
            p = p->next->next;
        }
        p = head;
        while (p)
        {
            if (!p->random)
                p->next->random = nullptr;
            else
                p->next->random = p->random->next;
            p = p->next->next;
        }
        Node *new_head = head->next;
        p = head;
        q = head->next;
        while (p)
        {
            p->next = q->next;
            p = p->next;
            if (!p)
                break;
            q->next = p->next;
            q = q->next;
        }
        return new_head;
    }
};
// @lc code=end
