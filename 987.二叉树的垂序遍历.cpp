/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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
#define N 1010
class Solution
{
    vector<int> nums[N][N * 2];
    vector<vector<int>> ans;
    void init_nums(TreeNode *root, int row, int col)
    {
        if (!root)
            return;
        nums[row][col].push_back(root->val);
        init_nums(root->left, row + 1, col - 1);
        init_nums(root->right, row + 1, col + 1);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        init_nums(root, 0, 0 + N);
        for (size_t j = 0; j < 2 * N; j++)
        {
            vector<int> arr;
            for (size_t i = 0; i < N; i++)
            {
                sort(nums[i][j].begin(), nums[i][j].end());
                for (auto &&num : nums[i][j])
                {
                    arr.push_back(num);
                }
            }
            if (!arr.empty())
            {
                ans.push_back(arr);
            }
        }
        return ans;
    }
};
// @lc code=end

