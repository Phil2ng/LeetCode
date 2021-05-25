/*
 * @lc app=leetcode.cn id=1787 lang=cpp
 *
 * 有技巧的动态规划
 * 
 * [1787] 使所有区间的异或结果为零
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
    static constexpr int MAXX = 1 << 10;

public:
    int minChanges(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> f(MAXX, INT_MAX / 2);
        f[0] = 0;
        for (int i = 0; i < k; ++i)
        {
            unordered_map<int, int> cnt;
            int size = 0;
            for (int j = i; j < n; j += k)
            {
                ++cnt[nums[j]];
                ++size;
            }
            int t2 = *min_element(f.begin(), f.end());
            vector<int> g(MAXX, t2);
            for (int mask = 0; mask < MAXX; ++mask)
            {
                for (auto [x, cntx] : cnt)
                {
                    g[mask] = min(g[mask], f[mask ^ x] - cntx);
                }
            }
            for_each(g.begin(), g.end(), [&](int &val)
                     { val += size; });
            f = move(g);
        }
        return f[0];
    }
};
// @lc code=end
