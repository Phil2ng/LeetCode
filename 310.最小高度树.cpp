/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * 找到叶子节点，BFS向上找父节点，所求为节点数为0的前一步
 * 
 * [310] 最小高度树
 */

// @lc code=start
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> ans;
        vector<vector<int>> road(n);
        vector<int> degrees(n, 0); // 入度出度是很好的指标，而不仅visited
        for (auto e : edges)
        {
            ++degrees[e[0]];
            ++degrees[e[1]];
            road[e[0]].emplace_back(e[1]);
            road[e[1]].emplace_back(e[0]);
        }
        set<int> q,prev;
        for (int i = 0; i < n; ++i)
            if (degrees[i] <= 1)
                q.insert(i);
        prev= q;
        while (!q.empty())
        {
            set<int> q2;
            for (auto k : q)
            {
                for (auto t : road[k])
                {
                    if (--degrees[t]==1)
                    {
                        q2.insert(t);
                    }
                }
            }
            prev = q;
            q = q2;
        }
        ans.assign(prev.begin(), prev.end());
        return ans;
    }
};
// @lc code=end

