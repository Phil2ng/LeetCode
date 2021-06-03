/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * 前缀和+哈希表
 * 
 * [525] 连续数组
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int cnt = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            cnt += nums[i] ? 1 : -1;
            if (mp.count(cnt))
            {
                ans = max(ans, i - mp[cnt]);
            }
            else
            {
                mp[cnt] = i;
            }
        }
        return ans;
    }
};
// @lc code=end
