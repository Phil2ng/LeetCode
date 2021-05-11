/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int maxNum = max(p->val, q->val), minNum = min(p->val, q->val);
        if (root->val > maxNum)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < minNum)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};
// @lc code=end
