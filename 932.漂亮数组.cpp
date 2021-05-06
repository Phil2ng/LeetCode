/*
 * @lc app=leetcode.cn id=932 lang=cpp
 *
 * 数学性质题
 * 
 * [932] 漂亮数组
 */

// @lc code=start
class Solution{
public:
    vector<int> beautifulArray(int N)
    {
        vector<int> ret;
        if (N == 1)
            return {1};
        for (int x : beautifulArray((N + 1) / 2))
            ret.push_back(2 * x - 1);
        for (int x : beautifulArray(N / 2))
            ret.push_back(2 * x);
        return ret;
    }
};
// @lc code=end
