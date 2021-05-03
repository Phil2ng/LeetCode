/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> ans;
        backtracking(nums, 0, ans);
        set<vector<int>> st(ans.begin(), ans.end());
        ans.assign(st.begin(), st.end());
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

