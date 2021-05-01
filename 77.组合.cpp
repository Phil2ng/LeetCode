/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * 组合问题 -- 回溯法
 * 
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> tmp(k, 0);
        backtracking(ans, k, 1, n, tmp);
        return ans;
    }
    void backtracking(vector<vector<int>> &ans, int step, int pos, int n, vector<int> &tmp)
    {
        if (step == 0)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = pos; i <= n; ++i)
        {
            tmp[step - 1] = i;
            backtracking(ans, step - 1, i + 1, n, tmp);
            tmp[step - 1] = 0;
        }
    }
};
// @lc code=end
