/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * 拓扑排序
 * 
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> rg(n);
        vector<int> inDeg(n);
        for (int i = 0; i < n; i++)
        {
            for (auto &&j : graph[i])
            {
                rg[j].push_back(i);
            }
            inDeg[i] = graph[i].size();
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (inDeg[i] == 0)
                que.push(i);
        }
        while (!que.empty())
        {
            int x = que.front();
            que.pop();
            for (auto &&y : rg[x])
            {
                inDeg[y]--;
                if (inDeg[y] == 0)
                    que.push(y);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (inDeg[i] == 0)
                ans.push_back(i);
        }
        return ans;
    }
};
// @lc code=end

