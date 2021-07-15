/*
 * @lc app=leetcode.cn id=1846 lang=cpp
 *
 * 计数排序 O(n)
 * 
 * [1846] 减小和重新排列数组后的最大元素
 */

// @lc code=start
class Solution
{
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        int n = arr.size(), ans = 0, cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        for (auto &&a : arr)
        {
            cnt[a > n ? n : a]++;
        }
        for (size_t i = 1; i <= n; i++)
        {
            ans = ans + cnt[i] < i ? ans + cnt[i] : i;
        }
        return ans;
    }
};
// @lc code=end

