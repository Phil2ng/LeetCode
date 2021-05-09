/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; ++i)
        {
            int num = nums[i];
            if (mp.count(num))
            {
                mp[num][0]++;
                mp[num][2] = i;
            }
            else
            {
                mp[num] = {1, i, i};
            }
        }
        int maxNum = 0, minLen;
        for (auto &[_, vec] : mp)
        {
            if (maxNum < vec[0])
            {
                maxNum = vec[0];
                minLen = vec[2] - vec[1] + 1;
            }
            else if (maxNum == vec[0])
            {
                minLen = min(minLen, vec[2] - vec[1] + 1);
            }
        }
        return minLen;
    }
};
// @lc code=end

