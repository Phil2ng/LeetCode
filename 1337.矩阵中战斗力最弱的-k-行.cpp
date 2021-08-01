/*
 * @lc app=leetcode.cn id=1337 lang=cpp
 *
 * [1337] 矩阵中战斗力最弱的 K 行
 */

// @lc code=start
typedef pair<int, int> PII;
class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        priority_queue<PII, vector<PII>, greater<PII>> heap;
        for (int i = 0; i < m; i++)
        {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            heap.push(make_pair(sum, i));
        }
        vector<int> ans;
        for (size_t i = 0; i < k; i++)
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};
// @lc code=end

