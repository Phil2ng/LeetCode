/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序搜索树
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
    TreeNode *prev = nullptr, *head;

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root)
            return root;
        increasingBST(root->left);
        if (prev)
        {
            prev->right = root;
            root->left = nullptr;
        }
        else
            head = root;
        prev = root;
        increasingBST(root->right);
        return head;
    }
};
// @lc code=end
