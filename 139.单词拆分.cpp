/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * dp[n] = dp[n-len(word1)] || dp[n-len(word2)] || ....
 * 
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (const string &word : wordDict)
            {
                int len = word.length();
                if (len <= i && s.substr(i - len, len) == word)
                {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

