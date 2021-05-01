/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * N皇后问题 -- 回溯DFS
 * 时间复杂度O(N!), 
 * 空间复杂度O(N)-位运算可优化空间复杂度
 * 
 * [51] N 皇后
 */

// @lc code=start
class Solution{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> column(n, false), ldiag(2 * n - 1, false), rdiag(2 * n - 1, false);
        backtracking(ans, board, column, ldiag, rdiag, 0, n);
        return ans;
    }
    void backtracking(vector<vector<string>> &ans, vector<string> &board, vector<bool> &column, vector<bool> &ldiag, vector<bool> &rdiag, int x, int n)
    {
        if (x == n)
        {
            ans.push_back(board);
            return;
        }
        for (int y = 0; y < n; ++y)
        {
            if (column[y] || ldiag[y - x + n - 1] || rdiag[x + y])
                continue;
            board[x][y] = 'Q';
            column[y] = ldiag[y - x + n - 1] = rdiag[x + y] = true;
            backtracking(ans, board, column, ldiag, rdiag, x + 1, n);
            board[x][y] = '.';
            column[y] = ldiag[y - x + n - 1] = rdiag[x + y] = false;
        }
    }
};
// @lc code=end
