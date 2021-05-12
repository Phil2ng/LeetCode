/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * 并查集
 * 
 * [684] 冗余连接
 */

// @lc code=start
class UnionFind
{
    vector<int> id;

public:
    UnionFind(int n) : id(n)
    {
        iota(id.begin(), id.end(), 0);
    }
    int find(int p)
    {
        while (id[p] != p)
        {
            p = id[p];
        }
        return p;
    }
    void connect(int p, int q)
    {
        id[find(p)] = find(q);
    }
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        UnionFind uf(n + 1);
        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            if (uf.isConnected(u, v))
                return e;
            uf.connect(u, v);
        }
        return { -1, -1 };
    }
};

// @lc code=end

