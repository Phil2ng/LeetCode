/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return 0;
        return pathSumStartWithRoot(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
    int pathSumStartWithRoot(TreeNode *root, int sum)
    {
        if (!root)
            return 0;
        int count = root->val == sum ? 1 : 0;
        count += pathSumStartWithRoot(root->left, sum - root->val);
        count += pathSumStartWithRoot(root->right, sum - root->val);
        return count;
    }
};
// @lc code=end

