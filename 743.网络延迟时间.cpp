/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
#define N 110

class Solution
{
    int d[N][N], n;
    void init()
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (i == j)
                    d[i][j] = 0;
                else
                    d[i][j] = INT_MAX / 2;
    }

    // 算法结束后，d[a][b]表示a到b的最短距离
    void floyd()
    {
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        Solution::n = n;
        init();
        for (auto &&t : times)
        {
            d[t[0]][t[1]] = t[2];
        }
        floyd();
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (d[k][i] == INT_MAX / 2)
                return -1;
            ans = max(ans, d[k][i]);
        }
        return ans;
    }
};
// @lc code=end

