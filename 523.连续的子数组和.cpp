/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * 同余定理+前缀和+哈希表
 * 
 * [523] 连续的子数组和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder))
            {
                if (i - mp[remainder] >= 2)
                    return true;
            }
            else
                mp[remainder] = i;
        }
        return false;
    }
};
// @lc code=end
