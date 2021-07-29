/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
 */

// @lc code=start
class Solution
{
public:
    vector<int> pathInZigZagTree(int label)
    {
        vector<int> ans;
        while (label)
        {
            ans.push_back(label);
            label /= 2;
        }
        reverse(ans.begin(), ans.end());
        int n = ans.size();
        for (int i = 0; i < n; i++)
        {
            if ((n - i - 1) % 2)
            {
                int l = pow(2, i), r = pow(2, i + 1) - 1;
                ans[i] = r - (ans[i] - l);
            }
        }
        return ans;
    }
};
// @lc code=end
