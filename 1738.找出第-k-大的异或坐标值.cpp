/*
 * @lc app=leetcode.cn id=1738 lang=cpp
 *
 * 二维前缀和 + 快速选择算法
 * 
 * [1738] 找出第 K 大的异或坐标值
 */

// @lc code=start
class Solution {
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> res(m + 1, vector<int>(n + 1, 0));
        vector<int> ans;
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                res[i][j] = res[i - 1][j] ^ res[i][j - 1] ^ res[i - 1][j - 1] ^ matrix[i - 1][j - 1];
                ans.push_back(res[i][j]);
            }
        }
        nth_element(ans.begin(), ans.begin() + k - 1, ans.end(), greater<int>());
        return ans[k-1];
    }
};
// @lc code=end

