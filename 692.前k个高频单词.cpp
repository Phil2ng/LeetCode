/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> cnt;
        for (string word : words)
        {
            ++cnt[word];
        }
        unordered_map<int, set<string>> res;
        vector<string> ans;
        int n = 0;
        for (auto &[word, count] : cnt)
        {
            res[count].insert(word);
            n = max(n, count);
        }
        for (int i = n; i > 0; --i)
        {
            for (string s : res[i])
            {
                ans.push_back(s);
                if (--k == 0)
                    return ans;
            }
        }
        return ans;
    }
};
// @lc code=end
