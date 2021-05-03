/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        if (!root)
            return ans;
        string str = "" + to_string(root->val);
        dfs(root, ans, str);
        return ans;
    }
    void dfs(TreeNode *root, vector<string> &ans, string &str)
    {
        if (!root->left && !root->right)
        {
            ans.push_back(str);
            return;
        }
        if (root->left)
        {
            string t = to_string(root->left->val);
            str += "->" + t;
            dfs(root->left, ans, str);
            str.erase(str.end() - t.size() - 2, str.end());
        }
        if (root->right)
        {
            string t = to_string(root->right->val);
            str += "->" + t;
            dfs(root->right, ans, str);
            str.erase(str.end() - t.size() - 2, str.end());
        }
    }
};
// @lc code=end

