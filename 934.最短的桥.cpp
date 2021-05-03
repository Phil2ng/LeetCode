/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * BFS 广度优先搜索
 * 找全第一个岛屿 -> BFS查找最短距离
 * 
 * [934] 最短的桥
 */

// @lc code=start
class Solution
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int shortestBridge(vector<vector<int>> &A)
    {
        int m = A.size(), n = A[0].size();
        queue<pair<int, int>> points;
        // dfs寻找第一个岛屿points，并把1全部赋值2
        bool flag = false;
        for (int i = 0; i < m; ++i)
        {
            if (flag)
                break;
            for (int j = 0; j < n; ++j)
            {
                if (A[i][j] == 1)
                {
                    dfs(A, points, m, n, i, j);
                    flag = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿，并把过程经过的0赋值为2
        int x, y, level = 0;
        while (!points.empty())
        {
            int n_points = points.size();
            while (n_points--)
            {
                auto [r, c] = points.front();
                points.pop();
                for (int i = 0; i < 4; ++i)
                {
                    x = r + direction[i], y = c + direction[i + 1];
                    if (x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    if (A[x][y] == 2)
                        continue;
                    if (A[x][y] == 1)
                        return level;
                    points.push({x, y});
                    A[x][y] = 2;
                }
            }
            ++level;
        }
        return 0;
        
    }
    void dfs(vector<vector<int>> &A, queue<pair<int, int>> &points, int m, int n, int r, int c)
    {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;
        if (A[r][c] == 0 || A[r][c] == 2)
            return;
        points.push({r, c});
        A[r][c] = 2;
        for (int i = 0; i < 4; ++i)
        {
            dfs(A, points, m, n, r + direction[i], c + direction[i + 1]);
        }
    }
};
// @lc code=end
