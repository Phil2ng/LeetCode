// DP
// dp[n] = max{ dp[i]*(n-i), i*(n-i) } ; 其中 0<i<n

class Solution
{
public:
    int cuttingRope(int n)
    {
        vector<int> dp = vector<int>(n + 1, 1);
        for (int k = 2; k <= n; ++k)
        {
            for (int i = 1; i < k; ++i)
            {
                dp[k] = max(dp[k], dp[i] * (k - i));
                dp[k] = max(dp[k], i * (k - i));
            }
        }
        return dp[n];
    }
};