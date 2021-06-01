/*
 * @lc app=leetcode.cn id=1744 lang=cpp
 * 
 * 前缀和+边界条件
 * 
 * [1744] 你能在你最喜欢的那天吃到你最喜欢的糖果吗？
 */

// @lc code=start
class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        vector<long> tmp(candiesCount.size() + 1, 0);
        for (int i = 0; i < candiesCount.size(); ++i)
        {
            tmp[i + 1] = candiesCount[i] + tmp[i];
        }
        vector<bool> ans;
        for (auto q : queries)
        {
            if (q[1] + 1 > tmp[q[0] + 1])
                ans.push_back(false);
            else if (long(q[1] + 1) * q[2] <= tmp[q[0]])
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};
// @lc code=end
