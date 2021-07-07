/*
 * @lc app=leetcode.cn id=1711 lang=cpp
 *
 * [1711] 大餐计数
 */

// @lc code=start
class Solution
{
public:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int maxSum = (1 << 21);

    int countPairs(vector<int> &deliciousness)
    {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int &val : deliciousness)
        {
            for (int sum = 1; sum <= maxSum; sum <<= 1)
            {
                if (mp.count(sum - val))
                {
                    ans = (ans + mp[sum - val]) % MOD;
                }
            }
            mp[val]++;
        }
        return ans;
    }
};
// @lc code=end
