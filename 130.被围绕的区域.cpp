/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * DFS/BFS 
 * 识别外侧O
 * 
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution{
public:
    void solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                int flag = i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1;
                if (flag && board[i][j] == 'O')
                {
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'F')
                    board[i][j] = 'O';
            }
        }
    }
    vector<int> direction{-1, 0, 1, 0, -1};
    void dfs(vector<vector<char>> &board, int r, int c)
    {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size())
            return;
        if (board[r][c] == 'X' || board[r][c] == 'F')
            return;
        board[r][c] = 'F';
        for (int i = 0; i < 4; ++i)
            dfs(board, r + direction[i], c + direction[i + 1]);
    }
};
// @lc code=end
