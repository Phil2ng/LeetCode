/*
 * @lc app=leetcode.cn id=318 lang=cpp
 *
 * [318] 最大单词长度乘积
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<string> &words)
    {
        unordered_map<int, int> dict;
        int ans = 0;
        for (string word : words)
        {
            int mask = 0, len = word.size();
            for (char c : word)
            {
                mask |= 1 << (c - 'a');
            }
            dict[mask] = max(dict[mask], len);
            for (auto &[h_mask, h_len] : dict)
            {
                if ((mask & h_mask) == 0)
                {
                    ans = max(ans, len * h_len);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

