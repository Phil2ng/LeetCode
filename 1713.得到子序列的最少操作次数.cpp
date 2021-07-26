/*
 * @lc app=leetcode.cn id=1713 lang=cpp
 *
 * 贪心+二分查找, LCS 问题转化为 LIS 问题
 * 
 * [1713] 得到子序列的最少操作次数
 */

// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        int n = target.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++)
        {
            pos[target[i]] = i;
        }
        vector<int> increase;
        for (auto &&a : arr)
        {
            if (pos.count(a))
            {
                int idx = pos[a];
                auto it = lower_bound(increase.begin(), increase.end(), idx);
                if (it != increase.end())
                {
                    *it = idx;
                }
                else
                {
                    increase.push_back(idx);
                }
            }
        }
        return n - increase.size();
    }
};
// @lc code=end
