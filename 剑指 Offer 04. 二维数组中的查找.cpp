// 数学规律题
// 或者看做 binary search tree 二叉搜索树
// 从右上或左下开始遍历

class Solution
{
public:
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        int i = m - 1, j = 0;
        while (i >= 0 && j < n)
        {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                ++j;
            else
                --i;
        }
        return false;
    }
};