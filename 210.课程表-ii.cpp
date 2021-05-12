/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0), res;
        for (auto &p : prerequisites)
        {
            graph[p[1]].push_back(p[0]);
            ++indegree[p[0]];
        }
        queue<int> q;
        for (int i = 0; i < numCourses; ++i)
        {
            if (!indegree[i])
                q.push(i);
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (auto v : graph[u])
            {
                --indegree[v];
                if (!indegree[v])
                    q.push(v);
            }
        }
        for (int i = 0; i < numCourses; ++i)
        {
            if (indegree[i])
                return vector<int>();
        }
        return res;
    }
};
// @lc code=end
