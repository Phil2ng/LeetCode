/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        int n = T.size();
        vector<int> ans(n);
        stack<int> indices;
        for (int i = 0; i < n; ++i)
        {
            while (!indices.empty())
            {
                int idx = indices.top();
                if (T[idx] >= T[i])
                    break;
                indices.pop();
                ans[idx] = i - idx;
            }
            indices.push(i);
        }
        return ans;
    }
};
// @lc code=end

