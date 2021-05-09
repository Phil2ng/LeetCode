/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */

// @lc code=start
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans = 0, psum = 0;
        unordered_map<int, int> hashmap;
        hashmap[0] = 1;
        for (int num : nums)
        {
            psum += num;
            ans += hashmap[psum - k];
            ++hashmap[psum];
        }
        return ans;
    }
};
// @lc code=end
