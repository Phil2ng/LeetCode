/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, 0);
        queue<int> q;
        for (int i = 0; i < n; ++i)
        {
            if (!color[i])
            {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (int j : graph[node])
                {
                    if (!color[j])
                    {
                        q.push(j);
                        color[j] = color[node] == 1 ? 2 : 1;
                    }
                    else if (color[node] == color[j])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end
