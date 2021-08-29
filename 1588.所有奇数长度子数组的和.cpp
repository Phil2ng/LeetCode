/*
 * @lc app=leetcode.cn id=1588 lang=cpp
 *
 * [1588] 所有奇数长度子数组的和
 */

// @lc code=start
class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size(), sum = 0;
        vector<int> prefixSums(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            prefixSums[i + 1] = prefixSums[i] + arr[i];
        }
        for (int start = 0; start < n; start++)
        {
            for (int length = 1; length <= n - start; length += 2)
            {
                int end = start + length;
                sum += prefixSums[end] - prefixSums[start];
            }
        }
        return sum;
    }
};
// @lc code=end
