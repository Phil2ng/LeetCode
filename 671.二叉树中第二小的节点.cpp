/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * 遍历
 * 
 * [671] 二叉树中第二小的节点
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
    int ans = -1, minNum;

public:
    int findSecondMinimumValue(TreeNode *root)
    {
        minNum = root->val;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        if (ans != -1 && node->val >= ans)
            return;
        if (node->val > minNum)
            ans = node->val;
        dfs(node->left);
        dfs(node->right);
    }
};
// @lc code=end
