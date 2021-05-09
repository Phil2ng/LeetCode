/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int num : nums)
            ++mp[num];
        int ans = 0;
        for (auto &[num, cnt] : mp)
        {
            if (mp.count(num + 1))
            {
                ans = max(ans, cnt + mp[num + 1]);
            }
        }
        return ans;
    }
};
// @lc code=end
