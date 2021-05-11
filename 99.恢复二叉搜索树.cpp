/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
    TreeNode *mistake1 = nullptr, *mistake2 = nullptr, *prev = nullptr;

public:
    void recoverTree(TreeNode *root)
    {
        inorder(root);
        if (mistake1 && mistake2)
        {
            swap(mistake1->val, mistake2->val);
        }
    }
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        if (root->left)
            inorder(root->left);
        if (prev && root->val < prev->val)
        {
            if (!mistake1)
                mistake1 = prev;
            mistake2 = root;
        }
        prev = root;
        if (root->right)
            inorder(root->right);
    }
};
// @lc code=end
