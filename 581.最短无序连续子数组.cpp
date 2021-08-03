/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int mini = INT_MAX, maxi = INT_MIN, right = 0, left = 0;
        int n = nums.size(), flag = 1;
        for (int i = 1; i < n; i++)
        {
            if (flag && nums[i] >= nums[i - 1])
                continue;
            flag = 0;
            maxi = max(maxi, nums[i - 1]);
            if (nums[i] < maxi)
            {
                mini = min(mini, nums[i]);
                right = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > mini)
            {
                left = i - 1;
                break;
            }
        }
        return right - left;
    }
};
// @lc code=end
