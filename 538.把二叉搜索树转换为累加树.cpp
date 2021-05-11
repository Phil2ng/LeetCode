/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    TreeNode *prev = nullptr;

public:
    TreeNode *convertBST(TreeNode *root)
    {
        if (!root)
            return root;
        root->right = convertBST(root->right);
        if (prev)
            root->val += prev->val;
        prev = root;
        root->left = convertBST(root->left);
        return root;
    }
};
// @lc code=end

