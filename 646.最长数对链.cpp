/*
 * @lc app=leetcode.cn id=646 lang=cpp
 *
 * dp[i] = max(dp[j]) + 1
 * 
 * [646] 最长数对链
 */

// @lc code=start
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int m = pairs.size(), n = pairs[0].size();
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b) { return a[1] < b[1]; });
        vector<int> dp(m, 1);
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; pairs[j][1] < pairs[i][0]; ++j)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
