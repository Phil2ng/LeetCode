/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution
{
private:
    bool flag = false;
    vector<pair<int, int>> next;
    vector<vector<bool>> row = vector<vector<bool>>(9, vector<bool>(128, false));
    vector<vector<bool>> column = vector<vector<bool>>(9, vector<bool>(128, false));
    vector<vector<bool>> grid = vector<vector<bool>>(9, vector<bool>(128, false));

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        for (int r = 0; r < 9; ++r)
        {
            for (int c = 0; c < 9; ++c)
            {
                int num = board[r][c];
                if (num == '.')
                {
                    next.push_back({r, c});
                }
                else
                {
                    row[r][num] = true;
                    column[c][num] = true;
                    grid[(r / 3) * 3 + (c / 3)][num] = true;
                }
            }
        }
        dfs(board, 0);
    }
    bool dfs(vector<vector<char>> &board, int step)
    {
        if (step == next.size())
        {
            return true;
        }
        auto [r, c] = next[step];
        for (int x = '1'; x <= '9'; ++x)
        {
            if (!row[r][x] && !column[c][x] && !grid[r / 3 * 3 + c / 3][x])
            {
                board[r][c] = x;
                row[r][x] = column[c][x] = grid[r / 3 * 3 + c / 3][x] = true;
                if (dfs(board, step + 1))
                    return true;
                board[r][c] = '.';
                row[r][x] = column[c][x] = grid[r / 3 * 3 + c / 3][x] = false;
            }
        }
        return false;
    }
};
// @lc code=end
