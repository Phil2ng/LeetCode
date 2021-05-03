/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution{
private:
    vector<vector<int>> ans;
    vector<int> sequence;
    void dfs(vector<int> &candidates, int step, int target)
    {
        if (target == 0)
        {
            ans.push_back(sequence);
            return;
        }
        for (int i = step; i < candidates.size() && target >= candidates[i]; ++i)
        {
            if (i > step && candidates[i] == candidates[i - 1])
                continue;
            sequence.push_back(candidates[i]);
            dfs(candidates, i + 1, target - candidates[i]);
            sequence.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }
};
// @lc code=end
