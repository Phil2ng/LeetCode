// DFS/BFS,DP

class Solution
{
    int matrix[100][100], vis[100][100], ans = 0;

public:
    int movingCount(int m, int n, int k)
    {
        memset(matrix, 0, sizeof(matrix));
        memset(matrix, 0, sizeof(vis));
        return dfs(0, 0, m, n, k);
    }
    int dfs(int i, int j, int m, int n, int k)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || get_k(i) + get_k(j) > k)
            return 0;
        vis[i][j] = 1;
        return 1 + dfs(i + 1, j, m, n, k) + dfs(i, j + 1, m, n, k) + dfs(i - 1, j, m, n, k) + dfs(i, j - 1, m, n, k);
    }
    int get_k(int n)
    {
        int ret = 0;
        while (n)
        {
            ret += n % 10;
            n /= 10;
        }
        return ret;
    }
};