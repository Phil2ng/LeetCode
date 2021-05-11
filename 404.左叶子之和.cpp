/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * 迭代BFS和递归DFS分别实现树的遍历
 * 
 * [404] 左叶子之和
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
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node->left)
            {
                if (isLeafNode(node->left))
                    ans += node->left->val;
                else
                    q.push(node->left);
            }
            if (node->right)
                q.push(node->right);
        }
        return ans;
    }
    bool isLeafNode(TreeNode *node)
    {
        return !node->left && !node->right;
    }

    // int sumOfLeftLeaves(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;
    //     return dfs(root);
    // }
    // int dfs(TreeNode *root)
    // {
    //     int ans = 0;
    //     if (root->left)
    //     {
    //         ans += isLeafNode(root->left) ? root->left->val : dfs(root->left);
    //     }
    //     if (root->right)
    //     {
    //         ans += dfs(root->right);
    //     }
    //     return ans;
    // }
    // bool isLeafNode(TreeNode *node)
    // {
    //     return !node->left && !node->right;
    // }
};
// @lc code=end
