/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * 分类讨论
 * 
 * [794] 有效的井字游戏
 */

// @lc code=start
class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int xCount = 0, oCount = 0;
        for (auto &&row : board)
        {
            for (auto &&c : row)
            {
                if (c == 'X')
                    xCount++;
                else if (c == 'O')
                    oCount++;
            }
        }
        if (xCount != oCount && xCount != oCount + 1)
            return false;
        if (win(board, 'X') && xCount != oCount + 1)
            return false;
        if (win(board, 'O') && xCount != oCount)
            return false;
        return true;
    }
    bool win(vector<string> &board, char c)
    {
        for (int i = 0; i < 3; i++)
        {
            if (board[i][0] == c && board[i][1] == c && board[i][2] == c)
                return true;
            if (board[0][i] == c && board[1][i] == c && board[2][i] == c)
                return true;
        }
        if (board[0][0] == c && board[1][1] == c && board[2][2] == c)
            return true;
        if (board[0][2] == c && board[1][1] == c && board[2][0] == c)
            return true;
        return false;
    }
};
// @lc code=end

