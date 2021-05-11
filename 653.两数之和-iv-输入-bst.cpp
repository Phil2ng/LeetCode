/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    vector<int> nums;

public:
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root);
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] == k)
                return true;
            else if (nums[l] + nums[r] > k)
                --r;
            else if (nums[l] + nums[r] < k)
                ++l;
        }
        return false;
    }
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        nums.push_back(root->val);
        inorder(root->right);
    }
};
// @lc code=end

