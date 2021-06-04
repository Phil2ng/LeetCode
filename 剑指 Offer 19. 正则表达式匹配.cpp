// 动态规划,分类讨论

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> f = vector<vector<bool>>(m + 1, vector<bool>(n + 1, false));
        f[0][0] = true;
        for (int i = 2; i <= n; i += 2)
            if (p[i - 1] == '*')
                f[0][i] = f[0][i - 2];
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (p[j - 1] == '.')
                    f[i][j] = f[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    if (s[i - 1] == p[j - 2] || p[j - 2] == '.')
                        f[i][j] = f[i][j - 2] || f[i - 1][j] || f[i - 1][j - 2];
                    else
                        f[i][j] = f[i][j - 2];
                }
                else
                    f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1];
            }
        }
        return f[m][n];
    }
};