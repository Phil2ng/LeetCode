/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    int ans = INT_MAX, prev = INT_MIN / 2;

public:
    int getMinimumDifference(TreeNode *root)
    {
        preorder(root);
        return ans;
    }
    void preorder(TreeNode *root)
    {
        if (!root)
            return;
        preorder(root->left);
        ans = min(ans, root->val - prev);
        prev = root->val;
        preorder(root->right);
    }
};
// @lc code=end
