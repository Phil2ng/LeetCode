/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * 全排列 -- 有回溯的DFS
 * 
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        return ans;
    }
    void backtracking(vector<int> &nums, int step, vector<vector<int>> &ans)
    {
        if (step == nums.size() - 1)
        {
            ans.push_back(nums);
            return;
        }
        for (int i = step; i < nums.size(); ++i)
        {
            swap(nums[i], nums[step]);
            backtracking(nums, step + 1, ans);
            swap(nums[i], nums[step]);
        }
    }
};
// @lc code=end

