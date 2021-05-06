/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * 分治法，需要记忆备忘录 -> 相当于动态规划
 * 
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> val(n + 2, 1);
        for (int i = 0; i < n; i++)
            val[i + 1] = nums[i];
        vector<vector<int>> memoization(n + 2, vector<int>(n + 2, -1));
        return fun(val, memoization, 0, n + 1);
    }
    int fun(vector<int> &val, vector<vector<int>> &memoization, int l, int h)
    {
        if (h - l <= 1)
            return 0;
        if (memoization[l][h] != -1)
            return memoization[l][h];
        int sum = 0;
        for (int i = l + 1; i < h; ++i)
        {
            sum = val[l] * val[i] * val[h] + fun(val, memoization, l, i) + fun(val, memoization, i, h);
            memoization[l][h] = max(memoization[l][h], sum);
        }
        return memoization[l][h];
    }

    // int maxCoins(vector<int> &nums)
    // {
    //     int n = nums.size();
    //     vector<vector<int>> rec(n + 2, vector<int>(n + 2));
    //     vector<int> val(n + 2);
    //     val[0] = val[n + 1] = 1;
    //     for (int i = 1; i <= n; i++)
    //     {
    //         val[i] = nums[i - 1];
    //     }
    //     for (int i = n - 1; i >= 0; i--)
    //     {
    //         for (int j = i + 2; j <= n + 1; j++)
    //         {
    //             for (int k = i + 1; k < j; k++)
    //             {
    //                 int sum = val[i] * val[k] * val[j];
    //                 sum += rec[i][k] + rec[k][j];
    //                 rec[i][j] = max(rec[i][j], sum);
    //             }
    //         }
    //     }
    //     return rec[0][n + 1];
    // }
};
// @lc code=end

