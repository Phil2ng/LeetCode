/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
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
    unordered_map<TreeNode *, TreeNode *> parents;
    vector<int> ans;
    void build_parents(TreeNode *root)
    {
        if (root->left)
        {
            parents[root->left] = root;
            build_parents(root->left);
        }
        if (root->right)
        {
            parents[root->right] = root;
            build_parents(root->right);
        }
    }
    void find_ans(TreeNode *node, TreeNode *from, int k)
    {
        if (node == nullptr)
            return;
        if (k == 0)
        {
            ans.push_back(node->val);
            return;
        }
        if (node->left != from)
        {
            find_ans(node->left, node, k - 1);
        }
        if (node->right != from)
        {
            find_ans(node->right, node, k - 1);
        }
        if (parents[node] != from)
        {
            find_ans(parents[node], node, k - 1);
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        build_parents(root);
        find_ans(target, nullptr, k);
        return ans;
    }
};
// @lc code=end

