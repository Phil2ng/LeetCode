/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * 回溯法 DFS
 * 
 * [79] 单词搜索
 */

// @lc code=start
class Solution
{
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || board[0].empty())
            return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        bool find = false;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                backtracking(board, visited, 0, word, find, i, j);
        return find;
    }
    void backtracking(vector<vector<char>> &board, vector<vector<bool>> &visited, int step, const string &word, bool &find, int r, int c)
    {
        if (find)
            return;
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return;
        if (visited[r][c] || board[r][c] != word[step])
            return;
        if (step == word.size() - 1)
        {
            find = true;
            return;
        }

        visited[r][c] = true;
        for (int i = 0; i < 4; ++i)
            backtracking(board, visited, step + 1, word, find, r + direction[i], c + direction[i + 1]);
        visited[r][c] = false;
    }
};
// @lc code=end
