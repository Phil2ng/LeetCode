/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * 滑动窗口+位运算+哈希表
 * 
 * [187] 重复的DNA序列
 */

// @lc code=start
class Solution
{
    const int L = 10;
    unordered_map<char, int> bin = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> ans;
        unordered_map<int, int> cnt;
        int n = s.size(), x = 0;
        for (int i = 0; i < n; i++)
        {
            x = ((x << 2) | bin[s[i]]) & ((1 << (2 * L)) - 1);
            if (i >= L - 1)
            {
                cnt[x]++;
                if (cnt[x] == 2)
                    ans.push_back(s.substr(i - L + 1, L));
            }
        }
        return ans;
    }
};
// @lc code=end

