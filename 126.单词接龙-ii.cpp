/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * 两节点间最短距离 -- BFS广度优先搜素
 * 
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> dict = {wordList.begin(), wordList.end()};
        if (!dict.count(endWord))
            return ans;
        dict.erase(beginWord);
        dict.erase(endWord);
        unordered_set<string> q1{beginWord}, q2{endWord};
        // BFS构图
        unordered_map<string, vector<string>> next;
        bool reversed = false, found = false;
        while (!q1.empty())
        {
            unordered_set<string> q;
            for (const auto &w : q1)
            {
                string s = w;
                for (int i = 0; i < s.size(); ++i)
                {
                    char ch = s[i];
                    for (char c = 'a'; c <= 'z'; ++c)
                    {
                        s[i] = c;
                        if (!dict.count(s) && !q2.count(s))
                            continue;
                        reversed ? next[s].push_back(w) : next[w].push_back(s);
                        q.insert(s);
                        if (q2.count(s))
                            found = true;
                    }
                    s[i] = ch;
                }
            }
            if (found)
                break;
            for (auto &w : q)
            {
                dict.erase(w);
            }
            if (q.size() <= q2.size())
                q1 = q;
            else
            {
                q1 = q2;
                q2 = q;
                reversed = !reversed;
            }
        }
        if (found)
        {
            vector<string> path = {beginWord};
            // DFS查找路径
            dfs(beginWord, endWord, next, path, ans);
        }
        return ans;
    }
    void dfs(string &src, string &dst, unordered_map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ans)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (auto &s : next[src])
        {
            path.push_back(s);
            dfs(s, dst, next, path, ans);
            path.pop_back();
        }
    }
};
// @lc code=end
