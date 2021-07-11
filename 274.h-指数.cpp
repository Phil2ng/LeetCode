/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * 计数排序
 * 
 * [274] H 指数
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int maxt = 0, ans = 0;
        unordered_map<int, int> cnt;
        for (int c : citations)
        {
            cnt[c]++;
            maxt = max(maxt, c);
        }
        for (int i = maxt; i >= 0; i--)
        {
            if (ans + cnt[i] > i)
            {
                if (ans < i)
                    ans = i;
                break;
            }
            ans += cnt[i];
        }
        return ans;
    }
};
// @lc code=end

