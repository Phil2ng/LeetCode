/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * 差分
 * 
 * [1109] 航班预订统计
 */

// @lc code=start
class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> arr(n + 2, 0), ans(n);
        for (auto &&b : bookings)
        {
            arr[b[0]] += b[2];
            arr[b[1] + 1] -= b[2];
        }
        for (int i = 1; i <= n; i++)
        {
            arr[i] += arr[i - 1];
            ans[i - 1] = arr[i];
        }
        return ans;
    }
};
// @lc code=end

